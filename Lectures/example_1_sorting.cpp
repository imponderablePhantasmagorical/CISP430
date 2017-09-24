#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    //Seed our random number generator
    srand(time(NULL));
    double time_start,
        time_end;

    //Initialize and create our array
    int num_entries = 20000;
    int max_num_possible = 1000;
    int numbers[num_entries];
    for(int i=0; i < num_entries; i++) {
        //Generate the random number 
        numbers[i] = rand() % max_num_possible;
    }

    //Set our initial "max"
    int max_num = numbers[0];

    //Start our timer
    time_start = clock(); //time(NULL);

    //Start the max finding algorithm
    for(int i=1; i < num_entries; i++) {
        if(numbers[i] > max_num) {
            cout << "New Max Found:" << numbers[i] << endl;
            max_num = numbers[i];
        }
    }
    time_end = clock(); //time(NULL);
    cout << "Total Runtime (s): " << (float(time_end-time_start)/CLOCKS_PER_SEC) << endl << endl;
    cout << "Max number is: " << max_num << endl;

    return 0;
}
