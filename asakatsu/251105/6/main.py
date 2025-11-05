from decimal import *
from math import sqrt;

getcontext().prec = 21
x0, y0, r = map(Decimal, input().split())

left = int((x0 - r).quantize(Decimal("1"), rounding=ROUND_CEILING))
right = int((x0 + r).quantize(Decimal("1"), rounding=ROUND_FLOOR))

ans = 0
for x in range(left, right+1):
    dx = x - x0
    dy = (r * r - dx * dx).sqrt()
    bottom = (y0 - dy).quantize(Decimal("1"), rounding=ROUND_CEILING)
    top = (y0 + dy).quantize(Decimal("1"), rounding=ROUND_FLOOR)
    ans += int((top - bottom).to_integral_value()) + 1

print(ans)
