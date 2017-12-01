#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;

bool is_operator(char symbol);

int is_full();
int peek();
void push(char item);
int pop();
int eval_postfix(string);
int eval_operation(int,int,char);

//is_empty collides with std namespace, has to be it's own

namespace Postfix {
	int is_empty();
}


int main() {
    cout << eval_postfix("6324+-*");
    return 0;
}

int eval_postfix(string postfix) {
    /*
    Evaluating a postfix string
    1. Scan the postfix from LEFT TO RIGHT, until end of postfix string
    2. If a char is operand (0..9), push char into stack and go back to 1
    3. Else if a char is operator (\*, +, -, /), pop the two elements from the stack. 
    4. Apply the operation to the popped elements from step 3.
    5. Push the result back into the stack
    6. When postfix string is done being evaluated, the last element in the stack is the answer
    */
    for(int i=0; i < postfix.length(); i++) {
        //Set our current character for analysis
        char current_char = postfix[i];

        if(!is_operator(current_char)) {
            //Operand found. Convert to int and push onto the stack
            int current_num = (int)current_char-'0';
            push(current_num);
        } else {
            //found an operator, apply it to the two previously found operands 
            int a = pop();
            int b = pop(); 
            int output = eval_operation(a, b, current_char);
            push(output);
        }
    }
    return pop();
}

//Postfix Operations
bool is_operator(char symbol)  {
    if(symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return true;
    }
    return false;
}

int eval_operation(int a, int b, char operation) {
    switch(operation) {
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        case '-':
            return a - b;
            break;
        case '+':
            return a + b;
            break;
        default:
            return 0;
    }
}

//Stack
int Postfix::is_empty() {
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
    if(Postfix::is_empty()) {
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

int pop() {
    if(Postfix::is_empty()) {
        cout << "Stack is empty. Cannot pop" << endl;
        return 0;
    }
    int temp = stack[top];
    top = top - 1;
    return temp;
}


/* Sample Output 
*  input:  "53+2"
*  output: 16
*  (5 + 3 * 2 = 16)
*/

