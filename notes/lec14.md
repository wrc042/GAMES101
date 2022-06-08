# Ray Tracing II

## Uniform Spatical Partitions(Grids)

Grids work well on large collections of objects that are distributed evenly in size and space

## Spatial Partition

KD-Tree

## Object Partitions & Bounding Volume Hierachy(BVH)

- choose a dimention to split
- always choose the longest axis
- at location of median object

```python
Intersection(ray, node):
    if ray misses node bbox:
        return
    if node is a leaf node:
        test intersection with all objs
        return closest intersection
    
    return closest of Intersection(ray, node.child)
```

Spatial partition

- Partition space into non-overlapping regions
- An object can be contained in multiple regions

Object partition(better)

- Partition set of objects into disjoint subsets
- Bounding boxes for each set may overlap in space

## Basic radiometry

## Radiant Energy and Flux(Power)

Definition: Radiant energy is the energy of electromagnetic radiation.  
Definition: Radiant flux (power) is the energy emitted, reflected, transmitted or received, per unit time.

$\Phi=\frac{dQ}{dt}[W=Watt][lm=lumen]$

- light emmitted from a source - radiant intensity
- light falling on a surface - irradiance
- light traveling along a ray - radiance

Definition: The radiant (luminous) intensity is the power per unit
solid angle (?) emitted by a point light source.

$I(\omega)=\frac{d\Phi}{d\omega}[\frac{lm}{sr}=cd=candela]$  
$\Omega=\frac{A}{r^2}$  
$dA=r^2\sin\theta d\theta d\phi$  
$d\omega=\sin\theta d\theta d\phi$  
