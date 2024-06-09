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

void printSRecords(SRecord srecords[], int numSRecords) {
    // 打印學生成績信息
    printf("%-15s %-12s %8s    %-10s %5s %5s %5s %5s %5s %5s\n", "Name", "Department", "Grade", "SID", "HW", "Quiz", "Midterm", "Final", "Other", "Total");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < numSRecords; i++) {
        printf("%-15s %-12s %8d    %-10s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n", srecords[i].student.name, srecords[i].student.department, srecords[i].student.grade, srecords[i].student.sid, srecords[i].hw, srecords[i].quiz, srecords[i].midterm, srecords[i].final, srecords[i].other, srecords[i].total);
    }
}


void randomInitStudents(Student students[], int numStudents) {
    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < numStudents; i++) {
        // Generate random student data
        sprintf(students[i].name, "Student %03d", i + 1);
        sprintf(students[i].department, "Department %d", rand() % 5 + 1);
        students[i].grade = rand() % 4 + 1;
        sprintf(students[i].sid, "SID%04d", rand() % 1000 + 1);
    }
}
