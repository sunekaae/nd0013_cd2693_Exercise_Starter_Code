#include "factorial.h"

// Your code goes here
// See factorial.h for your method's signature 
// (eg. its args and return value)
int factorial(int n) {
    if (n==1) {
        return 1;
    }
    else {
        int factorial_result = factorial(n-1);
        return n*factorial_result;
    }
}
