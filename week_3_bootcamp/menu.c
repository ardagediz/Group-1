#include <stdio.h>

int main() {
    int choice;

    printf("MENU OPTIONS\n");
    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Option 4\n");
    printf("5. Option 5\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You selected Option 1.\n");
            break;
        case 2:
            printf("You selected Option 2.\n");
            break;
        case 3:
            printf("You selected Option 3.\n");
            break;
        case 4:
            printf("You selected Option 4.\n");
            break;
        case 5:
            printf("You selected Option 5.\n");
            break;
        default:
            printf("Invalid choice! Please select a valid option (1-5).\n");
    }

    return 0;
}
