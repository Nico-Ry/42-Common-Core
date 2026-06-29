# Philosophers

Philosophers is a concurrency and synchronization project from the 42 Common Core.

The goal is to solve the classic Dining Philosophers problem using threads and mutexes while avoiding race conditions, deadlocks and incorrect timing behavior.

This project is important because it introduces the difficulties of shared state and concurrent execution.

---

## Overview

The simulation represents philosophers sitting around a table.

Each philosopher repeatedly:

```text
think
  ↓
take forks
  ↓
eat
  ↓
sleep
  ↓
repeat
```

Each philosopher needs two forks to eat. Since forks are shared resources, the program must synchronize access carefully.

The challenge is to ensure that:

* philosophers do not use the same fork at the same time
* no data race occurs
* death detection is accurate
* timestamps are correct
* the simulation stops cleanly
* the program avoids deadlocks

---

## Main Topics

* threads
* mutexes
* shared memory
* synchronization
* race conditions
* deadlock prevention
* timing
* monitoring thread state
* clean program termination

---

## Project Rules

The program receives arguments such as:

```text
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

This runs a simulation with:

* 5 philosophers
* 800 ms before a philosopher dies without eating
* 200 ms eating time
* 200 ms sleeping time

With the optional final argument:

```bash
./philo 5 800 200 200 7
```

The simulation stops when every philosopher has eaten at least 7 times.

---

## Skills Practiced

* C programming
* POSIX threads
* mutex locking and unlocking
* shared state protection
* time measurement
* avoiding data races
* avoiding deadlocks
* debugging concurrent programs
* clean resource cleanup

---

## Why This Project Matters

Concurrency bugs are difficult because they are not always reproducible.

A program can appear to work once, then fail depending on timing, CPU scheduling or thread execution order.

This project helped me understand why shared data must be protected and why concurrent systems require careful design.

```text
shared data
  ↓
mutex protection
  ↓
safe read/write access
  ↓
predictable simulation behavior
```

---

## Typical Problems to Avoid

Important edge cases include:

* one philosopher only
* all philosophers starting at the same time
* multiple philosophers trying to take the same fork
* death occurring while another action is being logged
* printing after the simulation has already ended
* forgetting to unlock a mutex
* destroying mutexes too early
* inaccurate timestamps
* CPU-heavy busy waiting

---

## How to Build

```bash
make
```

---

## How to Run

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_required]
```

Examples:

```bash
./philo 5 800 200 200
./philo 4 410 200 200
./philo 5 800 200 200 7
```

---

## What I Learned

The most important lessons from this project were:

* how threads execute independently
* why shared state needs synchronization
* how mutexes prevent simultaneous access to shared resources
* how deadlocks can happen
* how timing affects program correctness
* why logging also needs protection
* how to stop multiple threads cleanly
* how small concurrency bugs can create unpredictable behavior

---

## Notes

Philosophers was a key project for understanding concurrency.

It helped me build a stronger foundation for backend and systems programming, where multiple requests, workers or processes often interact with shared resources.
