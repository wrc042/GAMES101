# Animation cont

## Single Particle Simulation

Euler's Method

$x^{t+\Delta t}=x^t+\Delta t\dot{x}^t$  
$\dot{x}^{t+\Delta t}=\dot{x}^t+\Delta t\ddot{x}^t$

simple iterative method  
unstable

- inaccuracies increase as time step increase

## Combating Instability

Midpoint Method

$x_{mid}=x(t)+\Delta t/2\cdot v(x(t),t)$  
$x(t+\Delta t)=x(t)+\Delta t\cdot v(x_{mid},t)$

(Modified Euler

Runge-Kutta Families: RK4

Position-based/Verlet Integration

## Fluid Simulation

- Assuming water is composed of small rigid-body spheres
- Assuming the water cannot be compressed (i.e. const. density)
- So, as long as the density changes somewhere, it should be “corrected” via changing the positions of particles

Material Point Method(MPM)

- Lagrangian: consider particles carrying material properties
- Eulerian: use a grid to do numerical integration
