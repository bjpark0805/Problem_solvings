import sys
import heapq
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	classes = []
	for _ in range(N):
		classes.append(list(map(int, input().split())))
	classes.sort()
	rooms = []
	heapq.heappush(rooms, classes[0][1])
	for i in range(1, len(classes)):
		if rooms[0] <= classes[i][0]:
			heapq.heappop(rooms)
		heapq.heappush(rooms, classes[i][1])

	print(len(rooms))

main()