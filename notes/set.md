# Set

## 集合の一致
- Zobrist hashing
  - 単なる集合ならXOR
    - [ABC250 E - Prefix Equality](https://atcoder.jp/contests/abc250/tasks/abc250_e)
  - 多重集合なら加算
    - [ABC367 F - Rearrange Query](https://atcoder.jp/contests/abc367/tasks/abc367_f)

## Mex
- 要素数 $N$ の集合のMexは $0$ 以上 $N$ 以下なので、この範囲で $A_i = k$ となる $i$ の個数を管理
  - [ABC272 E - Add and Mex](https://atcoder.jp/contests/abc272/tasks/abc272_e)

## ビット列で表される集合においてある集合の部分集合を列挙する

```cpp
ll y = x;
while (true) {
  // ここで何か操作
  if (y == 0) break;
  y = (y-1) & x;
}
```
