# Geometry III

## Subdivision

### Loop Subdivision

new vertex: 3/8*(A+B)+1/8*(C+D)  
old vertex: $(1-n*u)*original+u*neighbor\_sum$  
n: vertex degree  
u: 3/16 if n=3 else 3/(8n)

### Catmull-Clark Subdivision - General Mesh

$f=\frac{v_1+v_2+v_3+v_4}{4}$  
$e=\frac{f_1+f_2+v_1+v_2}{4}$  
$v=\frac{f_1+f_2+f_3+f_4+2(m_1+m_2+m_3+m_4)+4p}{16}$

Convergence - Overall Shape and Creases

## Simplification

edge collapsing

(Garland & Heckbert 1997)

Quadric Error Metrics - Minimize l2 loss

Quadric Error of Edge Collapse

Better idea: choose point that minimizes quadric error

Assign score with quadric error metric:

- approximate distance to surface as sum of distances to planes containing triangles
- iteratively collapse edge with smallest score
- greedy algorithm

## Shadow Mapping

An image-space algorithm

no knowledge of scene geometry

the point is seen by both camera and light

- depth imgae from light
- standard depth from eyes

- hard shadows
- quality depends on shadow map resolution
- precision problem
