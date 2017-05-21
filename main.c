#include <stdio.h>

#define false 0
#define true 1

void swap(int d[], int i, int j)
{
    int tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
}

void dump(int d[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d ",d[i]);
    }
    printf("\n");
}

void qsort(int d[], int len)
{
    int pivot = 0;
    int i = 1;
    int j = len-1;
    int findi = false;
    int findj = false;
    

    
    if(len<=1) return;
    
    dump(d,len);
    
    // do until i meet j
    while(i < j)
    {
        // if d[i] less than pivot, find next
        // else set findi flag
        if(d[i] < d[pivot]) i++;
        else findi = true;
        
        // if d[i] less than pivot, find next
        // else set findj flag
        if(d[j] > d[pivot]) j--;
        else findj = true;
        
        // if find i and j, swap d[i] d[j], go next i,j, clear find flag 
        // else donothing
        if(findi && findj)
        {
            swap(d, i, j);
            i++;
            j--;
            findi = findj = false;
        }
    }
    
    if(d[0]>d[i])
        swap(d,0,i);
    
    dump(d,len);
    
    qsort(d,i);
    qsort(d+i,len-i);
}

int main()
{
    int d[10] = {5,10,1,2,9,2,4,7,8,3};
 //   int d[10] = {5,1,1,2,4,2,4,1,2,3};
//int d[10] = {5,10,6,7,9,8,9,7,8,9};
    printf("Hello, World!\n");

    qsort(d, sizeof(d)/sizeof(d[0]));

    dump(d,sizeof(d)/sizeof(d[0]));
    return 0;
}

