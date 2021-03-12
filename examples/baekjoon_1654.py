import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	K, N = map(int, input().split())
	LAN = [input(int) for _ in range(K)]
	m = min(LAN)
	minv, maxv = m//(N//K + 1), max(m, max(LAN)//N)
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		cnt = 0
		for l in LAN:
			cnt += l // midv
		if cnt >= N:
			minv = midv
		else:
			maxv = midv - 1

	cnt = 0
	for l in LAN:
		cnt += l // maxv
	if cnt >= N:
		minv = maxv
		
	print(minv)

main()