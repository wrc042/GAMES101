# Ray Tracing I

## Basic Ray-Tracing Algorithm

- light travels in straight lines
- light rays do not "collide" with each other if they cross
- light rays travels from the light sorces to eyes

- Generate an image by casting one ray per pixel
- Check for shadows by sending a ray to the light

Recursive Ray Tracing

## Ray-Surface Intersection

- intersection
- if point is inside

$r(t)=o+td$  
$(p-p')\cdot N=0$  
$t=\frac{(p'-o)\cdot N}{d\cdot N}$

Möller Trumbore Algorithm - A faster approach, giving barycentric coordinate directly

## Accelerating Ray-Surface Intersection

## Bounding Volumes

AABB Axis-Aligned Bounding Box

- The ray enters the box only when it enters all pairs of slabs
- The ray exits the box as long as it exits any pair of slabs

$t_{enter}=\max(t_{min})$  
$t_{exit}=\min(t_{max})$  
tenter < texit && texit >= 0

box:  
$t=\frac{p_x'-o_x}{d_x}$
