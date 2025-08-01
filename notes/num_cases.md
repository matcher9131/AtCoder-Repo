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
