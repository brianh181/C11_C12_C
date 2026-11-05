#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void reverseArray(char *arr, int n) {
    int loopingnum = n;
    if (loopingnum % 2 == 0) {
        loopingnum /= 2;
    } else {
        loopingnum = (loopingnum - 1) / 2;
    }

    for (int i = 0; i < loopingnum; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main(void) {
    char sentence[100], snop[100], palidrome[100];

    memset(sentence, '\0', sizeof(sentence));
    memset(snop, '\0', sizeof(snop));
    memset(palidrome, '\0', sizeof(palidrome));

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int j = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            snop[i - j] = toupper(sentence[i]);
            palidrome[i - j] = toupper(sentence[i]);
        } else {
            j++;
        }
    }
    snop[-1] = '\0'; // Null-terminate the modified string
    palidrome[-1] = '\0'; // Null-terminate the palindrome string

    reverseArray(palidrome, strlen(palidrome));

    for (int i = 0; i < strlen(snop); i++) {
        if (snop[i] != palidrome[i]) {
            printf("The sentence is not a palindrome.\n");
            return 0;
        }
    }

    printf("The sentence is a palindrome.\n");
    return 0;

}