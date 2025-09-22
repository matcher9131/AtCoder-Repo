# Grid

## 全マス対象の操作
- 1マスの移動だけ追えばあとはすべてわかる
  - [ARC153 B - Grid Rotations](https://atcoder.jp/contests/arc153/tasks/arc153_b)

## 重ならないように配置
- あらかじめグリッドをいくつかに分けて、そこに収まるかどうかを判定
  - [ABC223 E - Placing Rectangles](https://atcoder.jp/contests/abc223/tasks/abc223_e)

## そのマスを含む行と列のマスの和の最大値
- 各行の和を $S_i$ 、各列の和を $T_j$ とし、 $T_j$ の降順に並び替えて $S_i + T_j - A_{i,j}$ を全探索。 $A_{i,j} = \min_j A_{i, j}$ ならその先の $j$ は探索不要
  - ただし打ち切りの条件は内側のループが合計で $O(N)$ しか回らないことを保証できれば何でもよい
    - [ABC298 F - Rook Score](https://atcoder.jp/contests/abc298/tasks/abc298_f)
      - 数字の書かれているマスが $N$ 個なので、打ち切り条件は「 $(i, j)$ に数字が書かれていない」でOK（最小値に拘る必要はない）
- 条件を満たすマスの個数を数えるときもほぼ同様
  - [ABC176 E - Bomber](https://atcoder.jp/contests/abc176/tasks/abc176_e)

## そのマスを含む行と列のマスの和（ちょうど）
- 「 $N$ マスにしか数字がかかれていない」かつ「和が $K$ ちょうどになる個数を数える」なら↑とは異なりソート不要
  - 一旦全マスが空白だとして $S_i + T_j = K$ を満たす $(i,j)$ の個数を数え、数字が書かれた各マスに対して $S_i + T_j = K + A_{i,j}$ なら解を増やし、 $S_i + T_j = K$ なら解を減らす
    - [ABC023 C - 収集王](https://atcoder.jp/contests/abc023/tasks/abc023_c)

## 特殊な操作をしながら探索するときの特殊な操作の回数
- 特殊な操作のコストを $1$ 、それ以外を $0$ としてBFS
  - [ABC213 E - Stronger Takahashi](https://atcoder.jp/contests/abc213/tasks/abc213_e)

## 正方形グリッドで右か下へのみ移動する経路を全探索
- 前半と後半に分けるとそれぞれ $O(2^N)$ 通り
  - [ABC271 F - XOR on Grid Path](https://atcoder.jp/contests/abc271/tasks/abc271_f)

## 次に訪れるべきマスが今まで訪れたマスの全ての近傍となる条件でバックトラッキング
- 毎度次に訪れるべきマスを探索する
  - [ABC211 E - Red Polyomino](https://atcoder.jp/contests/abc211/tasks/abc211_e)
