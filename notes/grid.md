# Grid

## 全マス対象の操作
- 1マスの移動だけ追えばあとはすべてわかる
  - [ARC153 B - Grid Rotations](https://atcoder.jp/contests/arc153/tasks/arc153_b)

## 重ならないように配置
- あらかじめグリッドをいくつかに分けて、そこに収まるかどうかを判定
  - [ABC223 E - Placing Rectangles](https://atcoder.jp/contests/abc223/tasks/abc223_e)

## そのマスを含む行と列のマスの和
- $i$ を固定したとき、 $S_j$ の降順に並び替えて $S_i + S_j - A_{i,j}$ を探索。 $A_{i,j} = \min_i A_{i, j}$ ならその先は探索不要
  - [ABC298 F - Rook Score](https://atcoder.jp/contests/abc298/tasks/abc298_f)
- 条件を満たすマスの個数を数えるときもほぼ同様
  - [ABC176 E - Bomber](https://atcoder.jp/contests/abc176/tasks/abc176_e)

## 特殊な操作をしながら探索するときの特殊な操作の回数
- 特殊な操作のコストを $1$ 、それ以外を $0$ としてBFS
  - [ABC213 E - Stronger Takahashi](https://atcoder.jp/contests/abc213/tasks/abc213_e)
