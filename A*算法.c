#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int contain(int*arr,int num,int size)
{
    for(int i = 0;i<size ;i++)
    {
        if(arr[i] == num)
        {
            return 1;
        }
    }

    return 0;
}

void pailiezh(int * src ,int * dst ,int size ,int leve)
{
    //printf("%d %d ----\n",size,leve);
    if(leve == size)
    {
        //printf("print one times\n");
        for(int i = 0; i < size ;i++)
        {
            printf("%d ",dst[i]);
        }
        printf("\n");
    
        return;
    }

    for(int i = 0;i<size;i++)
    {
        if(leve == 0)
        {
           // printf("clear dst array\n");
            memset(dst,0,sizeof(int)*size);
        }

        if(contain(dst,src[i],leve) == 0)
        {
            dst[leve] = src[i];
           // printf("insert : %d leve : %d \n",src[i],leve);
            pailiezh(src,dst,size,leve+1);
        }
        
    }
}


int main()
{
    int a[9] = {1,2,3,4,5,6,7,8,9};
    int b[9];
    pailiezh(a,b,9,0);
    return 0; 
}
