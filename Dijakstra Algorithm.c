#include<stdio.h>
#define INFINITY 9999
#define MAX 10
void Dijkstra(int Graph[MAX][MAX],int n,int start);
void Dijkstra(int Graph[MAX][MAX],int n,int start)
{
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if (Graph[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=Graph[i][j];
    for (i=0; i<n; i++)
    {
        distance[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }
    distance[start]=0;
    visited[start]=1;
    count=1;
    while (count<n-1)
    {
        mindistance=INFINITY;
        for (i=0; i<n; i++)
            if (distance[i]<mindistance && visited[i]==0)
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for (i=0; i<n; i++)
            if (visited[i]==0)
                if (mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0; i<n; i++)
        if(i!=start)
        {
            printf("Distance of node: %d=%d",i,distance[i]);
            printf("\nPath: %d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("~~%d",j);
            }
            while(j!=start);
            printf("\n");
        }
    printf("\n\n");
}
int main()
{
    int Graph[MAX][MAX],i,j,n,u;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Graph[%d][%d]: ",i,j);
            scanf("%d",&Graph[i][j]);
        }
    }
    u=0;
    Dijkstra(Graph,n,u);
    return 0;
}
