/*Aim: WAP to get students PCM marks from the user and find the average. Use conditional operator to print if the student is eligible for admission. Eligibility criteria is 50% in PCM.
*/


#include<stdio.h>
int main()
{
    int p,c,m,avg;
    printf("Enter Physics Marks:");
    scanf("%d",&p);
    printf("Enter Chemistry Marks:  ");
    scanf("%d",&c);
    printf("Enter Maths Marks:  ");
    scanf("%d",&m);
    avg=(p+c+m)/3;
    printf("AVERAGE=%d\n",avg);
    avg>=50?printf("You are eligible for Admission"):printf("You are not eligible for Adission");
    return 0;
}

/*Enter Physics Marks:70
Enter Chemistry Marks:  60
Enter Maths Marks:  60
AVERAGE=63
You are eligible for Admission*/
