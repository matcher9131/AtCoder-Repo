# [ABC399](https://atcoder.jp/contests/abc399) Review
- Rated参加
- まさかの483位でここ3回の負け分を一気に取り戻す
  - 取っ掛かりがよくわからないEを早々にスキップしてFでシグマを捏ね繰り回したのが功を奏した
  - 結果的にEがクソ難しかったので正解

## C - Make it Forest
- AC(7分)
- 単純無向グラフが森
  - $\Leftrightarrow$ 閉路を含まない
  - $\Leftrightarrow$ すべての連結成分が木
  - $\Leftrightarrow$ すべての連結成分において、その頂点数を $|V_i|$ とすると辺数が $|V_i| - 1$
- 連結無向グラフが $|E| \geq |V|$ を満たすとき、 $|E| - |V| + 1$ 本の辺をうまく選んで消去すれば必ず木になる

## D - Switch Seats
- AC(16分+1WA)
- $i = 1, 2, \dots, N-3$ の順に以下を行う
  - $A_i = X, A_{i+1} = Y$ とおく
  - 以下のいずれかを満たす場合はスキップして次の $i$ へ
      1. $X = Y$
      2. $X$ が既に登場している、すなわち $A_j = X$ を満たす $j < i$ が存在する
      3. $A_{i+2} = Y$ 
  - $A_j = X, j \neq i$ および $A_k = Y, k \neq i+1$ を満たす $j, k$ に対し、 $|j - k| = 1$ ならばカウントを1つ増やす
- なおスキップ条件の3つ目（`abba`になるパターン）を除外し忘れて1敗
  - かなりの数のテストケースが通っていなかったので他に原因があるのではないかとヒヤヒヤしながら提出するも無事`AC`
  - 入力が長くなればなるほど`abba`の並びが出現する可能性は高くなるので別におかしい話ではなかった

## E - Replace
- 時間切れ
- （公式解説）…ムズすぎィ！
  - サイクルのみの連結成分とサイクル以外の頂点を含む連結成分で扱いが異なるのは聞いてないっすよ…

## F - Range Power Sum
- AC(36分)
- $A$ の累積和を $S$ （ただし、 $S_0 = 0$ ）とおいて、シグマを変形していく
$$
    \begin{aligned}
        \sum_{i=1}^N \sum_{j=i}^N \left( \sum_{k=i}^j A_k \right)^K &= \sum_{i=1}^N \sum_{j=i}^N (S_j - S_{i-1})^K \\
        &= \sum_{i=0}^{N-1} \sum_{j=i}^N (S_j - S_i)^K \\
        &= \sum_{i=0}^{N-1} \sum_{j=i}^N \sum_{r=0}^K \begin{pmatrix} K \\ r \end{pmatrix} S_j^{K-r} (-S_i)^r \\
        &= \sum_{r=0}^K \begin{pmatrix} K \\ r \end{pmatrix} \sum_{i=0}^{N-1} \left( \sum_{j=i}^N S_j^{K-r} \right)  (-S_i)^r
    \end{aligned}
$$
- ここで ${\displaystyle \sum_{i=0}^{N-1} \left( \sum_{j=i}^N S_j^{K-r} \right)  (-S_i)^r }$ に関して、足す順番を $i = N-1, N-2, \dots, 1, 0$ にすることで ${\displaystyle \sum_{j=i}^N S_j^{K-r} }$ は順番に計算できる
  - $x^y \bmod P$ が $O(\log P)$ であることを踏まえると $O(N \log P)$ で計算できる
  - よって全体の時間計算量は $O(NK (\log P)^2)$ で十分間に合う
