#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to simulate the NFA
bool simulateNFA(const char *str, int index, int state) {
    int length = strlen(str);
    
    // If we've reached the end of the string, check if we are in the accepting state
    if (index == length) {
        return state == 2; // accepting state
    }

    char currentChar = str[index];

    switch (state) {
        case 0:
            // Initial state, expecting 'o' to transition to state 1
            if (currentChar == 'o') {
                return simulateNFA(str, index + 1, 1);
            }
            break;
        case 1:
            // Middle state, we can transition to state 2 if current char is '1', or stay in state 1
            if (currentChar == '1') {
                return simulateNFA(str, index + 1, 2);
            } else {
                return simulateNFA(str, index + 1, 1);
            }
            break;
        case 2:
            // Accepting state, we can transition here only if current char is '1'
            if (currentChar == '1') {
                return simulateNFA(str, index + 1, 2);
            }
            break;
        default:
            return false;
    }
    
    return false;
}

bool isAcceptedByNFA(const char *str) {
    return simulateNFA(str, 0, 0);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isAcceptedByNFA(str)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}
