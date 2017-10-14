# Stack

The stack is a **Last in - First out** data structure
this means the last element put into the stack is the first element that can be removed
Stack acts like a dish-dispenser. Only the top plate can be removed from the stack

### Stack Operations
- **Push:** Adds an item to the stack. If the stack is flow, then it creates an overflow condition
- **Pull:** Removing the top-most element from the stack and returns it
- **Peek** or **Top:** Returns the top element from the stack, but does not remove it
- **isEmpty:** Returns true if the stack is empty, otherwise false
- **isFull:** Returns true if the stack is full, otherwise false

Push and pull are the MAIN operations on a stack

### Stack Members
**Top:** Contains a pointer to the top item in the stack


## Example
Suppose we have a stack of size 10. 

**Top** starts at -1 (indicates the stack is empty)

```
1. Push 'A'
    top = top + 1
    stack[top] = 'A'
2. Push 'B'
    top = top + 1 
    stack[top] = 'B'
3. Push 'D'
    top = top + 1
    stack[top] = 'D'
4. Pop
    temp = stack[top] //temp == 'D'
    top = top -1
5. ... Pop until all elements are removed ...
6. Pop when empty
    Returns _Stack Empty_ error
```
