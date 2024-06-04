#include <stdlib.h>
#include <string.h>
#include "myhead.h"

// Comparison function for qsort
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->sid, studentB->sid);
}

// Comparison function by name
int compareStudentsByName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

void sortStudents(Student* students, int numStudents, const char* sortBy) {
    if (strcmp(sortBy, "sid") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudents);
    } else if (strcmp(sortBy, "name") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudentsByName);
    } else {
        // Handle invalid sortBy parameter
        // You can throw an error, print a message, or take any other appropriate action
    }
}
