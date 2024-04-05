#include<stdio.h>
#include<stdlib.h>
#define nV 4
#define INF 999
void printMatrix(int matrix[][nV])
{
  int i,j;
  for (i = 0; i < nV; i++)
    {
    for (j = 0; j < nV; j++)
    {
      if (matrix[i][j] == INF)
        printf("INF\t\t");
      else
        printf("%d\t\t",matrix[i][j]);
    }
    printf("\n");
   }
   printf("\n\n");
}
void floydWarshall(int graph[][nV])
{

  int matrix[nV][nV], i, j, k;
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];
  for (k = 0; k < nV; k++)
    {
    for (i = 0; i < nV; i++)
    {
      for (j = 0; j < nV; j++)
      {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
      printMatrix(matrix);
  }
}
int main() {
  int graph[nV][nV] = {{0,    1,   -2,   INF},
                       {4,    0,    3,   INF},
                       {INF, INF,   0,    2},
                       {5,   INF,  INF,   0}};
  floydWarshall(graph);
  return 0;
}
