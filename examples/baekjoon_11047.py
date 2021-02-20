import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, K = list(map(int, input().split()))
	A = []
	for _ in range(N):
		A.append(input(int))
	A.sort(reverse = True)
	i, n = 0, 0
	while i < N:
		n += K//A[i]
		K %= A[i]
		i += 1
		if K == 0:
			break
	print(n)
	
main()