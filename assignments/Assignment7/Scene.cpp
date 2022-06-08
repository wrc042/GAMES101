//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"

void Scene::buildBVH() {
    printf(" - Generating BVH...\n\n");
    this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}

Intersection Scene::intersect(const Ray &ray) const {
    return this->bvh->Intersect(ray);
}

void Scene::sampleLight(Intersection &pos, float &pdf) const {
    float emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()) {
            emit_area_sum += objects[k]->getArea();
        }
    }
    float p = get_random_float() * emit_area_sum;
    emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()) {
            emit_area_sum += objects[k]->getArea();
            if (p <= emit_area_sum) {
                objects[k]->Sample(pos, pdf);
                break;
            }
        }
    }
}

bool Scene::trace(const Ray &ray, const std::vector<Object *> &objects,
                  float &tNear, uint32_t &index, Object **hitObject) {
    *hitObject = nullptr;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        float tNearK = kInfinity;
        uint32_t indexK;
        Vector2f uvK;
        if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
            *hitObject = objects[k];
            tNear = tNearK;
            index = indexK;
        }
    }

    return (*hitObject != nullptr);
}

// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray &ray, int depth) const {
    // TO DO Implement Path Tracing Algorithm here
    Vector3f L(0, 0, 0);
    Intersection p = Scene::intersect(ray);
    if (!p.happened)
        return L;

    if (p.obj->hasEmit())
        if (depth == 0)
            // return Vector3f(1, 1, 1);
            return p.m->getEmission();
        else
            return Vector3f(0, 0, 0);

    Intersection p_light;
    float pdf_light;
    sampleLight(p_light, pdf_light);
    Ray ray_direct(p.coords, (p_light.coords - p.coords).normalized());
    Intersection p_test = intersect(ray_direct);
    float r = (p_light.coords - p.coords).norm();
    if (abs(p_test.distance - r) < 1e-6) {
        L += p_light.emit *
             p.m->eval(ray.direction, ray_direct.direction, p.normal) *
             dotProduct(ray_direct.direction, p.normal) *
             dotProduct(-ray_direct.direction, p_light.normal) / (r * r) /
             pdf_light;
    }
    if (get_random_float() < RussianRoulette) {
        Vector3f wi = p.m->sample(ray.direction, p.normal);
        Ray ray_new(p.coords, wi);
        float pdf = p.m->pdf(ray.direction, wi, p.normal);
        L += castRay(ray_new, depth + 1) *
             p.m->eval(ray.direction, wi, p.normal) * dotProduct(wi, p.normal) /
             pdf / RussianRoulette;
    }
    return L;
}