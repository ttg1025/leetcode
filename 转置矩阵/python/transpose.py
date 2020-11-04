A = [[1,2,3],[4,5,6],[7,8,9]]
B=[]
for i in range(len(A[0])):#len(A[0])矩阵列数
    temp = []
    for j in range(len(A)):#len(A)矩阵行数
        temp.append(A[j][i])
    B.append(temp)
print(B)