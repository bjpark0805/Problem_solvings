import sys 
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	meetings = []
	for _ in range(N):
		meetings.append(list(map(int, input().split())))
	meetings.sort(key=lambda x: (x[1], x[0]))
	last_end, n = 0, 0
	for i in range(N):
		if meetings[i][0] >= last_end:
			n += 1
			last_end = meetings[i][1]

	print(n)

main()