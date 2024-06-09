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

typedef struct {
    Student student;
    // 作業,平時測驗,期中測驗,期末報告,其他(出席及平時表現),原始成績
    double hw, quiz, midterm, final, other, total;
} SRecord;

void printStudents(Student students[], int numStudents);
void printSRecords(SRecord srecords[], int numSRecords);
int readSRecordsFromCSV(const char* filename, SRecord srecords[], int maxNumSRecords);



void randomInitStudents(Student students[], int numStudents);
// void sortStudentsBySID(Student* students, int numStudents);
// void sortStudentsByName(Student* students, int numStudents);
void sortStudents(Student* students, int numStudents, const char* sortBy);

#endif // MYHEAD_H