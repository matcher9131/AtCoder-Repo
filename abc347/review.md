# [ABC347](https://atcoder.jp/contests/abc347) Review
- バーチャル参加
- `WA`の嵐
  - 25分を余分に費やしたがなんとか1150位相当でとどまった
- というかDまで全ていつもよりちょいムズなんだが……

## C - Ideal Holidays
- AC（15分+1WA）
- $D_i \bmod (A+B)$ からなる数列を $D'$ として、その最小値と最大値の差が $A$ 未満になればいいというガバ実装で`WA`
  - $A=2, B=3, D=(4,5)$ は題意を満たすが $D' = (4, 0)$ となってしまう
- 正しくは上記または以下を満たすときが`Yes`になる
  - $D'$ を昇順にソートして、任意の $1 \leq i < N$ に対して $D'_{i+1} - D'_i < B$ が成り立つ

## D - Popcount and XOR
- AC（28分+2WA）
- $c = \mathrm{popcount}(C)$ とする
- $c > a+b$ のときは明らかに不可能
- $X, Y$ の双方でビットが立っている桁数を $z$ とおくと、 $\mathrm{popcount}(X \oplus Y) = a + b - 2z$
  - よって $c$ と $a+b$ の偶奇が一致しないときは不可能
- $a+b>60$ のとき、 $z \geq a+b-60$ が成り立つため $\mathrm{popcount}(X \oplus Y) \leq a + b - 2(a+b-60) = 120 - a - b$
  - よって $c > 120 - a - b$ のときも不可能
- それ以外のときは以下の手順で $X, Y$ をつくる
    1. $C$ で下位からビットが立っている $a - z$ 桁を $X$ にコピー
    2. $C$ で上位からビットが立っている $b - z$ 桁を $Y$ にコピー
    3. $C$ でビットが立っていない桁のうち $z$ 桁において、 $X, Y$ の双方にビットを立てる
- 十分条件を満たせていなかったようで`WA`を2度ほど出したが、以下の対策を施して通した
  - 上記手順1. 2. で桁数が足りなかった場合は不可能扱いにする
  - 上記手順2. 終了時に $X \oplus Y \neq C$ なら不可能扱いにする
  - 上記手順3. で桁数が足りなかった場合は不可能扱いにする
- （公式解説） $a, b, c$ って三角不等式成り立つのか……あとヘロンの公式みたい（高校生並みの感想）

## E - Set Add Query
- AC（20分+2WA）
- $i$ 番目のクエリ終了時の $|S|$ を $T_i$ とおくと、以下の手順で $A$ が求まる
  - $i = 1, 2, \dots, Q$ の順に以下を行う
    - $x_i \notin S$ のとき、 $L_{x_i} = i$ として $i$ 番目のクエリが $x_i$ だったことを記録しておく
    - $x_i \in S$ のとき、 $A_{x_i}$ に $\sum_{j=L_{x_i}}^{i} T_j$ を加える
  - すべてのクエリ終了後に $\forall x \in S$ について、 $A_x$ に $\sum_{j=L_{x}}^{Q} T_j$ を加える
- 区間和をFenwick treeに任せることで計算量は $O((N + Q)\log Q)$
- `long long`ではなく`int`にしてしまった箇所が複数ありそれぞれで`WA`を食らう
  - 迂闊にもほどがある……
