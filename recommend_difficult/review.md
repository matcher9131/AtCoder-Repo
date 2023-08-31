# AtCoder Problems Recommendation (Difficult) Reivew
AtCoder Problems RecommendationのDifficultでおすすめされる問題をひたすら解いてひたすらレビューする

## ABC243 E - Edge Deletion
- 各頂点からDijkstra法を行い、最短経路を復元して使用された辺以外を削除したらいいのではないかと考えたが
  - 同じ距離で2ルート以上ある場合に使わなくてよい辺をうまく検出できず`WA`
- 公式解説を見る
  - 各辺について必要かどうかを1つずつ判断する必要がある
    - ↑の解き方のときに2頂点 $i, j$ の距離 $d_{i,j}$ を記録する必要がなかったため、この発想に至らなかった