#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vector.h"

#define MAXLEN 7000
#define MAX_N MAXLEN
#define TRUE 1
#define FALSE 0

void SetRusLang(void)
{
    system("chcp 1251");
    system("cls");
}

int replacePairs(int x)
{
    if (x<10)
        return x*10;
    else if (x>=10 && x<=99)
        return x%10*10+x/10;
    else
    {   
        int tail=replacePairs(x%100);
        return replacePairs(x/100)*100+tail;
    }
}

void qSort(int* arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left]%10 < middle%10) left++;
            while (arr[right]%10 > middle%10) right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = tmp;
            }
        } while (left <= right);
        qSort(arr, first, right);
        qSort(arr, left, last);
    }
}

int getInt(int* a)
{
	int n;
	do
	{
		n=scanf("%d",a);
        if (n==0)
		{
			printf("Error");
			scanf("%*[^\n]");	 
		}
	}while (n==0);
	return n < 0 ? FALSE : TRUE;
}

int main(void)
{
	int n,firstVal;
    SetRusLang();
	printf("Введите кол-во элементов последовательности\n");
	while (!getInt(&n));
	struct VectorL* seq=createVector(n);
    struct VectorL* newSeq=createVector(n);
    for (int i=0;i<n;i++)
	{
        int res;
		while(!getInt(&res));
        changeElement(seq,i,res);
        changeElement(newSeq,i,replacePairs(res));
	}
    printf("Исходная последовательность: ");
    printVec(seq);
    printf("Преобразованная последовательность: ");
    printVec(newSeq);
    qSort(newSeq->pointerFirst,0,n-1);
    printf("Отсортированная последовательность: ");
    printVec(newSeq);
	return 0;
}
