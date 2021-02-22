import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	L, N, rF, rB = list(map(int, input().split()))
	grass = []
	for _ in range(N):
		x, c = list(map(int, input().split()))
		t = x * (rF - rB)
		grass.append((c, t))
	grass.sort(reverse = True)
	last_time, taste = 0, 0
	for i in range(len(grass)):
		if grass[i][1] >= last_time:
			taste += (grass[i][1] - last_time) * grass[i][0]
			last_time = grass[i][1]
	print(taste)

main()