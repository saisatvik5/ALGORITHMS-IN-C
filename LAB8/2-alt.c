#include <stdio.h>
#define SIZE 10
 
void computePrefixAvg(int*, int*);
 
int main()
{
  int arr[] = {12, 14, 13, 15, 19, 17, 16, 11, 18, 20};
  int pfavg[SIZE], i, j, k; 
 
  computePrefixAvg(arr, pfavg);
 
  printf("Array Elements              Average\n");
  printf("===================================\n");
  for (i = 0; i < 10; i ++ )
  {
    for (j = 0; j <= i; j++)
    {
	  printf("%d ", arr[j]);
    }
    for (k = 10; k > j; k--)
    {
	  printf("   ");
    }
    printf(" : %d\n", pfavg[i]);
  }  
}
 
void computePrefixAvg(int* arr, int* pfArr)
{
  int sum = 0;
 
  for(int i = 0; i < SIZE; i++)
  {
    sum += arr[i];
    pfArr[i] = sum / (i + 1);
  }
}
