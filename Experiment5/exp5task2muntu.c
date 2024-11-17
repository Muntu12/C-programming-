/* WAP to find the factorial of a number using recursive function */
#include<stdio.h>
int factorialRecursive(int num){
  if(num <= 1){
    return 1;
  }
   return num * factorialRecursive(num-1);
}

int main(){
    int num;

    printf("\t\t\t *** Recursive Factorial Function *** \n\n");

    printf("Enter Number:");
    scanf("%d", &num);
     printf("Factorial of %d is %d", num, factorialRecursive(num));
     return 0;
}
/*OUTPUT:
                        *** Recursive Factorial Function ***

Enter Number:4
Factorial of 4 is 24
Process returned 0 (0x0)   execution time : 2.994 s
Press any key to continue*/














