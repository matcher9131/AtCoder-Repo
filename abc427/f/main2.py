n, m = map(int, input().split())
a = list(map(int, input().split()))

fMap = [{}, {}]
def dfs(last, cur):
    j = last == n//2 - 1
    if cur%m not in fMap[j]:
        fMap[j][cur%m] = 0
    fMap[last == n//2 - 1][cur%m] += 1
    for i in range(last+2, n//2):
        dfs(i, cur + a[i])
dfs(-2, 0)

lMap = [{}, {}]
def dfs2(last, cur, containsFirst):
    if cur%m not in lMap[containsFirst]:
        lMap[containsFirst][cur%m] = 0
    lMap[containsFirst][cur%m] += 1
    for i in range(last+2, n):
        dfs2(i, cur + a[i], containsFirst or i == n//2)
dfs2(n//2 - 2, 0, False)

ans = 0
for r, c in fMap[0].items():
    rr = 0 if r == 0 else m-r
    ans += c * (lMap[0].get(rr, 0) + lMap[1].get(rr, 0))
for r, c in fMap[1].items():
    rr = 0 if r == 0 else m-r
    ans += c * lMap[0].get(rr, 0)

print(ans)
