#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 12
#define MAX_NAME 50
#define MAX_ADDRESS 100
#define NUM_SUBJECTS 5
#define PASS_MARK 40

struct Student {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    int marks[NUM_SUBJECTS];
};

void inputStudentData(struct Student *students, int count);
void findPassFail(struct Student *students, int count);
void maxMathStudent(struct Student *students, int count);
void minPhysicsStudent(struct Student *students, int count);
void maxAverageStudent(struct Student *students, int count);
void printAllStudents(struct Student *students, int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int choice, studentCount;

    printf("Enter the number of students (10-12): ");
    scanf("%d", &studentCount);
    if (studentCount < 10 || studentCount > 12) {
        printf("Invalid number of students. Exiting.\n");
        return 1;
    }

    inputStudentData(students, studentCount);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find passed/failed students\n");
        printf("2. Student with maximum marks in Mathematics\n");
        printf("3. Student with minimum marks in Physics\n");
        printf("4. Student with maximum average marks\n");
        printf("5. Print all student records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findPassFail(students, studentCount);
                break;
            case 2:
                maxMathStudent(students, studentCount);
                break;
            case 3:
                minPhysicsStudent(students, studentCount);
                break;
            case 4:
                maxAverageStudent(students, studentCount);
                break;
            case 5:
                printAllStudents(students, studentCount);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void inputStudentData(struct Student *students, int count) {
     int i,j;
 for ( i = 0; i < count; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Address: ");
        scanf(" %[^\n]s", students[i].address);
        printf("Enter marks for 5 subjects (Math, Physics, Chemistry, English, Computer Science):\n");
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }
}

void findPassFail(struct Student *students, int count) {
    printf("\nStudents who passed in at least 3 subjects:\n");
    int i,j;
    for ( i = 0; i < count; i++) {
        int passCount = 0;
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].marks[j] >= PASS_MARK) {
                passCount++;
            }
        }
        if (passCount >= 3) {
            printf("%s\n", students[i].name);
        }
    }

    printf("\nStudents who failed in at least 3 subjects:\n");
 for ( i = 0; i < count; i++) {
        int failCount = 0;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].marks[j] < PASS_MARK) {
                failCount++;
            }
        }
        if (failCount >= 3) {
            printf("%s\n", students[i].name);
        }
    }
}

void maxMathStudent(struct Student *students, int count) {
    int maxMath = 0, maxIndex = 0;
    int i;
    for ( i = 0; i < count; i++) {
        if (students[i].marks[0] > maxMath) {
            maxMath = students[i].marks[0];
            maxIndex = i;
        }
    }
    printf("\nStudent with maximum marks in Mathematics:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Marks: %d\n", maxMath);
}

void minPhysicsStudent(struct Student *students, int count) {
    int minPhysics = 100, minIndex = 0;
int i;
    for ( i = 0; i < count; i++) {
        if (students[i].marks[1] < minPhysics) {
            minPhysics = students[i].marks[1];
            minIndex = i;
        }
    }
    printf("\nStudent with minimum marks in Physics:\n");
    printf("Name: %s\n", students[minIndex].name);
    printf("Marks: %d\n", minPhysics);
}

void maxAverageStudent(struct Student *students, int count) {
    float maxAvg = 0;
    int maxIndex = 0;
    int i,j;
    for ( i = 0; i < count; i++) {
        float avg = 0;
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            avg += students[i].marks[j];
        }
        avg /= NUM_SUBJECTS;
        if (avg > maxAvg) {
            maxAvg = avg;
            maxIndex = i;
        }
    }
    printf("\nStudent with maximum average marks:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Average Marks: %.2f\n", maxAvg);
}

void printAllStudents(struct Student *students, int count) {
    printf("\nAll Student Records:\n");
int i,j;
    for ( i = 0; i < count; i++) {
        int total = 0;
        printf("\nName: %s\n", students[i].name);
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].marks[j];
        }
        printf("Total Marks: %d\n", total);
    }
}
