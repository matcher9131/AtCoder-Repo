# [ABC368](https://atcoder.jp/contests/abc368) Review
- バーチャル参加
- Fが解けたと思ったらお前緑色かい！
  - んでEが黄色かい！
    - さらにGが青色かい！

## C - Triple Attack
- AC
- 基本的には3回殴って $T \gets T + 3, H_i \gets H_i - 5$ の繰り返し
- ただし端数処理が面倒
  - こういうのいつも一発で通るかヒヤヒヤするんだよなぁ…

## D - Minimum Steiner Tree
- AC
- $K$ 個の頂点の最小共通祖先 is 何？
  - 2個ならやり方は知っているんだが…
- しかし深い順に親を列挙していけばそのうち $K$ 個の頂点の最小共通祖先に行き着くことに気づく
  - あとは計算量に気をつけてこれを形にするのみ
- 頂点 $0$ を根とする根付き木として、DFSで各頂点に対して以下を記録する
  - 深さ
  - 親となる頂点番号
- 指定された $K$ 個の頂点からなる集合 $S$ を用意し、未チェックの頂点がちょうど1個になるまで以下を繰り返し行う。操作が終わったときの $|S|$ が解となる
    1. $S$ の要素のうちもっとも深い頂点の1つ（複数ある場合はどれでもよい）を $V_C$ とする
    2. $V_C$ の親となる頂点 $V_P$ について、 $V_P \notin S$ ならば $S \gets S \cup \{ V_P \}$ とする
    3. $V_C$ をチェック済みにする
- 未チェックの頂点がなくなるまで↑を行うと、 $K$ 個の頂点の最小共通祖先が根でないときに余分な頂点を含んでしまうので注意
  - サンプルにこのパターンがなかったが、自分でテストケースを作ることで間違いに気づいた
    - chokudai社長曰くテストケースを作る能力も競プロの実力の内らしいので、これは嬉しい成長
- 実装の際は未チェックの頂点のみを管理する`priority_queue`と $S$ を管理する`unordered_set`を用いた
  - 計算量は $O(N \log N)$
- （公式解説）ユーザー解説含む4つの解法と自分のが全く異なってて草

## E - Train Delay
- 時間切れ
- 各列車の発車時刻および到着時刻の $2M$ 個を昇順で管理することは思いついたが
  - そこから無駄に有向グラフを生やしてしまい失敗
    - 発車時刻と到着時刻を共通して管理するというのはどこかの問題で見たパターンだったし、同時刻に到着と出発が重なる際は到着を優先すべきところまではわかっていたので、その点だけは褒めたい
- 電車 $i$ に乗り継げるのは時刻 $S_i$ までに駅 $A_i$ に本来なら到着しているはずの電車なので、時刻 $S_i$ において本来なら $T_j \leq S_i$ となる電車のうち実際に到着するのが最も遅いものだけを記録すれば $X_i$ を決定できる
  - なので乗り継ぎ関係をグラフにして全探索する必要はなかった

## F - Dividing Game
- AC
- Nimの変則バージョンだよなぁと思いつつ
  - Nimの基本的な考え方は[石取りゲーム(Nim)    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/game/nim#grundy%E6%95%B0%E3%81%AB%E3%82%88%E3%82%8B%E4%B8%80%E8%88%AC%E5%8C%96)にわかりやすくまとめられている
- 非負整数 $n$ のGrundy数を $G_n$ と表すことにすると、 $G_n = \mathrm{mex} \{ G_m | m \text{は} n \text{の正の約数}, m \neq n \}$ となる
  - $n$ 自身を除く $n$ の正の約数は必ず $n$ より小さいことから、 $G_1 = 0$ として $n = 2, 3, \dots $ と順に $G_n$ を求めていくことができる
    - $\mathrm{mex}$ に関して、 $G_n$ は $n$ の正の約数の個数を超えないことと、 $A_i \leq 10^5$ より約数の個数がべらぼうに多くなることはないので、 $G_m = k$ となる $m$ が存在するかどうかを $k$ を添え字にした適当な配列（要素数 $K$ ）で記録することで計算量 $O(K)$ で求められる
- $2 \cdot 3 \cdot 5 \cdot 7 \cdot 11 \cdot 13 \cdot 17 > 10^5$ よりせいぜい正の約数は100個だろうと高をくくって $K = 100$ としたが
  - $83160$ の正の約数の個数が $126$ なので想定としては危険
    - 実際には $G_n$ は $n$ の正の約数の個数より遥かに小さくなるので問題はない( $G_{83160} = 9$ )が、しっかり検討すべき
- あとは恒例の $G_{A_1} \oplus G_{A_2} \oplus \dots \oplus G_{A_N}$ が $0$ ならば後手勝ち、それ以外なら先手勝ちで判断すればOK
- 計算量は $A_i$ の最大値を $A$ として $O(\max \{ KA\sqrt{A}, N \})$