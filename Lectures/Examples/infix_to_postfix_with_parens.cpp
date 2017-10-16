#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
char stack[MAX];
int top = -1;

bool is_operator(char symbol);
int precedence(char c);
int is_empty();
int is_full();
char peek();
void push(char item);
char pop();

int main() {
    string output = ""; //Postfix string
    string input = "";
    //Get input infix string
    cout << "Please enter an infix expression: ";
    cin >> input;

    //Output a header
    cout << "Log: " << endl;
    cout << "==============================" << endl;

    //Iterate through our input
    for(int i = 0; i < input.size(); i++) {
        //Set our current working character
        char symbol = input[i];

        //Determine if the symbol is a paren, operator or operand
        //Is an open paren, push into stack
        if(symbol == '(') {
            cout << "Found an open paren. Pushing to stack." << endl;
            push(symbol);
        } else if(symbol == ')') {
            cout << "Found a closing paren. Pushing all symbols on stack into output" << endl;
            //Found a closing paren. Outputting all symbols on stack until opening paren is found
            while(!is_empty()) {
                //If we reach our opening paren, pop it and break the loop
                if(peek() == '(') {
                    pop();
                    break;
                }
                //The symbol wasn't an open paren. Pop it and add to output
                cout << "Pushing " << peek() << endl;
                output += pop();
            }
        } else if(is_operator(symbol)) {
            //Symbol was an operator or parenthesis
            cout << symbol << " is a operator" << endl;
            if(is_empty()) {
                cout << "Stack was empty. Adding "  << symbol << endl;
            } else if(precedence(peek()) > precedence(symbol)) {
                cout << "Stack Top Higher Prec, Popping " << peek() << " then pushing " << symbol << endl;
                output += pop();
            } else if(precedence(symbol) > precedence(peek())) {
                cout << "Stack Top Lower Prec, Pushing " << symbol << endl;
            }
            push(symbol);
        } else {
            //Symbol was an operand
            cout << symbol << " is an operand. Outputting." << endl;
            output += symbol;
        }
    }
    //Done parsing string, pop all remaining operators and add to output
    while(!is_empty()) {
        output += pop();
    }

    cout << endl << endl << "Final Output: " << endl;
    cout << output;
    return 0;
}

//Postfix Operations
bool is_operator(char symbol)  {
    if(symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return true;
    }
    return false;
}

int precedence(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

//Stack
int is_empty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int is_full() {
    if(top == MAX) {
        return 1;
    } else {
        return 0;
    }
}

char peek() {
    if(is_empty()) {
        cout << "Stack is empty. Cannot peek" << endl;
    }
    return stack[top];
}

void push(char item) {
    if(is_full()) { 
        cout << "Stack is full. Cannot push" << endl;
        return;
    }
    top = top + 1;
    stack[top] = item;
}

char pop() {
    if(is_empty()) {
        cout << "Stack is empty. Cannot pop" << endl;
        return 0;
    }
    int temp = stack[top];
    top = top - 1;
    return temp;
}
