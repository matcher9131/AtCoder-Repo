# DP
※ 確率DPに関してはnum_casesのほうに記載


## 共通
- 後ろからDPはかなり強力
  - [ABC078 D - ABS](https://atcoder.jp/contests/abc078/tasks/arc085_b)


## 遷移がループしそうなDP
- 状態数を増やせばループを回避できることがある
  - [ABC303 D - Shift vs. CapsLock](https://atcoder.jp/contests/abc303/tasks/abc303_d)


## DPで数え上げたいが要素数が多すぎる
- そもそも漸化式を一般項で表せる
  - [SoundHound Inc. Programming Contest 2018 -Masters Tournament- C - Ordinary Beauty](https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c)


## DPで特定の条件を満たすものの個数を数える
- 条件を満たすものと満たさないものの間で遷移があるかを確かめ、ある場合は両方を同時に数える
  - [ABC418 D - XNOR Operation](https://atcoder.jp/contests/abc418/tasks/abc418_d)


## 連続部分列の個数をDPで数える
- $\mathrm{dp}_{i}$ を $i$ を右端とする連続部分列のうち条件を満たすものの個数とすると重複カウントを無くせるかもしれない
  - [ABC418 D - XNOR Operation](https://atcoder.jp/contests/abc418/tasks/abc418_d)


## $A$ の部分列と $B$ の部分列が一致するような場合の数
- 2次元累積和の要領で $\mathrm{dp}_{i,j}$ を $\mathrm{dp}_{i-1,j}, \mathrm{dp}_{i,j-1}, \mathrm{dp}_{i-1,j-1}$ から更新できる
  - [ABC130 E - Common Subsequence](https://atcoder.jp/contests/abc130/tasks/abc130_e)