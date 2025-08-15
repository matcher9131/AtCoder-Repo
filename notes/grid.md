# Grid

## 全マス対象の操作
- 1マスの移動だけ追えばあとはすべてわかる
  - [ARC153 B - Grid Rotations](https://atcoder.jp/contests/arc153/tasks/arc153_b)

## 重ならないように配置
- あらかじめグリッドをいくつかに分けて、そこに収まるかどうかを判定
  - [ABC223 E - Placing Rectangles](https://atcoder.jp/contests/abc223/tasks/abc223_e)

## そのマスを含む行と列のマスの和
- 各行の和を $S_i$ 、各列の和を $T_j$ とし、 $T_j$ の降順に並び替えて $S_i + T_j - A_{i,j}$ を全探索。 $A_{i,j} = \min_j A_{i, j}$ ならその先の $j$ は探索不要
  - ただし打ち切りの条件は内側のループが合計で $O(N)$ しか回らないことを保証できれば何でもよい
    - [ABC298 F - Rook Score](https://atcoder.jp/contests/abc298/tasks/abc298_f)
      - 数字の書かれているマスが $N$ 個なので、打ち切り条件は「 $(i, j)$ に数字が書かれていない」でOK（最小値に拘る必要はない）
- 条件を満たすマスの個数を数えるときもほぼ同様
  - [ABC176 E - Bomber](https://atcoder.jp/contests/abc176/tasks/abc176_e)

## 特殊な操作をしながら探索するときの特殊な操作の回数
- 特殊な操作のコストを $1$ 、それ以外を $0$ としてBFS
  - [ABC213 E - Stronger Takahashi](https://atcoder.jp/contests/abc213/tasks/abc213_e)
