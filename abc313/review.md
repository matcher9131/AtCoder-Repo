# ABC313 Review
- Rated参加
- 今回はC止まり
  - 夏期講習の疲れが明らかに見える…
  - 意外にもRatingは-1で済んだ
- と思ったがAtCoder ProblemsによるとDから既に青色だった
  - ならばまぁ実力通り…なのか？

## A - To Be Saikyo
- AC
- 「単独で最大」という条件を何度もミスりそうになった
- 改めて見返すと随分と変な場合分けをしているが、実際のところは $\max \{0, \max_{2 \leq i \leq N} \{ P_{i} \} + 1 - P_1 \}$ を求めればよい

## B - Who is Saikyo?
- AC
- はじめに考えた解き方
  - `unordered_set`を用意し、順に$A_i$ を突っ込んで $B_i$ を消去する
  - セットのサイズが1なら最強がわかり、2以上ならわからないので`-1`を出力
  - 残念ながらこの方針はNG
    - $A_1 = 1, B_1 = 2, A_2 = 2, B_2 = 3$ のような順番で来られると人 $2$ がセットに残ってしまう
- いろいろ悩んだ挙句、結局有向グラフを作って探索することに
  - $N$ が少ないのをいいことに各頂点を起点とするDFSをして、すべての頂点を回ることができたら起点が最強と判断した
- 自分の解法：$O(N(N + M))$
    1. $N$ 頂点の有向グラフを作り、各 $i$ に対し $A_i$ から $B_i$ に辺を張る
    1. 各 $i (1 \leq i \leq N)$ を起点にDFSを行い、すべての頂点を訪問できたらその $i$ を出力する
    1. ↑でそのような $i$ が見つからなかった場合は`-1`を出力する
- が、後から考えるとトーナメントの考え方を用いれば良かったことに気づく
  - 勝ち残るのが1人というのはまさにトーナメントなので
  - すなわち全員を並べた`unordered_set`などを用意しておき、 $B_i$ に登場する人を消去していけばよい

## C - Approximate Equalization 2
- AC
- 直感的に全ての $A_i$ が平均値付近にならないとダメそうと気づく
- 自分の解法：$O(N)$
    1. $A_i$ の平均値 $\bar{A}$ を求め、$\bar{A}$ を整数に切り捨てたものを $L$、切り上げたものを $R$ とする
    1. $A_i \lt L$ を満たすすべての $i$ に対し $L - A_i$ を求め、その合計を $S_L$ とする
    1. $A_i \gt R$ を満たすすべての $i$ に対し $A_i - R$ を求め、その合計を $S_R$ とする
    1. $\max \{ S_L, S_R \}$ を答える
- はじめ $S_L$ と $S_R$ を分けずに $S$ として $\lfloor S / 2 \rfloor$ を答えとしたが、入力例3の答えと微妙にズレていて間違いに気づけた

## D - Odd or Even
- 時間切れ
  - コードは終了後に提出したもの
- $1 \leq i \leq N$ に対し、$i$ から始まる連続する $K$ 個の整数（ただし、$N$ を超えるときは $N$ を引く）を質問として突っ込み、隣り合う質問を比較することで1つずつ偶奇が一致するかどうかを調べることを目論見る
  - 偶奇が一致するかどうかだけを調べると厳密には2通りの $A$ が存在することになる（一方は他方の $0$ と $1$ を全て入れ替えたもの）が、$K$ が奇数であるためにいずれか1つの質問で使った項を全て足して実際に偶奇が一致するかどうかでどちらが正解なのかわかる
  - しかし残念ながらこの方法は $N$ が $K$ の倍数のとき破綻する
    - 例えば $N = 6, K = 3$ のとき、$A_1$ と $A_4$、$A_2$ と $A_5$、$A_3$ と $A_6$ しか比べられず、$A$ が一意に定まらない
- とにかく $K - 1$ 個は同じで1個のみ異なるような2つの質問の組であって、その異なる1個どうしによるペアが $1$ 以上 $N$ 以下の全ての整数を含むようにすればいいのだが、いい方法が思い浮かばない…
- ここで公式解説をチラ見
  - $i \leq K + 1$ と $K + 1 \lt i \leq N$ に分ける発想はなかった
  - 部分列への意識というのは今後も課題になりそう
- 書いたコードは公式解説のコード以外の部分を読んでそのまま書き下ろしただけなので解説は割愛
  - 公式解説のコードを見ると自分のコードがいかに泥臭いかがわかる…

## E - Duplicate
- 時間切れ
  - コードは終了後に提出したもの
- 実は解が`-1`にならない条件（`2`以上の桁が連続しない）はコンテスト中にわかっていたが時間内にまとめられなかった
- 自分の解法：$O(N)$
    - 以下、四則演算はすべて $\bmod \ 998244353$ とする
    1. $S$ を`1`以外が出現した直後で区切る
    1. ↑のそれぞれにおいて「連続する`1`の数 $c$」「その後に来る`1`以外の数 $x$」を求め、$(c, x)$ の配列 $A$ を作る
        - 文字列の末尾が`1`のときは、最後の $x$ は`0`にする
    1. 整数 $i$ に対し $A_j (j \gt i)$ を操作によってすべて消すために必要な回数を $C$ とおき、配列 $A$ を後ろから見て順に $C$ を更新していく
        - $c_i = 0$ のとき（文字列の先頭が`1`以外のときはあり得る）は単に $C \gets C + 1$
        - ↑以外のとき、「その後に来る`1`以外の数 $x$」を消すまでに $c$ が $C(x - 1)$ 個増えていることを考慮して、$C \gets C(x - 1) + x + c$
    1. $C - 1$ を出力する


