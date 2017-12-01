#include <iostream>
#include <string>

using namespace std;

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

int main() {
    string input = "{(())}";
    for(char& c : string) {
        if(c == "{" || c == "(" || c == "[") {
            push(c);
        } else if(c == "}", c == ")" || c == "]") {
        }

    return 0;
}
