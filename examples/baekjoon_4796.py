import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	i = 1
	while True:
		L, P, V = list(map(int, input().split()))
		if not L and not P and not V:
			break
		print('Case {}: {}'.format(i, V//P * L + min(V%P, L)))
		i += 1

main()