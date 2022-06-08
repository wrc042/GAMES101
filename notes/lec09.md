# Shading III

## Barycentric Coordinates

$(x,y)=\alpha A+\beta B+\gamma C$  
$\alpha+\beta+\gamma=1$

$\alpha=\frac{-(x-x_B)(y_C-y_B)+(y-y_B)(x_C-x_B)}{-(x_A-x_B)(y_C-y_B)+(y_A-y_B)(x_C-x_B)}$  
$\beta=\frac{-(x-x_C)(y_A-y_C)+(y-y_C)(x_A-x_C)}{-(x_B-x_C)(y_A-y_C)+(y_B-y_C)(x_A-x_C)}$  
$\gamma=1-\alpha-\beta$  
(cross product to compute area)

barycentric coordinates are not invariant under projection

## Texture Magnification

Bilinear Interpolation

point query vs. range query

Mipmap - fast approx square

level D=$\log_2 L$  
$L=\max(\sqrt{(\frac{du}{dx})^2+(\frac{dv}{dx})^2},\sqrt{(\frac{du}{dy})^2+(\frac{dv}{dy})^2})$

Trilinear Interpolation

Linear interpolation based on continuous D value

Anisotropic Filtering - Ripmap
