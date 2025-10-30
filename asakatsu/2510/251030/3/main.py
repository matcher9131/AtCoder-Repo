import re

s = input()
pattern = re.compile("^A?KIHA?BA?RA?$")
result = pattern.match(s)
if result:
    print("YES")
else:
    print("NO")
