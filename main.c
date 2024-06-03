#include <stdio.h>
#include "myhead.h"

#define MAX_STUDENT 10

int main() {
    // 創建並初始化學生實例
    Student students[MAX_STUDENT];
    randomInitStudents(students, MAX_STUDENT);
    
    sortStudentsbySID(students, MAX_STUDENT);
    printStudents(students, MAX_STUDENT);

    sortStudentsbyName(students, MAX_STUDENT);
    printStudents(students, MAX_STUDENT);

    sortStudentsbyGrade(students, MAX_STUDENT);
    printStudents(students, MAX_STUDENT);


    return 0;
}