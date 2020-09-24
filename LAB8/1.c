#include <stdio.h>

int sumArray(int array[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return array[0]%2==0?array[0]:0;
    }

    int mid = size / 2;
    int rsize = size - mid;
    int lsum = sumArray(array, mid);
    int rsum = sumArray(array + mid, rsize);
    return lsum + rsum;
}

int main() {
    int arr[6]={1,2,3,4,5,6};
    int sumOfArray=sumArray(arr,6);
    printf("Sum of even is %d",sumOfArray);
    
    return 0;
}
