import math

T = int(input())
for t in range(T):
    N, L = map(int, input().split())
    C = list(map(int, input().split()))
    idx = 0
    tmp = 0
    for i in range(L):
        if C[i] != C[i+1]:
            tmp = math.gcd(C[i], C[i+1])
            idx = i
            break
    while idx >= 0:
        tmp = int(C[idx] // tmp)
        idx -= 1
    c = [tmp]
    s = [tmp]
    for i in range(L):
        tmp = int(C[i] // tmp)
        c.append(tmp)
        if not tmp in s:
            s.append(tmp)
    s.sort()
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    y = ""
    for code in c:
        y += alphabet[s.index(code)]
    print("Case #" + str(t+1) + ": " + y)