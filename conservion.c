#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char*);

// Function to convert decimal to binary and return as a string
char* decimalToBinary(int decimal)
{
    // Allocate space for a 32-bit binary string + '\0'
    char* binary = (char*)malloc(33);
    if (binary == NULL) return NULL; // Safety check

    int i = 0;
    
    // FIX: Using do-while ensures '0' maps correctly to '0'
    do {
        binary[i++] = '0' + (decimal & 1);
        decimal >>= 1;
    } while (decimal > 0);
    
    binary[i] = '\0';
    reverseString(binary);
    return binary;
}

// Function to convert binary to decimal and return as an integer
int binaryToDecimal(char binary[])
{
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}
// driver code
int main()
{
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Goodbye!\n");
            break;
        }

        char input[100]; 
        int decimalInput; // FIX: Isolated variable to preserve choice menu

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalInput); // FIX: Read into decimalInput
            char* result = decimalToBinary(decimalInput);
            if (result != NULL) {
                printf("Decimal to Binary: %s\n", result);
                free(result);
            }
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            int binaryResult = binaryToDecimal(input);
            printf("Binary to Decimal: %d\n", binaryResult);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// reversing string
void reverseString(char* str)
{
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}