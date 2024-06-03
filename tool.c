#include <stdio.h>
#include "myhead.h"

void printStudents(Student students[], int numStudents) {
    // 打印學生信息
    printf("%-15s %-12s %8s    %-10s\n", "Name", "Department", "Grade", "SID");
    printf("------------------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%-15s %-12s %8d    %-10s\n", students[i].name, students[i].department, students[i].grade, students[i].sid);
    }
}
