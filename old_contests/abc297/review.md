# [ABC297](https://atcoder.jp/contests/abc297) Review
- バーチャル参加
- 時間ギリギリでGまで制覇してまさかの190位付近相当
  - これがRatedならどれほどよかったことか……！
  - 現行の7問制のGより簡単だとはわかっていてもGが解けたのは素直に嬉しい
    - Eまでが簡単で瞬殺できて時間が余ったのが幸いした

## D - Count Subtractions
- AC（4分）
- 以下 $A>B$ とする
- $A \bmod B > 0$ のとき
  - 操作を $\left\lfloor \frac{A}{B} \right\rfloor$ 回行って $A \gets A \bmod B$ とする
- $A \bmod B = 0$ のとき
  - 操作を $\frac{A}{B} - 1$ 回行うと $A=B$ となるので終了する
- 計算量は $O(\log \min \{ A, B \})$

## E - Kth Takoyaki Set
- AC（9分）
- 支払う金額としてあり得るものの集合として $S = {0}$ を用意し、以下を繰り返す
  1. $S$ から最小の要素 $x$ を取り出す
      - 取り出した回数が $K+1$ になったら $x$ を解として出力する
  1. $i = 1, 2, dots, N$ に対し、 $x+A_i$ を $S$ に追加する
- `set`を用いてイテレータで`s.begin()`から順番に走査することで処理を簡略化した
  - 追加される要素はいずれも現在見ている要素より後になるので問題無い
- 計算量は $A = \max_i A_i$ として $O(KN \log A)$

## F - Minimum Bounding Box 2
- AC（50分程度？）
- まず縦の長さの期待値 $E_x$ と横の長さの期待値 $E_y$ を求めて $E_x E_y$ を解にできないかと考えたが、入力例1の時点で破綻した
  - 4つ角のせいで $x,y$ が独立ではないという
- 次に縦横の2要素のみのなんちゃって包除原理で数えようとして失敗したが、気合を入れて4要素でやればいけるのではないかと思い実行することに
  - 黄色問題を解くには気合も必要ということで
- 長方形の縦横の長さがそれぞれ $x,y$ となるような確率を $P(x,y)$ とおくと、解は ${\displaystyle \sum_{x=1}^H \sum_{y=1}^W xyP(x,y)}$
- $P(x,y)$ について
  - 縦横の長さがそれぞれ $x,y$ となるような長方形を1つ取って固定する
  - 事象 $A,B,C,D$ を以下のように定める。また、事象 $X$ に対して $|X|$ をその事象を満たすようなマスの選び方の場合の数とする
    - $A:$ 長方形の最上行に選んだマスが含まれる
    - $B:$ 長方形の最下行に選んだマスが含まれる
    - $C:$ 長方形の最左列に選んだマスが含まれる
    - $D:$ 長方形の最右列に選んだマスが含まれる
  - このとき $A \cap B \cap C \cap D$ であればこの長方形が題意を満たすので、これを包除原理で数える
    - $A \cap B$ などより $A \cup B$ のほうが余事象を用いて数えやすいので、そちらを数える方針で
      - $|A| = \begin{pmatrix} xy \\ K \end{pmatrix} - \begin{pmatrix} (x-1)y \\ K \end{pmatrix}$
      - $|A \cup B| = \begin{pmatrix} xy \\ K \end{pmatrix} - \begin{pmatrix} (x-2)y \\ K \end{pmatrix}$
      - $|A \cup C| = \begin{pmatrix} xy \\ K \end{pmatrix} - \begin{pmatrix} (x-1)(y-1) \\ K \end{pmatrix}$
      - $\dots$
      - $A \cup B \cup C \cup D = \begin{pmatrix} xy \\ K \end{pmatrix} - \begin{pmatrix} (x-2)(y-2) \\ K \end{pmatrix}$
    - ただし、 $n < r$ のとき $\begin{pmatrix} n \\ r \end{pmatrix} = 0$ とする
  - あとは縦横の長さがそれぞれ $x,y$ となるような長方形の選び方が $(H+1-x)(W+1-y)$ 通りあることを踏まえると、 $P(x,y)$ を求めることができる
- なお $K=1$ のときのみ別扱いしないと間違った解 $2$ が出力される
  - 正しい解は $H,W$ の値にかかわらず $1$ なので最初に弾いておく
  - 入力例2があって助かったぜ……
- （公式解説）主客転倒も考えたがうまく条件を明示できなかった……これは今後の課題ということで

## G - Constrained Nim 2
- AC（30分程度？）
- 各山のGrundy数をXORしたものが $0$ なら後手勝ち、それ以外なら先手勝ちのいつものパターン
- 問題はGrundy数で、小さい $L,R$ でひたすら試したところ以下がわかった
  - 山にある石の個数を $x$ とするとき、 $x < L+R$ ならGrundy数は $\left\lfloor \frac{x}{L} \right\rfloor$ であり、以降周期 $L+R$ で同じように続く
    - すなわちGrundy数は $\left\lfloor \frac{x \bmod (L+R)}{L} \right\rfloor$ と求められる
- 8パターンほど試して例外がなかったので証明など考えずともいけるやろ！の精神で提出（おい）
