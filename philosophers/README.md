# **Dining Philosophers Simulation**

## **Overview**
This project implements the classic **Dining Philosophers Problem** using multithreading and mutexes to ensure synchronization and avoid deadlocks. The philosophers alternate between eating, thinking, and sleeping while sharing forks as resources. The simulation adheres to specific rules to prevent starvation and ensure proper resource sharing.

---

## **Features**
- Simulates philosophers' behaviors:
  - Eating, thinking, and sleeping.
  - Using shared forks.
- Uses mutexes for thread-safe resource management.
- Logs each philosopher's state with timestamps and color-coded output.
- Ends simulation if:
  - A philosopher dies from starvation.
  - All philosophers have eaten the required number of meals.
- Configurable via command-line arguments.

---

## **Requirements**
- **OS**: Linux or macOS.
- **Compiler**: `gcc` or equivalent.
- **Libraries**: `pthread`.

---

## **Usage**
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]

Arguments
number_of_philosophers (1–200): Number of philosophers at the table.
time_to_die (>100 ms): Maximum time a philosopher can go without eating.
time_to_eat (>100 ms): Time taken to eat a meal.
time_to_sleep (>100 ms): Time spent sleeping after eating.
number_of_times_each_philosopher_must_eat (optional): Ends the simulation after all philosophers eat this many meals.

Example bash

./philo 5 800 200 200 3
This starts a simulation with:

5 philosophers.
800 ms before starvation.
200 ms to eat.
200 ms to sleep.
Ends after each philosopher eats 3 meals.

Output
Each philosopher logs their state with a timestamp (in milliseconds) and their ID:


0	1	is thinking
12	2	has taken a fork
15	2	is eating
217	2	is sleeping

If a philosopher dies:
1234	3	died

## **Code Structure**
- main.c: Orchestrates initialization, simulation, and cleanup.
- simulation_init.c: Handles argument parsing and memory allocation.
- philo_actions.c: Manages philosophers taking forks, eating, and releasing forks.
- philo_states.c: Handles sleeping and thinking states.
- philo_threads.c: Creates and manages threads for philosophers.
- health_monitor.c: Monitors philosopher health and handles simulation termination.
- utils.c: Provides utility functions (e.g., time management).
- print_status.c: Logs philosopher states.
- validate_args.c: Validates command-line arguments.
- parse_args.c: Parses command-line arguments.
## **Design Considerations**
- Thread Safety:
	- Mutexes are used to protect shared resources (forks, logs).
- Deadlock Prevention:
	- Philosophers attempt to lock both forks only when both are available.
- Dynamic Resource Management:
	- Handles varying numbers of philosophers and forks.
## **Error Handling**
- Ensures proper argument validation.
- Handles memory allocation failures gracefully.
- Logs meaningful error messages for incorrect usage or system issues.
## **Known Issues**
May experience delays in logging under high concurrency.
Limited to systems supporting pthread.
### **Compilation**
Use the provided Makefile to compile the program:
```bash
make

