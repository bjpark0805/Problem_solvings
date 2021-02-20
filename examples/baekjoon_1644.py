import sys
import math
def input(_type = str):
	return _type(sys.stdin.readline().strip())
def main():
	N = input(int)
	root_n = int(math.sqrt(N))
	prime_bool = [True for _ in range(N)]
	prime_bool[0] = False
	i = 2
	while i <= root_n:
		if not prime_bool[i-1]:
			i += 1
			continue
		j = i
		while i * j <= N:
			prime_bool[i*j-1] = False
			j+= 1
		i += 1
	primes = []
	for i in range(1, N+1):
		if prime_bool[i-1]:
			primes.append(i)
	p,q,s,cnt = 0,0,0,0

	while q < len(primes):
		s += primes[q]
		if s == N:
			cnt += 1
			q += 1
		elif s < N:
			q += 1
		else:
			s -= primes[p] + primes[q]
			p += 1
	print(cnt)

if __name__ == '__main__':
	main()