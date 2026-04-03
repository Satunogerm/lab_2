#include <stdio.h>

struct student
{   
    char name[50];
    int age;
    float med_grade;
};

int main()
{   
    struct student s1;



    printf("Enter your name\n");
    scanf("%s" , s1.name);
    printf("Enter your age\n");
    scanf("%i" , &s1.age);
    printf("Enter your Medium grade\n");
    scanf("%f" , &s1.med_grade);

    printf("Your Name = %s\n" , s1.name);
    printf("Your Age = %i\n" , s1.age);
    printf("Your Medium grade = %.2f\n" , s1.med_grade);




    return 0;
}

