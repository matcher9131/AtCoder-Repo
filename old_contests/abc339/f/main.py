from bisect import bisect_left, bisect_right

n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
ans = 0
for i in range(n):
    for j in range(i, n):
        expected = a[i] * a[j]
        if expected > a[n-1]:
            break
        l = bisect_left(a, expected)
        r = bisect_right(a, expected)
        ans += (r - l) * 2 if i != j else r - l

print(ans)
