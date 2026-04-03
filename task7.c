#include <stdio.h>
#include <string.h>

#define MAX 50

enum Course { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

struct Student {
    char name[50];
    int age;
    enum Course course;
    float gpa;
};

// Function declarations
void add(struct Student *s, int *count);
void list(struct Student *s, int count);
void search(struct Student *s, int count, char *name);
void sort(struct Student *s, int count);
void showCourse(enum Course c);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;
    char name[50];
    
    do {
        printf("\n1. Add\n2. List\n3. Search\n4. Sort by GPA\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                add(students, &count);
                break;
            case 2:
                list(students, count);
                break;
            case 3:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                search(students, count, name);
                break;
            case 4:
                sort(students, count);
                break;
            case 5:
                printf("Bye!\n");
        }
    } while(choice != 5);
    
    return 0;
}

void showCourse(enum Course c) {
    if (c == FRESHMAN) printf("Freshman");
    else if (c == SOPHOMORE) printf("Sophomore");
    else if (c == JUNIOR) printf("Junior");
    else printf("Senior");
}

void add(struct Student *s, int *count) {
    if (*count >= MAX) {
        printf("Full!\n");
        return;
    }
    
    struct Student *new = &s[*count];
    
    printf("Name: ");
    fgets(new->name, 50, stdin);
    new->name[strcspn(new->name, "\n")] = 0;
    
    printf("Age: ");
    scanf("%d", &new->age);
    
    int c;
    printf("Course (0=Freshman,1=Sophomore,2=Junior,3=Senior): ");
    scanf("%d", &c);
    new->course = c;
    
    printf("GPA: ");
    scanf("%f", &new->gpa);
    getchar();
    
    (*count)++;
    printf("Added!\n");
}

void list(struct Student *s, int count) {
    if (count == 0) {
        printf("No students\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Course: ");
        showCourse(s[i].course);
        printf("\nGPA: %.2f\n", s[i].gpa);
    }
}

void search(struct Student *s, int count, char *name) {
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].name, name) == 0) {
            printf("\nFound!\n");
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n", s[i].age);
            printf("GPA: %.2f\n", s[i].gpa);
            found = 1;
        }
    }
    
    if (!found) printf("Not found\n");
}

void sort(struct Student *s, int count) {
    // Bubble sort by GPA (descending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (s[j].gpa < s[j+1].gpa) {
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    printf("Sorted by GPA!\n");
    list(s, count); // show sorted list
}