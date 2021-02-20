import heapq
def main():
	N = int(input())
	A = list(map(int, input().split()))
	min_heap = []
	for a in A:
		heapq.heappush(min_heap, a)

	for _ in range(N-1):
		temp = list(map(int, input().split()))
		for t in temp:
			heapq.heappush(min_heap, t)
			heapq.heappop(min_heap)
	
	print(heapq.heappop(min_heap))

if __name__ == '__main__':
	main()

