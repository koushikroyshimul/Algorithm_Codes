#include<stdio.h>
int a[100];
int b[100];
void Merge(int low,int mid,int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i==mid+1)
    {
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(j>high)
    {
        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }
    for(i=low; i<=high; i++)
    {
        a[i]=b[i];
    }
}
void Mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        Mergesort(low,mid);
        Mergesort(mid+1,high);
        Merge(low,mid,high);
    }
}
int main()
{
    int max,i;
    printf("Enter maximum element : ");
    scanf("%d",&max);
    for(i=1; i<=max; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    Mergesort(1,max);
    for(i=1; i<=max; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

