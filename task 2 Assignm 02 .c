#include <stdio.h>
#include <string.h>


void getCustomerInfo();
void displayInventory();
void addToCart();
void displayTotalBill();
void showInvoice();


char productNames[5][50] = {"Hand senitizer", "Face wash", "Lotion", "Tissue Pack"};
int productCode[4] = {001, 002, 003, 004};
float prices[4] = { 100.00, 200.00, 300.00, 150.00};
int stock[4] = {50, 10, 20, 8};

// Cart Arrays
int cartQuantity[5] = {0};
float totalBill = 0.0;
float discountedBill = 0.0;

// Customer Information
char customerName[50];
char customerCNIC[20];

int main() {
    int choice;
    int exitFlag = 0;

    printf("========================================\n");
    printf("     SUPERMARKET INVENTORY SYSTEM\n");
    printf("========================================\n");

    while (!exitFlag) {
        printf("\nMenu:\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getCustomerInfo();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addToCart();
                break;
            case 4:
                displayTotalBill();
                break;
            case 5:
                showInvoice();
                break;
            case 6:
                exitFlag = 1;
                printf("Exiting the system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// 1. Customer Info
void getCustomerInfo() {
    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", customerName);  // To take full name input
    printf("Enter Customer CNIC: ");
    scanf(" %[^\n]", customerCNIC);
    printf("Customer information saved successfully.\n");
}

// 2. Display Inventory
void displayInventory() {
    printf("\n%-10s %-15s %-10s %-10s\n", "Product Code", "Product", "Price", "Stock");
    printf("---------------------------------------------\n");
    int i;
    for ( i = 0; i < 4; i++) {
        printf("%-10d %-15s %-10.2f %-10d\n", productCode[i], productNames[i], prices[i], stock[i]);
    }
}

// 3. Add to Cart
void addToCart() {
    int prodNum, qty, found = 0;
    displayInventory();
    printf("\nEnter the Product Number to add to cart: ");
    scanf("%d", &prodNum);
    int i;
    for ( i = 0; i < 5; i++) {
        if (productCode[i] == prodNum) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (qty <= stock[i]) {
                cartQuantity[i] += qty;
                stock[i] -= qty;
                printf("Item added to cart successfully!\n");
            } else {
                printf("Sorry, only %d items left in stock.\n", stock[i]);
            }
            break;
        }
    }

    if (!found) {
        printf("Invalid product number.\n");
    }
}

// 4. Display Total Bill
void displayTotalBill() {
    totalBill = 0.0;
    int i;
    for ( i = 0; i < 5; i++) {
        totalBill += prices[i] * cartQuantity[i];
    }

    printf("\nYour total bill is: %.2f\n", totalBill);

    char promo[20];
    printf("Do you have a promocode? (Enter code or 'no'): ");
    scanf(" %[^\n]", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        discountedBill = totalBill - (totalBill * 0.25);
        printf("Promo code applied! You got 25%% discount.\n");
    } else {
        discountedBill = totalBill;
        printf("No discount applied.\n");
    }
}

// 5. Show Invoice
void showInvoice() {
    printf("\n================ INVOICE ================\n");
    printf("Customer Name: %s\n", customerName);
    printf("Customer CNIC: %s\n", customerCNIC);
    printf("-----------------------------------------\n");
    printf("%-15s %-10s %-10s\n", "Product", "Qty", "Price");
    int i;
    for ( i = 0; i < 5; i++) {
        if (cartQuantity[i] > 0) {
            printf("%-15s %-10d %-10.2f\n", productNames[i], cartQuantity[i], prices[i] * cartQuantity[i]);
        }
    }

    printf("-----------------------------------------\n");
    printf("Total Bill: %.2f\n", totalBill);
    printf("After Discount: %.2f\n", discountedBill);
    printf("=========================================\n");
}

