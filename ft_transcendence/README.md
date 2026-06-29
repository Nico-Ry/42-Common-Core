# ft_transcendence

ft_transcendence is the final project of the 42 Common Core.

It is a full-stack multiplayer web application built by a team of five students. The project combines backend architecture, authentication, realtime features, database modeling, frontend development, Docker infrastructure and collaborative Git workflow.

This folder documents the project inside my Common Core repository.

The complete public version with detailed documentation is available here:

**[Ft_transcendence-personal](https://github.com/Nico-Ry/Ft_transcendence-personal)**

---

## Overview

The application is a multiplayer web platform with:

* user registration and login
* JWT authentication
* 42 OAuth login
* two-factor authentication
* user profiles
* friends system
* realtime presence
* realtime game features
* live chat
* match history
* achievements
* leaderboard
* multilingual interface
* Dockerized infrastructure

The stack runs with a React frontend, a NestJS backend, a PostgreSQL database and an Nginx reverse proxy.

---

## My Main Contributions

My main focus was the backend authentication and social systems.

I worked especially on:

* JWT authentication architecture
* HTTP-only cookie authentication
* global API guard
* public route decorator
* 42 OAuth integration
* OAuth state handling
* TOTP-based two-factor authentication
* 2FA enable, verify and disable flow
* temporary 2FA pending session handling
* login protection and error handling
* friends system API
* friend requests
* accepting and declining requests
* removing friends
* realtime friends and presence updates
* Swagger/OpenAPI documentation
* backend error messages used by the frontend

---

## Backend Architecture

The backend followed a modular NestJS architecture.

```text
Request
  ↓
Guard
  ↓
Controller
  ↓
Service
  ↓
Prisma
  ↓
PostgreSQL
```

For realtime features, the architecture used WebSocket gateways:

```text
Client socket
  ↓
Socket.IO Gateway
  ↓
Service
  ↓
State / Database
  ↓
Realtime event emitted to clients
```

This structure helped keep authentication, users, friends, game logic and realtime features separated into clear modules.

---

## Authentication Flow

The project included several authentication paths:

### Email and password login

* user submits credentials
* backend validates the password
* backend creates a JWT
* JWT is stored in an HTTP-only cookie
* protected routes are accessed through the global guard

### 42 OAuth login

* user starts login with 42
* backend generates and validates OAuth state
* user authenticates through 42
* backend links or creates the local account
* session is created with the same JWT cookie system

### Two-factor authentication

* user enables 2FA
* backend generates a TOTP secret
* frontend displays a QR code
* user verifies the code with an authenticator app
* future logins require a second verification step

---

## Friends and Realtime Presence

I also worked on the friends system and realtime synchronization.

The friends system included:

* searching users
* sending friend requests
* listing incoming requests
* listing outgoing requests
* accepting requests
* declining requests
* removing friends

Realtime presence allowed users to see friend status changes such as:

* online
* offline
* waiting
* playing

This connected REST API behavior with WebSocket updates so the UI could stay synchronized without manual refreshes.

---

## Tech Stack

| Layer          | Technology                    |
| -------------- | ----------------------------- |
| Frontend       | React, Vite, TypeScript       |
| Backend        | NestJS, TypeScript            |
| Database       | PostgreSQL                    |
| ORM            | Prisma                        |
| Realtime       | Socket.IO                     |
| Authentication | JWT, OAuth2, TOTP 2FA         |
| Infrastructure | Docker, Docker Compose, Nginx |
| Documentation  | Swagger / OpenAPI             |
| Styling        | Tailwind CSS                  |

---

## Observability Extension

In my personal copy of the project, I also added an observability branch for interview preparation and backend monitoring practice.

The branch adds:

* Prometheus metrics endpoint
* `prom-client` integration
* custom authentication and 2FA metrics
* Grafana dashboard experiments
* backend monitoring concepts

This helped me connect the project to real-world backend reliability topics such as metrics, dashboards, alerts and service visibility.

The detailed version is available in:

**[Ft_transcendence-personal](https://github.com/Nico-Ry/Ft_transcendence-personal)**

---

## Skills Practiced

* backend architecture
* API design
* authentication flows
* secure cookie sessions
* OAuth2
* two-factor authentication
* database modeling
* Prisma ORM
* REST APIs
* WebSockets
* realtime state synchronization
* Dockerized development
* team collaboration
* Git branches and pull requests
* technical documentation

---

## What I Learned

This project was the biggest step from small isolated programs to a complete application.

The most important lessons were:

* how to structure a modular backend
* how authentication flows connect frontend, backend and database
* why global guards and public routes need clear design
* how to handle partial login state for 2FA
* how OAuth differs from classic login
* how realtime events keep users synchronized
* how database models affect API design
* how Docker simplifies team development
* how important documentation is in a team project

---

## Notes

This repository only keeps a Common Core documentation entry for ft_transcendence.

The maintained public copy with the full README, team details, setup instructions and observability work is kept separately to avoid duplicating the same large project in multiple repositories.
