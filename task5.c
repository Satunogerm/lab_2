#include <stdio.h>

enum Day 
{
    monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday
};

struct Event 
{
    enum Day day;
};

int main() 
{
    int input;
    struct Event e;
    
    printf("Enter day number (1-7): ");
    scanf("%d", &input);
    
    e.day = (enum Day)input;
    
    printf("Day: ");
    switch(e.day) 
    {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        case 7: printf("Sunday\n"); break;
        default: printf("Error\n");
    }
    
    return 0;
}