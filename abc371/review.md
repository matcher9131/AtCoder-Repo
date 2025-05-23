# [ABC371](https://atcoder.jp/contests/abc371) Review
- バーチャル参加
- ギリギリでEを突破
  - 緑色の難易度じゃないと思うんだがなぁ…

## C - Make Isomorphic
- AC
- グラフの同型判定なんてやったこと無ぇ！
  - と思ったが、 $N \leq 8$ だから頂点の順列の全列挙が余裕で間に合う
- よってあらかじめ $H$ に頂点番号を割り振って、 $G$ と各頂点を結ぶ辺の有無が一致するように $H$ の辺を追加or削除するのに支払う額を求めればよい
  - ↑を全ての頂点番号の割り振り方 $N!$ 通りで試して最小値を解にすればOK
    - 計算量は $O(N!N^2)$

## D - 1D Country
- AC
- 累積和を用いれば楽勝だが
  - $-10^9 \leq X_i \leq 10^9$ のため`TLE`および`MLE`不可避
- 座標に関しては $X_i, L_i, R_i$ のみが現れて、その大小関係のみが意味を持つため、座標圧縮をすればなんとかなりそう
  - $X_i, L_i, R_i$ をまとめて一つの`vector`にぶちこんで座標圧縮を行う
- これで各座標が最小値 $0$ 、最大値が高々 $N + 2Q \leq 3 \times 10^5$ の範囲に収まるのであとは何なりと
  - 累積和の更新でミスりそうだったのでSegment treeに頼った
    - 計算量は $O((N + 3Q) \log (N + 2Q))$
- （公式解説）$S_X$ を「 $X_i \leq X$ を満たす村の人口の合計」と考えて↑に至ったが、そもそも $S_i$ を「左から $i$ 番目までの村の人口の合計」とすれば良かったのか…
  - 相変わらずインデックス主軸でものを考えるのが苦手だなぁ…

## E - I Hate Sigma Problems
- AC
- **手を動かすのは大事**
- 数列 $\{A_i\}$ の全ての項が異なる場合
  - $\sum_{i=1}^{N} \sum_{j=i}^{N} f(i,j) = \sum_{i=1}^{N} \sum_{j=i}^{N} (j - i + 1) = \sum_{i=1}^{N} \sum_{j=1}^{N-i+1} j = \sum_{i=1}^N \sum_{j=1}^{i} j = \dfrac{N(N+1)(N+2)}{6}$
    - 以下これを $M_N$ とする
- 同じ数字が存在するときに解が $M_N$ と比べてどの程度小さくなるのかを小さい $N$ で何パターンも愚直に試した結果、おそらく以下の法則を満たしそうなことがわかった
    1. 数列 $\{A_i\}$ に同じ数字の項がちょうど2個のみ存在する場合
        - その2つが第 $i$ 項と第 $j$ 項（ただし $i < j$ ）にあるならば、解は $M_N$ と比べて $i(N + 1 - j)$ だけ小さくなる
    1. 数列 $\{A_i\}$ に同じ数字の項がちょうど $K(\geq 2)$ 個存在し、それ以外が全て異なる場合
        - 同じ数字の項が第 $B_1, B_2, \dots , B_K$ 項にあるならば、解は $M_N$ と比べて $\sum_{j=1}^{K-1} B_j(N + 1 - B_{j+1})$ だけ小さくなる
          - 要するに $1$ 番目と $2$ 番目、$2$ 番目と $3$ 番目…、 $K-1$ 番目と $K$ 番目のそれぞれで1.と同じことを繰り返せばよい
    1. 数列 $\{A_i\}$ に複数種類の同じ数字の項が存在する場合
        - 各数字において独立に2.を求めて、その合計を $M_N$ から引けばよい
- 証明がわからなかったが残り時間もわずかだったのでとりあえず出してみたら通った
  - 計算量は $O(N)$
- （公式解説）言われてみれば連続部分列のカウント問題だなこれ…
  - 公式解説では「左端が $x_k+1$ 以上、右端が $x_{k+1}-1$ 以下の連続部分列の個数」をカウントしているが、↑の $B_j(N + 1 - B_{j+1})$ はその真逆の「左端が $B_j$ 以下、右端が $B_{j+1}$ 以上の連続部分列の個数」を求めていることになる
    - これをキーにして自分の解法の妥当性を証明できそう
- 簡単のため数列 $\{A_i\}$ は $1$ をちょうど $K$ 個含み、それ以外は全て互いに異なる数からなるものとする
  - また、以下を定義する
    - 左から $j$ 番目の $1$ を $1_j$ と表す
    - 数 $x$ を含むすべての連続部分列からなる集合を $S_x$ とする
- ここで $|S_1|$ を考える
    1. $K=2$ のとき
        - $|S_1| = |S_{1_1}| + |S_{1_2}| - |S_{1_1} \cap S_{1_2}|$
    1. $K=k$ のとき
        - $|S_1| = \sum_{j=1}^{k} |S_{1_j}| - \sum_{j=1}^{k-1} |S_{1_j} \cap S_{1_{j+1}}|$ と表せると仮定する
    1. $K=k+1$ において
        - $|S_1| = \left| \bigcup_{j = 1}^{k} S_{1_j} \right| + |S_{1_{k+1}}| - \left| \left( \bigcup_{j = 1}^{k} S_{1_j} \right) \cap S_{1_{k+1}} \right| \\ = \sum_{j=1}^{k} |S_{1_j}| - \sum_{j=1}^{k-1} |S_{1_j} \cap S_{1_{j+1}}| + |S_{1_{k+1}}| - |S_{1_k} \cap S_{1_{k+1}}| \\ = \sum_{j=1}^{k+1} |S_{1_k}| - \sum_{j=1}^{k} |S_{1_j} \cap S_{1_{j+1}}|$
            - $\because j \leq k$ を満たす $1_j$ と $1_{k+1}$ を含む連続部分列は必ず $1_k$ を含む
    1. 以上より帰納的に $|S_1| = \sum_{j=1}^{k} |S_{1_j}| - \sum_{j=1}^{k-1} |S_{1_j} \cap S_{1_{j+1}}|$ といえる
- ここまでの議論は $1$ 以外の項がどのようなものであっても関係ないので同様に $|S_2|$ 以降も求まることと、 $M_N = \sum_{i = 1}^{\max A_i} \sum_{j=1}^{K_i} |S_{i_j}|$ であることから、↑の解法は妥当である
