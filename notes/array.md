# Array

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
    - [ABC293 G - Triple Index](https://atcoder.jp/contests/abc293/tasks/abc293_g)

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


## $i$ 番目と $i+1$ 番目の間および $N$ 番目と $1$ 番目の間に制約がある
- 「 $i$ 番目と $1$ 番目の間で制約を満たす/満たさない」をDPの要素に付け加える
  - [ABC307 E - Distinct Adjacent](https://atcoder.jp/contests/abc307/tasks/abc307_e)
- $1$ 番目を決め打ちして探索し、 $N$ 番目が条件を満たすかどうかを確認する

## $X_i + X_j \geq p, Y_i + Y_j \geq q$ を満たす $(i,j)$ の個数
- $X_i$ の取りうる値が少ないなら $X$ に関しては普通の配列で全探索して、 $Y$ に関してはFenwick treeなどで区間和を得る
  - [AGC047 A - Integer Product](https://atcoder.jp/contests/agc047/tasks/agc047_a)

## 対称性のあるものを全て列挙する
- 一つの文字について条件を満たすものをすべて挙げ、それぞれについて文字をローテーションしたものを用意する
  - [ARC127 B - Ternary Strings](https://atcoder.jp/contests/arc127/tasks/arc127_b)

## $A_l + A_{l+1} + \dots + A_r$ が与えられる
- $S_r - S_{l-1}$ が与えられているのに等しい
  - [ABC238 E - Range Sums](https://atcoder.jp/contests/abc238/tasks/abc238_e)

## 値によりペアを貪欲に作る
- `lower_bound`による検索は同じ値になるペアを複数組む際にうまく行かない（使用済みのものを何度も検索してしまう）
  - `map`で個数を保持すればOK（個数が0になった要素は直ちに`erase`する）
    - [AGC029 B - Powers of two](https://atcoder.jp/contests/agc029/tasks/agc029_b)

## 連結リストっぽい操作がしたい
- `next[i]`を管理することで以下が行える
  - $O(1)$ ランダムアクセス
  - `next`を直に繋ぎ変える（複数削除を一括で行う）
    - [ABC421 F - Erase between X and Y](https://atcoder.jp/contests/abc421/tasks/abc421_f)

## 片方向連結リストで $x$ から $y$ へ辿りたいがどちらが先にあるのかわからない
- $x$ からの走査と $y$ からの走査を交互に行う
  - [ABC421 F - Erase between X and Y](https://atcoder.jp/contests/abc421/tasks/abc421_f)

## $K$ 種類の要素に対してそれぞれ空間 $O(N)$ が必要でそのままやるわけにはいかないが、使用する要素数の合計が $N$ に収まる
- 空間 $O(N)$ のみを使い回す
  - [ABC261 F - Sorting Color Balls](https://atcoder.jp/contests/abc261/tasks/abc261_f)
    - 色ごとに転倒数を数える必要があるが、要素の合計数が $N$ なので転倒数を数え終わるごとに各要素に`fw.add(x, -1)`しても $O(N \log N)$ で抑えられる

## 制約条件が2つあるマッチング（それぞれの $i$ に対し $A_i \leq C_j$ かつ $B_i \leq D_j$ を満たすような $j$ をマッチさせる）
- 降順にソートして順に見ていくことで $A_i \leq C_i$ を必ず満たすようにしておいて、 $B_i \leq D_j$ となる最小の $D_j$ を持つ $j$ をマッチさせる
  - [ABC245 E - Wrapping Chocolate](https://atcoder.jp/contests/abc245/tasks/abc245_e)

## 左端から順に連続部分列の和が $K$ を超えないように分ける
- `r = upper_bound(s.begin(), s.end(), s[l] + k) - s.begin() - 1` ※半開区間
  - [ABC159 E - Dividing Chocolate](https://atcoder.jp/contests/abc159/tasks/abc159_e)

## 二分探索で非整数を求める
- 二分探索を適当な回数で打ち切る（100回くらい？）
  - [ABC294 F - Sugar Water 2](https://atcoder.jp/contests/abc294/tasks/abc294_f)

## 2つのランレングス符号をデコードして一致する箇所を探す

```cpp
vector<ll> v1(n1), l1(n1);
vector<ll> v2(n2), l2(n2);

vector<ll> sumL1(n1);
sumL1[0] = l1[0];
for (ll i = 1; i < n1; ++i) {
    sumL1[i] = sumL1[i-1] + l1[i];
}
vector<ll> sumL2(n2);
sumL2[0] = l2[0];
for (ll i = 1; i < n2; ++i) {
    sumL2[i] = sumL2[i-1] + l2[i];
}

ll ans = 0;
ll i = 0, j = 0, k = 0;
while (i < w) {
    ll ni = sumL1[j] > sumL2[k] ? sumL2[k] : sumL1[j];
    if (v1[j] == v2[k]) ans += ni - i;
    i = ni;
    if (sumL1[j] > sumL2[k]) ++k;
    else if (sumL1[j] < sumL2[k]) ++j;
    else {
        ++j;
        ++k;
    }
}
```

- [ABC294 E - 2xN Grid](https://atcoder.jp/contests/abc294/tasks/abc294_e)
- [ABC421 D - RLE Moving](https://atcoder.jp/contests/abc421/tasks/abc421_d)


## 漸化式が与えられた列において $10^9$ 以上のオーダーの項を求める
- 行列累乗の利用
  - $a_{k+1} = pa_k + q$ ならば $\begin{pmatrix} a_k \\ 1 \end{pmatrix} = \begin{pmatrix} p & q \\ 0 & 1 \end{pmatrix}^k \begin{pmatrix} a_0 \\ 1 \end{pmatrix}$
    - [ABC293 E - Geometric Progression](https://atcoder.jp/contests/abc293/tasks/abc293_e)
  - $a_{k+2} = pa_{k+1} + qa_k$ ならば $\begin{pmatrix} a_{k+1} \\ a_k \end{pmatrix} = \begin{pmatrix} p & q \\ 1 & 0 \end{pmatrix}^k \begin{pmatrix} a_1 \\ a_0 \end{pmatrix}$


## DFSなのだが毎度探索する対象が変化する
- 計算量が間に合うなら毎度探索する対象を作り直す
  - [ABC281 F - Xor Minimization](https://atcoder.jp/contests/abc281/tasks/abc281_f)
- バックトラッキング


## 3次元累積和

```cpp
// 構築
vector<vector<vector<ll>>> s(n+1, vector<vector<ll>>(m+1, vector<ll>(l+1)));
for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
        for (ll k = 0; k < l; ++k) {
            s[i+1][j+1][k+1] = s[i][j+1][k+1] + s[i+1][j][k+1] + s[i+1][j+1][k] - s[i+1][j][k] - s[i][j+1][k] - s[i][j][k+1] + s[i][j][k] + a[i][j][k];
        }
    }
}
// [xl, xr)×[yl, yr)×[zl, zr)
ll ans = s[xr][yr][zr] - s[xl][yr][zr] - s[xr][yl][zr] - s[xr][yr][zl] + s[xr][yl][zl] + s[xl][yr][zl] + s[xl][yl][zr] - s[xl][yl][zl];
```


## 2項ずつ選んで差の絶対値の和を最大化する
- 大きい方 $\left\lfloor \frac{N}{2} \right\rfloor$ 個と小さい方 $\left\lfloor \frac{N}{2} \right\rfloor$ 個に分ける
  - 隣接する2項という制限があっても $N$ が偶数なら達成可能（括弧に対応付けると最も内側のものから順番にできる）
  - $N$ が奇数なら奇数番目の1項を除いて左右に分ける
    - [ARC196 A - Adjacent Delete](https://atcoder.jp/contests/arc196/tasks/arc196_a)


## 文字列中に長さ $K$ の回文があるかどうかを判定する
- 直前 $K-1$ 文字の情報を持てばDPで回せる
  - [ABC359 D - Avoid K Palindrome](https://atcoder.jp/contests/abc359/tasks/abc359_d)


## 同じ部分列が2度現れるかどうかを判定する
- （インデックスが）辞書順最小となるものと辞書順最大となるものを取り、一致するかどうかを見る
  - [ARC195 A - Twice Subsequence](https://atcoder.jp/contests/arc195/tasks/arc195_a)


## 区間 $[1, j]$ の項の種類数と区間 $[j+1, i]$ の項の種類数の和を $O(N \log N)$ で求める

$$
\mathrm{dp}_{i+1, j} =
  \begin{cases}
    \mathrm{dp}_{i,j} + 1 && (A_{i+1} \notin S_{j+1, i}) \\
    \mathrm{dp}_{i,j} && (A_{i+1} \in S_{j+1, i}) \\
  \end{cases}
$$

- ただし $S_{j+1,i}$ は $A_{j+1}, A_{j+2}, \dots, A_i$ からなる集合
- $A_{i+1} \in S_{j+1, i}$ を満たすかどうかは $j$ について単調性があるため、実際には $\mathrm{dp}_{i}$ に対して区間加算で $\mathrm{dp}_{i+1}$ が得られる
  - よってインラインDPで更新すれば $O(N \log N)$ で計算できる
- [ABC397 F - Variety Split Hard](https://atcoder.jp/contests/abc397/tasks/abc397_f)


## 連続する項を含まない（連続とは限らない）部分列を列挙する
- 部分列そのものではなく部分列から得られる何らかの値が必要なら以下のDFSで $O(\phi^N)$ でできる
  - [ABC427 F - Not Adjacent](https://atcoder.jp/contests/abc427/tasks/abc427_f)

```cpp
auto dfs = [&](auto dfs, ll last, ll val) -> void {
    /* valを用いて何かを行う */
    for (ll i = last + 2; i < n; ++i) {
        dfs(dfs, i, /* 新しいval */);
    }
};
dfs(dfs, -2, /* 初期値 */);
```