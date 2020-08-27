#include<stdio.h>
//int iter = 0;
void printIt(int *arr,int n) {
    printf("\n");
    for(int c = 0; c < n ; c++)
        printf("%d ", arr[c]);
    printf("\n");
}

int mean(int* arr, int n) {
    int sum=0;
    for(int i=0; i<n; i++) {
      sum=sum+arr[i];
   }
   return(sum/n);
}


void swap(int* xp, int* yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int findPosition(int arr[],int arr_c[],int n,int mean) {
    int i, j, min_idx,value,flag = 0; 
    
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    }
    
    for(int i=0; i<n; i++) {
      if(arr[i] >= mean && flag == 0) {
          //printf("%d = %d = %d\n",mean,arr[i],i);
          value = arr[i];
          flag =1;
          break;
          
      }
   }
   
   for(int i=0; i<n; i++) {
      if(value == arr_c[i]) {
          //printf("%d = %d = %d\n",mean,arr_c[i],i);
          return i;
          
      }
   }
} 

int partition(int *arr, int n,int pos,int k) {
    
    //printIt(arr,n);
    //printf("\n");
    int arr_left[20]={0},left = 0;
    int arr_right[20]={0},right = 0;
    //printf("\n%d -- %d\n",pos,n);
    int mean_local = arr[pos];
    
    for(int c = 0; c < n ; c++) {
        if( c == pos)
            continue;
        //printf("\n%d - %d",arr[c],mean);
        if( arr[c] < mean_local ) {
            arr_left[left] = arr[c];
            left++;
        }
        else if( arr[c] >= mean_local) {
            arr_right[right] = arr[c];
            right++;
        }
    }
    
    // printf("\nleft - ");
    // printIt(arr_left,left);
    
    // printf("\nright - ");
    // printIt(arr_right,right);
    
    
    //printf("\n%d -- %d\n",pos,mean);
    
    for(int c = 0; c < left ; c++) {
        arr[c] = arr_left[c];
    }
     
    arr[left] = mean_local;
    
    for(int c = 0; c < right ; c++) {
        arr[left+1+c] = arr_right[c];
    }
    //printf("%d = %d - %d",iter++,mean_local,k-1);
    if (mean_local==arr[k-1]) 
        return mean_local;
    if (mean_local>arr[k]) {
        //partition(copied1,n,pos,k);
        int copied[16],copied1[16];
        int loop;
        for(loop = 0; loop < n; loop++) {
            copied[loop] = arr_left[loop];
            copied1[loop]= arr_left[loop];
        }
        int mean_n = mean(arr_left,left);
        int pos = findPosition(arr_left,copied,left,mean_n);
        //printIt(copied1,left);
        //printf("left = ");
        partition(copied1,left,pos,k);
    }
    else if (mean_local<arr[k-1]) {
        int copied[16],copied1[16];
        int loop;
        for(loop = 0; loop < n; loop++) {
            copied[loop] = arr_right[loop];
            copied1[loop]= arr_right[loop];
        }
        int mean_n = mean(arr_right,right);
        int pos = findPosition(arr_right,copied,right,mean_n);
        //printf("right = ");
        //printIt(copied1,right);
        partition(copied1,right,pos,k);

    }
    
}


int main()
{
    int arr[]={8,53,87,53,23,6,10,20,30,40,53};
    int i = 0;
    int k = 3; //K'th smallest
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int copied[16],copied1[16];
    int loop;
   
    printIt(arr,n);
    printf("kth is : %d\n",k);
    for(loop = 0; loop < n; loop++) {
        copied[loop] = arr[loop];
        copied1[loop]= arr[loop];
    }
    
    int mean_n = mean(arr,n);
    int pos = findPosition(arr,copied,n,mean_n);
    
    
    int ans = partition(copied1,n,pos,k);
    printf("\nIt's =  %d \n",ans);
    
    //printf("\n \t %d",copied1[ans]);
    //printIt(copied1,n);
    return 0;
}
