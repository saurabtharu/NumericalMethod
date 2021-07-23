
def larange(xArr, yArr, n, x):
	sum = 0
	
	for i in range(n):
		mult = 1.0
		for j in range(n):
			if (i != j):
				mult = mult * (x - xArr[j]) / (xArr[i] - xArr[j])
		sum = sum + mult * yArr[i]
	
	return sum

n = int(input("Enter the number of degrees:  "))

xArray = list(n)
yArray = list(n)
print("Enter the value of x and y as \n")

for i in range(n):

	# xArray[i],  yArray[i] = int(input().split())
	
	xArray.append(int(input(f"x{i} = ")))
	yArray.append(int(input(f"y{i} = ")))


x = float(input("Enter the value of which the interpolation is required:  "))

answer = larange(xArray, yArray, n, x)

print(f"The  required answer is {answer}")