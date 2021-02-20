import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, L = list(map(int, input().split()))
	coor = list(map(int, input().split()))
	coor.sort()
	i, end_L, ans = 0, 0, 0
	while i < N:
		if coor[i] > end_L:
			end_L = coor[i]-0.5+L
			ans += 1
		i += 1
	print(ans)

main()