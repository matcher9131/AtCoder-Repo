# Array

## 共通
- 後ろからDPはかなり強力
  - [ABC078 D - ABS](https://atcoder.jp/contests/abc078/tasks/arc085_b)

## 全要素への操作
- 何度か操作を行うとそれ以上変化しなくなる
  - [東京海上日動 プログラミングコンテスト2020 C - Lamps](https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c)
- 最後の1回の操作のみが適用される
  - [ARC135 C - XOR to All](https://atcoder.jp/contests/arc135/tasks/arc135_c)

## 2要素への操作
- 偶数番目の和・奇数番目の和やそれらの差、転倒数やその偶奇などの不変数を見つける
  - 特に隣り合った要素への操作の場合有効
    - [ARC119 C - ARC Wrecker 2](https://atcoder.jp/contests/arc119/tasks/arc119_c) （`偶数番目の和 - 奇数番目の和`が不変）
    - [ARC136 B - Triple Shift](https://atcoder.jp/contests/arc136/tasks/arc136_b) （転倒数の偶奇が不変）
    - [ABC296 F - Simultaneous Swap](https://atcoder.jp/contests/abc296/tasks/abc296_f) （ $A, B$ の転倒数の合計の偶奇が不変）
  - ※配列内に同じ要素があるとき、**転倒数の偶奇はどちらにすることもできる**
    - 略証：同じ要素にラベルを付けて区別すると、操作の後にラベルを付け替える/替えないことで転倒数を偶数にも奇数にもできる
- $A_i + i$ に注目すると交換操作が単純になる
  - [ARC120 C - Swaps 2](https://atcoder.jp/contests/arc120/tasks/arc120_c)
- 具体的なゴールを設定し、到達可能かどうかを判定する
  - [ARC185 B - +1 and -1](https://atcoder.jp/contests/arc185/tasks/arc185_b)
  

## 転倒数
- 座標圧縮→Segment treeで管理しながら
  - [ABC231 F - Jealous Two](https://atcoder.jp/contests/abc231/tasks/abc231_f)

## Segment treeに複雑なデータを持たせる
- `set`, `multiset`, `map`
  - `op`が $O(N \log N)$ になるので大体の場合不可能、よって別々にできないかを検討
    - [ABC170 E - Smart Infants](https://atcoder.jp/contests/abc170/tasks/abc170_e)

## 最小値の最大値、最大値の最小値
- ほぼ二分探索
  - [ZONeエナジー プログラミングコンテスト “HELLO SPACE” (2021) C - MAD TEAM](https://atcoder.jp/contests/zone2021/tasks/zone2021_c)

## 不変な配列への $[L, R)$ クエリ
- $[L, M)$ と $[M, R)$ がマージ不可
  - Mo's algorithm
    - [ABC174 F - Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)

## クエリ順が $1, 2, \dots, N$
- $\mathrm{ans}_i$ から $\mathrm{ans}_{i+1}$ を作る
  - [ABC276 F - Double Chance](https://atcoder.jp/contests/abc276/tasks/abc276_f)
- 前からの累積和と後ろからの累積和を用いる
  - [ABC279 E - Cheating Amidakuji](https://atcoder.jp/contests/abc279/tasks/abc279_e)

## 関数列
- 関数を代表する値のみを見る
  - [ARC155 B - Abs Abs Function](https://atcoder.jp/contests/arc155/tasks/arc155_b)

## $N \leq 40$ でナップサック
- 半分全列挙
  - [ABC184 F - Programming Contest](https://atcoder.jp/contests/abc184/tasks/abc184_f)

## 広義単調増加列に対して大量の「 $i$ 番目を削除」クエリ
- $C_k$ を $A_i = k$ となる $i$ の個数として（`atcoder::segtree`推奨）、 $C$ の累積和で二分探索
  - [ABC392 F - Insert](https://atcoder.jp/contests/abc392/tasks/abc392_f)

## $A_i$ が含まれる区間の数
- imos法
  - [ABC080 D - Recording](https://atcoder.jp/contests/abc080/tasks/abc080_d)

## $\sum_{l \leq i \leq r} A_i$ が $M$ の倍数
- $S_i = (\sum_{k=1}^i A_k) \bmod M$ として $S_i = S_j$ となる $(i, j)$ を見る
  - [ABC105 D - Candy Distribution](https://atcoder.jp/contests/abc105/tasks/abc105_d)

## トポロジカルソート
- トポロジカルソートをしてその順序で見ていく（辺を辿って探索はしない）
  - [ABC245 F - Endless Walk](https://atcoder.jp/contests/abc245/tasks/abc245_f)

## $\sum (A_i \bmod M)$
- $A_i \geq M$ となる $i$ が何個あるかを数えて（ $=C$ ）、 $\sum A_i - CM$
  - [ABC378 E - Mod Sigma Problem](https://atcoder.jp/contests/abc378/tasks/abc378_e)

## $A_i \leq A_j$ かつ $B_i \leq B_j$ となるような $(i, j)$
- $A_i$ の昇順→ $B_i$ の降順でソート
  - すべて数える：転倒数を求める　※ただし $B_i = B_j$ となるパターンは別途対応が必要
  - 同じ $i$ または $j$ を持つものはカウントしない： $B$ のLISを求める
    - [ARC126 B - Cross-free Matching](https://atcoder.jp/contests/arc126/tasks/arc126_b)
    - [ARC133 B - Dividing Subsequence](https://atcoder.jp/contests/arc133/tasks/arc133_b)

## Sum = XOR Sum
- $A_l \oplus A_{l+1} \oplus \dots \oplus A_{r} = A_l + A_{l+1} + \dots + A_r \Leftrightarrow $ 任意の $l \leq i < j \leq r$ に対して $A_i \ \mathrm{AND} \ A_j = 0$
  - [ABC098 D - Xor Sum 2](https://atcoder.jp/contests/abc098/tasks/arc098_b)

## 周期 $M$ の列から更に小さい周期となるものを取り除く
- $M$ の小さい順に求め、 $f(M)$ から $\sum_{m|M} f(m)$ を引く
  - [ABC304 F - Shift Table](https://atcoder.jp/contests/abc304/tasks/abc304_f)

## 遷移がループしそうなDP
- 状態数を増やせばループを回避できることがある
  - [ABC303 D - Shift vs. CapsLock](https://atcoder.jp/contests/abc303/tasks/abc303_d)

## $i$ を固定したときに対象となる $j$ が複数存在する
- $i$ を固定して $j$ の探索、 $j$ を固定して $i$ の探索の双方を行うことにより複数ではなく高々1個にする
  - [ABC302 D - Impartial Gift](https://atcoder.jp/contests/abc302/tasks/abc302_d)

## 区間和を管理したい列で区間を $b$ 倍して $c$ を足す
- `(区間の総和, 区間の長さ)`をモノイドにすればモノイド作用にできて`atcoder::lazy_segtree`に載せられる

```cpp
struct S {
    ll sum;
    int length;
};
S op(S a, S b) {
    return { a.sum + b.sum, a.length + b.length };
}
S e() {
    return {0, 0};
}
struct F {
    ll mul;
    ll add;
};
S mapping(F f, S x) {
    return { f.mul * x.sum + f.add * x.length, x.length };
}
F composition(F f, F g) {
    return { f.mul * g.mul, f.mul * g.add + f.add };
}
F id() {
    return {1, 0};
}
```

- なお $b=0$ とすることで区間に同じ値を代入できる
  - [ABC417 F - Random Gathering](https://atcoder.jp/contests/abc417/tasks/abc417_f)


## 周期性がある列に対して $f([L, R))$ の最大値などを求める
- $L = 1, 2, \dots, N$ に固定する
  - [ABC300 F - More Holidays](https://atcoder.jp/contests/abc300/tasks/abc300_f)


## $M$ で割り切れる場合の数をDPで求めたいが $M$ が変動する
- $M = 1, 2, \dots$ と複数回DPを回す
  - [ABC262 D - I Hate Non-integer Number](https://atcoder.jp/contests/abc262/tasks/abc262_d)
  - [ABC336 E - Digit Sum Divisible](https://atcoder.jp/contests/abc336/tasks/abc336_e)


## DPで数え上げたいが要素数が多すぎる
- そもそも漸化式を一般項で表せる
  - [SoundHound Inc. Programming Contest 2018 -Masters Tournament- C - Ordinary Beauty](https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c)


## $i$ 番目と $i+1$ 番目の間および $N$ 番目と $1$ 番目の間に制約がある
- 「 $i$ 番目と $1$ 番目の間で制約を満たす/満たさない」をDPの要素に付け加える
  - [ABC307 E - Distinct Adjacent](https://atcoder.jp/contests/abc307/tasks/abc307_e)
- $1$ 番目を決め打ちして探索し、 $N$ 番目が条件を満たすかどうかを確認する

## 回数の期待値をDPで
- ${\displaystyle \mathrm{dp}_i = 1 + \sum_j p_j \cdot \mathrm{dp}_j}$
  - ただし $p_j$ は遷移確率
    - [ABC280 E - Critical Hit](https://atcoder.jp/contests/abc280/tasks/abc280_e)

## DPで特定の条件を満たすものの個数を数える
- 条件を満たすものと満たさないものの間で遷移があるかを確かめ、ある場合は両方を同時に数える
  - [ABC418 D - XNOR Operation](https://atcoder.jp/contests/abc418/tasks/abc418_d)

## 連続部分列の個数をDPで数える
- $\mathrm{dp}_{i}$ を $i$ を右端とする連続部分列のうち条件を満たすものの個数とすると重複カウントを無くせるかもしれない
  - [ABC418 D - XNOR Operation](https://atcoder.jp/contests/abc418/tasks/abc418_d)

## すごろくDP
- $\mathrm{dp}_{i,j}:$ $i$ 回振ったときに地点 $j$ にいる確率
- 遷移は出目 $x$ のそれぞれについて $\mathrm{dp}_{i+1,\min \{ N, j+x \}} = p(x) \mathrm{dp}_{i,j}$
  - ただし $p(x)$ は出目 $x$ の出る確率
- $i$ 回目にはじめてゴールする確率は $\mathrm{dp}_{i,N} - \mathrm{dp}_{i-1,N}$
  - [ABC298 E - Unfair Sugoroku](https://atcoder.jp/contests/abc298/tasks/abc298_e)

## $X_i + X_j \geq p, Y_i + Y_j \geq q$ を満たす $(i,j)$ の個数
- $X_i$ の取りうる値が少ないなら $X$ に関しては普通の配列で全探索して、 $Y$ に関してはFenwick treeなどで区間和を得る
  - [AGC047 A - Integer Product](https://atcoder.jp/contests/agc047/tasks/agc047_a)
