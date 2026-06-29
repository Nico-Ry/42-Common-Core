# Webserv

Webserv is an HTTP/1.1 server written in C++ as part of the 42 Common Core.

The goal of the project is to build a small web server from scratch, capable of accepting client connections, parsing HTTP requests, serving files, handling routes, processing uploads and executing CGI scripts.

This project connects low-level networking with backend fundamentals and is one of the most relevant Common Core projects for backend development.

---

## Overview

The server listens for incoming TCP connections, handles multiple clients using non-blocking I/O, parses HTTP requests and generates valid HTTP responses.

It supports configuration-based behavior, similar to a simplified Nginx-style server.

Main responsibilities include:

* opening server sockets
* accepting client connections
* handling multiple clients concurrently
* parsing HTTP requests
* serving static files
* handling errors
* supporting file uploads
* executing CGI scripts
* generating HTTP responses
* managing timeouts and connection state

---

## Main Topics

* HTTP/1.1
* TCP sockets
* non-blocking I/O
* `poll()`
* request parsing
* response generation
* routing
* CGI execution
* file uploads
* server configuration
* client connection management
* error handling

---

## Skills Practiced

* C++ programming
* low-level networking
* backend fundamentals
* HTTP protocol behavior
* event-driven programming
* parsing
* file descriptor management
* debugging network applications
* working with concurrent clients
* writing maintainable server architecture

---

## Why This Project Matters

Webserv is one of the most important projects in the Common Core for backend-oriented developers.

Instead of using an existing framework, the project requires understanding what happens underneath a web server:

```text
client
  ↓
TCP connection
  ↓
HTTP request
  ↓
request parsing
  ↓
route handling
  ↓
file / CGI / upload logic
  ↓
HTTP response
  ↓
client
```

This makes it useful preparation for understanding backend frameworks, reverse proxies, APIs, HTTP security and production infrastructure.

---

## Features

* HTTP/1.1 request handling
* Multiple server blocks
* Multiple listening ports
* Non-blocking client handling
* Static file serving
* Directory handling
* Configurable error pages
* File upload support
* CGI execution
* Request body size limits
* Basic route configuration
* Connection timeout handling

---

## How to Build

```bash
make
```

---

## How to Run

```bash
./webserv path/to/config.conf
```

Example:

```bash
./webserv configs/default.conf
```

The exact configuration path may depend on the files available in this repository.

---

## Testing

The server can be tested with a browser, `curl`, or custom HTTP requests.

Examples:

```bash
curl -v http://localhost:8080/
curl -v -X POST http://localhost:8080/upload
curl -v http://localhost:8080/cgi-bin/script.py
```

---

## What I Learned

This project helped me understand how web servers work internally.

The most important lessons were:

* how sockets accept and manage client connections
* how non-blocking I/O avoids freezing the server
* how HTTP requests are structured
* how servers map requests to files, routes or CGI scripts
* how response codes and headers are generated
* how difficult edge cases become when handling real client behavior
* why frameworks and reverse proxies are useful in production

---

## Notes

Webserv was a major step from low-level C/C++ projects toward backend engineering.

It gave me a stronger understanding of the networking and protocol layer behind APIs, web frameworks and reverse proxies like Nginx.
