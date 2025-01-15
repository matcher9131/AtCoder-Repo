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

## 018 - Statue of Chokudai（★3）
- 許容される相対誤差または絶対誤差が $10^{-7}$ なら`double`を使っておけばそうそう誤差でやられることはない
  - ただし（今回は問題ないが）桁落ち、情報落ちには注意

## 019 - Pick Two（★6）
- 区間DP：計算量は $O(N^3)$ になることが多い
- 更新順に注意
  - 今回は区間幅が狭いほうから更新する

## 020 - Log Inequality（★3）
- 精度が重要な時に`double`を使うのは要注意
  - `double`の仮数部は52桁なので、整数を扱う場合`long long`より精度が低い

## 021 - Come Back in One Piece（★5）
- 有向グラフで2頂点が行き来できる：強連結成分分解
  - 手順
      1. 任意の頂点からDFSを行い帰りがけ順を記録する
      2. 辺を全て逆にして帰りがけ順の大きいほうから順次DFSを行う
        - DFSが終わるたびに強連結成分が現れる

## 022 - Cubic Cake（★2）
- ゼロ除算を気にしなくてよいなら`gcd(x, y)`は短く書ける
  - そもそもC++17なら`<numeric>`に`gcd(x, y)`がある

## 024 - Select +／- One（★2）
- ちょうど $K$ 回：偶奇性が必要になることがある

## 026 - Independent Set on a Tree（★4）
- 木は必ず二部グラフ

## 027 - Sign Up Requests （★2）
- `set::insert(value)`は`pair<iterator, bool>`を返すので挿入に成功するかどうかは予め`set::contains(value)`で調べなくてもよい

## 028 - Cluttered Paper（★4）
- 二次元いもす法

## 029 - Long Bricks（★5）
- 区間変更＆区間最大値取得：Lazy Segment Tree
  - メモ：`<atcoder/lazysegtree>`の使い方
    - 参考リンク：[AtCoder LibraryのLazy Segtreeの使い方 - ARMERIA](https://betrue12.hateblo.jp/entry/2020/09/22/194541)
    - `lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);`
      - 区間取得演算に必要
        - `S`：モノイド（取得する結果）の型
        - `S op(S a, S b)`：区間取得演算（$S$ の要素どうしの演算）
        - `S e()`：区間取得演算に対する単位元（`op(e(), a) == a`となるもの）を返す関数
      - 区間操作演算に必要
        - `F`：写像（操作）の型
          - 実際に関数`function<S(F)> f`を持たせるわけではない
          - `f(x)`を求めるのに必要なデータを格納する型と考えるべき？
        - `S mapping(F f, S x)`：各データ $x$ に対して更新の操作を $f$ として $f(x)$ を返す関数
          - これが操作 $f$ の本体と考えたほうがよさそう
          - 引数にデータは持てるが振る舞いを持てないため、同じ`F f`に対して異なる挙動が必要な場合はそもそもLazy Segment Treeは使えない
            - 必要最小限以外の情報を`x`に持たせてなんとかすることはできる
        - `S composition(F f, F g)`：遅延されている操作 $g$ に対して、新たに遅延される操作 $f$ が行われたときの合成写像 $f \circ g$ を返す関数
          - $f, g$ の順序に注意！
        - `F id()`：区間操作演算における恒等写像（`mapping(id(), a) == a`となるもの）を返す関数

## 031 - VS AtCoder（★6）
- Grundy数：現在の盤面から1手で行けることのできる全ての盤面のGrundy数による集合のmex
  - mex：その集合に含まれない最小の非負整数
- Grundy数が $0$ なら後手必勝、それ以外なら先手必勝
- 複数の山があるときは $\mathrm{xor}$ を計算すればOK

## 032 - AtCoder Ekiden（★3）
- $N \leq 10$ なら順列による全探索が可能

## 033 - Not Too Bright（★2）
- 与えられた数字が小さいときのコーナーケースに注意

## 034 - There are few types of elements（★4）
- 連続する区間で単調性のあるもの：尺取り法

## 036 - Max Manhattan Distance（★5）
- マンハッタン距離：45度回転して $x$ 座標の差と $y$ 座標の差の大きいほう
  - ここでいう45度回転は $(x,y)$ に対して $(x+y,x-y)$ を指す

## 037 - Don't Leave the Spice（★5）
- 配るDPで考えると区間更新（$j+L_i \leq k \leq \min \{ j+R_i, W \}$ に対して $dp_{i,k} = \max \{ dp_{i,k}, dp_{i-1,j} + V_i \}$）が必要となりLazy Segment Treeが必要だが
  - 貰うDPで考えると区間更新ではなく1点更新でOK（$dp_{i,j} = \max \{ dp_{i-1,j-R_i}, dp_{i-1,j-R_i+1}, \ \dots, dp_{i-1,j-L_i} \}$）なため通常のSegment Treeで大丈夫
    - しかもこちらのほうが速い

## 038 - Large LCM（★3）
- $xy \gt c \Leftrightarrow x \gt \frac{c}{y}$

## 039 - Tree Distance（★5）
- 前に解いた問題（[ABC220 F - Distance Sums 2](https://atcoder.jp/contests/abc220/tasks/abc220_f)）の類題なのに完全に忘れていた
  - 木において頂点 $i, j$ の最短距離を $\mathrm{dist}(i,j)$ とするとき、$\displaystyle D_i = \sum_{j = 1}^{N} \mathrm{dist}(i,j)$ は $D_i = D_p - S_i + (N - S_i) = D_p + N - 2S_i$ と求められる
    - ただし $p$ は $i$ の親、$S_i$ は $i$ を頂点とする部分木のサイズである
    - なお $D_1$ はあらかじめ求めておく（DFSで各頂点の深さを合計すればOK）

## 042 - Multiple of 9（★4）
- まずは1要素DPを考える

## 043 - Maze Challenge with Lack of Sleep（★4）
- 「今向いている方向」も状態なので、$(i, j, d)$ の3要素を頂点に持つグラフで拡張Dijkstra

## 044 - Shift and Swapping（★3）
- 配列をシフトするのではなく $x, y$ をシフトする
- 数学的定義と異なり`i % n`は負になる可能性がある
  - `(i % n + n) % n`なら $0$ 以上 $n$ 未満の整数になる

## 046 - I Love 46（★3）
- $\bmod{M}$ で分類することで計算量を $O(M)$ にできる

## 048 - I will not drop out（★3）
- 与えられた制約の意味をよく考える
  - 今回の場合 $A_i - B_i \lt B_i$ が成り立つので、問題 $i$ を配点が $B_i, A_i - B_i$ の2問に分けて降順にソートするだけでOK

## 050 - Stair Jump（★3）
- 貰うDPのときは添え字が負にならないかチェックする
  - 今回でいう`dp[i] += dp[i - l]`の部分

## 051 - Typical Shop（★5）
- 計算量 $O(N2^N)$ がギリギリ`TLE`しそうなとき：半分全列挙にすると $O(N2^{\frac{N}{2}})$ でいける

## 052 - Dice Product（★3）
- $\displaystyle \sum_{j_1 = 1}^6 \sum_{j_2 = 1}^6 \dots \sum_{j_N = 1}^6 A_{1,j_1}A_{2,j_2} \dots A_{N,j_N} = \sum_{j_1 = 1}^6 \sum_{j_2 = 1}^6 \dots \sum_{j_{N-1} = 1}^6 A_{1,j_1}A_{2,j_2} \dots A_{N,j_N} \sum_{j_N = 1}^6 A_{N,j_N} = \dots = \sum_{j_1 = 1}^6 A_{1,j_1} \sum_{j_2 = 1}^6 A_{2,j_2} \dots \sum_{j_N = 1}^6 A_{N,j_N} = \prod_{i = 1}^N \sum_{j_i = 1}^6 A_{i,j_i} $

## 056 - Lucky Bag（★5）
- DP復元：どこから遷移してきたのかを情報に持つ
- 最初の要素から気を抜かない（範囲外アクセス）

## 058 - Original Calculator（★4）
- 有向グラフにおけるサイクル復元：
  - DFSで探索して行きがけ順で見たのに帰りがけ順で見ていない頂点が出てきたら閉路あり
  - 行きがけ順で`push`して帰りがけ順で`pop`する`stack`を用意すればサイクルを復元できる
    - ただし今回は全頂点において出次数1なので行きがけ順だけ気にすればOK

## 060 - Chimera（★5）
- LIS（最長増加部分列）の長さの求め方：
  - $dp_j$ を $(A_1, \dots, A_i)$ における長さが $j$ の増加部分列の末項の最小値とおく
    - 初期値：全項 $\infty$
    - 更新：$A_i \geq dp_k$ となるような最小の $k$ に対し $dp_k = A_i$
    - 解：$A_k \lt \infty$ となる最大の $k$
  - なおDPを更新するごとに $k$ の値をメモすれば、$(A_1, \dots, A_i)$ における増加部分列で $A_i$ を含むものの長さの最大値を得られる
    - この問題においては $B_K = A_i$ として計算するのに使える

## 063 - Monochromatic Subgrid（★4）
- 行数と列数で極端に差があるグリッド：少ないほうで全探索

## 064 - Uplift（★3）
- 範囲更新が必要に見えて、実際は更新範囲の端だけ監視していればOKなタイプ

## 066 - Various Arrays（★5）
- 確率変数 $X,Y$ が独立なら $E(X + Y) = E(X) + E(Y), \ E(XY) = E(X) + E(Y)$

## 069 - Colorful Blocks 2（★3）
- $a^b \bmod m$：繰り返し2乗法（$a^{2^n}$ を前計算しておいて $b$ を2進数表記で考える）

## 070 - Plant Planning（★4）
- 2次元以上のマンハッタン距離の和： $x$ 座標と $y$ 座標を独立して考えてOK
- 1次元において1つの動点と多数の定点の距離の和：動点が定点の中央値に等しいときに最小になる
  - 動点が中央値より大きくなっても小さくなっても定点との距離の和が増えてしまうため

## 072 - Loop Railway Plan（★4）
- 最長単純閉道：隣の頂点への最長単純道を考える
- 最長単純道：`dp[道が含む頂点の集合][今いる頂点] = 道の長さの最大値`(Bit DP)
- なお今回は全探索でも問題なく、バックトラックで行けた模様

## 075 - Magic For Balls（★3）
- ビット操作関数を覚える
  - `bit_floor, bit_ceil, bit_width, countr_zero, countr_one, countl_zero, countr_one, popcount`

## 076 - Cake Cut（★3）
- 循環配列の連続区間：2巡させた通常の配列でOK
- 区間和：尺取法

