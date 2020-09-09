#include <stdio.h>

int MAX = -1;
int NUM = -1;

int majority(int arr[], int low, int high, int x) 
{
    if ((low > high) || (low == high && arr[low] != x)) 
        {
            return 0;
        }
    if (low == high && arr[low] == x) 
        {
            return 1;
        }
        else
        {
    return majority(arr, low, (low + high) / 2, x) + majority(arr, 1 + (low + high) / 2, high, x); 
    } 
}

void driver(int arr[], int n) {
    int majo = 0;
    for(int i=0;i<n;i++) {
        majo = majority(arr,0,n, arr[i]);
        if(MAX <= majo && NUM < arr[i]) {
            MAX = majo; 
            NUM = arr[i];
        }
    }
} 

int main() 
{
    int arr[] = { 5, 7, 5, 7, 8, 1, 4, 8, 4, 9, 7 };
    int n = sizeof (arr) / sizeof (arr[0]);
    
    driver(arr,n);

    printf("the element: %d \nwith the highest majority is: %d",NUM,MAX);
    return 0;
}
