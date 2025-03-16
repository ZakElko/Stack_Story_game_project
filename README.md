# Story Game Program - CISC 187 Chapter 19 (Stack Implementation)

## Author:
Zakaria Elkhodary  
Date: 11/12/2024  

## Description:
This program utilizes a **stack data structure** to create an interactive word-based story game. Users can push words onto the stack, remove words, capitalize them, and generate a short story based on the words entered. The program ensures **input validation** for an enhanced user experience.

## Features:
- **Push words** onto a stack (limited to 10 characters per word).
- **Pop words** from the stack.
- **Capitalize all words** stored in the stack.
- **Display all words** currently in the stack.
- **Generate a story** based on the last 5 words added.
- **Robust Input Handling**:
  - Ensures menu choices are valid (1-6).
  - Limits word length to **10 characters** to maintain readability.

## Technologies Used:
- **C++** (Standard Library)
- `stack` data structure (implemented via `storygame` class)
- `limits`, `algorithm`, `cctype` for input handling and processing

## How to Run:
1. Compile the program using a C++ compiler:

