import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	assn = []
	schedule = [0]*1001
	for _ in range(N):
		assn.append(list(map(int, input().split())))
	assn.sort(key=lambda x:(x[1], x[0]), reverse = True)

	for i in range(len(assn)):
		for j in range(assn[i][0], 0, -1):
			if schedule[j] == 0:
				schedule[j] = assn[i][1]
				break
	print(sum(schedule))
main()
		