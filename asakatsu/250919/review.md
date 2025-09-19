# [あさかつ9/19](https://kenkoooo.com/atcoder/#/contest/show/b87b4eaf-6cc9-4184-a14b-bbe6967e7efd) Review

## 第2問 - ABA and BAB
- スキップ
- 公式解説を見てお前が灰色なわけあるかい！と叫ぶ
  - しかしテクニックとしては覚えておかないといけないもの
  - ARCのA問題はたまに難易度推定が変になるんだよなぁ……

## 第4問 - Reserve or Reverse
- 2WAからの時間切れ
- $l = 0, r = N$ として以下を繰り返す
    1. $l \geq r$ なら終了
    1. 区間 $(l, r)$ で $S_l > S_k$ となる最大の $k$ を探す
        - 存在すれば $S_l$ と $S_k$ をswapして $r \gets k$ とする
    1. $l \gets l+1$
- 適切で簡単な実装が思い浮かばなかったので無駄にSegment treeに`{ch, index}`の構造体を載せる
  - swap時に構造体ごとswapしてしまい1敗（indexはswapしてはならない）
  - 半開区間と閉区間を取り違え $r \gets k-1$ としてしまい1敗

## 第5問 - Programming Contest
- AC（18分）
- どうみても半分全列挙ですありがとうございました
- `lower_bound(...)`だと $T$ を超えないことが保証できないので `upper_bound(...) - 1`とすべきパティーン
  - 今回は先頭に $0$ が来るので`upper_bound(...) != v.begin()`が保証される
