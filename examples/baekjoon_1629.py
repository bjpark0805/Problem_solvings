import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())
def recmul(A, B, C):
	"""
	Recurvie version
	"""
	if B == 1:
		return A
	n = A if B % 2 else 1
	return (n * (recmul(A, B//2, C)%C)**2)%C

def main():
	A, B, C = map(int, input().split())
	A, ans, rest = A%C, A%C, 1
	print(recmul(A, B, C))
	while B > 1:
		print(ans)
		if B % 2:
			rest, B = (rest*ans)%C, B - 1
		ans, B = (ans ** 2)%C, B//2
	print((ans*rest)%C)


main()