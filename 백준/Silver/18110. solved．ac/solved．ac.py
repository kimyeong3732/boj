import sys

def my_round(n):
	if n - int(n) < 0.5:
		return int(n)
	
	return int(n) + 1

input = sys.stdin.readline()
n = int(input)

if n == 0:
	print(0)

else:
	exc = my_round(n * 0.15)
	nums = [int(sys.stdin.readline()) for i in range(n)]
	
	nums.sort()
	
	sumnum = 0
	for i in range(exc, n-exc):
	    sumnum += nums[i]
		
	print(my_round(sumnum / (n - 2 * exc)))