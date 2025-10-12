import * as fs from "fs";

const [n, m, ...a] = fs.readFileSync("/dev/stdin", "utf8").split(/\s/).filter(s => s.length > 0).map(s => parseInt(s, 10));

const fMap = [new Map<number, number>(), new Map<number, number>()];
const dfs = (last: number, cur: number): void => {
    const j = last == (n>>1) - 1 ? 1 : 0;
    const k = cur % m;
    fMap[j].set(k, (fMap[j].get(k) ?? 0) + 1);
    for (let i = last + 2; i < (n>>1); ++i) {
        dfs(i, cur + a[i]);
    }
};
dfs(-2, 0);

const lMap = [new Map<number, number>(), new Map<number, number>()];
const dfs2 = (last: number, cur: number, containsFirst: boolean): void => {
    const j = containsFirst ? 1 : 0;
    const k = cur % m;
    lMap[j].set(k, (lMap[j].get(k) ?? 0) + 1);
    for (let i = last + 2; i < n; ++i) {
        dfs2(i, cur + a[i], containsFirst || i == (n>>1));
    }
};
dfs2((n>>1) - 2, 0, false);

let ans = 0;
for (const [r, c] of fMap[0]) {
    const rr = r == 0 ? 0 : m-r;
    ans += c * ((lMap[0].get(rr) ?? 0) + (lMap[1].get(rr) ?? 0));
}
for (const [r, c] of fMap[1]) {
    const rr = r == 0 ? 0 : m-r;
    ans += c * (lMap[0].get(rr) ?? 0);
}
console.log(ans);