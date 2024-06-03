#ifndef MYHEAD_H
#define MYHEAD_H

// 定義學生結構
typedef struct {
    char name[50];
    char department[50];
    int grade;
    char sid[50];
} Student;

void printStudents(Student students[], int numStudents);

// Your code goes here

#endif // MYHEAD_H