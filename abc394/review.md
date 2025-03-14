# [ABC394](https://atcoder.jp/contests/abc394) Review
- Rated参加
- E, Fに全く手が出ず惨敗
  - レート30を溶かす

# E - Palindromic Shortest Path
- 時間切れ
- 最短でなくてもよいパスと言われてフリーズ
- （公式解説）パス $(w,z)$ を直接考えるのではなく、内側から順に回文条件を満たすように考えるとよい
  - すなわち、パス $(x,y)$ が条件を満たすときに辺 $(w,x), (y,z)$ が同じ文字ならばパス $(w,z)$ も条件を満たすことを用いて、頂点 $(x,y)$ から $(w,z)$ へ重み $2$ の辺を張る
- 頂点数 $N$ ではなく $2N$ や $N^2$ でDFSは慣れてないのでちょっと重点的な修行が必要かもしれない
  - むしろ木DPと考えてもよさそうな気がする

# F - Alkane
- 時間切れ
- 次数4以上の頂点間のみ辺を張って頑張ろうとするも
  - 次数5以上の頂点から辺を消さねばならずうまくいかない
- （公式解説） $\mathrm{dp}_v$ を頂点 $v$ およびその子孫で作ることのできる最大のアルキル基の頂点数として、木DPを行いつつついでに解を求めればいいらしい
  - 解とは微妙に異なるものをDPするパティーン……まだ思いつかないなぁ……
