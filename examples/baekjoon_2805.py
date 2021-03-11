import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, M = map(int, input().split())
	H = list(map(int, input().split()))
	minh, maxh = 0, max(H)
	while minh + 1 < maxh:
		# print(minh, maxh)
		midh = (minh + maxh)//2
		tmp = sum([h - midh if h >= midh else 0 for h in H])
		if tmp >= M:
			minh = midh
		else:
			maxh = midh - 1
	if sum([h - maxh if h >= maxh else 0 for h in H]) >= M:
		minh = maxh
	print(minh)
main()