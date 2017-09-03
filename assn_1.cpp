#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

float round_two_places(float);

int main() {
    //Variables for tracking the number of items sold by scoop number`
    int single_scoop_sold = 0,
        double_scoop_sold = 0,
        triple_scoop_sold = 0;

    //Prompt user for input and store our data
    cout << "Number of single scoop cones sold: ";
    cin >> single_scoop_sold;
    cout << "Number of double scoop cones sold: ";
    cin >> double_scoop_sold;
    cout << "Number of triple scoop cones sold: ";
    cin >> triple_scoop_sold;
    cout << endl; //print an extra newline to seperate input and output

    //Create our variables for holding cost
    float single_scoop_cost = 1.49,
          double_scoop_cost = 2.49,
          triple_scoop_cost = 3.49;
    
    //Calculate our sales totals
    float single_scoop_total = round_two_places(single_scoop_sold * single_scoop_cost),
          double_scoop_total = round_two_places(double_scoop_sold * double_scoop_cost),
          triple_scoop_total = round_two_places(triple_scoop_sold * triple_scoop_cost);

    int total_num_sold = single_scoop_sold + double_scoop_sold + triple_scoop_sold;
    float total_money = single_scoop_total + double_scoop_total + triple_scoop_total;

    //Make our column widths easy to change in one place
    int col_1 = 30,
        col_2 = 5,
        col_3 = 15;
    //Output our formatted sales information
    cout << left << setw(col_1) << "DeLIGHTful Cones: "     << setw(col_2) << single_scoop_sold << "$" << setw(col_3) << single_scoop_total << endl;
    cout << left << setw(col_1) << "Double DeLIGHT Cones: " << setw(col_2) << double_scoop_sold << "$" << setw(col_3) << double_scoop_total << endl;
    cout << left << setw(col_1) << "Triple DeLIGHT Cones: " << setw(col_2) << triple_scoop_sold << "$" << setw(col_3) << triple_scoop_cost << endl;
    cout << left << setw(col_1) << "Total: " << setw(col_2) << total_num_sold << "$" << setw(col_3) << total_money;

    return 0;
}

float round_two_places(float num) {
    /*ie 1.2734 * 100 = 127.34,
      floor to get rid of the remaining decimals (which we don't want)
      then divide by 100 to move decimals back into correct place.*/
    return (floor(num*100)/100);
}
