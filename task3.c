#include <stdio.h>

struct date
{
    int day , month , year;
};

struct person
{
    char name[64];
    struct date birthday;
};

int main()
{
    struct date d1;
    struct person p1;
   
    printf("Enter your name\n");
    scanf("%s" , p1.name);
    printf("Enter your birthday date\n");
    printf("Day = ");
    scanf("%i" , &d1.day);
    printf("Month = ");
    scanf("%i" , &d1.month);
    printf("Year = ");
    scanf("%i" , &d1.year);
    
    if( d1.year > 2000)
    {
        printf("Enter your name = %s" , p1.name);
        printf("Your birthday date = %i.%i.%i" , d1.day , d1.month , d1.year);
    }

}