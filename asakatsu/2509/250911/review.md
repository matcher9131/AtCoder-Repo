# [あさかつ9/11](https://kenkoooo.com/atcoder/#/contest/show/9ab34be0-3b11-48ae-a3b5-8764ce59bf84) Review

## 第4問 - Grid Repainting
- AC（6分）
- マス $(H,W)$ にたどり着けるなら解は $HW - B - (D+1)$
  - ただし $B$ は初期状態での黒マスの数、 $D$ はマス $(1,1)$ から $(H,W)$ までの最短距離
- よってBFSをすればOK

## 第5問 - AtCoder Language
- AC（45分）
- 小さい $N, K, L$ で総当たりのコードを書いてみると、同じ文字が出現する場合は間に $N-K$ 文字以上が存在すれば条件を満たせることがわかる
- よって解は $L \times (L-1) \times \dots \times (L-(N-K)) \times (L-(N-K)) \times \dots$ となるので $O(N)$ で求まる

## 第6問 - Red Polyomino
- 時間切れ
- 最も解が大きくなりそうな $N=K=8$ かつ全面白マスの入力例3の解が5桁に収まっていることから、Back trackingを疑うべき問題
- いつものDFSとは異なり、最後に訪れたマスの近傍だけではなく全ての赤マス近傍を毎度チェックする必要がある点に注意
