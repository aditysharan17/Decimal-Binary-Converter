# Decimal ⇄ Binary Converter

A simple command-line utility written in C for converting between decimal and binary number systems. Built as a menu-driven program demonstrating bitwise operations, dynamic memory allocation, and string manipulation.

## Features

- **Decimal to Binary** — Converts any non-negative decimal integer to its binary string representation.
- **Binary to Decimal** — Converts a binary string back into its decimal integer value.
- **Interactive Menu** — Loops continuously until the user chooses to exit.
- **Dynamic Memory** — Binary output is allocated on the heap and freed after use.

## How It Works

- `decimalToBinary(int decimal)` uses bitwise AND (`& 1`) and right-shift (`>> 1`) to extract bits one at a time, builds the string in reverse order, then reverses it into the correct order using `reverseString`.
- `binaryToDecimal(char binary[])` iterates over the binary string left to right, accumulating the decimal value via `decimal = decimal * 2 + bit`.
- `reverseString(char* str)` reverses a string in place using a two-pointer swap.

## Getting Started

### Prerequisites

- A C compiler (e.g. `gcc`)

### Build

```bash
gcc -o converter converter.c
```

### Run

```bash
./converter
```

### Example

```
Menu:
1. Decimal to Binary
2. Binary to Decimal
3. Exit
Enter your choice: 1
Enter a decimal number: 42
Decimal to Binary: 101010

Menu:
1. Decimal to Binary
2. Binary to Decimal
3. Exit
Enter your choice: 2
Enter a binary number: 101010
Binary to Decimal: 42

Menu:
1. Decimal to Binary
2. Binary to Decimal
3. Exit
Enter your choice: 3
Goodbye!
```

## Project Structure

```
.
├── converter.c   # Main source file
└── README.md     # Project documentation
```

## Notes / Limitations

- Only supports non-negative decimal integers (no handling for negative numbers).
- No input validation on binary strings (e.g. characters other than `0`/`1` will produce incorrect results).
- Binary buffer is fixed at 33 bytes, sufficient for 32-bit integers.

## License

This project is open source and available under the [MIT License](LICENSE).
