#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

void minMax(int *arr, int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    //for (int i = 1; i < n; i++) {
    //    if (arr[i] < *min) {
    //        *min = arr[i];
    //    }
    //    if (arr[i] > *max) {
    //        *max = arr[i];
    //    }
    //}

    int *ptr;
    for (ptr = &arr[0]; ptr < &arr[n]; ptr++) {
        if (*ptr < *min) {
            *min = *ptr;
        }
        if (*ptr > *max) {
            *max = *ptr;
        }
    }

}

void reverseArray(int *arr, int n) {
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
    //Question 1: Swap two integers
    int x = 3, y = 9;
    printf("Before: x=%d y=%d\n", x, y);
    // call swap here
    int (*ptr)(int *, int *) = swap;
    ptr(&x, &y);
    printf("After: x=%d y=%d\n", x, y);

    //Question 2: Find smallest and largest
    int data[5] = {4, -2, 9, 0, 7};
    int lo, hi;
    minMax(data, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);

    //Question 3: Reverse an array
    int data2[6] = {1, 2, 3, 4, 5, 6};

    reverseArray(data2, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", data2[i]);
    }
    printf("\n");

    //The Function still works with odd numbers, it just doesn't do anything with the middle number.
    return 0;
}
