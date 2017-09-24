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
        
