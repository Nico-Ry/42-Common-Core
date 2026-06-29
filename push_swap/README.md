# push_swap

push_swap is an algorithm and optimization project from the 42 Common Core.

The goal is to sort a stack of integers using a limited set of operations and produce the smallest possible sequence of instructions.

This project focuses on algorithmic thinking, stack manipulation, complexity, optimization and edge-case handling.

---

## Overview

The program receives a list of integers and outputs a sequence of operations that sorts them in ascending order.

It works with two stacks:

```text id="f9cv5y"
Stack A: initial numbers
Stack B: temporary stack used during sorting
```

Only a limited set of operations is allowed:

| Operation | Description                            |
| --------- | -------------------------------------- |
| `sa`      | swap the first two elements of stack A |
| `sb`      | swap the first two elements of stack B |
| `ss`      | `sa` and `sb` at the same time         |
| `pa`      | push the first element of B to A       |
| `pb`      | push the first element of A to B       |
| `ra`      | rotate stack A upward                  |
| `rb`      | rotate stack B upward                  |
| `rr`      | `ra` and `rb` at the same time         |
| `rra`     | reverse rotate stack A                 |
| `rrb`     | reverse rotate stack B                 |
| `rrr`     | `rra` and `rrb` at the same time       |

---

## Algorithm Used

For the main sorting logic, I used a **Turk algorithm** approach.

The idea is to move elements between the two stacks by calculating the cheapest move at each step.

Instead of blindly pushing numbers, the algorithm evaluates where each number should be inserted and how many operations are needed to place it correctly.

---

## Turk Algorithm Explanation

The general strategy is:

1. Handle very small inputs with dedicated simple sorting functions.
2. Push part of stack A into stack B.
3. For every element, calculate its best target position in the other stack.
4. Calculate the cost of moving that element and its target into position.
5. Choose the cheapest move.
6. Execute combined rotations when possible.
7. Push the selected element.
8. Repeat until the elements are ready to be restored into stack A.
9. Rotate stack A so the smallest number is at the top.

Simplified flow:

```text id="vfvjtb"
parse input
  ↓
validate numbers
  ↓
handle small sort cases
  ↓
push elements from A to B
  ↓
calculate target positions
  ↓
calculate move costs
  ↓
perform cheapest move
  ↓
push back to A in sorted order
  ↓
final rotation
```

---

## Cost Calculation

The important part of the Turk algorithm is the cost calculation.

For each candidate element, the program estimates:

* how many rotations are needed in stack A
* how many rotations are needed in stack B
* whether rotations can be combined with `rr`
* whether reverse rotations can be combined with `rrr`
* whether normal and reverse rotations must be done separately

The goal is to select the move that requires the fewest total operations.

Example idea:

```text id="u7xkx5"
candidate number
  ↓
target position
  ↓
rotation cost in A
  ↓
rotation cost in B
  ↓
combined move cost
  ↓
cheapest candidate selected
```

This makes the sorting strategy much more efficient than a naive approach.

---

## Small Sorts

For small input sizes, the project uses specific sorting logic.

Examples:

* 2 numbers: simple swap if needed
* 3 numbers: minimal hardcoded logic
* 5 numbers: push smallest elements, sort 3, then push back

Small dedicated sort functions are useful because they reduce operation count and avoid unnecessary complexity.

---

## Input Validation

The program checks for invalid input, including:

* non-numeric values
* duplicate numbers
* integer overflow
* empty arguments
* badly formatted input

Invalid input prints:

```text id="c1svtn"
Error
```

---

## Main Topics

* sorting algorithms
* stack operations
* greedy optimization
* cost calculation
* input parsing
* integer validation
* linked lists or stack structures
* algorithmic edge cases
* operation minimization

---

## Skills Practiced

* C programming
* algorithm design
* data structures
* stack manipulation
* complexity thinking
* parsing
* error handling
* optimization
* debugging with large input sets

---

## How to Build

```bash id="bl47l6"
make
```

---

## How to Run

```bash id="4uy7oq"
./push_swap 4 2 1 3
```

Example output:

```text id="0hu96s"
pb
sa
pa
ra
```

The output is a list of operations that, when applied to the initial stack, sorts the numbers.

---

## Testing

Example with random numbers:

```bash id="h5ksba"
ARG="4 67 3 87 23"; ./push_swap $ARG
```

If a checker is available:

```bash id="yflk6m"
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

Expected result:

```text id="fn9jnq"
OK
```

---

## What I Learned

The most important lessons from this project were:

* how to design an algorithm under strict operation constraints
* how stack operations affect sorting strategy
* why small inputs deserve special handling
* how greedy choices can reduce total operations
* how to calculate insertion positions
* how to combine rotations efficiently
* how important input validation is
* how to test algorithms with many randomized cases

---

## Notes

push_swap was a strong algorithmic project because the goal was not only to sort, but to sort efficiently with a limited instruction set.

Using the Turk algorithm helped me understand how local cost decisions can produce an effective global sorting strategy.
