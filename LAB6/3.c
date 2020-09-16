#include<stdio.h>

#define Swap(x, y, t)((t) = (x), (x) = (y), (y) = (t)) void SelectionSort(int arr[], int n) {

  int i, j, temp;

  for (i = 0; i < n; i++)

  {

    for (j = i + 1; j < n; j++)

    {

      if (arr[j] < arr[i]) Swap(arr[i], arr[j], temp);
    }

  }

}

int main()

{

  int Size;

  printf("Enter Size :\n");
  scanf("%d", & Size);
  int arr[Size], Len, i;

  printf("Enter Elements In Array:\n");

  for (i = 0; i < Size; i++) scanf("%d", & arr[i]);
  Len = sizeof(arr) / sizeof(arr[0]);
  int Mid;
  if (Len % 2 == 0) Mid = Len / 2;
  else
    Mid = (Len / 2) + 1;
  int New[Mid];
  for (i = 0; i < Mid; i++) New[i] = arr[2 * i];
  SelectionSort(New, Mid);
  for (i = 0; i < Mid; i++) arr[i * 2] = New[i];
  for (i = 0; i < Size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
