
#include<stdio.h> 
int a[50], max;

void
maximum (int i, int j) 
 
{
  
 
int max1;
  if (i == j)
    max = a[i];
  else if (i == j - 1)
    
    {
      
 
if (a[i] > a[j])
	
 
	{
	  
 
max = a[i];
	
 
}
      
 
      else
	
 
	{
	  
 
max = a[j];
	
 
}
    
 
}
  
 
  else
    
 
    {
      
 
maximum (i, (i + j) / 2);
      max1 = max;
      maximum (((i + j) / 2) + 1, j);
      if (max < max1)
	
 
 
max = max1;
    
 
}

 
}


 
 
 
void
main () 
 
{
  
 
int i, n;
  
 
printf ("Enter size of array : ");
  scanf ("%d", &n);
  
printf ("Enter elements in array:");
  for (i = 0; i < n; i++)
    
scanf ("%d", &a[i]);
  maximum (0, n - 1);
  printf ("\nMaximum : %d", max);

}
