#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "myhead.h"

void printStudents(Student students[], int numStudents) {
    // 打印學生信息
    printf("%-15s %-12s %8s    %-10s\n", "Name", "Department", "Grade", "SID");
    printf("------------------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%-15s %-12s %8d    %-10s\n", students[i].name, students[i].department, students[i].grade, students[i].sid);
    }
}

void randomInitStudents(Student students[], int numStudents) {
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
