# 3D and Viewing Transformation

## 3D Transformation

scale

$\begin{pmatrix}
    s_x & 0 & 0 & 0\\
    0 & s_y & 0 & 0\\
    0 & 0 & s_z & 0\\
    0 & 0 & 0 & 1
\end{pmatrix}$

translation

$\begin{pmatrix}
    1 & 0 & 0 & t_x \\
    0 & 1 & 0 & t_y \\
    0 & 0 & 1 & t_z \\
    0 & 0 & 0 & 1
\end{pmatrix}$

rotation

$R_x=\begin{pmatrix}
    1 & 0 & 0 & 0\\
    0 & \cos\alpha & -\sin\alpha & 0 \\
    0 & \sin\alpha & \cos\alpha & 0 \\
    0 & 0 & 0 & 1
\end{pmatrix}$

$R_y=\begin{pmatrix}
    \cos\alpha & 0 & \sin\alpha & 0 \\
    0 & 1 & 0 & 0\\
    -\sin\alpha & 0 & \cos\alpha & 0 \\
    0 & 0 & 0 & 1
\end{pmatrix}$

$R_z=\begin{pmatrix}
    \cos\alpha & -\sin\alpha & 0 & 0 \\
    \sin\alpha & \cos\alpha & 0 & 0 \\
    0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 1
\end{pmatrix}$

Euler angles $R_{xyz}(\alpha,\beta,\gamma)=R_x(\alpha)R_y(\beta)R_z(\gamma)$

### Rodrigues’ Rotation Formula

$R(\bf{n},\alpha)=\cos(\alpha)\bf{I}+(1-\cos(\alpha))\bf{nn}^T+\sin(\alpha)\begin{pmatrix}
    0 & -n_z & n_y \\
    n_z & 0 & -n_x \\
    -n_y & n_x & 0 \\
\end{pmatrix}$

## Viewing Transformation

### View/Camera Transformation

camera:

position $\vec{e}$  
direction $\vec{g}$  
up-direction $\vec{t}$

translation + rotation

### Projection Transformation

MVP

model view projection

### Orthographic Projection

to $[-1,1]^2$

translation + scale

$M_{oetho}=\begin{pmatrix}
    \frac{2}{r-l} & 0 & 0 & 0 \\
    0 & \frac{2}{t-b} & 0 & 0 \\
    0 & 0 & \frac{2}{n-f} & 0 \\
    0 & 0 & 0 & 1
\end{pmatrix}
\begin{pmatrix}
    1 & 0 & 0 & -\frac{r+l}{2} \\
    0 & 1 & 0 & -\frac{t+b}{2} \\
    0 & 0 & 1 & -\frac{n+f}{2} \\
    0 & 0 & 0 & 1
\end{pmatrix}
$

- Looking at / along -Z is making near and far not intuitive(right hand)

### Perspective Projection

$M_{persp\to ortho}=\begin{pmatrix}
    n & 0 & 0 & 0 \\
    0 & n & 0 & 0 \\
    0 & 0 & n+f & -nf \\
    0 & 0 & 1 & 0 \\
\end{pmatrix}$

$M_{persp}=M_{ortho}M_{persp\to ortho}$

field-of-view(fovY) is the angle  
aspect ratio=width/height

$\tan\frac{fovY}{2}=t/|n|$  
$aspect=r/t$

$M_{viewport}=\begin{pmatrix}
    width/2 & 0 & 0 & width/2 \\
    0 & height/2 & 0 & height/2 \\
    0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 1 \\
\end{pmatrix}$
