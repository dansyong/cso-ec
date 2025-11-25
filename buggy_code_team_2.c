#include <stdio.h>

#define MAX_N 100

int main(void) {
    int a[MAX_N];
    int n = 0;
    int x;

    // read non-negative integers until negative or limit
    while (n < MAX_N && scanf("%d", &x) == 1 && x >= 0) { // n should be less than MAX_N because the array shouldn't go up to MAX_N
        a[n] = x;
        n++;
    }

    if (n == 0) {
        printf("No data.\n");
        return 0;
    }

    int best_len = 0;     // length of best increasing run
    int best_start = 0;   // starting index of best run
    int curr_len = 1;     // length of current run
    int curr_start = 0;   // starting index of current run

    for (int i = 1; i < n; i++) {           // scan through array of inputs
        if (a[i] > a[i - 1]) {             // still increasing
            curr_len++;
        } else {
            if (curr_len >= best_len) {    // update best run
                best_len = curr_len;
                best_start = curr_start;
            }
            curr_len = 1;
            curr_start = i + 1;            // new run starts here
        }
    }

    // print the best increasing run we found
    printf("Longest increasing run length: %d\n", best_len);
    printf("Run values: ");
    for (int i = best_start; i < best_start + best_len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
