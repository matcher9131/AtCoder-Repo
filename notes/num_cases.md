# Number of cases

## 区別がつかないものを区別のつくグループに分ける
- 重複組合せ
  - 0個のグループが許されない：あらかじめ1個ずつ配っておく
    - [ARC134 C - The Majority](https://atcoder.jp/contests/arc134/tasks/arc134_c)
  - 0個のグループ数が限定される：0個にするグループを決めてから残りにあらかじめ1個ずつ配っておく
    - [ABC156 E - Roaming](https://atcoder.jp/contests/abc156/tasks/abc156_e)

## 0個以上を選んで和を $K$ にする
- 2要素DP
  - [ABC222 E - Red and Blue Tree](https://atcoder.jp/contests/abc222/tasks/abc222_e)

## 組み合わせの全列挙
- $N-K$ 個の $0$ と $K$ 個の $1$ を並べた配列 $(0, 0, \dots, 0, 1, 1, \dots, 1)$ に対して`next_permutation`

## 場合分けが細かすぎる
- 場合の数そのものを求めるのではなく場合の数の期待値や確率とすることで、場合分けを確率的な操作で記述できる
  - [ABC301 F - Anti-DDoS](https://atcoder.jp/contests/abc301/tasks/abc301_f)

## 包除原理
- ${\displaystyle \left| \bigcup_{i=1}^n A_i \right| = \sum_{k=1}^n(-1)^{k-1} \sum_{J \subset [n], |J| = k} \left| \bigcap_{j \in J} A_j \right |}$ （ただし $[n] = {1, 2, \dots, n}$ ）の形が有名だが、capとcupを逆にした ${\displaystyle \left| \bigcap_{i=1}^n A_i \right| = \sum_{k=1}^n(-1)^{k-1} \sum_{J \subset [n], |J| = k} \left| \bigcup_{j \in J} A_j \right |}$ も成り立つ
  - [ABC297 F - Minimum Bounding Box 2](https://atcoder.jp/contests/abc297/tasks/abc297_f)

## 必ずしも $A \cap B$ のほうが $A \cup B$ より数えやすいとは限らない
- 「少なくとも1個がAで少なくとも1個がB」という場合は、余事象を考えることにより $A \cap B$ より $A \cup B$ のほうが数えやすい
  - [ABC297 F - Minimum Bounding Box 2](https://atcoder.jp/contests/abc297/tasks/abc297_f)

## $P(X \geq i)$ が求めやすい $X$ に関して $E_X$ を求める
- $E_X = \sum_{i} iP(X=i) = \sum_i P(X \geq i)$
  - [ABC295 E - Kth Number](https://atcoder.jp/contests/abc295/tasks/abc295_e)

## すごろくDP（ゴールする確率）
- $\mathrm{dp}_{i,j}:$ $i$ 回振ったときに地点 $j$ にいる確率
- 遷移は出目 $x$ のそれぞれについて $\mathrm{dp}_{i+1,\min \{ N, j+x \}} = p(x) \mathrm{dp}_{i,j}$
  - ただし $p(x)$ は出目 $x$ の出る確率
- $i$ 回目にはじめてゴールする確率は $\mathrm{dp}_{i,N} - \mathrm{dp}_{i-1,N}$
  - [ABC298 E - Unfair Sugoroku](https://atcoder.jp/contests/abc298/tasks/abc298_e)

## すごろくDP（ゴールに到達するまでにサイコロを振る回数の期待値）
- $E_i = 1 + \sum_{j} p_j E_{i+j} + X$ として **後ろから** 計算
  - ただし $p_j$ は **$0$ を除いた** 目 $j$ が出る確率、 $X$ は $0$ を出す回数の期待値
    - [ABC263 E - Sugoroku 3](https://atcoder.jp/contests/abc263/tasks/abc263_e)

## 回数の期待値をDPで
- ${\displaystyle \mathrm{dp}_i = 1 + \sum_j p_j \cdot \mathrm{dp}_j}$
  - ただし $p_j$ は遷移確率
    - [ABC280 E - Critical Hit](https://atcoder.jp/contests/abc280/tasks/abc280_e)

## 確率 $p_x$ で値 $x$ を得る試行を繰り返し、値の合計が $X$ 以上になるまでの試行回数の期待値を得る
- 得た値の合計が $i$ **以上** になるまでの試行回数の期待値を $E_i$ として、 $E_i = 1 + \sum_{j=0} p_j E_{\max \{ i-j, 0 \}}$ ※移項が必要
  - [ABC382 E - Expansion Packs](https://atcoder.jp/contests/abc382/tasks/abc382_e)

## 集合 $S$ に対し $f(S)$ を数えたいが、 $S \subset T$ となる $f(T)$ を含んでしまう
- メビウス変換で上位集合のものを取り除く

```cpp
for (int i = 0; i < n; ++i) {
    for (ull bit = 0; bit < (1ULL << n); ++bit) {
        c[bit] -= c[bit | (1ULL << i)];
    }
}
```

- ループの順序を逆にすると引きすぎてしまうので注意
  - [ABC423 F - Loud Cicada](https://atcoder.jp/contests/abc423/tasks/abc423_f)


## $N$ 個から $0$ 個以上を選ぶ場合の数で、ある $y = f(x)$ が存在して $A_j = f(A_i)$ となる $i, j$ を同時に選べない
- $f(A_i) = A_j$ ならば $f(A_j) = A_i$ が成り立つならばこの2つをセットにして数える
  - [ABC168 E - ∙ (Bullet)](https://atcoder.jp/contests/abc168/tasks/abc168_e)

```cpp
unordered_map<ll, ll> count;

ll ans = 1;
set<ll> used;
for (const auto &[val, c] : count) {
    if (used.contains(val)) continue;
    ll other = f(val);
    if (count.contains(other)) {
        ans *= mint(2).pow(c) * mint(2).pow(count[other]) - 1;
        used.insert(other);
    } else {
        ans *= mint(2).pow(c);
    }
}
```

## $O(N^2)$ が間に合うときに $0 \leq j \leq i \leq N$ のすべてで ${\displaystyle \begin{pmatrix} i \\ j \end{pmatrix}}$ を求めたい
- パスカルの三角形
  - [ABC425 E - Count Sequences 2](https://atcoder.jp/contests/abc425/tasks/abc425_e)

## $A_i$ を用いない場合の数
- 左右からの累積和
  - [ABC291 F - Teleporter and Closed off](https://atcoder.jp/contests/abc291/tasks/abc291_f)

## $r$ が小さいときの ${}_n H_r = \binom{n+r-1}{r-1}$

```cpp
mint nhr(ll n, ll r) {
    mint numer = 1, denom = 1;
    for (ll i = 1; i < r; ++i) {
        numer *= n+i;
        denom *= i;
    }
    return numer / denom;
}
```

- 分母と分子に分けないと $\log M$ 倍（≒30倍）の計算量になってしまうので注意