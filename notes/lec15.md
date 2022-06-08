# Ray Tracing III

## Radiometry cont

Definition: The irradiance is the power per unit area incident on a surface point.

$E(x)=\frac{d\Phi(x)}{dA}[W/m^2][lm/m^2=lux]$

Definition: The radiance (luminance) is the power emitted, reflected, transmitted or received by a surface, per unit solid angle, per projected unit area.

$L(p,\omega)=\frac{d^2\Phi(p,\omega)}{d\omega dA\cos\theta}$

- Irradiance: power per projected unit area
- Intensity: power per solid angle
- Radiance: Irradiance per solid angle
- Radiance: Intensity per projected unit area

$dE(p,\omega)=L_i(p,\omega)\cos\theta d\omega_i$

## BRDF(Bidirectional Reflectance Distribution Function)

$dE(\omega_i)=L(\omega_i)cos\theta_id\omega_i$  
$f(\omega_i\to\omega_r)=\frac{dL_r(\omega_r)}{dE_i(\omega_i)}=\frac{dL_r(\omega_r)}{L_i(p,\omega)\cos\theta d\omega_i}$  
$L_r(p,\omega_r)=\int_{H^2}f_r(p,\omega\to\omega_r)L_i(p,\omega_i)cos\theta_id\omega_i$

the rendering equation

$L_o(p,\omega_o)=L_e(p,\omega_o)+\int_{\Omega^+}L_i(p,\Omega_i)f_r(p,\omega_i,\omega_o)(n\cdot\omega_i)d\omega_i$

$I(u)=e(u)+\int I(v)K(u,v)dv$  
$L=E+KL$  
$L=(I-K)^{-1}E=(I+K+K^2+\dots)E=E+KE+K^2E+\dots$

- E: Emission directly from light sources
- KE: Direct illumination on surface

## Probability Review

$E[X]=\int xp(x)dx$  
$E[Y]=E[f(x)]=\int f(x)p(x)dx$
