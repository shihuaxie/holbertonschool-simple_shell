# Simple Shell - Holberton School Australia
![Simple Shell](./shell.jpeg)
## 📖 Table of Contents

- 📝 Description  
- ✨ Features  
- 📂 File Structure  
- ⚙️ System and Library Calls  
- 💻 Installation  
- 🚀 Usage  
- 🎯 Examples  
- 📖 Man Page  
- 👥 Authors  

---

## 📝 Description
This project is a UNIX command line interpreter (shell) developed as part of the Holberton School / ALX curriculum.  

It provides a minimal implementation of a shell in C (GNU89). The program reads user input, parses it into arguments, searches for the executable, and runs it in a child process.

The shell works in:  
- **Interactive mode** – displays a prompt and executes commands until user exits.  
- **Non-interactive mode** – reads commands from a file or pipe and executes them.  

---

## ✨ Features

- Display a prompt and wait for user input  
- Execute commands with arguments  
- Search executables using the `PATH` environment variable  
- Handle errors gracefully:  
  - Command not found  
  - Permission denied  
- Built-in commands:  
  - `exit` → exit the shell  
  - `env` → print environment variables  
- Fork only runs if the command exists (saves resources)  
- Supports **EOF (Ctrl+D)** to exit shell  
- Works in both **interactive and non-interactive** modes  
- Provides **basic error messages** similar to `/bin/sh`  

---

## 📂 File Structure

| File | Description                                      |
|-----------|---------------------------------------------|
|simple-shell.c     |Entry point: main loop, prompt, input reading
|shell.h	|Header file: prototypes, macros, extern variables
|tokenizers.c	|Tokenize input string into an argv array
|path.c	    |Search executables via PATH
|builtins.c	|Implements built-in commands (exit, env)
|AUTHORS	|Contributors list
|man_1_simple_shell	|Manual page for the shell
|README.md|	This file

---

## ⚙️ System and Library Calls

The project makes use of the following system and library calls:

- access – to check if a command exists in PATH.
- chdir – to change directory (future built-in support).
- close – to close file descriptors.
- execve – to execute new programs.
- exit – to terminate the shell or child process.
- fork – to create a new process (only called if command exists).
- free – to release allocated memory.
- isatty – to check interactive vs non-interactive mode.
- malloc – to dynamically allocate memory.
- perror – to print error messages.
- signal – to handle signals (e.g., Ctrl+C).
- stat – to check file information and verify executables.
- strtok – to parse command line input into tokens.
- wait / waitpid – to wait for child processes.
- write – to print output to standard streams.

---

## 💻 Installation

Clone this repository and compile the source files with **gcc**:
```bash
git clone https://github.com/shihuaxie/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o main
```

---

## 🚀 Usage

Run the shell in interactive mode:
```bash
./main
```
Run the shell in non-interactive mode with a command or script:
```bash
echo "ls -l" | ./main
./main < script.sh
```

---

## 🎯 Examples

Interactive:
```bash
$ ./main
$ ls -l
total 8
-rw-r--r-- 1 user user   0 Aug 18 12:00 file1
-rw-r--r-- 1 user user   0 Aug 18 12:00 file2
$ echo Hello World
Hello World
$ exit
```
# Non-interactive:
```bash
$ echo "/bin/ls" | ./main
file1  file2
```

---

## 📖 Man Page

To view the manual page for the shell:
```bash
man ./man_1_simple_shell
```

---

## 👥 Authors
- Ashleigh Henna [https://github.com/ashleigh6734](https://github.com/ashleigh6734)

- Grâce Kayembe [https://github.com/GraceKayembe](https://github.com/GraceKayembe)

- Katherine Beringer [https://github.com/kayrbee](https://github.com/kayrbee)

- Sylvia Xie [https://github.com/shihuaxie](https://github.com/shihuaxie)

