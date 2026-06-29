# 42 Common Core

A collection of my projects from the **42 Lausanne Common Core**.

The Common Core gave me strong foundations in low-level programming, Unix systems, algorithms, networking, concurrency, graphics, Docker infrastructure and full-stack development.

This repository is mainly an archive of my validated 42 projects, but it also serves as a portfolio index for the technical skills developed during the curriculum.

---

## Overview

| Area           | Skills practiced                                           |
| -------------- | ---------------------------------------------------------- |
| C programming  | memory management, pointers, custom libraries, parsing     |
| Unix systems   | processes, signals, file descriptors, pipes, redirections  |
| Algorithms     | sorting, stack operations, optimization, complexity        |
| Graphics       | ray tracing, fractals, MiniLibX, vectors, geometry         |
| Networking     | sockets, HTTP, client/server architecture                  |
| Concurrency    | threads, mutexes, synchronization, race conditions         |
| Infrastructure | Docker, Docker Compose, Nginx, MariaDB, WordPress          |
| Full-stack     | authentication, APIs, database modeling, realtime features |

---

## Highlight Projects

### [ft_transcendence](./ft_transcendence)

Final Common Core project: a full-stack multiplayer web application.

**Main topics**

* backend architecture
* authentication
* JWT and OAuth2
* two-factor authentication
* REST APIs
* WebSockets
* PostgreSQL database modeling
* Dockerized development and production setup
* team workflow with branches, reviews and issues

**Tech:** TypeScript · NestJS · React · PostgreSQL · Prisma · Docker · Nginx · Socket.IO

> Note: my personal copy with a more detailed README and observability experiments is here:
> [Ft_transcendence-personal](https://github.com/Nico-Ry/Ft_transcendence-personal)

---

### [Webserv](./Webserv)

HTTP/1.1 server written in C++.

**Main topics**

* TCP sockets
* non-blocking I/O
* `poll()`
* HTTP request parsing
* routing
* file uploads
* CGI execution
* concurrent clients
* server configuration

**Tech:** C++ · Linux · Sockets · HTTP · CGI

---

### [MiniRT](./MiniRt)

A small ray tracing engine written in C.

**Main topics**

* ray-object intersections
* camera system
* lighting
* shadows
* vectors and 3D math
* scene parsing
* rendering pipeline

**Tech:** C · MiniLibX · Ray tracing · Geometry

---

### [Minishell](./Minishell)

A simplified Unix shell.

**Main topics**

* command parsing
* pipes
* redirections
* environment variables
* builtins
* process execution
* signals
* file descriptor management

**Tech:** C · Unix · Bash behavior · Processes

---

### [Philosophers](./Philosophers)

Dining Philosophers concurrency problem.

**Main topics**

* threads
* mutexes
* synchronization
* deadlock prevention
* timing
* shared state
* race condition handling

**Tech:** C · pthreads · Mutexes · Concurrency

---

### [Inception](./Inception)

Docker infrastructure project.

**Main topics**

* multi-container architecture
* Dockerfiles
* Docker Compose
* Nginx reverse proxy
* MariaDB
* WordPress
* volumes
* container networking

**Tech:** Docker · Docker Compose · Nginx · MariaDB · WordPress · Linux

---

## Project Index

| Project                                | Description                                   | Main skills                                   |
| -------------------------------------- | --------------------------------------------- | --------------------------------------------- |
| [Libft](./Libft)                       | Custom C standard library                     | C fundamentals, memory, strings, linked lists |
| [ft_printf](./ft_printf)               | Recreation of `printf`                        | variadic functions, formatting, parsing       |
| [get_next_line](./Get_Next_Line)       | Read files line by line                       | file descriptors, buffers, static variables   |
| [Born2beroot](./Born2beroot)           | Linux server administration project           | virtualization, users, permissions, security  |
| [push_swap](./push_swap_commented)     | Stack sorting algorithm project               | algorithms, complexity, optimization          |
| [minitalk](./minitalk)                 | Client/server communication with Unix signals | signals, bit manipulation, IPC                |
| [fract-ol](./fractol)                  | Fractal renderer                              | graphics, complex numbers, MiniLibX           |
| [Philosophers](./Philosophers)         | Dining Philosophers problem                   | threads, mutexes, synchronization             |
| [Minishell](./Minishell)               | Unix shell recreation                         | processes, pipes, redirections, signals       |
| [MiniRT](./MiniRt)                     | Ray tracing engine                            | 3D math, rendering, scene parsing             |
| [CPP Modules](./CPP_Modules)           | C++ introduction modules                      | OOP, inheritance, templates, STL basics       |
| [Inception](./Inception)               | Docker infrastructure                         | containers, networking, Nginx, MariaDB        |
| [Webserv](./Webserv)                   | HTTP server in C++                            | sockets, HTTP, CGI, non-blocking I/O          |
| [ft_transcendence](./ft_transcendence) | Full-stack final project                      | backend, auth, realtime, database, Docker     |

---

## Technical Progression

The Common Core progressively moved from low-level programming to complete software systems.

```text
C foundations
  ↓
memory management, parsing, custom libraries
  ↓
Unix processes, file descriptors, signals
  ↓
algorithms and optimization
  ↓
graphics and mathematical rendering
  ↓
concurrency and synchronization
  ↓
C++ and object-oriented programming
  ↓
networking and HTTP servers
  ↓
Docker infrastructure
  ↓
full-stack web application
```

---

## Strongest Portfolio Projects

For recruiters or technical reviewers, these are the most representative projects:

1. **ft_transcendence** — full-stack app, backend architecture, auth, database, realtime
2. **Webserv** — HTTP server, sockets, networking, C++
3. **Minishell** — Unix processes, shell behavior, file descriptors
4. **MiniRT** — 3D math, ray tracing, C graphics
5. **Inception** — Docker infrastructure and service orchestration
6. **Philosophers** — concurrency, mutexes, race conditions

---

## Tech Stack Used Across the Common Core

**Languages**

C · C++ · TypeScript · SQL · Shell

**Systems**

Unix · Linux · processes · signals · file descriptors · sockets · threads · mutexes

**Backend and Web**

NestJS · REST APIs · WebSockets · JWT · OAuth2 · PostgreSQL · Prisma

**Infrastructure**

Docker · Docker Compose · Nginx · MariaDB · WordPress

**Graphics**

MiniLibX · ray tracing · fractals · vector math · 3D geometry

---

## Notes

Most projects follow the original 42 structure and may not yet include detailed individual README files.

The root README is intended as a clear index of the repository. More detailed project-level documentation can be added progressively for the most important projects.
