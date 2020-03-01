#include "vector.h"
#include "my_std.h"
int main()
{
    SetRusLang();
    printf("¬ведите кол-во строчек матрицы: ");
    int vecDefaultElem = 0;
    struct VectorL* matrixDefaultElem;
    int m=0;
    while(!getInt(&m));
    struct VectorL* matrix = createVector(m,sizeof(struct VectorL*),&matrixDefaultElem);
    for (int i=0;i<m;i++)
    {
        printf("%s %d%s","¬ведите кол-во столбцов в",i,"-ой строчке: ");
        int n=0;
        while(!getInt(&n));
        struct VectorL* curRaw = createVector(n,sizeof(int),&vecDefaultElem);
        for (int j=0;j<n;j++)
        {
            printf("¬ведите элемент строки: ");
            int elem=vecDefaultElem;
            while(!getInt(&elem));
            changeElement(curRaw,j,&elem);
            printf("%d",*((int*)getElement(curRaw,j)));
        }
        changeElement(matrix,i,curRaw);
    }
    for (int i=0;i<m;i++)
    {
        struct VectorL* curRaw = (struct VectorL*)getElement(matrix,i);
        printf("%d",*((int*)getElement(curRaw,1)));
        for (int j=0;j<3;j++)
        {
            printf("%d ",*((int*)getElement(curRaw,j)));       
        }
    }
    return 0;
}
