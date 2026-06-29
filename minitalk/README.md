# minitalk

minitalk is an inter-process communication project from the 42 Common Core.

The goal is to create a small client/server messaging system using only Unix signals.

The client sends a string message to the server, and the server receives and reconstructs it bit by bit.

---

## Overview

The project contains two programs:

| Program  | Role                                                 |
| -------- | ---------------------------------------------------- |
| `server` | Waits for incoming signals and reconstructs messages |
| `client` | Sends a message to the server using its process ID   |

The server prints its PID when launched. The client uses that PID to send a message.

```text id="6x4428"
server starts
  ↓
server prints PID
  ↓
client receives PID + message
  ↓
client converts characters to bits
  ↓
client sends bits as signals
  ↓
server reconstructs characters
  ↓
server prints the message
```

---

## Signals Used

The project uses Unix signals to represent binary data.

A common approach is:

| Signal    | Meaning    |
| --------- | ---------- |
| `SIGUSR1` | binary `0` |
| `SIGUSR2` | binary `1` |

Each character is converted into bits, and each bit is sent as a signal.

For example:

```text id="78wm68"
'A' -> 01000001
```

The client sends each bit one by one. The server receives the signals, rebuilds the byte and prints the corresponding character.

---

## Main Topics

* Unix signals
* process IDs
* inter-process communication
* bit manipulation
* binary representation
* signal handlers
* asynchronous execution
* client/server architecture

---

## Skills Practiced

* C programming
* working with `kill()`
* working with `signal()` / `sigaction()`
* handling process IDs
* bit shifting
* reconstructing characters from bits
* debugging asynchronous behavior
* writing small client/server programs

---

## How to Build

```bash id="yhjp3e"
make
```

This should build the client and server executables.

---

## How to Run

First, start the server:

```bash id="aef6yk"
./server
```

The server displays its process ID:

```text id="xng832"
Server PID: 12345
```

Then, in another terminal, send a message using the client:

```bash id="lhfa5g"
./client 12345 "Hello from minitalk"
```

The server should receive and print the message.

---

## Example

Terminal 1:

```bash id="t19f1b"
./server
```

Output:

```text id="72vd0u"
Server PID: 12345
```

Terminal 2:

```bash id="xszuxz"
./client 12345 "Hello 42"
```

Server output:

```text id="7tig03"
Hello 42
```

---

## Why This Project Matters

minitalk is small, but it teaches an important systems concept: processes normally do not share memory, so they need a communication mechanism.

In this project, that communication happens through signals.

```text id="syj5p5"
character
  ↓
bits
  ↓
signals
  ↓
received bits
  ↓
reconstructed character
```

This helped me understand how low-level communication can be built from very small primitives.

---

## Typical Edge Cases

Important cases to handle include:

* missing arguments
* invalid server PID
* empty messages
* long messages
* special characters
* signal timing
* server remaining active after receiving a message
* avoiding lost signals by controlling send speed

---

## What I Learned

The most important lessons from this project were:

* how Unix processes can communicate through signals
* how characters are represented as bytes
* how to send data bit by bit
* how signal handlers work
* why asynchronous behavior is harder to debug
* why timing matters when sending many signals quickly
* how to build a simple protocol between two programs

---

## Notes

minitalk was a useful introduction to inter-process communication.

It made low-level concepts like PIDs, signals and binary representation much more concrete.
