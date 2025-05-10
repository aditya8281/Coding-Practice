#include <stdio.h>
#include <stdlib.h>

struct Date{
    int day;
    int month;
    int year;
};
struct Student {
    char name[50];
    int roll;
    struct Date dob;
};

int main() {
    struct Student student;

    scanf("%[^n]",student.name);
}
