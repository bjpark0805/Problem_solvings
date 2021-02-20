import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())
"""
	Golomb's sequence algorithm:
	
	G(1) = 1
	G(n+1) = 1 + G(n + 1 - G(G(n)))
"""
def main():
	n = input(int)
	if n <= 5:
		if n <= 1:
			print(1)
		elif n <= 3:
			print(2)
		else:
			print(3)
		return
	f_tuple = [(0,0),(1,1),(2,2),(3,4),(4,6)]
	i, k, curr = 6, 3, 4
	while True:
		k_val, first_index = f_tuple[k]
		_, next_first_index = f_tuple[k+1]
		for _ in range(next_first_index - first_index):
			curr, i = curr + 1, i + k_val
			# print(curr, i)
			if i > n:
				print(curr-1)
				return
			f_tuple.append((curr, i))
		k += 10

if __name__ == '__main__':
	main()
