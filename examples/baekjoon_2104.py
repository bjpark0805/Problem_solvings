import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())
def main():
	N = input(int)
	A = list(map(int, input().split()))
	def recSum(s, e):
		if s == e:
			return A[s]**2
		m = (s+e)//2
		i1, i2, minv, sumv, score = m, m, A[m], A[m], A[m]**2
		while i1 > s or i2 < e:
			if i1 == s:
				minv, sumv = min(A[i2+1], minv), sumv + A[i2+1]
				score = max(minv * sumv, score)
				i2 += 1
				continue
			if i2 == e:
				minv, sumv = min(A[i1-1], minv), sumv + A[i1-1]
				score = max(minv * sumv, score)
				i1 -= 1
				continue
			if A[i1-1] >= A[i2+1]:
				minv, sumv = min(minv, A[i1-1]), sumv + A[i1-1]
				i1 -= 1
			else:
				minv, sumv = min(minv, A[i2+1]), sumv + A[i2+1]
				i2 += 1
			score = max(minv * sumv, score)

		return max(score, recSum(s, m), recSum(m+1, e))
	print(recSum(0, N-1))
				
				
main()