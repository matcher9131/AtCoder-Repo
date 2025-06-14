# [ABC339](https://atcoder.jp/contests/abc339) Review
- バーチャル参加
- 一度解いた問題があったにもかかわらず1350位相当となんともな順位

## D - Synchronized Players
- AC（34分＋2WA）
- 2人の座標の組み合わせを頂点とする単なるBFSだが
  - 入力の際に同じ行に2人のプレイヤーがいる際に2人目が解釈されないコードを書いてしまい2度の`WA`
    - 一度やっているにも関わらずこのポカである

## E - Smooth Subsequence
- AC（15分）
- $\mathrm{dp}_j$ を $j$ を末項とする条件を満たす部分列の最大の長さとして、 $i = 1, 2, \dots, N$ の順に以下のように更新していく
  - ${\displaystyle \mathrm{dp}_{A_i} \gets \max_{A_i - D \leq x \leq A_i + D} \mathrm{dp}_x + 1}$
- このままでは計算量 $O(ND)$ で`TLE`するので、DPを`segtree`にすることで $O(N \log \max A)$ にできる

## F - Product Equality
- 時間切れ
- メモ：　$10^{1000}$ ぐらいまでの数で計算量 $10^6$ ぐらいまでなら**Pythonを使えば実行時間的に問題なく多倍長整数の演算ができる**