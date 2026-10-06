*This project has been created as part of the 42 curriculum by abuet.*

# push_swap

![Language](https://img.shields.io/badge/language-C-blue)
![School](https://img.shields.io/badge/school-42-black)
![Algorithm](https://img.shields.io/badge/algorithm-Turk-orange)

A sorting program written in C that sorts a list of integers using **two stacks** and a limited set of operations, while keeping the number of moves as low as possible. It outputs the sequence of operations needed to sort the numbers.

> Project from the [42 school](https://42.fr/) curriculum, written in C following the 42 coding standard (the *Norm*). The main challenge is algorithmic efficiency: the number of operations is graded against strict limits.

---

## The rules

The program starts with all numbers in **stack A** and an empty **stack B**. At the end, all numbers must be back in stack A, sorted in ascending order, using only these operations:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | Swap the first two elements of A / B / both |
| `pa` / `pb`        | Push the top element of B onto A / of A onto B |
| `ra` / `rb` / `rr` | Rotate A / B / both: the first element becomes the last |
| `rra` / `rrb` / `rrr` | Reverse rotate A / B / both: the last element becomes the first |

## Algorithm

Small inputs (3 and 5 numbers) are handled with dedicated, hard-coded strategies. Larger inputs use the **Turk algorithm**, a cost-based approach:

1. **Push to B**: push elements from A to B until only 3 remain in A, then sort those 3.
2. **Compute costs**: for each element in B, find its target position in A and calculate how many rotations are needed to bring both into place.
3. **Choose the cheapest move**: pick the element with the lowest total cost, combining rotations of both stacks (`rr` / `rrr`) whenever possible to save moves.
4. **Push back to A**: repeat until B is empty.
5. **Final rotation**: rotate A so that the smallest number is on top.

## Error handling

The program prints `Error` on the standard error output when:

- an argument is not a valid integer;
- a number is outside the `int` range;
- the same number appears more than once.

If no argument is given, the program displays nothing.

## Project structure

```text
.
├── main.c                 # Entry point
├── ft_init.c              # Argument parsing and stack initialization
├── check_move.c           # Input validation
├── sorting.c              # Sorting strategies (small inputs and Turk algorithm)
├── number_move.c          # Move cost calculation
├── number_move_2.c        # Move cost calculation (continued)
├── swap.c                 # sa, sb, ss
├── push.c                 # pa, pb
├── rotate.c               # ra, rb, rr
├── reverse.c              # rra, rrb, rrr
├── ft_atoi.c, ft_split.c, ft_strlcpy.c   # Helper functions
├── push_swap.h            # Header
├── checker_Mac            # Checker program provided by 42 (macOS)
└── Makefile
```

## Build

```bash
git clone https://github.com/abuet-lab/<Push_swap>.git
cd <Push_swap>
make
```

| Rule          | Description |
|---------------|-------------|
| `make`        | Compiles the `push_swap` executable |
| `make clean`  | Removes object files |
| `make fclean` | Removes object files and the executable |
| `make re`     | Rebuilds everything from scratch |

## Usage

```bash
./push_swap 3 2 5 1 4
```

Output (one operation per line):

```text
pb
pb
sa
...
```

## Testing

The `checker` program reads the operations, applies them to the stacks and prints `OK` if the result is sorted, `KO` otherwise.

### Linux

```bash
# One test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG

# 20 tests with 100 random numbers, showing the number of operations
for i in {1..20}; do
    ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | tee /tmp/ops.txt | wc -l)
    RES=$(./checker_linux $ARG < /tmp/ops.txt)
    echo "Test $i: $RES - $OPS ops"
done
```

### macOS

Install `gshuf` with `brew install coreutils`. The provided checker is an x86 binary, so it runs through Rosetta on Apple Silicon:

```bash
# One test with 100 random numbers
ARG=$(gshuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | arch -x86_64 ./checker_Mac $ARG

# 20 tests with 100 random numbers, showing the number of operations
for i in {1..20}; do
    ARG=$(gshuf -i 1-1000 -n 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | tee /tmp/ops.txt | wc -l)
    RES=$(arch -x86_64 ./checker_Mac $ARG < /tmp/ops.txt)
    echo "Test $i: $RES - $OPS ops"
done
```

To test with 500 numbers, replace `-n 100` with `-n 500`.

## What I learned

- Designing and implementing a **cost-based sorting algorithm**
- Reasoning about **algorithmic complexity** and optimizing the number of operations
- Implementing and manipulating **stack data structures** in C
- Writing robust **input validation** (overflow, duplicates, invalid input)
- Testing an algorithm automatically with shell scripts

## Resources

- [Push swap — Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

### Use of AI

AI was used to help write this README and to provide examples explaining how the Turk algorithm works.
