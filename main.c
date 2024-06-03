#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "myhead.h"

#define MAX_STUDENT 10

void initializeStudents(Student students[], int numStudents) {
    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < numStudents; i++) {
        // Generate random student data
        sprintf(students[i].name, "Student %d", i + 1);
        sprintf(students[i].department, "Department %d", rand() % 5 + 1);
        students[i].grade = rand() % 4 + 1;
        sprintf(students[i].sid, "SID%04d", rand() % 1000 + 1);
    }
}

// Comparison function for qsort
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return -strcmp(studentA->sid, studentB->sid);
}

int main() {
    // 創建並初始化學生實例
    Student students[MAX_STUDENT];
    initializeStudents(students, MAX_STUDENT);

    // Sort students by SID using qsort function
    qsort(students, MAX_STUDENT, sizeof(Student), compareStudents);

    printStudents(students, MAX_STUDENT);

    return 0;
}