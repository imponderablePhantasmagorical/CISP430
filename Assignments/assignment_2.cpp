/*
Taylor Britton
CISP 430 - Mon/Wed 1:00pm
Assignment 2 - Fibonacci Table
*/

#include <iostream>
#include <iomanip>

using namespace std;

int fibonacci(int n) {
    int f;
    //If n is 1 or 0, we are at the end of our sequence and need to stop
    if(n<=1) {
        f = 1;
    } else {
        //Add the previous two entries together
        f = fibonacci(n-1) + fibonacci(n-2);
    }
    return f;
}

int main() {
    int n = 0;
    cout << "Please enter a value for n: ";
    cin >> n;
    cout << endl;

    //Print the header
    cout << "   ";
    for(int i = 0; i <= n; i++)  {
        cout << setw(5) << i;
    }
    cout << endl;
    //End header

    //Run our fibonacci function for values of 0 to n
    for(int i = 0; i <= n; i++) {    
        cout << "n=" << i; //Print n on line num
        //For each i, we want the fibonacci for each number up until i
        for(int j = 0; j <= i; j++) {
            //Output the fibonacci!
            cout << setw(5) << right << fibonacci(j);
        }
        cout << endl;
    } 
    return 0;
}
