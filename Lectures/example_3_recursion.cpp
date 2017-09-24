#include <iostream>

using namespace std;

int sum(int n) {
    int s;
    if(n==0) { //Our stop condition
        return 0;
    } else {
        s = n + sum(n-1)
    }
    return s;
}

int main() {
    cout << "Sum: " << sum(4) << endl;
    return 0;
}
