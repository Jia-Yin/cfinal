#include <stdio.h>
#include "myhead.h"

#define MAX_STUDENT 100

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Read student records from CSV\n");
    printf("2. Print student records\n");
    printf("3. Sort by total and print student records\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    SRecord srecords[MAX_STUDENT];
    int numSRecords = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numSRecords = readSRecordsFromCSV("records.csv", srecords, MAX_STUDENT);
                printf("%d records read.\n", numSRecords);
                break;
            case 2:
                if (numSRecords > 0) {
                    printSRecords(srecords, numSRecords);
                } else {
                    printf("No records to display. Please read records first.\n");
                }
                break;
            case 3:
                if (numSRecords > 0) {
                    sortSRecords(srecords, numSRecords, "total");
                    printf("\nAfter sorting by total:\n");
                    printSRecords(srecords, numSRecords);
                } else {
                    printf("No records to sort. Please read records first.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}