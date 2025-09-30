# [あさかつ9/25](https://kenkoooo.com/atcoder/#/contest/show/5ba934f7-cce7-49bd-9a13-5472d17cad6f) Review

## 第4問 - Multiply and Rotate
- AC（7分）
- どちらの操作でも $x$ の桁数が減ることはないので、 $x$ が $N$ の桁数より多くなった状態からどれだけ操作しても $x=N$ となることはない
- よって $N < 10^6$ より $x < 10^6$ の範囲でBFSで操作を繰り返し行えばOK
- 計算量は $O(N \log N)$

## 第5問 - Fruit Lineup
- AC（9分）
- まずリンゴ、バナナ、ブドウを1列に並べる
  - ブドウより左に来るバナナの個数を $i$ とすると、この場合の数は $\begin{pmatrix} C + D - 1 - i \\ D - 1 \end{pmatrix}$ 通り
- その状態でオレンジを挿入する
  - 挿入できる箇所は最も左にあるブドウより左の $A + i + 1$ 箇所なので、この場合の数は $\begin{pmatrix} A + i + B \\ B \end{pmatrix}$ 通り
- あとは↑の積を $0 \leq i \leq C$ の範囲で足し合わせるだけ

## 第6問 - Double Sum 2
- 時間切れ
- 公式解説と似たようなことをしていたが細部を詰めきれなかった
  - もう少し式ベースで考えないとダメか
