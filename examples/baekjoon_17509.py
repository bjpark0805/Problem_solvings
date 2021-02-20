import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	problems = []
	for _ in range(11):
		problems.append(list(map(int, input().split())))
	problems.sort(key=lambda x: x[0])
	T, penalty = 0, 0
	for i in range(len(problems)):
		T += problems[i][0]
		penalty += T + 20 * problems[i][1]
	print(penalty)
	
main()