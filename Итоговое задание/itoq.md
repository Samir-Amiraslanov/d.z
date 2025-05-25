# Иследование
### Интегральное уравнение
#### 1.Анализ симметрии:
$\int_{-x}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt=\alpha$ так как отрезок от ${[-x;x]}$ является симметричным можно разделить интеграл на 
$\int_{0}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt$ и $\int_{-x}^{0} \frac {\cos(t)}{\sqrt{1-t^2}}dt$.

$\int_{-x}^{0} \frac {\cos(t)}{\sqrt{1-t^2}}dt=-\int_{0}^{-x} \frac {\cos(t)}{\sqrt{1-t^2}}dt=|t=-t'; dt=-dt'|=\int_{0}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt.$ 

Из этого следует что 
$\int_{-x}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt=2\int_{0}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt.$

#### 3.Подстановка: 
Используем подстановку $t=\sin(\varphi)$, где $dt=\cos(\varphi)d\varphi$. 

${\sqrt{1-t^2}}={\sqrt{1-\sin(\varphi)^2}}=\cos(\varphi)$, так как $\varphi$ находится на отрезке $[0,\frac\pi2]$ при $t$ от $0$ до $x$,и $x \geq 0$ и где $\cos(\varphi)\geq 0$

Интеграл преобразуется в:

$\int_{0}^{x} \frac {\cos(t)}{\sqrt{1-t^2}}dt=\int_{0}^{\arcsin(x)} \frac {\cos(\sin(\varphi))}{\cos(\varphi)}\cos(\varphi)d\varphi=\int_{0}^{\arcsin(x)}  {\cos(\sin(\varphi))}d\varphi.$

Так как мы используем подстановку $t=\sin(\varphi)$.При этом:
- $t \in[0,x]$, где $0 \leq x\leq1$
- Следовательно, $\varphi=\arcsin(t)\in[0,\frac\pi2]$
  
Вывод:
$\varphi$ принвдлежит отрезку $[0,\frac\pi2]$, потому что $\arcsin(t)$ для $t\in[0,1]$ всегда лежит в этом интервале.

Тогда:



$2\int_{0}^{1} \frac {\cos(t)}{\sqrt{1-t^2}}dt=2\int_{0}^  {\frac\pi2}  {\cos(\sin(\varphi))}d\varphi=\alpha$ 

