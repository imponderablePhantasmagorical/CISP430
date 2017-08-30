#include <iostream>
#include <math>

int main() {
    //Variables for tracking the number of items sold by scoop number`
    int single_scoop_sold = 0,
        double_scoop_sold = 0,
        triple_scoop_sold = 0;
    cout << "Number of single scoop cones sold: ";
    cin >> single_scoop_sold;
    cout << "Number of double scoop cones sold: ";
    cin >> double_scoop_sold;
    cout << "Number of triple scoop cones sold: ";
    cin >> triple_scoop_sold;

    //Create our variables for holding cost
    float single_scoop_cost = 1.49,
          double_scoop_cost = 2.49,
          triple_scoop_cost = 3.49;
    
    float single_scoop_total = floor((single_scoop_sold * single_scoop_cost)*100)/100,
          double_scoop_total = double_scoop_sold * double_scoop_cost,
          triple_scoop_total = triple_scoop_sold * triple_scoop_cost;

    cout << "DeLIGHTful Cones:

    return 0;
}
