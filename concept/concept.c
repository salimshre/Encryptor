#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    char ch;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file!\n");
        fclose(input);
        exit(1);
    }

    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, output);
    }

    printf("File copied successfully!\n");

    fclose(input);
    fclose(output);

    return 0;
}
