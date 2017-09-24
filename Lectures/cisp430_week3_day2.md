# Algorithm Analysis
Mostly focused on _speed_ not _space_ in this class.
### Methods to Determine Algorithm Effeciency:
- Lab Study: Running the program in a lab setting, and timing the execution time.
- Algorithm Analysis: A genera methodoloigy for analyzing algorithms
    - Uses a high-level **_description_** of an algorithm, not it's **_implimentation_**
    - Takes into account **all possible outputs**
    - Allows you to evaluate algorithms without considering the hardware/software end, purely the theoretical aspect of the algorithm

### Analysis
An analysis of cost and times.
Cost: How long the procressor will take to execute the statement
Times: How many times each step will be executed

#### Effeciency of an Algorithm is based upon the one with the lowest time to execute.

## Examples:

### Insertion Sort
**Input:** Unsorted array of numbers
**Output:** Sorted array in DESC order

**General Strategy:**
- Start "empty handed"
- Insert a card in the right position of the already sorted hand
- Move card through the hand until it is in the correct position (the value before it is LESS THAN it)
- Continue until all cards are inserted/sorted

**Example of Strategy:**
[2, 5, 7], we want to add a "3" so we must find where this number belongs
1. Create an array [2, 5, 7, 3] (inserting our last number onto the end)
2. Compare element to last element. Since 7 is greater than 3, swap their positions
3. Our array is now [2, 5, 3, 7]. Continue comparing until the element compared is less than 3 (in this case, 2).

**Psuedo Code:**
```
Input: A[1...n] - An array of ints
for j=2 to n do
    //Key is the value we are attempting to currently sort
    key = A[j]
    
    //Set up our index so that we only iterate through the element to the left of the item
    i = j-1
    //Iterate through array and compare our key with the current array entry. This works backwards from our j value to 1 (our first element).
    while i > 0 and A[i] > key
        //Move the element down 1
        A[i+1] = A[i];
        //Decriment our loop counter
        i--;
    end while
    //Our current value is where our key belongs, so we set our key as the next value up from where the last iteration began and start over
    A[i+1] = key
```

**Analysis**

| Code | Cost | Times |
| ---- | ---- | ----- |
| `for j = 2 to n do` | C1 | n |
| `key = A[j]` | C2 | n-1 |       
| `i = j-1` | C3 | n-1 |
| `while i>0 and A[i] > key` | C4 | sigma(j=2 -> n) t |
| `A[i+1] = A[i]` | C5 | sigma(j=2 -> n) (t-1)  |
| `i--` | C6 | sigma(j=2 -> n) (t-1)  |
| `A[i+1] = key` | C7 | n-1 |

**Total time** = `n(C1 + C2 + C3 + C7) + (sigma(j=2 -> n) t(C4 + C5 + C6)) - (C2 + C3 + C5 + C6 + C7)`
**Without Cost** = `4n + sigma(j=2 -> n) t - 5`

_Note: Loop headers tend to be the only operations that will have an n times count. Code within a loop will only execute n-1, because the loop header must be checked 1 extra time for the end condition without executing the inner-loop code._

### Summation of Array (example)
Input: Array of N Numbers
Output: The total value of the array (sigma)

**Psuedo Code**
```
sum = 0
for i = 1 to n
    sum = sum + A[i]
display sum
```

**Analysis**

| Code | Cost | Times |
| ---  | ---  | --- |
| `sum = 0` | C1 | 1 |
| `for i=1 to n` | C2 | n + 1 |
| `sum = sum + A[i]` | C3 | n |
| `display sum` | C4 | 1 |

**Total Time** = (C1 + C2 + C4) + n(C2 + C3)
**Without Costs** = 2n + 3


