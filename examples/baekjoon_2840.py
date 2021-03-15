import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, K = map(int, input().split())
	ans, curr, impossible = ["?"] * N, 0, False
	for _ in range(K):
		S, ch = input().split()
		S = int(S)
		curr = (curr - S)%N
		if (ans[curr] != "?" and ans[curr] != ch) or (ch in ans and ans.index(ch) != curr):
			impossible = True
		ans[curr] = ch

	if impossible:
		print('!')
	else:
		print(''.join(ans[curr:])+''.join(ans[:curr]))

main()