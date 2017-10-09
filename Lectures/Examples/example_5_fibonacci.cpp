#include <iostream>

using namespace std;

//Function is 0 based (because the 0th fibonacci number = 1)
// ie fibonacci(3) returns the 4th fibonacci number
int fibonacci(int n) {
    int f;
    if(n==1 || n==0) {
        f = 1;
    } else {
        f = fibonacci(n-1) + fibonacci(n-2);
    }
    return f;
}

int main() {
    int n = 3;
    for(int i = 0; i < n; i++) {
        cout << "Fibonacci(" << i << "): " << fibonacci(i) << endl;
    } 
    return 0;
}
