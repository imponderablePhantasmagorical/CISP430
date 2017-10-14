# Recursion

A type of repetition.
Calling a method from inside of itself

A recurring call to a function from within the function itself, until a certain **stop condition** is met, in which case the function then returns to it's calling function. If a final condition is met, this returning is done until the top calling function is reached.

If no stopping condition is present, or if it is never met, then the loop will repeat forever.

## Example: Summation
_Finding the sum of numbers up until **n** using recursion instead of for loop_
```
int sum(int n) {
    int s;
    if(n==0) { //Our stop condition
        return 0;
    } else {
        s = n + sum(n-1) //Recursive call to sum()
    }
    return s; //This will return the value of the sum to it's calling function until it reaches the top level
}

int main() {
    cout << "Sum: " << sum(4) << endl;
    return 0;
}
```

#### What each recursion returns:
```
sum(4)                   Return: 10  (4 + 6)
    4 + sum(3)           Return: 6   (3 + 3)
        + sum(2)         Return: 3   (2 + 1)
            +sum(1)      Return: 1   (1 + 0)
                +sum(0)  Return: 0   (Return start)
```
