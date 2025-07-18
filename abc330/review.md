# [ABC330](https://atcoder.jp/contests/abc330) Review
- バーチャル参加
- Eまでを30分ちょっとでこなし850位相当
  - 2300位くらいまでEを解いているのでスピード勝負だったようだ
  - Cに一番時間がかかっているという謎現象

## D - Counting Ls
- AC（10分）
- 行 $i$ にある`o`の数を $R_i$ 、列 $j$ にある`o`の数を $C_j$ とおくと
  - マス $(i,j)$ の解への寄与は $(R_i-1)(C_j-1)$
- よって計算量 $O(N^2)$ で求まる

## E - Mex and Update
- AC（6分）
- $A_i = k$ となる要素数 $C_k$ を管理することで、 $C_k > 0$ となる最小の非負整数 $k$ をmexとすることができる
  - $N$ 要素のmexが $N$ より大きくなることはないので、 $C$ の要素数は $N$ でOK、かつ $A_i \geq N$ となる場合は無視できる
- [ABC272E](https://atcoder.jp/contests/abc272/tasks/abc272_e)でこれより難しいmexの問題をやったところだったのですぐに処理できた

## F - Minimize Bounding Square
- 時間切れ
- 参考：[slope trick (1) 解説編 | maspyのHP](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
- Slope trickを使えば機械的に処理できる
  - $f(x) = a + \sum_{l \in L} \max \{ 0, l - x \} + \sum_{r \in R} \max \{ 0, x - r \}$ と表せるならばSlope trickが使える
- 計算量は $X_i, Y_i$ の最大値を $M$ として $O(N \log N \log M)$
