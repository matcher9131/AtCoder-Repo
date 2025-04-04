# AtCoder Problems Recommendation (Difficult) Reivew
AtCoder Problems RecommendationのDifficultでおすすめされる問題をひたすら解いてひたすらレビューする

## ABC243 E - Edge Deletion
- 各頂点からDijkstra法を行い、最短経路を復元して使用された辺以外を削除したらいいのではないかと考えたが
  - 同じ距離で2ルート以上ある場合に使わなくてよい辺をうまく検出できず`WA`
- 公式解説を見る
  - 各辺について必要かどうかを1つずつ判断する必要がある
    - ↑の解き方のときに2頂点 $i, j$ の距離 $d_{i,j}$ を記録する必要がなかったため、この発想に至らなかった

## AGC018 B - Sports Festival
- 恐らくは二分探索法だろうなぁと思いつつ
  - 最も多くの人が参加するスポーツの参加人数を $x$ 人以下にできるかどうかを判定する部分をどうしようかと悩む
- 結局 $N \leq 300, M \leq 300$ であるのをいいことに、以下のようにゴリ押しで判定することにする
    1. 全てのスポーツを実施するものとする
    1. 現状で実施するスポーツの数を $m$ とするとき、$\lceil N/m \rceil \gt x$ ならば`false`を返す
    1. 実施される各スポーツについて参加する人数をカウントし、その最大値が $x$ 以下なら`true`を返す
    1. 最も多い人数が参加するスポーツを実施しないものとして、2.に戻る
- 計算量は $O(NM^2 \log N)$？
- そして提出後に二分探索の必要が全くないことに気づく
  - 実施しないスポーツの選択はいつも同じ順番で行われるので、1つずつ実施しないスポーツを選びながら最多参加者の最小値を記録していけばよい

## [ABC202 E - Count Descendants](https://atcoder.jp/contests/abc202/tasks/abc202_e)
- 木において頂点 $v$ が頂点 $u$ の子孫かどうかの判定
  - LCA + ダブリング
    - 参考：[ダブリングによる木の最近共通祖先（LCA：Lowest Common Ancestor）を求めるアルゴリズム | アルゴリズムロジック](https://algo-logic.info/lca/)
    - 前処理 $O(N \log N)$ 、クエリ $O(\log N)$
    - パッと思いついたのはこっち
      - しかし複数の頂点を一括して処理できないため本問だと間に合わない
  - オイラーツアー + タイムスタンプ
    - 頂点 $i$ の行きがけ・帰りがけの時刻をそれぞれ $s_i, t_i$ とおくと、頂点 $v$ が頂点 $u$ の子孫である条件は $s_u < s_v < t_u$
    - 二分探索により複数の頂点を一括して処理できる
- クエリ先読みかと思ったら別にそんなことはなかった

## [ABC223 F - Parenthesis Checking](https://atcoder.jp/contests/abc223/tasks/abc223_f)
- 正しい括弧列：括弧レベル
  - `(`を $+1$ 、`)`を $-1$ に対応させ、その累積和が途中で $0$ 未満になったら不正、ならなかったら正規
- 以下 $A_i$ を $i$ 文字目終了時の括弧レベルとする（ $A_0 = 0$ ）
- クエリ $1$ のとき
  - $S_l$ が`(`で $S_r$ が`)`のとき、入れ替えによって区間 $[l, r)$ の括弧レベルが $-2$ される
  - $S_l$ が`)`で $S_r$ が`(`のとき、入れ替えによって区間 $[l, r)$ の括弧レベルが $+2$ される
- クエリ $2$ のとき
  - $l$ 文字目開始前の括弧レベルは $A_{l-1}$ で、これを基準として括弧レベルを見ればよい
    - よって $S$ の $l$ 文字目から $r$ 文字目が正しい括弧列になる条件は $A_r = A_{l-1}$ かつ $l \leq i \leq r$ において $A_i \geq A_{l-1}$
- クエリ $1$ は区間加算、クエリ $2$ は区間最小値取得でいけるので`lazy_segtree`の出番
- ここまですぐに分かったのに実際の $S$ をswapし忘れて1敗
  - しかもそれになかなか気づかないという
