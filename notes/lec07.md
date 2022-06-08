# Shading I

## Occlusion - Z-buffering

- frame buffering
- depth buffering

```python
for T in trangles:
    for x, y, z in T:
        if z < zbuffer[x, y]
            framebuffer[x, y] = rgb
            zbuffer[x, y] = z
```

O(n) for n triangles

## Blinn-Phong Reflectance Rodel

- specular highlights
- diffuse reflection
- ambient lighting

shading independent of view direction

Lambert's cosine law

$L_d=k_d(I/r^2)max(0,n\cdot l)$
