#include <stdio.h>
#include <string.h>

// Function prototypes
void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount);
void processSale(int isbns[], int quantities[], int bookCount);
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int bookCount = 0;
    int choice;

    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &bookCount);
                break;

            case 2:
                processSale(isbns, quantities, bookCount);
                break;

            case 3:
                generateLowStockReport(isbns, titles, prices, quantities, bookCount);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}

// Function to add a new book
void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount) {
    int newISBN, i;
    char newTitle[50];
    float newPrice;
    int newQuantity;

    if (*bookCount >= 100) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    // Check for duplicate ISBN
    for (i = 0; i < *bookCount; i++) {
        if (isbns[i] == newISBN) {
            printf("Error: A book with this ISBN already exists!\n");
            return;
        }
    }

    printf("Enter Title: ");
    getchar(); // clear newline character
    gets(newTitle);

    printf("Enter Price: ");
    scanf("%f", &newPrice);

    printf("Enter Quantity: ");
    scanf("%d", &newQuantity);

    // Store values in arrays
    isbns[*bookCount] = newISBN;
    strcpy(titles[*bookCount], newTitle);
    prices[*bookCount] = newPrice;
    quantities[*bookCount] = newQuantity;

    (*bookCount)++;

    printf("Book added successfully!\n");
}

// Function to process a sale
void processSale(int isbns[], int quantities[], int bookCount) {
    int searchISBN, copiesSold, found = 0;

    if (bookCount == 0) {
        printf("No books in inventory.\n");
        return;
    }

    printf("Enter ISBN of the book sold: ");
    scanf("%d", &searchISBN);

    for (int i = 0; i < bookCount; i++) {
        if (isbns[i] == searchISBN) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &copiesSold);

            if (copiesSold > quantities[i]) {
                printf("Error: Not enough stock available!\n");
            } else {
                quantities[i] -= copiesSold;
                printf("Sale processed successfully! Remaining quantity: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (!found)
        printf("Book with ISBN %d not found.\n", searchISBN);
}

// Function to generate low-stock report
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    int found = 0;
    printf("\n===== Low Stock Report (Quantity < 5) =====\n");

    for (int i = 0; i < bookCount; i++) {
        if (quantities[i] < 5) {
            found = 1;
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: %s\n", titles[i]);
            printf("Price: Rs. %.2f\n", prices[i]);
            printf("Quantity: %d\n\n", quantities[i]);
        }
    }

    if (!found)
        printf("All books have sufficient stock.\n");
}

