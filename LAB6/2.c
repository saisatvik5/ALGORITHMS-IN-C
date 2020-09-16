#include<stdio.h> #include <stdlib.h>
int partition(int* input, int left, int right)

{

int range = (right - left + 1);

int pivot_index = left + (rand() % range); 
int pivot_element = input[pivot_index]; while ( left < right )
{

while ( input[left] < pivot_element ) left++;


while ( input[right] > pivot_element ) right--;

if ( input[left] == input[right] ) left++;
else if ( left < right ) { int tmp = input[left];
input[left] = input[right]; input[right] = tmp;
}

}

return right; 
}

int quick_select(int* input, int left, int right, int k)

{

if ( left == right ) return input[left];

int pivot_index = partition(input, left, right); int length = (pivot_index - left + 1);

if ( length == k )

return input[pivot_index];


else if ( k < length )

return quick_select(input, left, (pivot_index - 1), k); else
return quick_select(input, (pivot_index + 1), right, (k - length));

}

int main()

{

int  Size,k; printf("Enter Size :\n"); scanf("%d",&Size);
int arr[Size],i; for(i=0;i<Size;i++)
scanf("%d",&arr[i]); printf("Enter K :\n"); scanf("%d",&k);
int Len=sizeof(arr)/sizeof(arr[0]); 
int Res; Res=quick_select(arr,0,Len-1,k); printf("K Smallest Is %d\n",Res);
}
