for _ in range(int(input())):
	n = int(input())
	s = input()
	print("YES" if list(s) == sorted(s) else "NO")