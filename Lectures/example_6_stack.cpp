#include <iostream>

using namespace std;

const int MAX = 100;
int stack[MAX];
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

int peek() {
    if(is_empty()) {
        cout << "Stack is empty. Cannot peek" << endl;
    }
    return stack[top];
}

void push(int item) {
    if(is_full()) { 
        cout << "Stack is full. Cannot push" << endl;
        return;
    }
    top = top + 1;
    stack[top] = item;
}

int pull() {
    if(is_empty()) {
        cout << "Stack is empty. Cannot pop" << endl;
        return 0;
    }
    int temp = stack[top];
    top = top - 1;
    return temp;
}

int main() {
    push(10);
    push(5);
    cout << pull() << endl;
    cout << pull() << endl;
    cout << pull() << endl; //Produces error

    return 0;
}
