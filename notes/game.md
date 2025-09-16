# Game

## Nim
- 参考：
  -[競プロの Nim 問題まとめ (ネタバレあり) #競技プログラミング - Qiita](https://qiita.com/kobae964/items/775c10877763a65a0328)
  - [石取りゲーム(Nim)    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/game/nim)

## 互いが最適に動いたときのスコア
- ネガマックス法
  - 参考：[AtCoder ABC 201 D - Game in Momotetsu World (1Q, 水色, 400 点) - けんちょんの競プロ精進記録](https://drken1215.hatenablog.com/entry/2023/07/21/235300)
  - [ABC270 D - Stones](https://atcoder.jp/contests/abc270/tasks/abc270_d)
- 貪欲法
  - 自分の得と相手の損は等価
    - [全国統一プログラミング王決定戦予選(2019) C - Different Strokes](https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_c)
      - それぞれが交互に $A_i + B_i$ の降順に取る

## 特定の盤面にするための操作回数
- 盤面そのものをキーにしてBFS
  - [ABC224 D - 8 Puzzle on Graph](https://atcoder.jp/contests/abc224/tasks/abc224_d)

## 到達可能性
- 最終局面から逆算して初期盤面が可能かどうかを調べる
  - [AGC033 B - LRUD Game](https://atcoder.jp/contests/agc033/tasks/agc033_b)
