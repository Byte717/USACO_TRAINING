t = int(input())
for _ in range(t):
    a = input().strip()
    if(len(a)) < 3:
        print("NO")
        continue
    b = a[2:]
    if a.startswith("10") and b[0] != '0' and int(b) >= 2:
        print("YES")
    else:
        print("NO")
