////////////////// DFS

#include<stdio.h>
int G[10][10],visited[10],n;
void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
} 
void main()
{
    int i,j;
    printf("Enter number of vertices:");
   
    // scanf("%d",&n);
    n = 8;
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
    int inp[64] = 
    {
        0,1,1,1,1,0,0,0,
        1,0,0,0,0,1,0,0,
        1,0,0,0,0,1,0,0,
        1,0,0,0,0,0,1,0,
        1,0,0,0,0,0,1,0,
        0,1,1,0,0,0,0,1,
        0,0,0,1,1,0,0,1,
        0,0,0,0,0,1,1,0,
    };
    int pos = 0;
    for(i=0;i<n;i++)
       for(j=0;j<n;j++){
            G[i][j] = inp[pos];
            pos++;
       }
            // scanf("%d",&G[i][j]);
            
 
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
}
 
