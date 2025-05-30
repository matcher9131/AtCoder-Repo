# [ABC351](https://atcoder.jp/contests/abc351) Review
- バーチャル参加
- Cで素でミスるもFまで到達して800位相当

## D - Grid and Magnet
- AC（24分）
- 相互に行き来可能なマスの集合を $S_i$ 、 $S_i$ から一方的に到達可能なマスの集合を $T_i$ とすると
  - 任意の $i \neq j$ に対し $S_i \cap S_j = \varnothing$
  - $S_i$ 内の任意のマスから開始して到達できるマスの個数は $|S_i| + |T_i|$ で一定
- よって各 $S_i$ 内から適当に1つ選んでDFSをすればOK
  - なお任意の $i \neq j$ に対し $T_i \cap T_j$ が空集合とは限らないことに注意
- 単にDFSでいいことに気づくのにえらく時間がかかってしまった……

## E - Jump Distance Sum
- AC（19分）
- 市松模様の要領で考えると、座標の和の偶奇が一致しない点への移動は不可
  - よって座標の和が偶数のものと奇数のものに分けて考えてOK
- 移動回数は2点のチェビシェフ距離に一致する
  - マンハッタン距離を考える問題で45度回転（＆ $\sqrt{2}$ 倍拡大）をしてチェビシェフ距離で考える問題があるが、今回はチェビシェフ距離だと何もできなさそう
  - 逆にマンハッタン距離は $x$ と $y$ のそれぞれを独立に見ることができて、今回は明らかにこっちのほうがやりやすそう
- ということは45度回転させてマンハッタン距離にしてしまえばいいのでは？と思いつく
  - 簡単のため $\sqrt{2}$ 倍拡大もしておいて、あとで距離を2で割ればOK

## F - Double Sum
- AC（36分）
- 結局のところ $i = 1, 2, \dots, N$ に対し、 $j < i$ かつ $A_j < A_i$ を満たすものの個数と総和がわかればOK
  - よってそれぞれをFenwick Treeなどで管理すればよい
    - ただし $A_i \leq 10^8$ より座標圧縮が必須
- なお謎に個数と総和を構造体にひとまとめにしてSegment Treeを使った模様
- （公式解説） $i$ を固定するより $j$ を固定したほうがわかりやすいのでは……？
