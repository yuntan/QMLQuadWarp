HOW TO COMPUTE HOMOGRAPHY
====

Transform \\(\mathbb{p}=(x,y,1)\\) to \\(\mathbb{P}=(X,Y,1)\\)  
When \\(\mathbb{P'}=(X',Y',W')\\), we want to find a Homography matrix \\(H\\) that satisfy

\\[
\mathbb{P}=\frac{1}{W'}\mathbb{P'}, \mathbb{P'}=H\mathbb{p}
\\]

When \\(H=\begin{pmatrix}\mathbb{h}_1 \\\\ \mathbb{h}_2 \\\\ \mathbb{h}_3\end{pmatrix}\\) ( \\(h\\) is 3-dimentional vector), 

\\[
H\\mathbb{p}=
\begin{pmatrix}
\mathbb{h}_1\mathbb{p} \\\\ \mathbb{h}_2\mathbb{p} \\\\ \mathbb{h}_3\mathbb{p}
\end{pmatrix}
\\]

\\[
\mathbb{P}\times H\mathbb{p}=
\begin{pmatrix}
Y\mathbb{h}_3\mathbb{p}-\mathbb{h}_2\mathbb{p} \\\\
\mathbb{h}_1\mathbb{p}-X\mathbb{h}_3\mathbb{p} \\\\
X\mathbb{h}_2\mathbb{p}-Y\mathbb{h}_1\mathbb{p}
\end{pmatrix}
\\]

\\(\mathbb{P}\times H\mathbb{p}=0\\), then

\\[
\begin{pmatrix}
\mathbb{o} && -\mathbb{p} && Y\mathbb{p} \\\\
\mathbb{p} && \mathbb{o} && -X\mathbb{p} \\\\
-Y\mathbb{p} && X\mathbb{p} && \mathbb{o}
\end{pmatrix}
\begin{pmatrix}
\mathbb{h}_1 \\\\ \mathbb{h}_2 \\\\ \mathbb{h}_3
\end{pmatrix}
=\mathbb{o}
\\]

When see it as \\(A\mathbb{h}=\mathbb{o}\\), \\(A\\) is 3x9 matrix, and \\(h\\) is 9-dimentional vector.  
We can find three equation, but one can be figured out from others, so we have to fulfill only two equations.

\\[
\begin{pmatrix}
\mathbb{o} && -\mathbb{p} && Y\mathbb{p} \\\\
\mathbb{p} && \mathbb{o} && -X\mathbb{p}
\end{pmatrix}
\begin{pmatrix}
\mathbb{h}_1 \\\\ \mathbb{h}_2 \\\\ \mathbb{h}_3
\end{pmatrix}
=\mathbb{o}
\\]

Show components.

\\[
\begin{pmatrix}
0 && 0 && 0 && x && y && 1 && -xY && -yY && -Y \\\\
x && y && 1 && 0 && 0 && 0 && -xX && -yX && -X
\end{pmatrix}
\begin{pmatrix}
h_{11} \\\\ h_{12} \\\\ h_{13} \\\\ h_{21} \\\\ h_{22} \\\\ h_{23} \\\\ h_{31} \\\\ h_{32} \\\\ h_{33}
\end{pmatrix}
=
\begin{pmatrix}
0 \\\\ 0
\end{pmatrix}
\\]

Multiplying homography matrix isn't have deep meaning, so make \\(h_{33}=1\\) and we want to figure out 8 parameters.
Use 4 point correspondence and solve below.

\\[
\begin{pmatrix}
0 && 0 && 0 && x_1 && y_1 && 1 && -x_1Y_1 && -y_1Y_1 && -Y_1 \\\\
x_1 && y_1 && 1 && 0 && 0 && 0 && -x_1X_1 && -y_1X_1 && -X_1 \\\\
0 && 0 && 0 && x_2 && y_2 && 2 && -x_2Y_2 && -y_2Y_2 && -Y_2 \\\\
x_2 && y_2 && 2 && 0 && 0 && 0 && -x_2X_2 && -y_2X_2 && -X_2 \\\\
0 && 0 && 0 && x_3 && y_3 && 3 && -x_3Y_3 && -y_3Y_3 && -Y_3 \\\\
x_3 && y_3 && 3 && 0 && 0 && 0 && -x_3X_3 && -y_3X_3 && -X_3 \\\\
0 && 0 && 0 && x_4 && y_4 && 4 && -x_4Y_4 && -y_4Y_4 && -Y_4 \\\\
x_4 && y_4 && 4 && 0 && 0 && 0 && -x_4X_4 && -y_4X_4 && -X_4
\end{pmatrix}
\begin{pmatrix}
h_{11} \\\\ h_{12} \\\\ h_{13} \\\\ h_{21} \\\\ h_{22} \\\\ h_{23} \\\\ h_{31} \\\\ h_{32} \\\\ 1
\end{pmatrix}
=\mathbb{o}
\\]

\\[
\begin{pmatrix}
x_1 && y_1 && 1 && 0 && 0 && 0 && -x_1X_1 && -y_1X_1 \\\\
0 && 0 && 0 && x_1 && y_1 && 1 && -x_1Y_1 && -y_1Y_1 \\\\
x_2 && y_2 && 2 && 0 && 0 && 0 && -x_2X_2 && -y_2X_2 \\\\
0 && 0 && 0 && x_2 && y_2 && 2 && -x_2Y_2 && -y_2Y_2 \\\\
x_3 && y_3 && 3 && 0 && 0 && 0 && -x_3X_3 && -y_3X_3 \\\\
0 && 0 && 0 && x_3 && y_3 && 3 && -x_3Y_3 && -y_3Y_3 \\\\
x_4 && y_4 && 4 && 0 && 0 && 0 && -x_4X_4 && -y_4X_4 \\\\
0 && 0 && 0 && x_4 && y_4 && 4 && -x_4Y_4 && -y_4Y_4
\end{pmatrix}
\begin{pmatrix}
h_{11} \\\\ h_{12} \\\\ h_{13} \\\\ h_{21} \\\\ h_{22} \\\\ h_{23} \\\\ h_{31} \\\\ h_{32}
\end{pmatrix}
=
\begin{pmatrix}
X_1 \\\\ Y_1 \\\\ X_2 \\\\ Y_2 \\\\ X_3 \\\\ Y_3 \\\\ X_4 \\\\ Y_4
\end{pmatrix}
\\]

\\[
\begin{pmatrix}
h_{11} \\\\ h_{12} \\\\ h_{13} \\\\ h_{21} \\\\ h_{22} \\\\ h_{23} \\\\ h_{31} \\\\ h_{32}
\end{pmatrix}
=
\begin{pmatrix}
x_1 && y_1 && 1 && 0 && 0 && 0 && -x_1X_1 && -y_1X_1 \\\\
0 && 0 && 0 && x_1 && y_1 && 1 && -x_1Y_1 && -y_1Y_1 \\\\
x_2 && y_2 && 2 && 0 && 0 && 0 && -x_2X_2 && -y_2X_2 \\\\
0 && 0 && 0 && x_2 && y_2 && 2 && -x_2Y_2 && -y_2Y_2 \\\\
x_3 && y_3 && 3 && 0 && 0 && 0 && -x_3X_3 && -y_3X_3 \\\\
0 && 0 && 0 && x_3 && y_3 && 3 && -x_3Y_3 && -y_3Y_3 \\\\
x_4 && y_4 && 4 && 0 && 0 && 0 && -x_4X_4 && -y_4X_4 \\\\
0 && 0 && 0 && x_4 && y_4 && 4 && -x_4Y_4 && -y_4Y_4
\end{pmatrix}^{-1}
\begin{pmatrix}
X_1 \\\\ Y_1 \\\\ X_2 \\\\ Y_2 \\\\ X_3 \\\\ Y_3 \\\\ X_4 \\\\ Y_4
\end{pmatrix}
\\]


## References ##
* [ホモグラフィ - Shogo Computing Laboratory](http://shogo82148.github.io/homepage/memo/geometry/homography/)
* [CSS3 Transform 3D Test](http://jsdo.it/shogo82148/vdlv)
* [射影変換(ホモグラフィ)について理解してみる](http://yaju3d.hatenablog.jp/entry/2013/08/04/152524)
* [テクスチャマッピング入門 射影変換(ホモグラフィ)](http://jsdo.it/yaju3D/zUk5)
* [How to compute a homography](http://www.cse.iitd.ac.in/~suban/vision/geometry/node24.html)
* [ホモグラフィの計算](http://tessy.org/wiki/index.php?%A5%DB%A5%E2%A5%B0%A5%E9%A5%D5%A5%A3%A4%CE%B7%D7%BB%BB)
