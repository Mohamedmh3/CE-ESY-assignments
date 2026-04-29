# CE-ESY-assignments

## Circular Buffer in C

This project implements a **Circular Buffer** (Ring Buffer) using C language to store and read characters efficiently using **FIFO** (First In, First Out).

---

## Features

- ✓ Initialize the buffer
- ✓ Write data into the buffer
- ✓ Read data from the buffer
- ✓ Handle Overflow (Buffer Full)
- ✓ Handle Underflow (Buffer Empty)
- ✓ Track head, tail, and count

---

## Methods

### `initBuffer()`
Initializes the buffer by setting:
- `head = 0`
- `tail = 0`
- `count = 0`

### `writeBuffer()`
Adds a character to the buffer if space is available. If the buffer is full, it displays an Overflow message.

### `readBuffer()`
Reads and removes a character from the buffer. If the buffer is empty, it displays an Underflow message.

---

## Main Function

1. Takes user input (name)
2. Appends " CE-ESY" to the input
3. Stores the result in the circular buffer
4. Reads and displays the stored data
5. Verifies that the buffer is empty after reading

---

## How to Compile and Run

```bash
gcc -o Assignment_1 Assignment_1.c
./Assignment_1
```

---

## Example Usage

### With BUFFER_SIZE = 50

```
Enter your name: Mohammad

--- Writing to Buffer ---
Written 'M' -> head=1 tail=0 count=1
Written 'o' -> head=2 tail=0 count=2
Written 'h' -> head=3 tail=0 count=3
Written 'a' -> head=4 tail=0 count=4
Written 'm' -> head=5 tail=0 count=5
Written 'm' -> head=6 tail=0 count=6
Written 'a' -> head=7 tail=0 count=7
Written 'd' -> head=8 tail=0 count=8
Written ' ' -> head=9 tail=0 count=9
Written 'C' -> head=10 tail=0 count=10
Written 'E' -> head=11 tail=0 count=11
Written '-' -> head=12 tail=0 count=12
Written 'E' -> head=13 tail=0 count=13
Written 'S' -> head=14 tail=0 count=14
Written 'Y' -> head=15 tail=0 count=15

--- Reading from Buffer ---
Read 'M' -> head=15 tail=1 count=14
MRead 'o' -> head=15 tail=2 count=13
oRead 'h' -> head=15 tail=3 count=12
hRead 'a' -> head=15 tail=4 count=11
aRead 'm' -> head=15 tail=5 count=10
mRead 'm' -> head=15 tail=6 count=9
mRead 'a' -> head=15 tail=7 count=8
aRead 'd' -> head=15 tail=8 count=7
dRead ' ' -> head=15 tail=9 count=6
 Read 'C' -> head=15 tail=10 count=5
CRead 'E' -> head=15 tail=11 count=4
ERead '-' -> head=15 tail=12 count=3
-Read 'E' -> head=15 tail=13 count=2
ERead 'S' -> head=15 tail=14 count=1
SRead 'Y' -> head=15 tail=15 count=0
Y
Buffer is now completely empty.
```

### With BUFFER_SIZE = 10 (Demonstrating Overflow)

```
Enter your name: Mohammad

--- Writing to Buffer ---
Written 'M' -> head=1 tail=0 count=1
Written 'o' -> head=2 tail=0 count=2
Written 'h' -> head=3 tail=0 count=3
Written 'a' -> head=4 tail=0 count=4
Written 'm' -> head=5 tail=0 count=5
Written 'm' -> head=6 tail=0 count=6
Written 'a' -> head=7 tail=0 count=7
Written 'd' -> head=8 tail=0 count=8
Written ' ' -> head=9 tail=0 count=9
Written 'C' -> head=0 tail=0 count=10

Buffer is full! Cannot write 'E'

Buffer is full! Cannot write '-'

Buffer is full! Cannot write 'E'

Buffer is full! Cannot write 'S'

Buffer is full! Cannot write 'Y'

--- Reading from Buffer ---
Read 'M' -> head=0 tail=1 count=9
MRead 'o' -> head=0 tail=2 count=8
oRead 'h' -> head=0 tail=3 count=7
hRead 'a' -> head=0 tail=4 count=6
aRead 'm' -> head=0 tail=5 count=5
mRead 'm' -> head=0 tail=6 count=4
mRead 'a' -> head=0 tail=7 count=3
aRead 'd' -> head=0 tail=8 count=2
dRead ' ' -> head=0 tail=9 count=1
 Read 'C' -> head=0 tail=0 count=0
C
Buffer is now completely empty.
```