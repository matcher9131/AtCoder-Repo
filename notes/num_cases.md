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
- ${\displaystyle \left| \bigcup_{i=1}^n A_i \right| = \sum_{k=1}^n(-1)^{k-1} \sum_{J \subset [n], |J| = k} \left| \bigcap_{j \in J} A_j \right |}$ （ただし $[n] = {1, 2, \dots, n}$ の形が有名だが、capとcupを逆にした ${\displaystyle \left| \bigcap_{i=1}^n A_i \right| = \sum_{k=1}^n(-1)^{k-1} \sum_{J \subset [n], |J| = k} \left| \bigcup_{j \in J} A_j \right |}$ も成り立つ
  - [ABC297 F - Minimum Bounding Box 2](https://atcoder.jp/contests/abc297/tasks/abc297_f)

## 必ずしも $A \cap B$ のほうが $A \cup B$ より数えやすいとは限らない
- 「少なくとも1個がAで少なくとも1個がB」という場合は、余事象を考えることにより $A \cap B$ より $A \cup B$ のほうが余事象を用いて数えやすい
  - [ABC297 F - Minimum Bounding Box 2](https://atcoder.jp/contests/abc297/tasks/abc297_f)

## $P(X \geq i)$ が求めやすい $X$ に関して $E_X$ を求める
- $E_X = \sum_{i} iP(X=i) = \sum_i P(X \geq i)$
  - [ABC295 E - Kth Number](https://atcoder.jp/contests/abc295/tasks/abc295_e)
