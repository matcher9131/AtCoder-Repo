# Graph

## 用語
- オイラー路
  - すべての辺を1度ずつ通るパス
- ハミルトン路
  - 全頂点を通るパス
    - 「通った頂点の集合」 「今いる頂点」で2要素bit DP
- Functional graph
  - 全頂点の出次数が $1$ の有向グラフ

## 単にDFS/BFSすれば良さそうだが辺の数が多すぎる
- **超頂点**
  - [ABC302 F - Merge Set](https://atcoder.jp/contests/abc302/tasks/abc302_f)

## 最短経路に含まれる/含まれない辺を列挙
- 含まれるなら $d(u, v) = E_{u,v}$ が成り立つ
  - [ABC051 D - Candidates of No Shortest Paths](https://atcoder.jp/contests/abc051/tasks/abc051_d)

## 数列 $A_i$ を $P_{A_i}$ に置き換え
- Functional graph
  - [ABC296 E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)
- 特に $P$ が $(1,2, \dots, N)$ の並び替えならサイクルしか持たないグラフになる
  - [ABC175 D - Moving Piece](https://atcoder.jp/contests/abc175/tasks/abc175_d)

## 通る辺の順番に制約
- 辺列に対してDP
  - [ABC271 E - Subsequence Path](https://atcoder.jp/contests/abc271/tasks/abc271_e)

## 辺を削除
- 場合によっては入次数、出次数の管理だけでOKにできる
  - [全国統一プログラミング王決定戦予選(2019) D - Restore the Tree](https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d)
- 辺数によっては実際に削除するのが良いときもある
  - [ABC302 E - Isolation](https://atcoder.jp/contests/abc302/tasks/abc302_e)

## 頂点に値を書き込みながら/色を塗りながら辺を追加して矛盾がないかを調べる
- Weighted Union-find tree
  - [ABC087 D - People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)
  - [ABC328 F - Good Set Query](https://atcoder.jp/contests/abc328/tasks/abc328_f)

## 単純パスを全て網羅する
- $V$ が小さいなら「訪れた頂点集合」 「最後に訪れた頂点」で2要素DP
  - 初期値に注意（`dp[0]`が無効な状態かも）
  - [ABC274 E - Booster](https://atcoder.jp/contests/abc274/tasks/abc274_e)
  - [ABC278 F - Shiritori](https://atcoder.jp/contests/abc278/tasks/abc278_f)
  - [ABC301 E - Pac-Takahashi](https://atcoder.jp/contests/abc301/tasks/abc301_e)
- $V$ が小さくないなら明らかに損なパスを排除
  - 例：ある程度右/左まで行って折り返す以外の移動は不利
    - [ABC095 D - Static Sushi](https://atcoder.jp/contests/abc095/tasks/arc096_b)
    - [ABC197 E - Traveler](https://atcoder.jp/contests/abc197/tasks/abc197_e)

## 辺の最短パスへの寄与
- $d(u, v) = x$ を考えるときは $x$ より長い辺は存在しなくても問題ない
  - [ABC214 D - Sum of Maximum Weights](https://atcoder.jp/contests/abc214/tasks/abc214_d)

## ある2頂点が連結かどうかの条件が複数
- 頂点を（Union-find treeにおける）その頂点を含む連結成分の代表に置き換える

## 有向グラフで他の全頂点へ到達できるような頂点が存在するかどうかを判断する
- $O(V^3)$ が間に合うならFloyd-Warshallでいい
  - [ABC257 D - Jumping Takahashi 2](https://atcoder.jp/contests/abc257/tasks/abc257_d)
- 強連結成分をトポロジカルソートして、根となる強連結成分内の1頂点から他の全頂点へ到達可能かをDFSで探索
  - `atcoder::scc`を使えば $O(V+E)$

## 負辺を含み負閉路を含まないグラフで全頂点間の最短距離をDijkstraで求める
- ポテンシャル（参考：[ダイクストラとポテンシャルのはなし - niuez’s diary](https://niuez.hatenablog.com/entry/2019/03/04/142903)）
  - 頂点 $1$ から全頂点への最短距離をBellman-Fordで求めることによりポテンシャルを求め、残りはDijkstraで求める
  - 標高のようなポテンシャルがあらかじめ与えられている場合はそれをそのまま使うことによりいきなりDijkstraでOK
    - [ABC237 E - Skiing](https://atcoder.jp/contests/abc237/tasks/abc237_e)

## 頂点 $v$ から「ある条件」を満たす頂点 $u$ までの距離の最小値が $d$
- $v$ から距離 $d$ 未満のすべての頂点は「ある条件」を満たさない、かつ距離 $d$ の頂点の少なくとも1つが「ある条件」を満たす
  - [ABC299 E - Nearest Black Vertex](https://atcoder.jp/contests/abc299/tasks/abc299_e)

## Functional Graphで $K$ 回辺を辿る

```cpp
// vector<ll> child;
// atcoder::scc_graph g;

auto groups = g.scc();
// 頂点から強連結成分のインデックスを逆引き
vector<int> gi_dict(n);
for (int gi = 0; gi < groups.size(); ++gi) {
    for (const int v : groups[gi]) {
        gi_dict[v] = gi;
    }
}

int cur = root;
while (k > 0) {
    int gi = gi_dict[cur];
    int group_size = groups[gi].size();
    if (group_size > 1) {
        // サイクル
        int q = k / group_size, r = k % group_size;
        // TODO: qを用いてansを更新
        while (r--) {
            // TODO: ansを更新
            cur = child[cur];
        }
        break;
    } else if (child[cur] == cur) {
        // 自己ループ
        // TODO: kを用いてansを更新
        break;
    } else {
        // TODO: ansを更新
        cur = child[cur];
        --k;
    }
}

```

- [ABC241 E - Putting Candies](https://atcoder.jp/contests/abc241/tasks/abc241_e)

## 探索中にグラフ全体が変化する
- 変化が一定でバリエーションが少ないなら並行世界
  - [ABC420 D - Toggle Maze](https://atcoder.jp/contests/abc420/tasks/abc420_d)

## 木でパスの長さがDになるような頂点組 $(i, j)$ を考える
-　$(i,j)$ に注目するのではなく $i, j$ のLCAに注目する
  - [ABC220 E - Distance on Large Perfect Binary Tree](https://atcoder.jp/contests/abc220/tasks/abc220_e)

## 木の構造は変化しないが、辺の重みが途中で変化する
- オイラーツアーによるタイムスタンプとLazy segment treeの組み合わせ
  - [ABC294 G - Distance Queries on a Tree](https://atcoder.jp/contests/abc294/tasks/abc294_g)

## 頂点の重みと辺の重みの合計を考慮する
- 超頂点を追加して頂点の重みを辺の重みに変換する
  - [ARC029 C - 高橋君と国家](https://atcoder.jp/contests/arc029/tasks/arc029_3)

## 頂点集合からそれぞれの隣接頂点のうちある条件を満たすものに対して一斉に操作することを繰り返す
- BFSでキューが空になるまで対象となる頂点を一時領域においておき、その後一斉に操作してキューに放り込む
  - [ABC425 D - Ulam-Warburton Automaton](https://atcoder.jp/contests/abc425/tasks/abc425_d)
