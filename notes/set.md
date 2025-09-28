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


## 区別のつく要素を区別しないグループに分ける
- 分け方の場合の数のみが必要なら第二種スターリング数
  - 参考： [スターリング数の漸化式と3つの意味 | 高校数学の美しい物語](https://manabitimes.jp/math/841)
- 「グループに割り振った要素の集合」 「グループの個数」の2要素bit DPを検討する
  - 遷移の際に部分集合の部分集合を列挙することになるが全体で $O(3^N)$
    - [競プロ典型 90 問 045 - Simple Grouping（★6）](https://atcoder.jp/contests/typical90/tasks/typical90_as)

