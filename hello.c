#include <stdio.h>
#include <ctype.h>

#define SHIFT 3  // Shift value for encryption

int main() {
    char text[100];
    int i;

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            // Encrypt uppercase letters
            text[i] = ((text[i] - 'A' + SHIFT) % 26) + 'A';
        } else if (islower(text[i])) {
            // Encrypt lowercase letters
            text[i] = ((text[i] - 'a' + SHIFT) % 26) + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }

    printf("Encrypted text: %s", text);
    return 0;
}
/*making any changes 01
changes 02 03
*/