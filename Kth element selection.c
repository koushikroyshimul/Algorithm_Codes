#include<stdio.h>
int A[20];
void swap(int dex1, int dex2)
{
    int temp=A[dex1];
    A[dex1]=A[dex2];
    A[dex2]=temp;
}
int partition(int start, int end)
{
    int i=start+1;
    int j=i;
    int pivot=start;
    for(i=start+1; i<end; i++)
    {
        if(A[i]<A[pivot])
        {
            swap(i,j);
            j++;
        }
    }
    if(j<=end)
        swap(pivot,(j-1));
    return j-1;
}
void quick_sort(int start,int end,int K)
{
    int part;
    if(start<end)
    {
        part=partition(start, end);
        if (part==K-1)
            printf("kth element : %d ",A[part]);
        if (part>K-1)
            quick_sort(start,part,K);
        else
            quick_sort(part+1,end,K);
    }
    return;
}
int main()
{
    int i,N;
    printf("Enter the value of array: ");
    scanf("%d",&N);
    printf("Enter array elements: ");
    for (i = 0; i < N; i++)
        scanf("%d",&A[i]);
    printf("Enter the Kth element you want to find: ");
    int k;
    scanf("%d", &k);
    quick_sort(0, N, k);
    return 0;
}
