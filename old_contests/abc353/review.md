# [ABC353](https://atcoder.jp/contests/abc353) Review
- バーチャル参加
- 何か解けそうで解けないパターン
  - E,Fを両方落としたので2200位相当

## E - Yet Another Sigma Problem
- 時間切れ
- 文字列の比較に $O(|S|)$ かかることを失念して比較抜きで $O(N \log N)$ で行けたやろ！→勿論`TLE`
- （公式解説）Trie木は知らなんだ……
  - 参考：[トライ木(Trie木) の解説と実装【接頭辞(prefix) を利用したデータ構造】 | アルゴリズムロジック](https://algo-logic.info/trie-tree/)

## F - Tile Distance
- 時間切れ
- 概ね公式解説通りの実装だが細かいバグを潰しきれず
  - 第一象限からはみ出す移動を弾いてしまっていた
