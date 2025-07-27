# Graph

## 最短経路に含まれる/含まれない辺を列挙
- 含まれるなら $d(u, v) = E_{u,v}$ が成り立つ
  - [ABC051 D - Candidates of No Shortest Paths](https://atcoder.jp/contests/abc051/tasks/abc051_d)

## 数列 $A_i$ を $P_{A_i}$ に置き換え
- Functional graph
  - [ABC296 E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)
- 特に $P$ が $(1,2, \dots, N)$ の並び替えならサイクルしか持たないグラフになる
  - [ABC175 D - Moving Piece](https://atcoder.jp/contests/abc175/tasks/abc175_d)

## 通る辺の順番に制約
- 辺に対してDP
  - [ABC271 E - Subsequence Path](https://atcoder.jp/contests/abc271/tasks/abc271_e)

## 辺を削除
- 場合によっては入次数、出次数の管理だけでOKにできる
  - [全国統一プログラミング王決定戦予選(2019) D - Restore the Tree](https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d)

## 頂点に値を書き込みながら/色を塗りながら辺を追加して矛盾がないかを調べる
- Weighted Union-find tree
  - [ABC087 D - People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)
  - [ABC328 F - Good Set Query](https://atcoder.jp/contests/abc328/tasks/abc328_f)

## 単純パスを全て網羅する
- $V$ が小さいなら「訪れた頂点集合」 「最後に訪れた頂点」で2要素DP
  - [ABC274 E - Booster](https://atcoder.jp/contests/abc274/tasks/abc274_e)
  - [ABC278 F - Shiritori](https://atcoder.jp/contests/abc278/tasks/abc278_f)
- $V$ が小さくないなら明らかに損なパスを排除
  - 例：ある程度右/左まで行って折り返す以外の移動は不利
    - [ABC095 D - Static Sushi](https://atcoder.jp/contests/abc095/tasks/arc096_b)
    - [ABC197 E - Traveler](https://atcoder.jp/contests/abc197/tasks/abc197_e)

## 辺の最短パスの寄与
- $d(u, v) = x$ を考えるときは $x$ より長い辺は存在しなくても問題ない
  - [ABC214 D - Sum of Maximum Weights](https://atcoder.jp/contests/abc214/tasks/abc214_d)
