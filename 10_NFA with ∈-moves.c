#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STATES 100

// Function to add an edge in the NFA transition table
void addTransition(int nfa[MAX_STATES][MAX_STATES], int fromState, int toState) {
    nfa[fromState][toState] = 1;
}

// Function to perform DFS and find the ε-closure
void dfs(int state, bool visited[], int nfa[MAX_STATES][MAX_STATES], int numStates) {
    visited[state] = true;
    for (int i = 0; i < numStates; i++) {
        if (nfa[state][i] && !visited[i]) {
            dfs(i, visited, nfa, numStates);
        }
    }
}

// Function to compute the ε-closure of all states
void computeEpsilonClosure(int nfa[MAX_STATES][MAX_STATES], int numStates) {
    for (int state = 0; state < numStates; state++) {
        bool visited[MAX_STATES] = {false};
        dfs(state, visited, nfa, numStates);
        
        // Print the ε-closure of the current state
        printf("ε-closure(%d): { ", state);
        for (int i = 0; i < numStates; i++) {
            if (visited[i]) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }
}

int main() {
    int numStates = 4;
    int nfa[MAX_STATES][MAX_STATES] = {0};

    // Add ε-transitions
    addTransition(nfa, 0, 1);
    addTransition(nfa, 1, 2);
    addTransition(nfa, 2, 3);
    addTransition(nfa, 3, 0);

    // Compute and print the ε-closure of all states
    computeEpsilonClosure(nfa, numStates);

    return 0;
}
