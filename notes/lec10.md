# Geometry I

## Application of Textures

- Environment lighting
- Store microgeometry
- Procedural textures
- Solid modeling
- Volume rendering

Cube Map

Bump Mapping  
n = (-dp/du, -dp/dv, 1).normalized()

Displacement mapping

## Representation of Geometry

- implicit surface: hard sampling; easy inside/outside test
- explicit surface: easy sampling; hard inside/outside test

## Implicit representations

implicit representation is more in CG

- Constructive Solid Geometry - CSG
- Distance Function - SDF
- Level Set Methods

implicit:

- pros
  - compact description
  - certain queries easy
  - good for ray-to-surface intersection
  - exact description
  - easy to handle changes in topology
- cons
  - difficult to model complex shapes
