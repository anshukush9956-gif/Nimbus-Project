
#include <stdio.h>

#define MAX 100

// Structure to store book details
struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
};

// Function declarations
void addBook(struct Book *b, int *n);
void displayBooks(struct Book *b, int n);
void searchBook(struct Book *b, int n);
void issueBook(struct Book *b, int n);
void returnBook(struct Book *b, int n);
void updateBook(struct Book *b, int n);

int main() {
    struct Book books[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n====================================\n");
        printf("   LIBRARY BOOK MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Update Book Details\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addBook(books, &count);
                break;

            case 2:
                displayBooks(books, count);
                break;

            case 3:
                searchBook(books, count);
                break;

            case 4:
                issueBook(books, count);
                break;

            case 5:
                returnBook(books, count);
                break;

            case 6:
                updateBook(books, count);
                break;

            case 7:
                printf("\nThank you for using the Library System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

// Function to add a new book
void addBook(struct Book *b, int *n) {
    int id, i;

    if (*n >= MAX) {
        printf("\nLibrary storage is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    // Check for duplicate ID
    for (i = 0; i < *n; i++) {
        if (b[i].id == id) {
            printf("\nBook ID already exists!\n");
            return;
        }
    }

    b[*n].id = id;

    printf("Enter Book Title: ");
    scanf(" %49[^\n]", b[*n].title);

    printf("Enter Author Name: ");
    scanf(" %49[^\n]", b[*n].author);

    b[*n].available = 1;

    (*n)++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks(struct Book *b, int n) {
    int i;

    if (n == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n========== BOOK LIST ==========\n");

    for (i = 0; i < n; i++) {
        printf("\nBook ID: %d", b[i].id);
        printf("\nTitle: %s", b[i].title);
        printf("\nAuthor: %s", b[i].author);

        if (b[i].available == 1)
            printf("\nStatus: Available\n");
        else
            printf("\nStatus: Issued\n");
    }
}

// Function to search for a book
void searchBook(struct Book *b, int n) {
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (b[i].id == id) {
            printf("\nBook Found!");
            printf("\nBook ID: %d", b[i].id);
            printf("\nTitle: %s", b[i].title);
            printf("\nAuthor: %s", b[i].author);

            if (b[i].available == 1)
                printf("\nStatus: Available\n");
            else
                printf("\nStatus: Issued\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}

// Function to issue a book
void issueBook(struct Book *b, int n) {
    int id, i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (b[i].id == id) {

            if (b[i].available == 1) {
                b[i].available = 0;
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is already issued!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

// Function to return a book
void returnBook(struct Book *b, int n) {
    int id, i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (b[i].id == id) {

            if (b[i].available == 0) {
                b[i].available = 1;
                printf("\nBook returned successfully!\n");
            } else {
                printf("\nThis book is already available!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

// Function to update book details
void updateBook(struct Book *b, int n) {
    int id, i;

    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (b[i].id == id) {

            printf("\nEnter New Book Title: ");
            scanf(" %49[^\n]", b[i].title);

            printf("Enter New Author Name: ");
            scanf(" %49[^\n]", b[i].author);

            printf("\nBook details updated successfully!\n");
            return;
        }
    }

    printf("\nBook not found!\n");
}
