# I-eats 🚚 (Graph-Oriented Logistics Simulation - CLI - Windows)

> **I-eats** is a *finished* academic / learning project: a Windows console (CLI) simulation of a multi-role logistics network set on a set of **islands connected by bridges**. Users log in either as **Customer** (placing resource orders originating from islands) or **Driver** (fulfilling and navigating orders). The core engine models islands and bridges as a **graph with capacity constraints**, persisting data in simple file-based storage ("*.isle" data plus credential archives).

<p align="center">
  <img alt="MIT License" src="https://img.shields.io/badge/license-MIT-blue" />
  <img alt="Status Finished" src="https://img.shields.io/badge/status-finished-success" />
  <img alt="Last Commit" src="https://img.shields.io/github/last-commit/Klinker195/I-eats" />
  <img alt="Code Size" src="https://img.shields.io/github/languages/code-size/Klinker195/I-eats" />
</p>

---

## Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Architecture](#architecture)
4. [Project Structure](#project-structure)
5. [Data & Persistence](#data--persistence)
6. [Graph Model](#graph-model)
7. [User Roles & Flow](#user-roles--flow)
8. [Building (Windows)](#building-windows)
9. [Running](#running)
10. [Academic Context](#academic-context)

---

## Overview
I-eats provides a terminal-driven experience that emphasizes **graph manipulation, menu-based UI, role-dependent actions, and simple persistence** rather than network programming or GUI frameworks. The simulation abstracts a delivery / logistics scenario onto islands (vertices) and bridges (edges) with maximum weight constraints affecting order fulfillment planning.

## Features
- **Multi-Role Authentication**: Separate login / registration flows for *Customer* and *Driver* (with driver key gate).
- **Graph-Based World**: Islands & bridges loaded from / persisted to files; dynamic addition/removal via debug utilities.
- **Capacity Constraints**: Bridges (edges) carry a `MaxWeight` influencing which orders / resources can traverse paths.
- **Resource Orders**: Customers create orders composed of multiple resources & quantities linked to an island.
- **Driver Operations**: Drivers inspect pending orders, view resource lists, and (optionally) simulate fulfillment steps.
- **Debug Mode**: Exposes tools to add/remove islands, bridges, resources, and inspect internal lists/IDs.
- **Color & Navigation**: ANSI color highlighting and arrow-key menu navigation for an interactive console experience.
- **File-Based IDs**: Incremental IDs for islands and other entities stored in dedicated files for repeatable sessions.
- **Separation by Modules**: Distinct C source files for UI, accounts, graph operations, data structures, and utilities.
- **Finished Scope**: The project is feature-complete relative to its academic learning objectives (not an active product).

## Architecture
A modular C codebase organized by *concern*:
- **Entry Point**: `main.c` initializes the environment and dispatches to role-specific flows through the island start screen.
- **UI Layer**: `cliui.c` handles ASCII rendering, colorful menus, interactive selection (arrow keys), and debug listings.
- **Domain / Simulation**: `graph.c` (island & bridge management), `datastructures.c` & `linkedlist.c` (orders, edges, generic nodes).
- **Account Management**: `account.c` handles registration, login, validation (including driver key).
- **Utilities**: `utils.c` (ID management, validation helpers, error handling), `isle.c` (high-level orchestration of login/role switching).
- **Headers** (not shown here) define shared structs: `Vertex_t`, `Edge_t`, `Order_t`, `Node_t`, etc.

This structure separates user interaction from core data manipulation for clarity, while still keeping the code concise for educational review.

## Project Structure
```
I-eats/
  main.c
  isle.c
  account.c
  cliui.c
  graph.c
  datastructures.c
  linkedlist.c
  utils.c
  include/            
  data/               # *.isle and credential files (created at runtime)
  README.md
  LICENSE
```
> *Note:* Directory names like `include/` or `data/` should be created if not already present when organizing the repository; runtime may generate files on first execution.

## Data & Persistence
- **Credential Files**: Separate driver & customer credential archives (plaintext) for role-based login.
- **Island / Graph Files**: Each island stored with its ID and adjacency/bridge definitions (`.isle` files). An ID tracker file (e.g., `IslandIDs.isle`) increments to ensure unique vertex IDs.
- **Orders & Resources**: Persisted via serialized lists (plain text) enabling resume across runs.

## Graph Model
- **Vertices (`Vertex_t`)**: Island name, numeric ID, adjacency list of bridges.
- **Edges (`Edge_t`)**: Bridge between two island IDs with `MaxWeight` constraint.
- **Adjacency Representation**: Linked lists allow dynamic insertion/removal at runtime.
- **Constraints**: Order/resource routing must respect maximum weight on bridges (future enhancements could add path finding with weight filtering).

## User Roles & Flow
1. **Startup Menu** → Choose *Customer*, *Driver*, or *Debug*.
2. **Authentication** → Login or register (driver path guarded by driver key).
3. **Role Dashboard**:
   - *Customer*: Create orders, list existing, view resources.
   - *Driver*: Browse pending orders, inspect details, (optionally) mark progress.
4. **Debug Mode**: Manage islands, bridges, resource catalogs, inspect internal lists/IDs.
5. **Exit**: Return to startup or terminate session (data persists in files).

## Building (Windows)
I-eats uses Windows-specific APIs (`windows.h`, `_getch`, `_kbhit`, console handles) and is intended for **Windows only**.

### Option A – MSVC (Developer Command Prompt)
```bat
cl /Fe:i-eats.exe /I include *.c
```
If source files are in root without an `include` folder, adjust accordingly.

### Option B – MinGW (GCC)
```bash
gcc -O2 -Wall -Wextra -std=c11 -o i-eats.exe   main.c isle.c account.c cliui.c graph.c datastructures.c linkedlist.c utils.c
```
Add `-I include` if headers are in an `include` directory.

> Enable ANSI color support on newer Windows 10+ terminals (if needed) by setting the Virtual Terminal processing flag (recent Windows terminals often have it enabled automatically).

## Running
Run `i-eats.exe` in a terminal that supports ANSI escape sequences. The program will create needed data files on first run (IDs, credentials, islands). Use arrow keys / Enter to navigate menus; follow on-screen prompts for resource and order creation.

## Academic Context
Developed as a learning exercise focusing on data structures (graphs & linked lists), graph navigation and file I/O rather than production security or networking. Emphasis is on readability, modular separation, and demonstration of graph-based logistics constraints.

---

*Enjoy exploring the islands!* 🗺️
