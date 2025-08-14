#include <stdio.h>

/*
This program calculates the foo sequence based on the number of times the user has entered.
*/

int _foo_sequence(int n, int n4, int n3, int n2, int n1) {
    /*
    This function checks for the four base cases and calls upon itself if none of the base cases match.
    @n4 is the expression n - 1.
    @n3 is the expression n - 2.
    @n2 is the expression n - 3.
    @n1 is the expression n - 4.
    @returns an integer according to the base case.
    */

    if (n == 0) {
        return 3;
    } else if (n == 1) {
        return 6;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return n4;
    } else {
        return _foo_sequence(n - 1, n4 + n3 + n2 - n1 + 1, n4, n3, n2);
    }
}

int foo_sequence(int n) {
    /*
    This program calls the _foo_sequence function.
    @returns the answer of the foo sequence.
    */

    return _foo_sequence(n, 7, 2, 6, 3);
}

int main() {
    /*
    This is the main function of the program.
    @n stores the number of sequences of foo sequences.
    @sequence stores the answer for the foo sequence based on n.
    */

    int n;
    int sequence;

    printf("Enter a value for n: ");
    scanf("%d", &n);

    sequence = foo_sequence(n);

    printf("Foo(%d) = %d", n, sequence);

    return 0;
}