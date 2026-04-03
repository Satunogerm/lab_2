#include <stdio.h>

struct student
{   
    char name[50];
    int age;
    float med_grade;
};

int main()
{
    struct student arr[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter %i name\n" , i);
        scanf("%s" , arr[i].name);
        printf("Enter %i age\n" , i);
        scanf("%i" , &arr[i].age);
        printf("Enter %i Medium grade\n" , i);
        scanf("%f" , &arr[i].med_grade);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%i Name = %s" , i , arr[i].name);
        printf("%i Age = %i" , i , arr[i].age);
        printf("%i Medium grade = %.2f" , i , arr[i].med_grade);
    }

    float max = 0;
    int max_index = 0;


    for(int i = 0; i < 5; i++)
    {
        if( arr[i].med_grade > max)
        {
            max = arr[i].med_grade;
            max_index = i;
        }
    }

    printf("\n--- Highest Grade ---\n");
    printf("Student %d (%s) has the highest grade: %.2f\n", max_index + 1, arr[max_index].name, max);

    return 0;
}