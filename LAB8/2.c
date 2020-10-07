#include <stdio.h>

#include <string.h>

int catchValues[20] = {0};
int pos = 0;


void printIt(int* arr, int n) {
  for (int c = 0; c < n; c++)
    printf("%d ", arr[c]);
}

void removeDuplicates(int arr[], int n) {
  int c = 0, d = 0, count = 0;
  int b[20] = {0};

  for (c = 0; c < n; c++) {
    for (d = 0; d < count; d++) {
      if (arr[c] == b[d])
        break;
    }
    if (d == count) {
      b[count] = arr[c];
      count++;
    }
  }
  printIt(b, count);
}

void subsetSums(int arr[], int l, int r, int sum) {
  if (l > r) {
    for (int i = 0; i < r; i++) {
      if (arr[i] == sum) {
        catchValues[pos] = sum;
        pos++;
        // printf("%d\n",sum);
      }
    }
    return;
  }
  subsetSums(arr, l + 1, r, sum + arr[l]);
  subsetSums(arr, l + 1, r, sum);
}

int main() {
  int arr[] = {1, 2, 5, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  subsetSums(arr, 0, n - 1, 0);

  // printIt(catchValues,pos);

  removeDuplicates(catchValues, pos);
  return 0;
}
