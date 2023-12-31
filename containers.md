## C++ STLコンテナ 計算量の比較

- メソッドはすべてメンバ関数のもの
- 平均計算量を記載
- capacityは事前に十分な量を確保しているものとする
- insert, eraseともに（複数ではなく）単一の要素を処理するものとする
- erase(val)：単一の値を引数に指定
- erase(it)：単一のイテレータを引数に指定

| コンテナ | begin | end | push_back | push_front | insert | erase(val) | erase(it) | find |
|-|-|-|-|-|-|-|-|-|
| vector | $O(1)$ | $O(1)$ | $O(1)$ | $O(N)$ ※1 | $O(N)$ | $O(N)$ ※1 | $O(N)$ | $O(N)$ ※1 |
| set | $O(\log N)$ | $O(\log N)$ | - | - | $O(\log N)$ | $O(\log N)$ | $O(1)$ | $O(\log N)$ |
| unordered_set | $O(1)$ | $O(1)$ | - | - | $O(1)$ ※2 | $O(1)$ ※2 | $O(1)$ ※2 | $O(1)$ ※2 |
| map | $O(\log N)$ | $O(\log N)$ | - | - | $O(\log N)$ | $O(\log N)$ | $O(1)$ | $O(\log N)$ |
| unordered_map | $O(1)$ | $O(1)$ | - | - | $O(1)$ ※2 | $O(1)$ ※2 | $O(1)$ ※2 | $O(1)$ ※2 |
| list | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ ※1 | $O(1)$ | $O(N)$ ※1 |
| deque | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | $O(N)$ ※3 | $O(N)$ ※1,3 | $O(N)$ ※3 | $O(N)$ ※1 |

- ※1：メンバ関数としては存在しないため、同様のことを実現するコードを書いた場合の計算量を記載
- ※2：最悪 $O(N)$
- ※3：ライブラリの実装次第