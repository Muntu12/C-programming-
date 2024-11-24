/* AIM : WAP to define a counter function to print how many times the function is called. use storage classes */



#include<stdio.h>
void counter(){
   static int count = 0;
   count++;

   printf("Counter Function called : %d\n", count);

}
int main(){
    printf("\t\t\t *** Storage Class *** \n\n");
int i;
    for(i = 1; i<=12; i++)

        counter();


        return 0;
}
/*
                         *** Storage Class ***

Counter Function called : 1
Counter Function called : 2
Counter Function called : 3
Counter Function called : 4
Counter Function called : 5
Counter Function called : 6
Counter Function called : 7
Counter Function called : 8
Counter Function called : 9
Counter Function called : 10
Counter Function called : 11
Counter Function called : 12

Process returned 0 (0x0)   execution time : 0.081 s
Press any key to continue. */



