#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char str[]);

int main() {
    char message[200];
    int choice;

    do {
        printf("\n===== TCS Secure Message System =====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter the message to ENCODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0'; 
                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter the message to DECODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;

            case 3:
                printf("\nExiting system... Stay secure!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to encode message
void encodeMessage(char message[]) {
    reverseString(message); 

    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ (1 << 1); 
        message[i] = message[i] ^ (1 << 4); 
    }

    printf("\nEncoded Message:\n%s\n", message);
}

// Function to decode message
void decodeMessage(char message[]) {
   
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ (1 << 1); 
        message[i] = message[i] ^ (1 << 4); 
    }

    reverseString(message); 

    printf("\nDecoded Message:\n%s\n", message);
}

