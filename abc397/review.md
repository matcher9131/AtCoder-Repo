# [ABC397](https://atcoder.jp/contests/abc397) Review
- Rated参加
- またCまでしか解けなかったよ……
  - Ratedのときだけこうなる現象に名前をつけたい

## D - Cubes
- 時間切れ
- $x^3 - y^3 = (x-y)(x^2+xy+y^2)$ より、 $x-y=p$ とおくと $p(3y^2+3py+p^2) = N$ となる
  - $q = \frac{N}{p}$ とおくと、 $3y^2+3py+p^2 = q$ なので解の公式より $D = 12q - 3p^2$ を用いて $y = \dfrac{-3p \pm \sqrt{D}}{6}$ と表せる
    - $y$ が正の整数なので $D > 0$ かつ $D$ は平方数かつ $-3p + \sqrt{D}$ が6の倍数となればよい
- …と考えたのだが、おそらく $12q$ がオーバーフローしていることに気づかず`WA`の嵐
- そもそも **2次方程式は二分探索で解ける** ので $3y^2+3py+p^2 = q$ さえわかればよかったという

## E - Path Decomposition of a Tree
- 時間切れ
- とりあえず葉から取れるパスを貪欲に取っていく必要があるところまではわかったが、そこから具体的な処理が思い浮かばず
- （公式解説）……そもそもこれ見た目よりむずくね？
- メモ：木DP（あやふやだったので整理しておく）
  - DFSの帰りがけ順で子の情報を用いて親の情報を更新
  - 当然だが必然的に子→親の順に処理が走る
- 今回の場合「サイズ $K$ の部分木が1つのパスで繋がっているなら即切断」という処理が、該当する頂点群のなかで最も根に近いものの部分木のサイズを $0$ にするだけになり簡明
  - 子の個数カウントの際も部分木のサイズが $0$ のものをスキップするようにすればグラフを弄る必要がまったくない
