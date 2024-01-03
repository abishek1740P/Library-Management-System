#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
};

// Function prototypes
void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchBook(struct Book library[], int count, const char searchTitle[]);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display all Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3: {
                char searchTitle[100];
                printf("Enter the title to search: ");
                scanf("%s", searchTitle);
                searchBook(library, bookCount, searchTitle);
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a book to the library
void addBook(struct Book library[], int *count) {
    if (*count < MAX_BOOKS) {
        printf("Enter Book Title: ");
        scanf("%s", library[*count].title);
        printf("Enter Author: ");
        scanf("%s", library[*count].author);
        (*count)++;
        printf("Book added successfully!\n");
    } else {
        printf("Sorry, the library is full.\n");
    }
}

// Function to display all books in the library
void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
    } else {
        printf("\nLibrary Catalog:\n");
        for (int i = 0; i < count; i++) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("--------------------\n");
        }
    }
}

// Function to search for a book by title
void searchBook(struct Book library[], int count, const char searchTitle[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("\nBook Found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nBook not found.\n");
    }
}

