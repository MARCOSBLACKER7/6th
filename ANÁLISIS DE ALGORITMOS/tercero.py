def main():
 print("ingresa n: ")
	n = input()
	n= int(n)
	i = 1
	j= 1
		for i in range(n):
			for j in range(n):  
				C[i,j] = 0;
					for k = 1 to n do 
						C[i,j] = C[i,j] + A[i,k]*B[k,j];

main()