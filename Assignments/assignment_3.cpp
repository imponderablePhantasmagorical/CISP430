/*  Taylor Britton
 *  CISP430 - Mon/Wed 1:00pm
 *  Assignment 3
 */
#include <iostream>
#include <string>

const int MAX = 100;
char stack[MAX];
int top = -1;
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
        std::cout << "Stack is empty. Cannot peek" << std::endl;
    }
    return stack[top];
}

void push(int item) {
    if(is_full()) { 
        std::cout << "Stack is full. Cannot push" << std::endl;
        return;
    }
    top = top + 1;
    stack[top] = item;
}

char pop() {
    if(is_empty()) {
        std::cout << "Stack is empty. Cannot pop" << std::endl;
        return 0;
    }
    char temp = stack[top];
    top = top - 1;
    return temp;
}

int main() {
    bool error_flag = false; //Flag to end early due to error in parsing
    std::cout << "Enter a string to parse: ";
    std::string input;
    std::cin >> input;

    //std::string input = "{(([]))}";

    //Iterate through our input
    for(int i = 0; i < input.size(); i++) {
        //Set our current working character
        char c = input[i];

        //Open symbols are pushed onto the stack
        if((c == '{' || c == '(' || c == '[') && error_flag == false) {
            push(c);
        //Closing symbols are compared to the top of the stack. 
        //If they match, we remove the symbol from the top of the stack. 
        //Otherwise, we can end early as our string is not balanced
        } else {
            switch(c) {
                case('}'):
                    if(peek() == '{') {
                        pop();
                    } else {
                        error_flag = true;
                    }
                    break;
                case(')'):
                    if(peek() == '(') {
                        pop();
                    } else {
                        error_flag = true;
                    }
                    break;
                case(']'):
                    if(peek() == '[') {
                        pop();
                    } else {
                        error_flag = true;
                    }
                    break;
                default:
                    std::cout << "Unknown symbol found" << std::endl;
                    break;
            }
            if(error_flag) {
                std::cout << "Error parsing closing character " << c << ". Was expecting " << peek() << std::endl; 
            }
        }
    }
    //If there were no errors, our string has balanced symbols
    if(!error_flag && is_empty()) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    return 0;
}
