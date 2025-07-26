#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    char ch;

    input = fopen("Login.txt", "r");
    if (input == NULL) {
        puts("File read error");
        exit(1);
    }

    output = fopen("Output.txt", "w");
    if (output == NULL) {
        puts("File write error");
        fclose(input);
        exit(1);
    }

    // Read characters from input file, encrypt, and write to output file
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch + 3, output);
    }

    printf("Encryption process completed successfully.\n");
    printf("Output.txt file is generated.\n");

    fclose(input);
    fclose(output);
    
    return 0;
}

// hello there