#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the string is accepted by the DFA
bool isAccepted(char *str) {
    int state = 0; // Start in state 0
    
    // Process each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (c == '0') {
                    state = 1; // Move to state 1 if '0'
                } else {
                    return false; // Invalid if first character is not '0'
                }
                break;
            case 1:
                if (c == '0') {
                    state = 1; // Stay in state 1 if '0'
                } else if (c == '1') {
                    state = 1; // Stay in state 1 if '1'
                } else {
                    return false; // Invalid input
                }
                break;
            default:
                return false; // Should not reach here
        }
    }
    
    // String is accepted if we end in state 1 (which means ending with '1')
    return state == 1;
}

int main() {
    char input[100];

    // Get input from the user
    printf("Enter a string of '0' and '1': \n");
    scanf("%s", input);

    // Check if the input string is accepted by the DFA
    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }

    return 0;
}
