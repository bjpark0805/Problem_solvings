import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	histogram = []
	for _ in range(N):
		histogram.append(input(int))

	def recSum(s, e):
		if s == e:
			return histogram[s]
		if s + 1 == e:
			return max(max(histogram[s], histogram[e]), 2*min(histogram[s], histogram[e]))
		m = (s+e)//2
		area, height, lefti, righti = histogram[m], histogram[m], m, m
		maxv = max(recSum(s, m), recSum(m+1, e))
		while lefti > s or righti < e:
			if lefti == s:
				height = min(histogram[righti+1], height)
				area = max(area, height * (righti - lefti + 2))
				righti += 1
				continue
			if righti == e:
				height = min(histogram[lefti-1], height)
				area = max(area, height * (righti - lefti + 2))
				lefti -= 1
				continue
			if histogram[lefti-1] >= histogram[righti+1]:
				height = min(histogram[lefti-1], height)
				lefti -= 1
			else:
				height = min(histogram[righti+1], height)
				righti += 1
			area = max(area, height * (righti-lefti+1))
		return max(maxv, area)
	print(recSum(0, N-1))

main()