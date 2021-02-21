# import sys
# import heapq
# def input(_type=str):
# 	return _type(sys.stdin.readline().strip())

# def main():
# 	N, K = list(map(int, input().split()))
# 	devices = list(map(int, input().split()))
# 	taps, ans= [], 0
# 	for i in range(K):
# 		# print(taps)
# 		if len(taps) < N:
# 			taps.append(devices[i])
# 			continue
# 		if devices[i] in taps:
# 			continue
# 		max_idx, max_val = 
# 		for j in range(len(taps)):
# 			if taps[j] == devices[i]:
# 				continue
# 		# print(devices[i])
# 		ans += 1
# 		heapq.heappop(taps)
# 		heapq.heappush(taps, (-nexti, devices[i]))

# 	print(ans)

# main()

import sys
import heapq
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, K = list(map(int, input().split()))
	devices = list(map(int, input().split()))
	taps, ans= [], 0
	for i in range(K):
		# print(taps)
		nexti = K if not devices[i] in devices[i+1:] else devices.index(devices[i], i+1)
		find = False
		for j in range(len(taps)):
			if taps[j][1] == devices[i]:
				taps[j], find = (-nexti,devices[i]), True
				heapq.heapify(taps)
				break

		if not find:
			if len(taps) < N:
				heapq.heappush(taps, (-nexti, devices[i]))
				continue
			ans += 1
			heapq.heappop(taps)
			heapq.heappush(taps, (-nexti, devices[i]))
	# print(taps)

	print(ans)

main()