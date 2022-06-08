# Shading II

## Blinn-Phong Reflectance Rodel

specular term

intensity depends on view direction

$h=\text{bisector}(v,l)=\frac{v+l}{||v+l||}$

$L_s=k_s(I/r^2)max(0,n\cdot h)^p$

ambient term

shading that does not depend on anything  
(approximate/fake)

$L_a=k_aI_a$

## Shading Frequencies

- shade each triangles(flat shading)
- shade each vertex(Gouraud shading)
- shade each pixel(Phong shading)

defining per-vertex norm vectors: $N_v=\frac{\sum_iN_i}{||\sum_iN_i||}$

defining per-pixel norm vectors: Barycentric interpolation

## Graphic(Real-time Rendering) Pipeline

Vertex Processing- Triangle Processing- Rasterization- Fragment Processing- Framebuffer Operations
