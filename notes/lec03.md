# Transform

## Homogenous Coordinates

2D point = $(x,y,1)^T$
2D vector = $(x,y,0)^T$

scale

$\begin{pmatrix}
    s_x & 0 & 0 \\
    0 & s_y & 0 \\
    0 & 0 & 1
\end{pmatrix}$

rotation

$\begin{pmatrix}
    \cos\alpha & -\sin\alpha & 0 \\
    \sin\alpha & \cos\alpha & 0 \\
    0 & 0 & 1
\end{pmatrix}$

translation

$\begin{pmatrix}
    1 & 0 & t_x \\
    0 & 1 & t_y \\
    0 & 0 & 1
\end{pmatrix}$
