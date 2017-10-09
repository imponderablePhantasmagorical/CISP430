/**
_Find the factorial of a number **n**_
_Note: n! = (1 * 2 * ... * n-1 * n)_
_0! = 1_

fact(3) = 3 * fact(2)      Return 6 (3 * 2)
            2 * fact(1)    Return 2 (2 * 1)
               1 * fact(0) Return 1
*/

#include <iostream>

using namespace std;

int factorial(int n) {
    int f = 0;
    if(n==0) {
        f = 1; //Stop condition. Return 1 because fact(0) = 1
    } else {
        f = n * factorial(n-1); //Recursion call
    }
    return f; //Return our current factorial
}

int main() {
    cout << "Fact(0): " << factorial(0) << endl;
    cout << "Fact(3): " << factorial(3) << endl;
    cout << "Fact(4): " << factorial(4) << endl;
    return 0;
}
