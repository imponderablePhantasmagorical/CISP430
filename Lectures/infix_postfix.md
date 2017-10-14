# Infix and Postfix
Infix Expression: The expression of form a op b, where an operator is in between every pair of operands. (ie. a + b)
Postfix: The expression of the form a b op, where an operator is followed for every pair of operands (ie. a b +)
Note: Operands are all letters and digits

Postfix makes it easy to evaluate operations on multiple operands by making it easier and faster to read the operations.

Standard Steps of Alogrithm:
Ex. "A * B + C" => A B * C +
1. Print operands as they arrive
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack
3. If the incoming symbol is a left parentehsis, push it onto the stack
4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parenthesis
5. If the incoming symbol has a higher precedence than the top of the stack, push it on the stack
6. If the incoming symbol has equal precedence with the top, use association. 
    a. If the association is left-to-right,

## Evaluating a postfix string
1. Scan the postfix from LEFT TO RIGHT, until end of postfix
2. If a char is operand (0..9), push char into stack and go back to 1
3. Else if a char is operator (\*, +, -, /), pop the two elements from the stack. 
4. Apply the operation to the popped elements from step 3.
5. Push the result back into the stack
6. When postfix is done being evaluated, the last element in the stack is the answer
