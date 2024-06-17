#include <stdio.h>
#include <string.h>
#include "myhead.h"

#define MAX_STUDENT 100

void searchSRecords(SRecord srecords[], int numSRecords) {
    char searchInput[50];
    printf("Enter name or SID to search: ");
    scanf(" %[^\n]s", searchInput);
    // fgets(searchInput, sizeof(searchInput), stdin);
    // searchInput[strcspn(searchInput, "\n")] = '\0'; // Remove the trailing newline character
    // Strip the final '\n' character from searchInput
    // if (searchInput[strlen(searchInput) - 1] == '\n') {
    //     searchInput[strlen(searchInput) - 1] = '\0';
    // }
    printf("Search for %s\n", searchInput);
    // scanf(" %s", searchInput); // For simplicity, assuming SID can be input as a string

    int found = 0;
    for (int i = 0; i < numSRecords; i++) {
        if ((strstr(srecords[i].student.name, searchInput) != NULL) || (strcmp(searchInput, srecords[i].student.sid) == 0)) {
            // Assuming printSRecord is a function that prints a single student record
            printSRecord(srecords[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found for %s.\n", searchInput);
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Read student records from CSV\n");
    printf("2. Print student records\n");
    printf("3. Sort by total and print student records\n");
    printf("4. Search for a student record by name or SID\n");
    printf("5. Exit\n");
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
                searchSRecords(srecords, numSRecords);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}