#include <stdio.h>
int main()
{
    char arr[]={'A','B','C','D','E','F','G'};
    int n = sizeof(arr)/sizeof(char);
    for(int i=0;i<n;i++){
        if((arr[2*i + 1]!=' ')&&(arr[2*i + 2]!=' ')
        &&(2*i + 1<n)&&(2*i +2<n))
            printf("Degree of %c is 2 \n",arr[i]);
        else if((arr[2*i + 1]!=' ')&&(arr[2*i + 2]==' '))
            printf("Degree of %c is 1 \n",arr[i]);
        else
            printf("Degree of %c is 0 and %c is a leafnode \n",arr[i],arr[i]);
    }
    return 0;
}
