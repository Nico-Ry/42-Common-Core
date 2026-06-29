# Inception

Inception is a Docker infrastructure project from the 42 Common Core.

The goal of the project is to build a small multi-container environment from scratch using Docker, Docker Compose, Nginx, MariaDB and WordPress.

This project introduced me to service orchestration, container networking, persistent volumes, secrets, Makefile automation and infrastructure-style project organization.

---

## Overview

The project runs a WordPress website behind an Nginx reverse proxy, with MariaDB as the database.

Each major service runs in its own container:

```text
client
  ↓
Nginx container
  ↓
WordPress / PHP-FPM container
  ↓
MariaDB container
```

The containers communicate through a Docker network and store persistent data using bind mounts or volumes.

---

## Services

| Service        | Role                                        |
| -------------- | ------------------------------------------- |
| Nginx          | Reverse proxy and HTTPS entry point         |
| WordPress      | Website application running with PHP-FPM    |
| MariaDB        | Database used by WordPress                  |
| Docker Compose | Service orchestration                       |
| Makefile       | Build, reset, test and maintenance commands |

---

## Main Topics

* Docker
* Docker Compose
* container networking
* service orchestration
* Nginx configuration
* MariaDB setup
* WordPress configuration
* PHP-FPM
* bind mounts
* named volumes
* Docker secrets
* Makefile automation
* infrastructure testing

---

## Local Setup With Example Secrets

This repository includes example secret files with dummy values.

To run the project locally, copy the example files into the real ignored locations:

```bash
cp -r secrets.example/* secrets/
cp srcs/.env.example srcs/.env
```

Then edit the copied files if needed.

The real secrets/ files and srcs/.env are ignored by Git and should not be committed.

In a real deployment:

* never commit real passwords
* never reuse demo credentials
* replace all example secrets
* store secrets outside the public repository
* use environment-specific secret management
* rotate credentials if they were ever exposed

The `.gitignore` is configured to ignore secret files by default:

```gitignore
# --- Secrets (NEVER commit) ---
secrets/*
!secrets/.gitkeep
```

If example files are kept in the repository, they should be treated only as local demo values, not production credentials.

---

## Path-Based Secrets

The Compose configuration can load secrets from file paths.

This means the project can be adapted depending on where the secret files are stored.

For example, the project can be configured to use:

```text
secrets/
secrets.example/
/path/to/local/secrets/
```

The important idea is that the Compose file references secret files by path, and those paths can be adjusted depending on the execution environment.

---

## Makefile Automation

The project includes a Makefile to make the infrastructure easier to build, reset, inspect and test.

Useful commands include:

| Command             | Description                                                                    |
| ------------------- | ------------------------------------------------------------------------------ |
| `make up`           | Staged bring-up: database → WordPress → Nginx, with health waits               |
| `make build`        | Build images only                                                              |
| `make down`         | Stop and remove containers while keeping bind directories                      |
| `make re`           | Remove bind directories, rebuild and start again                               |
| `make pristine`     | Full reset: bind directories, named volumes and images, then rebuild and start |
| `make logs`         | Follow container logs                                                          |
| `make ps`           | Show container status                                                          |
| `make sh-nginx`     | Open a shell inside the Nginx container                                        |
| `make sh-wordpress` | Open a shell inside the WordPress container                                    |
| `make sh-mariadb`   | Open a shell inside the MariaDB container                                      |
| `make wp-reset`     | Delete only the WordPress bind directory while keeping the database            |
| `make db-reset`     | Delete the database bind directory while keeping WordPress files               |
| `make test`         | Run smoke tests for TLS, routing, PHP-FPM, database and WordPress              |
| `make env`          | Show the fully resolved Docker Compose configuration                           |

These commands made the project easier to test and reset during development.

---

## How to Run

From the project directory:

```bash
make up
```

Then open the configured domain or local address in the browser.

Depending on the VM and `/etc/hosts` configuration, the domain may need to point to the local VM IP.

---

## How to Stop

```bash
make down
```

---

## Full Rebuild

```bash
make re
```

For a complete reset:

```bash
make pristine
```

This removes generated data and rebuilds the environment from scratch.

---

## Testing

The project includes a smoke-test command:

```bash
make test
```

The tests are intended to verify important infrastructure behavior such as:

* Nginx routing
* HTTPS/TLS response
* WordPress availability
* PHP-FPM communication
* MariaDB availability
* container health
* expected service connectivity

---

## Skills Practiced

* writing Dockerfiles
* building custom service images
* configuring Docker Compose
* managing container dependencies
* configuring Nginx as a reverse proxy
* connecting WordPress to MariaDB
* using persistent storage
* working with secrets
* writing Makefile automation
* testing infrastructure behavior
* debugging container logs
* resetting and rebuilding environments

---

## What I Learned

This project helped me understand how multiple services work together in a containerized environment.

The most important lessons were:

* how containers communicate through Docker networks
* how Nginx acts as the public entry point
* how WordPress depends on both PHP-FPM and MariaDB
* how persistent data survives container recreation
* why secrets should be separated from source code
* how Makefiles can simplify infrastructure workflows
* how useful logs and smoke tests are when debugging services
* why clean reset commands are important in infrastructure projects

---

## Security Note

This project is an educational infrastructure exercise, not a production-ready deployment.

Any included secret values must be treated as examples only.

For real-world usage, credentials should be replaced, stored securely and excluded from the public repository.

---

## Notes

Inception was important because it connected system administration, Docker, networking and backend deployment concepts.

It gave me a practical foundation for understanding containerized services, reverse proxies and reproducible development environments.
