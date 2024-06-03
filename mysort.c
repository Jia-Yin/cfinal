#include <stdlib.h>
#include <string.h>
#include "myhead.h"

// Comparison function for qsort
int compareStudentSID(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->sid, studentB->sid);
}

int compareStudentName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

int compareStudentGrade(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return studentA->grade - studentB->grade;
}

void sortStudentsbySID(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareStudentSID);
}

void sortStudentsbyName(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareStudentName);
}

void sortStudentsbyGrade(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareStudentGrade);
}