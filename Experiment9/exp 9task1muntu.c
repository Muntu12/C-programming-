/*AIM: Design a structure student_record to contain name, roll_number, and total marks obtained. WAP to read 5 students data from the user and then display the topper on the screen. 
Name   : Muntazir Patel
roll no: 12
UIN    : 241A012
div    : A
*/
#include<stdio.h>
#include<string.h>
struct student_record{
    char name[50];
    int roll_number;
    float total_marks;
};
void input_student_data(struct student_record students[],int n){
for(int i=0;i<n;i++){
    printf("enter details for student %d;\n",i+1);
    printf("name:");
    scanf("%s",students[i].name);
    printf("roll number:");
    scanf("%d",&students[i].roll_number);
    printf("total marks:");
    scanf("%f",&students[i].total_marks);
}
}
int find_topper(struct student_record students[],int n){
int topper_index=0;
for(int i=1;i<n;i++){
    if(students[i].total_marks>students[topper_index].total_marks){
        topper_index=i;
    }
}
return topper_index;
}
int main(){
int n=5;
struct student_record students[n];
printf("\t\t***topper finder***\n\n");
input_student_data(students,n);
int topper_index=find_topper(students,n);
printf("\n topper details:\n");
printf("name:%s\n",students[topper_index].name);
printf("roll number:%d\n",students[topper_index].roll_number);
printf("total marks:%f\n",students[topper_index].total_marks);
return 0;
}
