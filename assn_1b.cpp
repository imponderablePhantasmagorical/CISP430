// This program contains many syntax errors and will not compile.
// Fix the errors so that it correctly finds the average of the
// two integers the user enters. 
// PUT YOUR NAME HERE.

#include <iostream>
using namespace std;
  
int main() {
    int num1, num2;
    double average;
    
    // Input 2 integers
    cout << "Enter two integers separated by one or more spaces: ";
    cin >> num1 >> num2;
 
    //Find and display their average
    average = (num1 + num2) / 2.0;

    cout << "\nThe average of these 2 numbers is " << average << endl;
   
    return 0;
}



