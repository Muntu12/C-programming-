/* AIM : WAP to find the largest element in an array
      */

#include<stdio.h>
int main()
{
     int n,i,a[100],large;


   printf("Enter the number of elements:");
   scanf("%d",&n);

   for (i=0;i<=n-1;i++)
   {
       printf("Enter a value:");
       scanf("%d",&a[i]);
   }

   large=a[0];
   for (i=0;i<=n-1;i++)
   {
       if(large<a[i])
        large=a[i];
   }
   printf("The largest number is %d",large);
   return 0;
}
/*
Enter the number of elements:5
Enter a value:12
Enter a value:15
Enter a value:68
Enter a value:68
Enter a value:3
The largest number is 68
Process returned 0 (0x0)   execution time : 19.090 s
Press any key to continue.
*/

















