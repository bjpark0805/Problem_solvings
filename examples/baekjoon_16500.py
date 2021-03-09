import sys
from functools import lru_cache
def input(_type=str):
	return _type(sys.stdin.readline().strip())

S = ""
A = []

@lru_cache(None)
def recString(k):
	if k == 0:
		return 1
	ans = 0
	for a in A:
		if a == S[k-len(a):k]:
			ans |= recString(k-len(a))
	return ans

def main():
	global S, A
	S = input()
	N = input(int)
	for _ in range(N):
		tmp = input()
		if tmp in S:
			A.append(tmp)

	print(recString(len(S)))

main()