import math

N = int(input())
P = 1 + 8 * N
p = int(math.sqrt(P))
if p * p == P:
    print("YES")
    print((p - 1) // 2)
else:
    print("NO")