# [ABC423](https://atcoder.jp/contests/abc423) Review
- Rated参加
- 気合の現状維持（レーティング $-1$ ）
  - ↓のような負け試合を実質引き分けに持ち込めたのはデカい
- Cで端の処理が上手く行かず時間を取られた上に`WA`を喰らって心が折れかけるも
  - 一旦後回しにしてDを解こう……→また`WA`
    - ここでパニックになったら終わり……と深呼吸
      - 幸いにも5分弱でデバッグができ
        - EがよくあるSegment treeにゴツい構造体を載せるタイプに違いないと信じて気合で解いて
          - Cに戻って今度こそ丁寧に端を処理してなんとか`AC`

## D - Long Waiting
- AC（20分＋1WA）
- よくあるイベントをまとめて`priority_queue`などで管理するやつ
- 今回はそこに（文字通り）入店待ちの`queue`が加わる
- $t$ を時刻、 $c$ を店内の人数とする
- 団体 $i$ の退店イベントの処理
    1. $c \gets c - C_i$
    1. 入店待ちの列があれば以下の処理を行う
       1. 先頭の団体 $j$ の人数 $C_j$ を見る
       1. $c + C_j \leq K$ なら入店させる。すなわち
           - 入店待ちの列から $j$ を削除
           - $c \gets c + C_j$
           - 時刻 $t + B_j$ に団体 $j$ が退店するイベントを追加
           - その後1. に戻る
       1. $c + C_j > K$ ならこの処理を打ち切る
- 団体 $i$ の来店イベントの処理
    1. 入店待ちの団体が無く $c + C_i \leq K$ ならば入店させる
        - $c \gets c + C_i$
        - 時刻 $t + B_i$ に団体 $i$ が退店するイベントを追加
    1. 入店待ちの団体があるか $c + C_i > K$ ならば
        - 入店待ちの列の末尾に $i$ を挿入する
- 来店イベントのとき「入店待ちの団体が無く」の条件を落として`WA`
  - Cが（この時点で）解けていない動揺が見て取れる……

## E - Sum of Subarrays
- AC（34分）
- Segment treeでなんとかする方針で
- 以下 ${\displaystyle \sum_{l=L_i}^{R_i} \sum_{r=l}^{R_i} \sum_{j=l}^r A_j = f(L_i, R_i)}$ と表すことにする

$$\begin{align*}
  f(l, r) &= f(l,m) + f(m+1,r) + \sum_{i=l}^m \sum_{j=m+1}^r \sum_{k=i}^j A_k \\
  &= f(l,m) + f(m+1,r) + \sum_{i=l}^m \sum_{j=m+1}^r \left( \sum_{k=i}^m A_k + \sum_{k=m+1}^j A_k \right) \\
  &= f(l,m) + f(m+1,r) + \sum_{i=l}^m \sum_{j=m+1}^r \sum_{k=i}^m A_k + \sum_{i=l}^m \sum_{j=m+1}^r \sum_{k=m+1}^j A_k \\
  &= f(l,m) + f(m+1,r) + (r-m) \sum_{i=l}^m \sum_{k=i}^m A_k + (m-l+1) \sum_{j=m+1}^r \sum_{k=m+1}^j A_k \\
\end{align*}$$

- ここで ${\displaystyle g(l,r) = \sum_{i=l}^r \sum_{k=i}^r A_k, \ h(l,r) = \sum_{i=l}^r \sum_{k=l}^i A_k}$ とおくと

$$\begin{align*}
  g(l, r) &= \sum_{i=l}^m \sum_{k=i}^r A_k + \sum_{i=m+1}^r \sum_{k=i}^r A_k \\
  &= \sum_{i=l}^m \sum_{k=i}^m A_k + \sum_{i=l}^m \sum_{k=m+1}^r A_k + \sum_{i=m+1}^r \sum_{k=i}^r A_k \\
  &= g(l, m) + (m-l+1) \sum_{k=m+1}^r A_k + g(m+1, r)
\end{align*}$$

- 同様に ${\displaystyle h(l,r) = h(l,m) + h(m+1,r) + (r-m) \sum_{k=l}^m A_k }$
- よって ${\displaystyle f(l,r), g(l,r), h(l,r), \sum_{k=l}^r A_k, l, r }$ の6つをSegment treeに載せれば全クエリを $O(Q \log N)$ で計算できる
- 実際には小さい $l, r$ で試しただけできっちり式変形をしたわけではないが、まぁ通ればヨシ！
- （公式解説） $A_i$ ごとの加算回数を $i$ の2次式で表せるのか……気づけんなぁ

## F - Loud Cicada
- 時間切れ
- $N \leq 20$ より全部分集合を全探索
- ある集合 $S$ に対し、 $\mathrm{lcm}(S)$ の倍数の年に $S$ に含まれるセミの全てが大量発生する
  - 毎度LCMを求めてもよいが、せっかくなのでbit DPでやってみた
- ところで、 $\mathrm{lcm}(S)$ の倍数の年には $S$ に含まれないセミも大量発生する可能性がある
  - 包除原理は係数が大きくなりすぎるため使えないが、メビウス変換で上位集合のものを除外していけばOK
    - 詳細はnotes/num_cases.mdにて
