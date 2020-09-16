#include <stdio.h>

#define Swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) void SelectionSort(int arr[1000],int n)
{

int i,j,temp;

for (i=0;i<n;i++)

for(j=i+1;j<n;j++)

if(arr[j]<arr[i])

Swap(arr[i],arr[j],temp);

}


void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])

{

int i = 0, j = 0, k = 0; while (i<n1 && j <n2)
{

if (arr1[i] < arr2[j]) arr3[k++] = arr1[i++];
else

arr3[k++] = arr2[j++];

}

while (i < n1)

arr3[k++] = arr1[i++];
 

while(j<n2)

arr3[k++] = arr2[j++];

}

int Search(int arr[],int size,int n)

{

int i,Res; for(i=0;i<size;i++)
if(arr[i]==n)

return i;

return -1;

}

int main()

{

int Size,i,Len,HLen,j,K;

printf("Enter Size:\n"); scanf("%d",&Size); int AIn[Size]; for(i=0;i<Size;i++)
scanf("%d",&AIn[i]); printf("Element To Search:\n"); scanf("%d",&K);
Len = sizeof(AIn)/sizeof(AIn[0]); HLen = Len/2;
int A[1000],B[1000];

for(i=0;i<=HLen;i++)
 

A[i]=AIn[i];

if(Len%2==0)

{

for(i=0;i<HLen;i++) B[i]=AIn[i+HLen];
}

else

{

for(i=HLen;i<Size;i++) B[i-HLen]=AIn[i];
}

int H1Len,H2Len; H1Len = HLen;
SelectionSort(A,H1Len); if(Size%2==0)
H2Len = HLen;

else

H2Len = HLen+1; SelectionSort(B,H2Len); int C[H1Len+H2Len];
mergeArrays(A,B,H1Len,H2Len,C); int Fin1,Fin2,Fin3;
Fin1 = Search(A,H1Len,K); Fin2 = Search(B,H2Len,K); Fin3 = Search(C,Size,K);
if (Fin3==-1)
printf("%d\n",Fin3);

else

{
if(Fin1==-1)
{
printf("B\n"); printf("%d\n",Fin2); printf("%d\n",Fin3);
}
else if(Fin2==-1)
{

printf("A\n"); printf("%d\n",Fin1); printf("%d\n",Fin3);
}
}

return 0;

}
