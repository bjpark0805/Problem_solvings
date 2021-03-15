import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, k = map(int, input().split())
	circle = [i for i in range(1, N+1)]
	curr, ans = 0, []
	while circle:
		n = len(circle)
		d = (curr + k - 1)%n
		ans.append(circle[d])
		del circle[d]
		if n != 1:
			curr = d%(n-1)
	print('<', end='')
	for a in ans[:-1]:
		print('{},'.format(a), end = ' ')
	print('{}>'.format(ans[-1]))
		
main()