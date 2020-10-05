////////////////////// BFS


#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void
bfs (int v)
{
  for (i = 1; i <= n; i++)
    if (a[v][i] && !visited[i]){
        printf(" %d - ",v);
      q[++r] = i;}
  if (f <= r)
    {
      visited[q[f]] = 1;
      bfs (q[f++]);
    }
}

void
main ()
{
  int v;
  printf ("\n Enter the number of vertices:");
  //scanf ("%d", &n);
    n = 8;
    for (i = 1; i <= n; i++)
    {
      q[i] = 0;
      visited[i] = 0;
    }
    
    int inp[64] = 
    {
        0,1,1,1,0,0,0,0,
        1,0,0,0,0,1,0,0,
        1,0,0,0,0,1,0,0,
        1,0,0,0,0,0,1,0,
        1,0,0,0,0,0,1,0,
        0,1,1,0,0,0,0,1,
        0,0,0,1,1,0,0,1,
        0,0,0,0,0,1,1,0,
    };
    int pos = 0;

//   printf ("\n Enter graph data in matrix form:\n");
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
	{
// 	  scanf ("%d", &a[i][j]);
            a[i][j] = inp[pos];
            pos++;
	}
    }

//   printf ("\n Enter the starting vertex:");
//   scanf ("%d", &v);
  bfs (2);
  printf ("\n The node which are reachable are:\n");
    printf ("\n", i);
  for (i = 1; i <= n; i++)
    {
        if (visited[i])
	        printf ("%d\t", i);
        else
    	{
    	  printf ("\n Bfs is not possible. Not all nodes are reachable");
    	  break;
    	}
    }
}
