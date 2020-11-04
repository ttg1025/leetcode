#include <stdio.h>
#include <malloc.h>
#include <windows.h>
int** transpose(int** A, int ASize, int AColSize, int returnSize, int** returnColumnSizes);
int** transposeX(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) ;
/**
 *返回大小为* returnSize的数组的数组。
 *数组的大小作为* returnColumnSizes数组返回。
 *注意：返回的数组和* columnSizes数组都必须被分配，假设调用者调用free（）。
 */
int** transpose(int** A, int ASize, int AColSize, int returnSize, int** returnColumnSizes){
    returnSize = AColSize;
    //二维数组
    int **result = (int **)malloc(returnSize*sizeof(int *));
    for(int i = 0;i < AColSize;i++)
    {
        result[i] = (int *)malloc(ASize*sizeof(int));
        returnColumnSizes[0][i] = ASize;
        for(int j = 0;j < ASize;j++)
        {
            result[i][j] = A[j][i];
        }
    }
    return result;

}

int** transposeX(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) 
{
    int i, j;
    int** ret = (int**)malloc(sizeof(int*) * (*AColSizes));
    columnSizes[0] = (int*)malloc(sizeof(int) * (*AColSizes));
    *returnSize = *AColSizes;
    for(i = 0; i < *AColSizes; i++) columnSizes[0][i] = ARowSize;
    for(i = 0; i < *AColSizes; i++) ret[i] = (int*)malloc(sizeof(int) * ARowSize);
    for(i = 0; i < ARowSize; i++)
    {
        for(j = 0; j < *AColSizes; j++)
        {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}

int main(){
    //二维数组赋值
    int **A = (int **)malloc(9*sizeof(int *));
    for(int i = 0;i < 3;i++ )
    {
    A[i] = (int *)malloc(3*sizeof(int));
    for(int j = 0;j < 3;j++)
    {
    A[i][j] = i*3+j+1;
    }
    }
    
    int **returnColumnSize = (int **)malloc(3*sizeof(int *));
    for(int i = 0;i < 1;i++ )
    {
    returnColumnSize[i] = (int *)malloc(3*sizeof(int));
    for(int j = 0;j < 3;j++)
    {
    returnColumnSize[i][j] = i*3+j+1;
    }
    }

    int aSize = 3;

    
    
    int **row = transpose(A,aSize,3,3,returnColumnSize);
    printf("%d  ",row[0][2]);
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("%d ",row[i][j]);

        }
    }
    system("pause");
    return 0;
}