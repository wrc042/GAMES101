# Geometry II

## Explicit Representations

- Point Cloud
- Polygon Mesh
  - .obj: vertices, normals, texture coordinates and their connectivities

## Bezier Curves

de Casteljau Algorithm

multiple interpolations

Algebrabic Formula:

$b^n(t)=\sum b_jB_j^n(t)$  
$B_j^n(t)=C_n^it^i(1-t)^{n-i}$

property:

- Affine transformation property
- Convex hull property

Piecewise cubic Bézier is the most common technique

C0 and C1 continuity

other types of spline: B-splines

## Surfaces

Bicubic Bezier Surface Patch

(u,v) to point
