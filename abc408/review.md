# [ABC408](https://atcoder.jp/contests/abc408) Review
- Rated参加
- E以降が解けず爆死
  - 同日朝にABC343をバーチャル参加して最高順位相当を叩き出したから逆にちょっと嫌な予感はしてたんだよなぁ…
- さようならレート1400台……また会う日まで……

## D - Flip to Gather
- AC（37分）
- 時間かかりすぎィ！
- `1`の連続する区間それぞれについて、左から順に`0`にするか`1`のままにするかをDPで選んでいけばよいのだが
  - `1`のままにした区間が左にあり、その右に`0`にした区間が存在する状態で今考えている区間を`1`にするような操作はできない
    - これを回避するのに思いっきり悩んでしまった
- 結局以下の3つの状態を導入することでDP遷移を実現した
  - 状態1: `00 ... 00`
    - 直前の状態1からのみ遷移可
  - 状態2: `00 ... 11`
    - 直前の状態1,2から遷移可
  - 状態3: `00 ... 11 ... 00`
    - 直前の状態2,3から遷移可
- （公式解説）区間なんて持ち出さなくても $l,r$ 決め打ちでいいのか……頭が固い！

## E - Minimum OR Path
- 時間切れ
- 上位ビットから順にDFSを繰り返すことはわかったが
  - 条件を間違えて全く正しい答えがでなかった
- 正しくは公式解説にある通り以下の通り、 $x = 2^{30} - 1$ から始めて $i$ ビット目を折った $x'$ について $w \mathrm{OR} x' = x'$ を満たす辺のみでDFSをして到達可能なら $x$ の $i$ ビット目も折るという操作になるが
  - $x = 0$ から始めて $i$ ビット目を立てて $w \mathrm{AND} x'$ が0でない辺のみでDFSをして到達不可能なら $x$ の $i$ ビット目を立てるとしていた
    - なにもかも逆で愕然とした……
    