#include <stdio.h>
/*
void printIt (int arr, int n)
{
  printf ("\n");
  for (int c = 0; c < n; c++) {
    for (int d = 0; d < n; d++)
        printf ("%d ", arr[c][d]);
    printf("\n")
  }
  printf ("\n");
}
*/
void main() {
  int arr[6][5] = {{4, 7, 5, 2, 4}, {8, 8, 9, 2, 2},  {3, 3, 8, 5, 3},
                   {3, 7, 3, 5, 2}, {10, 1, 3, 8, 4}, {10, 6, 9, 5, 10}};
  int n = sizeof(arr) / sizeof(arr[0]);
  int m = sizeof(arr[0]) / sizeof(arr[0][0]);
  ;
  int best = 10;
  // printf("%d",n);

  printf("Entered data is\n");
  for (int c = 0; c < n; c++) {
    for (int d = 0; d < m; d++) {
      printf("%d ", arr[c][d]);
    }
    printf("\n");
  }
  printf("\n");

  int pos1, pos2;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] < best) {
        best = arr[i][j];
        pos1 = i, pos2 = j;
      }
    }
  }

  printf("\n\nThe Best couple is = %d and %d with %d distancing", best, pos1,
         pos2);

  // printf ("\nIt's = %d \n", ans);
}
