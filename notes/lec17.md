# Materials and Appearances

## Material == BRDF

lightint is uniform:

$L_0(\omega_0)=\pi f_rL_i$

perfect specular reflection BRDF:

$\omega_o+\omega_i=2\cos\theta\vec{n}$

law of refraction

$\eta_i\sin\theta_i=\eta_t\sin\theta_t$

fresnel term: S and P polarization

## Microfacet Material

- Macroscale: flat & rough
- Microscale: bumpy & specular

$f(i,o)=\frac{F(i,h)G(i,o,h)D(h)}{4(n,i)(n,o)}$

fresnel term + shadowing-mask term + distribution of normals

Isotropic/Anisotropic: $f(\theta_i,\theta_r,\phi_i,\phi_r)!=f(\theta_i,\theta_r,|\phi_i-\phi_r|)$

Reflection depends on azimuthal angle

## Measuring BRDF

MERL BRDF Database
