# 补充

## Bresenham's line drawing algorithm

$(x_0,y_0)$到$(x_1,y_1)$

- 斜率$|m|<1$
- 从$x_0$开始 每次对x增加1
- 下一个像素点只能为$(x_i+1,y_i)$和$(x_i+1,y_i+1)$

$x_{i+1}=x_i+1$

$y_{i+1}=m(x_i+1)+B$

$d_{up}=\bar{y_i}+1-y_{i+1}$

$d_{low}=y_{i+1}-\bar{y_i}$

$\Delta d=2y_{i+1}-2\bar{y_i}-1=2m(x_i+1)-2\bar{y_i}+2B-1$

$p_i=2\Delta y\cdot x_i-2\Delta x\cdot\bar{y_i}+(2B-1)\Delta x+2\Delta y$

$c=(2B-1)\Delta x+2\Delta y$

递归

$p_0=2\Delta y-\Delta x$

$p_{i+1}-p_i=2\Delta y-2\Delta x(\bar{y}_{i+1}-\bar{y_i})$

$p_i<0$选下一点$p_{i+1}=p_i+2\Delta y$

$p_i>0$选上一点$p_{i+1}=p_i+2\Delta y-2\Delta x$
