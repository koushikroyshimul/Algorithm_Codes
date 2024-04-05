#include<stdio.h>
int Maximum(int array[],int index,int len)
{
    int max;
    if(index>=len-1)
    {
        if(array[index]>array[index+1])
            return array[index];
        else
            return array[index+1];
    }
    max=Maximum(array,index+1,len);
    if(array[index]>max)
        return array[index];
    else
        return max;
}
int Minimum(int array[],int index,int len)
{
    int min;
    if(index>=len-1)
    {
        if(array[index]<array[index+1])
            return array[index];
        else
            return array[index+1];
    }
    min=Minimum(array,index+1,len);
    if(array[index]<min)
        return array[index];
    else
        return min;
}
int main()
{
    int array[100],N,max,min,i;
    printf("Enter size of the array: ");
    scanf("%d",&N);
    printf("Enter the elements in array: ");
    for(i=0; i<N; i++)
        scanf("%d",&array[i]);
    max=Maximum(array,0,N-1);
    min=Minimum(array,0,N-1);
    printf("Minimum element in the array:%d\n",min);
    printf("Maximum element in the array:%d\n",max);
    return 0;
}

