# Ray Tracing IV

## MonteCarlo Integration

Monte Carlo estimator:  
$F_N=\frac{1}{N}\sum\frac{f(X_i)}{p(X_i)}\ X_i-p(x)$

## Path Tracing

Whitted-style ray tracing:

- Always perform specular reflections
- Stop bouncing at diffuse surface

$L_o(p,\omega)\approx\sum\frac{L_i(p,\omega_i)f_r(p,\omega_i,\omega_o)(n\cdot\omega_i)}{p(\omega_i)}$  
pdf $p(w_i)=1/2\pi$

```python
shade(p, wo):
    radomly choose N diractions wi-pdf
    Lo = 0.
    for each wi:
        trace a ray r(p, wi)
        if r hit the light:
            Lo += (1 / N) * Li * Fr * cosine / pdf(wi)
        else if r hit an obj at q:
            Lo += (1 / N) * shade(q, -wi) * Fr * cosine / pdf(wi)
```

path tracing: N = 1

sample from pixels

Russian Roulette: shading result divided by P: $L_o/P$

path tracing: correct but not efficient

sampling the light

$d\omega=\frac{dA\cos\theta'}{||x'-x||^2}$

$L_o=\int L_if_r\frac{dA\cos\theta'}{||x'-x||^2}$

pdf: 1/A

```python
shade(p, wo):
    # Contribution from the light source.
    Uniformly sample the light at x’ (pdf_light = 1 / A)
    L_dir = L_i * f_r * cos θ * cos θ’ / |x’ - p|^2 / pdf_light 
    # Contribution from other reflectors.
    L_indir = 0.0
    Test Russian Roulette with probability P_RR
    Uniformly sample the hemisphere toward wi (pdf_hemi = 1 / 2pi)
    Trace a ray r(p, wi)
    If ray r hit a non-emitting object at q
        L_indir = shade(q, -wi) * f_r * cos θ / pdf_hemi / P_RR
    Return L_dir + L_indir
```

modern: The general solution of light transport

- (Unidirectional & bidirectional) path tracing
- Photon mapping
- Metropolis light transport
- VCM / UPBP

tricks

- sampling the hemisphere
- pdfs choices
- random numbers
