/*
 * Input
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |
| 9 | 10| 11| 12|
| 0 | 0 | 0 | 0 |
*/
#include <iostream>

using namespace std;

int main() {
    int n = 4;
    int input_array[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {0,0,0,0} };
    for(int row = 0; row < n-1; row++) {
        int sum = 0; //Initialize our current columns sum variable
        for(int column = 0; column < n; column++) {
            sum += input_array[row][column];
        }
        input_array[3][column] = sum; //set our last row of the column to our sum
    }

    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++) {
            cout << " " << input_array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


