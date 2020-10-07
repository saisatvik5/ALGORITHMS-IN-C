#include<stdio.h>
int sum(int a[], int l, int r)
{
    if(l==r) return a[l];
    int mid = (l+r)/2;
    int lsum = sum(a,l,mid);
    int rsum = sum(a,mid+1,r);
    return lsum+rsum;
}

int main() {
    int b[] = {9,7,2,6,5,3};
    int fsum = sum(b,0,5);
    printf("The sum of the array is %d",fsum);
    return 0;
}
