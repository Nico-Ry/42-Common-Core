# Minishell

Minishell is a simplified Unix shell written in C as part of the 42 Common Core.

The goal of the project is to recreate core shell behavior: reading commands, parsing input, handling environment variables, executing programs, managing pipes and redirections, and correctly responding to signals.

This project was one of the most important Common Core projects for understanding how Unix systems execute and connect processes.

---

## Overview

Minishell reads user input, parses it into commands, expands variables, prepares redirections and pipes, then executes the requested programs using Unix system calls.

It recreates a small but functional shell inspired by Bash.

Main responsibilities include:

* displaying a prompt
* reading user input
* parsing commands and arguments
* handling quotes
* expanding environment variables
* executing binaries
* implementing built-in commands
* handling pipes
* handling input/output redirections
* managing child processes
* handling signals
* preserving shell state

---

## Main Topics

* Unix processes
* `fork()`
* `execve()`
* `wait()`
* pipes
* redirections
* file descriptors
* environment variables
* signals
* command parsing
* shell builtins
* error handling

---

## Builtins

The project implements common shell builtins such as:

* `echo`
* `cd`
* `pwd`
* `export`
* `unset`
* `env`
* `exit`

Some builtins need to run in the parent process because they modify the shell state, for example `cd`, `export`, `unset` and `exit`.

---

## Skills Practiced

* C programming
* Unix system calls
* process management
* file descriptor management
* parsing
* memory management
* signal handling
* debugging complex execution flows
* teamwork and project organization

---

## Why This Project Matters

Minishell gives a strong understanding of what happens when a user types a command in a terminal.

```text
user input
  ↓
lexer / parser
  ↓
variable expansion
  ↓
redirections and pipes setup
  ↓
fork processes
  ↓
execute commands
  ↓
wait and collect exit status
```

This knowledge is useful for backend and infrastructure work because many tools, scripts, containers and deployment workflows depend on Unix process behavior.

---

## How to Build

```bash
make
```

---

## How to Run

```bash
./minishell
```

Example usage:

```bash
echo hello
pwd
cd ..
ls -la | grep README
cat file.txt > output.txt
echo $PATH
```

---

## What I Learned

This project helped me understand how a shell works internally.

The most important lessons were:

* how commands are parsed before execution
* how processes are created with `fork()`
* how programs are executed with `execve()`
* how pipes connect the output of one process to the input of another
* how redirections modify standard input and output
* how signals affect interactive programs
* why file descriptors must be carefully opened and closed
* how shell state differs between parent and child processes

---

## Notes

Minishell was one of the most challenging Common Core projects because many small edge cases can break shell behavior.

It was especially useful for developing a deeper understanding of Unix internals, process execution and command-line tools.
