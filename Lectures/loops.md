# Loops

## while loops:
Pretest Loop
May not execute at all
```cpp
while(condition) {
  statement;
}
```

## do-while loops:
Post-test Loop
Must execute AT LEAST ONCE
```cpp
do {
    statement;
} while (condition);
```

## do-until loops:
Post-test Loop
Must execute AT LEAST ONCE
```cpp
do {
    statement;
} until (condition);
```

## for loops:
Pre-test Loop
Counter-controlled loop
Used for iterating a known amount of times
```cpp
for(initializations`; condition/test; update) {
    statements;
}
```
* you can omit initilzation if it is already done (ie `for(; condition; update)`)
* you can omit the update if it is done in the loop's statement body (ie `for(inits; condition;)`)
* you can omit the loop body if all of the work is done in the header



# Special Loop Keywords
### `break`
Terminates the execution of the entire loop

### `continue`
Terminates the current iteration (not the entire loop) causing the update portion of the loop to run again and the loop to iterate through again (if the condition is still true)
