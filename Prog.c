#include "vector.h"
#include "my_std.h"
#include <limits.h>

struct IntArr
{
    int* buffer;
    int size;
};

int vecDefaultElem = 0;
struct IntArr matrixDefaultElem;

unsigned int findMaxRaw(struct VectorL* matrix)
{
    unsigned int resIndex = 0;
    long long maxVal = LLONG_MIN;
    for (int i = 0; i < matrix->size; i++)
    {
        int sum = 0;
        struct IntArr* curRaw = (struct IntArr*)getElement(matrix, i);
        for (int j = 0; j < curRaw->size; j++)
        {
            sum += curRaw->buffer[j];
        }
        if (sum > maxVal)
        {
            maxVal = sum;
            resIndex = i;
        }
    }
    return resIndex;
}
///////////////////////////////////
void printArr(struct IntArr* arr)
{
	if (arr->size <=0)
	{
		printf("\narray is empty\n");
		return;
	}
    for (int i = 0; i < arr->size; i++)
    {
        printf(" %d ", arr->buffer[i]);
    }
}
///////////////////////////////////////
void QuickSort(struct VectorL* matrix, unsigned int index)
{
        struct IntArr* curRaw = (struct IntArr*)getElement(matrix, index);
        quickSort(curRaw->buffer,0,curRaw->size-1);
}
//////////////////////////////////////
void printVec(struct VectorL* matrix)
{
    for (int i = 0; i < matrix->size; i++)
    {
        struct IntArr* curRaw = (struct IntArr*)getElement(matrix, i);
        printArr(curRaw);
    }
}
/////////////////////////////////////
void copyMatrix(struct VectorL* to, struct VectorL* from)
{
    to->size = from->size;
    to->defaultElem = from->defaultElem;
    to->elementSize = from->elementSize;
    for (int i = 0; i < from->size; i++)
    { 
        struct IntArr* elemTo = (struct IntArr*)getElement(to,i);
        struct IntArr* elemFrom = (struct IntArr*)getElement(from,i);
        memcpy(elemTo->buffer,elemFrom->buffer,sizeof(elemFrom->size)*from->elementSize);
        elemTo->size=elemFrom->size;
    }
}
/////////////////////////////////////
void FillMatrix(struct VectorL* matrix)
{
    for (int i = 0; i < matrix->size; i++)
    {
        printf("%s %d%s", "Введите кол-во столбцов в", i, "-ой строчке: ");
        int n = 0;
        while (!getInt(&n));
        struct IntArr* curRaw = (struct IntArr*)malloc(sizeof(struct IntArr));
        curRaw->buffer = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            printf("Введите элемент строки: ");
            int elem = vecDefaultElem;
            while (!getInt(&elem));
            curRaw->buffer[j] = elem;
        }
	curRaw->size=n;
        struct IntArr* elemTo= (struct IntArr*)getElement(matrix,i);
	printf("\n\n%p\n\n",curRaw->buffer);
	printf("\n\n%p\n\n",elemTo->buffer);
        memcpy(elemTo->buffer,curRaw->buffer,(curRaw->size)*sizeof(int));
        elemTo->size=curRaw->size;
	printArr((struct IntArr*)getElement(matrix,i));
    }
}

int main()
{
    SetRusLang();
    printf("Введите кол-во строчек матрицы: ");
    int m = 0;
    while (!getInt(&m));
    struct VectorL* matrix = createVector(m, sizeof(struct IntArr*), &matrixDefaultElem);
    struct VectorL* newMatrix = createVector(m, sizeof(struct IntArr*), &matrixDefaultElem);
    FillMatrix(matrix);
    copyMatrix(newMatrix, matrix);
    unsigned int index=findMaxRaw(matrix);
    QuickSort(newMatrix,index);
    printf("Исходная матрица: \n");
    printVec(matrix);
    printf("Полученная матрица: \n");
    printVec(newMatrix);
    return 0;
}
