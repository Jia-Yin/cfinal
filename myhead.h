#ifndef MYHEAD_H
#define MYHEAD_H

#include <stdio.h>

// 定義學生結構
typedef struct {
    char name[50];
    char department[50];
    int grade;
    char sid[50];
} Student;

void printStudents(Student students[], int numStudents);
void randomInitStudents(Student students[], int numStudents);
// void sortStudentsBySID(Student* students, int numStudents);
// void sortStudentsByName(Student* students, int numStudents);
void sortStudents(Student* students, int numStudents, const char* sortBy);

#endif // MYHEAD_H