#include <stdio.h>
int SIZE = 0;

void printIt(int* arr, int n) {
  printf("\n");
  for (int c = 0; c < n; c++) printf("%d ", arr[c]);
}

void prefixAverages(int* arr, int* aArr) {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    sum += arr[i];
    aArr[i] = sum / (i + 1);
  }
}

int main() {
  int arr[] = {12, 14, 13, 15, 19, 17, 16, 11, 18, 20};
  SIZE = sizeof(arr) / sizeof(arr[0]);
  int aAvg[SIZE], i, j, k;
  printIt(arr, SIZE);
  prefixAverages(arr, aAvg);
  printf("\n\nPrefix Avg array is : ");
  printIt(aAvg, SIZE);
}
