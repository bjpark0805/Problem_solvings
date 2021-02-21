import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	K = input(int)
	sensors = list(map(int, input().split()))
	if K>=N:
		print(0)
		return		
	sensors.sort()
	diff = []
	for i in range(1, len(sensors)):
		diff.append(sensors[i]-sensors[i-1])
	diff.sort()
	print(diff)
	if K == 1:
		print(sum(diff))
	else:
		print(sum(diff[:-K+1]))
main()