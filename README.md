# Push_swap Project
## Description
- The Push_swap project involves sorting a stack of integers using a limited set of operations. This project aims to deepen understanding of sorting algorithms, data structures, and algorithm optimization techniques.

## Objective
- The main goal of the Push_swap project is to implement a program that sorts a stack of integers in ascending order by using two stacks.
- The program must minimize the number of operations performed in order to obtain the sorted stack.
- A check program that checks whether the stack is sorted and the second stack is empty.

## Features
- Uses two stacks and a limited number of operations, including Push (pa, pb), Swap(sa, sb), Rotate(ra, rb, rr) and Reverse Rotate(rra, rrb, rrr).
- Supports optimization techniques to minimize the number of operations required for sorting.
- Handles error cases and provides informative error messages.

## Usage
To use the Push_swap program, follow these steps:

1. Clone the repository:
```
git clone <repository-url>
```
2. Navigate to the push_swap directory:
```
cd ft_push_swap
```
3. Compile the program:
```
make push_swap
```
4. Execute the program with a list of integers as arguments:
```
./push_swap 4 2 7 1 3
```
5. Optionally, use the checker program to verify the sorting:
```
make checker
ARG="4 2 7 1 3"; ./push_swap $ARG | ./checker $ARG
```
