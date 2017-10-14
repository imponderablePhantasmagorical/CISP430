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


# Asymptotic Analysis

**Goal**: to simply analysis of running time by getting rid of "details" which may be affected by the specific implmentation and hardware
- 3n^2 ~= n^2 (the square is the "dominate" number in the function)

Models the running time of an algorithm increases with the size of the input in the limit.

```
Best/Worst of a Sort Algo (example)
Total time = n + sigma(n->j=2) Tj

Best: Tj = 1, running time: f(n) - _Linear_ time, the list was already sorted and only checking was required.
Worst: Tj = j, running time: f(n^2) - _Quadratic_ time, had to check and sort EVERY ENTRY in the list
Average: Tj = j/2, running time: f(log(n)) - Can be very difficult to find! Also, sometimes as bad as Worst Case time
```

## Big O Notation
**Used for _worst case analysis_**
Use O-Notation to express a a number of primitive operations exectured as a function of input size.

This is an "asymptotic upper bound"

### Terminology

Special Classes of O-time Algorithms
- Constant: O(1)
- Logarithmic: O(log n)
- Linear: O(n)
- Quadraticc: O(n^2)
- Polynomial: O(n^k), k >= 1
- Expoential: O(a^n), a > 1

"Relatives" of Big O
Big Omega - Asymptotic lower bound (Best case?)
Big Theta - Asymptotic tight bound


### Simple Rule: Drop the lower order terms and constant factors. ie.
1. 50n x log(n) is O(n x log(n))
2. 7n - 3 is O(n)
3. 8n^2 x log(n) + 5n^2 + n is I(n^2 x log(n))
Beware that large constant factors might make lower timed functions more expensive (ie. 1,000,000n is less effecient then 2n^2) but according to big O, it will be more effecient (ie. O(n) vs O(n^2))


### Comparing Big O times
- An algorithm that runs in O(n) is better than one that runs in O(n^2) time.
- O(log(n)) = O(n)
- Heirarchy (Least time to Most time)
    1. log(n)
    2. n
    3. n^2
    4. n^3
    5. 2^n

#### Example of Asymptotic Analysis
**Algorithm** prefix_averages_ver1(X)
    _Input:_ An n-element array of X numbers
    _Output:_ An n-element array A of numbers such that A[i] is the average of elements X[0],...,X[i] (an average of all values before and including itself)

```
for i = 0 to n-1 do   //Iterate through the array
    a = 0             //Initialize our current sum to 0
    for j = 0 to i do //Loop through the array a second time to gain our sum
        a = a + X[j]  //add whatever entry we're in to our running sum
    A[i] = a/(i+1)    // Get our average and insert it into our new array
return A              //Return our array
```

This algorithm will have a running time dependant on the size of the input.
The outter For loop will run for N iterations
The inner For loop will run for i iterations 0->n-1. At most this will be N iterations

Thus the O(n) analysis of this algorithm is O(n^2) because the worst time is found by running through all the entries twice. 

#### Another example
**Algorithm** prefix_averages_ver2(X)
    _Input:_ same as above
    _Output:_ same as above

```
s = 0 //Set our running sum to 0 at the start
for i = 0 to n do //iterate through the entire array
    s = s + X[i] //find our running sum at the current position
    //Insert our current sum divided by our current position (the average of all numbers up until this point)
    A[i] = s / (i+1)
return A
```
There is only 1 loop in this function, thus the O time is O(n)
This is a large improvement over the ver1 of this algorithm by not requiring a second inner loop

#### Practice analysis
Example:

Input: 
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |
| 9 | 10| 11| 12|
| 0 | 0 | 0 | 0 |

Output:
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |
| 9 | 10| 11| 12|
|15 | 18| 21| 24|

Last row cells should be made into a sum of the column above it
Columns are denoted by i
Rows are denoted by j

Input: Two dimensional array (n x n). X[n][n]
Output: The same array with the last row used to store the total of the columns

for each column, iterate through all rows of that column and sum it up

```
X[i][j]
for i = 0 to n do
    s = 0 //Initialize our sum counter
    for j = 0 to n do
        s = s + X[i][j]
    X[i][n] = s
end
```
        
