# [競プロ典型 90 問](https://atcoder.jp/contests/typical90) Reivew
レビューというより一口メモ

## 001 - Yokan Party（★4）
- 最小値の最大化：二分探索

## 002 - Encyclopedia of Parentheses（★3）
- 括弧の対応：括弧の深さレベルが途中で負にならず、最終的に0になる

## 003 - Longest Circular Road（★4）
- 木の直径：任意の点を根としてDFS(BFS)で最も深い葉を見つけ、その点を根として再びDFS(BFS)

## 004 - Cross Sum（★2）
- あらかじめ和を求めておくことで $O(HW)$ を $O(H+W)$ にするいつものやつ

## 005 - Restricted Digits（★7）
- 桁DP：ダブリングで遷移回数を減らす
  - 今回は桁ごとに独立なのでいつものDPのようにテーブル全体を用意する必要はなく、1行だけあればいける

## 006 - Smallest Subsequence（★5）
- 文字種ごとにデータを用意すると $O(K)$ を $O(C)$（$C$ は文字の種類数）にできることがある

## 007 - CP Classes（★3）
- `lower_bound()`で探して右側と左側を見る（`it == a.begin()`や`it == a.end()`のときに注意）

## 008 - AtCounter（★4）
- この問題ではDPを1-indexedにしたほうが場合分けが不要で楽だが、初期値に注意

## 009 - Three Point Angle（★6）
- 偏角でソートしてから`lower_bound()`で探して右側と左側を見る（`it == a.begin()`や`it == a.end()`のときの処理、および`atan2()`の値域と差の取り方に注意）

## 010 - Score Sum Queries（★2）
- 区間和には累積和

## 011 - Gravy Jobs（★6）
- 区間の終点でソートしてからのDP
  - 仕事を受けるのであればすぐに取り掛かったほうが良い
  - 締め切りが早い順に受けるかどうかの判断が必要

## 012 - Red Painting（★4）
- グリッドグラフ＋Union-Findの組み合わせ

## 013 - Passing（★5）
- Warshall-Floydは間に合わないのでDijkstraを2回するだけ
- ★5になってはいるが今の基準だと緑色の低いほうだろうか…

## 014 - We Used to Sing a Song Together（★3）
- 順番を入れ替えても問題がないのでソートして小さいほうから順に貪欲に小学校を割り当てる

## 015 - Don't be too close（★6）
- $N \leq 10^7$ のときの ${}_{N}C_k \pmod p$ の高速計算：あらかじめ $k! \pmod p$ を求めておく
- 調和級数の和 $\displaystyle \sum_{k = 1}^{N} \frac{1}{k}$ について
  - $f(x) = \frac{1}{x}$ とおくと $f'(x) = -\frac{1}{x^2} \lt 0$ より $f(x)$ は単調減少
  - よって自然数 $k$ に対し、$k \leq x \leq k + 1$ において $f(k + 1) \lt f(x)$ なので  
    $\int_{k}^{k + 1} f(k + 1) dx \lt \int_{k}^{k + 1} f(x) dx$ すなわち $\frac{1}{k + 1} \lt \log (k + 1) - \log k$
  - $\displaystyle \therefore \sum_{k = 1}^{N} \frac{1}{k} = 1 + \sum_{k = 1}^{N - 1} \frac{1}{k + 1} \lt 1 + \sum_{k = 1}^{N - 1} (\log (k + 1) - \log k) = 1 + \log N$
  - 一方で $g(x) = \frac{1}{x + 1}$ とおくと $g'(x) = -\frac{1}{(x + 1)^2} \lt 0$ より $g(x)$ は単調減少
  - よって自然数 $k$ に対し、$k - 1 \leq x \leq k$ において $g(x) \lt g(k - 1)$ なので  
    $\int_{k - 1}^{k} g(x) dx \lt \int_{k - 1}^{k} g(k) dx$ すなわち $\log (k + 1) - \log k \lt \frac{1}{k}$
  - $\displaystyle \therefore \sum_{k = 1}^{N} (\log (k + 1) - \log k) = \log (N + 1) \lt \sum_{k = 1}^{N} \frac{1}{k}$
  - 以上により $\displaystyle \log (N + 1) \lt \sum_{k = 1}^{N} \frac{1}{k} \lt 1 + \log N$ なので $\displaystyle O \left( \sum_{k = 1}^{N} \frac{1}{k} \right) = O(\log N)$ である

## 016 - Minimum Coins（★3）
- 9999枚以下という制限のおかげで全探索可能




