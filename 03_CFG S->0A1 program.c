#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool parseA(const char *str, int *index);

bool parseS(const char *str, int *index) {
    // Check for the initial '0'
    if (str[*index] == '0') {
        (*index)++;
        // Check for the A part
        if (parseA(str, index)) {
            // Check for the trailing '1'
            if (str[*index] == '1') {
                (*index)++;
                return true;
            }
        }
    }
    return false;
}

bool parseA(const char *str, int *index) {
    // A -> 0A
    if (str[*index] == '0') {
        (*index)++;
        return parseA(str, index);
    }
    // A -> 1A
    else if (str[*index] == '1') {
        (*index)++;
        return parseA(str, index);
    }
    // A -> e (epsilon)
    else {
        return true;
    }
}

bool isValidString(const char *str) {
    int index = 0;
    if (parseS(str, &index) && str[index] == '\0') {
        return true;
    }
    return false;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}
