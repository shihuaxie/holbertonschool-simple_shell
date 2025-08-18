Simple Shell

📖 Table of Contents
	•	Description
	•	Features
	•	Flowchart
	•	File Structure
	•	System and Library Calls
	•	Installation
	•	Usage
	•	Examples
	•	Man Page
	•	Authors

⸻

📝 Description

This project is a UNIX command line interpreter (shell) developed as part of the Holberton School / ALX curriculum.

It provides a minimal implementation of a shell in C (GNU89). The program reads user input, parses it into arguments, searches for the executable, and runs it in a child process.

The shell works in:
	•	Interactive mode – displays a prompt and executes commands until user exits.
	•	Non-interactive mode – reads commands from a file or pipe and executes them.

⸻

✨ Features
	•	Display a prompt and wait for user input.
	•	Execute commands with arguments.
	•	Search executables using the PATH environment variable.
	•	Handle errors gracefully (command not found, permission denied).
	•	Built-in commands:
	•	exit → exit the shell.
	•	env → print environment variables.
	•	Supports EOF (Ctrl+D) to exit shell.
	•	Works in interactive and non-interactive mode.

⸻

🔄 Flowchart

flowchart TD
    A[Start Shell] --> B{isatty(STDIN)?}
    B -- yes --> C[Display prompt]
    B -- no  --> D[Read line]
    C --> D[Read line]
    D --> E{EOF (Ctrl+D)?}
    E -- yes --> Z[Exit]
    E -- no  --> F[Tokenize input -> argv]
    F --> G{Built-in?}
    G -- exit --> Z[Exit]
    G -- env  --> H[Print environment] --> B
    G -- no   --> I{Has '/' ?}
    I -- yes --> J[execve(argv[0], argv, environ)]
    I -- no  --> K[Resolve via PATH -> fullpath or not found]
    K -->|found| J
    K -->|not found| B
    J --> L[fork + execve + waitpid] --> B


⸻

📂 File Structure

File	Description
main.c	Entry point: main loop, prompt, input reading.
shell.h	Header file: prototypes, macros, extern variables.
parser.c	Tokenize input string into an argv array.
execute.c	Handles fork, execve, and waitpid.
path.c	Search executables via PATH.
builtins.c	Implements built-in commands (exit, env).
errors.c	Error messages handling.
utils.c	Helper functions (string ops, memory mgmt).
AUTHORS	Contributors list.
man_1_simple_shell	Manual page for the shell.
README.md	This file.

Code style: Betty compliance, ≤ 5 functions per file.

⸻

⚙️ System and Library Calls

The shell makes use of the following system and library calls:
	•	fork → create child process
	•	execve → replace process image
	•	wait, waitpid → wait for process termination
	•	getline → read input line
	•	isatty → check interactive mode
	•	access → check file permissions
	•	stat, lstat, fstat → file info (optional)
	•	write, perror → output / error messages
	•	malloc, free → memory allocation
	•	_exit, exit → terminate process
	•	strtok, strcmp, strlen, strcpy → string manipulation

⸻

🛠 Installation

Clone the repository and compile:

git clone https://github.com/<your-team>/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


⸻

🚀 Usage

Run in interactive mode:

./hsh

Run in non-interactive mode (piped):

echo "ls -l" | ./hsh


⸻

💻 Examples

Interactive

$ ./hsh
($) /bin/echo "Hello World"
Hello World
($) ls -l
total 12
-rw-r--r--  1 user  staff  1234 Aug 18 10:00 main.c
...
($) env
PATH=/usr/bin:/bin:...
($) exit
$

Non-interactive

$ echo "/bin/ls" | ./hsh
AUTHORS  main.c  shell.h  README.md


⸻

📖 Man Page

A manual page is included. To view it after compiling:

man ./man_1_simple_shell


⸻

👥 Authors

See AUTHORS file for contributors list.

⸻

