#pragma once

#include "Object.hpp"

#include <cstring>

bool rayTriangleIntersect(const Vector3f &v0, const Vector3f &v1,
                          const Vector3f &v2, const Vector3f &orig,
                          const Vector3f &dir, float &tnear, float &u,
                          float &v) {
    // TODO: Implement this function that tests whether the triangle
    // that's specified bt v0, v1 and v2 intersects with the ray (whose
    // origin is *orig* and direction is *dir*)
    // Also don't forget to update tnear, u and v.

    auto e1 = v1 - v0;
    auto e2 = v2 - v0;
    auto s = orig - v0;
    Vector3f s1, s2;
    s1.x = dir.y * e2.z - dir.z * e2.y;
    s1.y = dir.z * e2.x - dir.x * e2.z;
    s1.z = dir.x * e2.y - dir.y * e2.x;

    s2.x = s.y * e1.z - s.z * e1.y;
    s2.y = s.z * e1.x - s.x * e1.z;
    s2.z = s.x * e1.y - s.y * e1.x;

    float tmp = 1. / (s1.x * e1.x + s1.y * e1.y + s1.z * e1.z);

    auto t = tmp * (s2.x * e2.x + s2.y * e2.y + s2.z * e2.z);
    auto b1 = tmp * (s1.x * s.x + s1.y * s.y + s1.z * s.z);
    auto b2 = tmp * (s2.x * dir.x + s2.y * dir.y + s2.z * dir.z);

    if (t >= 0 && b1 > 0 && b2 > 0 && (1 - b1 - b2) > 0) {
        tnear = t;
        u = b1;
        v = b2;
        return true;
    }
    return false;
}

class MeshTriangle : public Object {
  public:
    MeshTriangle(const Vector3f *verts, const uint32_t *vertsIndex,
                 const uint32_t &numTris, const Vector2f *st) {
        uint32_t maxIndex = 0;
        for (uint32_t i = 0; i < numTris * 3; ++i)
            if (vertsIndex[i] > maxIndex)
                maxIndex = vertsIndex[i];
        maxIndex += 1;
        vertices = std::unique_ptr<Vector3f[]>(new Vector3f[maxIndex]);
        memcpy(vertices.get(), verts, sizeof(Vector3f) * maxIndex);
        vertexIndex = std::unique_ptr<uint32_t[]>(new uint32_t[numTris * 3]);
        memcpy(vertexIndex.get(), vertsIndex, sizeof(uint32_t) * numTris * 3);
        numTriangles = numTris;
        stCoordinates = std::unique_ptr<Vector2f[]>(new Vector2f[maxIndex]);
        memcpy(stCoordinates.get(), st, sizeof(Vector2f) * maxIndex);
    }

    bool intersect(const Vector3f &orig, const Vector3f &dir, float &tnear,
                   uint32_t &index, Vector2f &uv) const override {
        bool intersect = false;
        for (uint32_t k = 0; k < numTriangles; ++k) {
            const Vector3f &v0 = vertices[vertexIndex[k * 3]];
            const Vector3f &v1 = vertices[vertexIndex[k * 3 + 1]];
            const Vector3f &v2 = vertices[vertexIndex[k * 3 + 2]];
            float t, u, v;
            if (rayTriangleIntersect(v0, v1, v2, orig, dir, t, u, v) &&
                t < tnear) {
                tnear = t;
                uv.x = u;
                uv.y = v;
                index = k;
                intersect |= true;
            }
        }

        return intersect;
    }

    void getSurfaceProperties(const Vector3f &, const Vector3f &,
                              const uint32_t &index, const Vector2f &uv,
                              Vector3f &N, Vector2f &st) const override {
        const Vector3f &v0 = vertices[vertexIndex[index * 3]];
        const Vector3f &v1 = vertices[vertexIndex[index * 3 + 1]];
        const Vector3f &v2 = vertices[vertexIndex[index * 3 + 2]];
        Vector3f e0 = normalize(v1 - v0);
        Vector3f e1 = normalize(v2 - v1);
        N = normalize(crossProduct(e0, e1));
        const Vector2f &st0 = stCoordinates[vertexIndex[index * 3]];
        const Vector2f &st1 = stCoordinates[vertexIndex[index * 3 + 1]];
        const Vector2f &st2 = stCoordinates[vertexIndex[index * 3 + 2]];
        st = st0 * (1 - uv.x - uv.y) + st1 * uv.x + st2 * uv.y;
    }

    Vector3f evalDiffuseColor(const Vector2f &st) const override {
        float scale = 5;
        float pattern =
            (fmodf(st.x * scale, 1) > 0.5) ^ (fmodf(st.y * scale, 1) > 0.5);
        return lerp(Vector3f(0.815, 0.235, 0.031),
                    Vector3f(0.937, 0.937, 0.231), pattern);
    }

    std::unique_ptr<Vector3f[]> vertices;
    uint32_t numTriangles;
    std::unique_ptr<uint32_t[]> vertexIndex;
    std::unique_ptr<Vector2f[]> stCoordinates;
};
