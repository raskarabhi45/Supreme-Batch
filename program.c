#include <stdio.h> // Include necessary header

int main() {
    char c = 'a'; // Declare 'c' as a character variable and initialize it with 'a'

    switch (c) {
        case 97: // Use integer value 97 (ASCII code for 'a')
            printf("Hello");
            break;
        case 'a': // Use character 'a'
            printf("Hi");
            break;
        default:
            printf("No Case");
    }

    return 0;
}
