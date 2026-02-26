*This project has been created as part of the 42 curriculum by abuet.*

# Push Swap

## Description

Push Swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks — **stack A** and **stack B** — and a limited set of operations, while minimizing the total number of moves. This project challenges you to think about algorithmic efficiency and to implement an optimized sorting strategy in C.

The program takes a list of integers as arguments and outputs the shortest sequence of instructions to sort them in ascending order on stack A.

### Available operations

- `sa` / `sb` / `ss` — swap the top two elements of stack A / B / both
- `pa` / `pb` — push the top element of stack B to A / A to B
- `ra` / `rb` / `rr` — rotate stack A / B / both upward
- `rra` / `rrb` / `rrr` — reverse rotate stack A / B / both

## Instructions

### Requirements

- CC

### Compilation

```bash
make
```

This will produce the `push_swap` executable.

### Usage

```bash
./push_swap 3 1 4 1 5 9 2 6
```

The program outputs the list of operations to sort the given integers, one per line.

### Cleanup

```bash
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # fclean + compile
```

### Testing

You can verify the correctness and count of operations using the provided checker (if applicable):

```bash
ARG="3 1 4 1 5 9 2 6"; ./push_swap $ARG | ./checker $ARG
```

Expected output: `OK`

## Resources

### Documentation & References

https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### AI Usage

I used AI to write this README and to provide examples explaining how the Turkish algorithm works.

## test avec checker

### linux : 

test 100 nombres aléatoire : 

	ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
	./push_swap $ARG | ./checker_linux $ARG

test 5 * 100 nombres aléatoire : 

	for i in {1..20}; do
  		ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  		OPS=$(./push_swap $ARG | tee /tmp/ops.txt | wc -l)
  		RES=$(cat /tmp/ops.txt | ./checker_linux $ARG)
  		echo "Test $i: $RES - $OPS ops"
		done

### mac : 

test 100 nombres aléatoire :

	ARG=$(gshuf -i 1-1000 -n 100 | tr '\n' ' ')
		./push_swap $ARG | arch -x86_64 ./checker_Mac $ARG

test 5 * 100 nombres aléatoire

	for i in {1..20}; do                       
  		ARG=$(gshuf -i 1-100 -n 100 | tr '\n' ' ')
  		OPS=$(arch -x86_64 ./push_swap $ARG | tee /tmp/ops.txt | wc -l)
  		RES=$(cat /tmp/ops.txt | arch -x86_64 ./checker_Mac $ARG)
  		echo "Test $i: $RES - $OPS ops"
		done