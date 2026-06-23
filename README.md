# Operating System Lab 💻⚙️

Welcome to the **Operating System Lab** repository! This project serves as a deeply comprehensive collection of classical Operating System algorithms, process management techniques, synchronization problems, and bash scripting utilities, primarily implemented in **C**, **C++**, and **Bash**.

All files have been strictly structured and accurately renamed with their proper extensions (`.c`, `.cpp`, `.sh`) to eliminate confusion and streamline direct compilation.

---

## 📑 Table of Contents

- [Repository Organization](#repository-organization)
- [1. CPU Scheduling Algorithms](#1-cpu-scheduling-algorithms)
- [2. Disk Scheduling Algorithms](#2-disk-scheduling-algorithms)
- [3. Page Replacement Algorithms](#3-page-replacement-algorithms)
- [4. Deadlock Avoidance](#4-deadlock-avoidance)
- [5. System Calls & Process Management](#5-system-calls--process-management)
- [6. Bash Shell Scripting Utilities](#6-bash-shell-scripting-utilities)
- [Getting Started (Compilation & Execution)](#getting-started-compilation--execution)

---

## 📂 Repository Organization

The entire codebase is cleanly categorized by computer science concepts into 6 main directories:

```text
Operating-System-Lab/
├── CPU_Scheduling/          # CPU resource allocation algorithms
├── Disk_Scheduling/         # HDD I/O seek algorithms
├── Page_Replacement/        # Memory paging & swapping algorithms
├── Deadlock_Avoidance/      # Banker's algorithm (safe state)
├── System_Calls/            # Low-level UNIX process management in C
├── Shell_Scripts/           # Bash scripts for OS administration
└── README.md
```

---

## 1. CPU Scheduling Algorithms
**Location:** `/CPU_Scheduling/`

Scheduling algorithms allocate CPU time to processes efficiently. This directory contains multiple logic variations (both C and C++ assignments):
- **FCFS (First Come First Serve):** `cpu_fcfs.c`, `cpu_fcfs.cpp`
- **SJF (Shortest Job First):** `cpu_sjf.c`, `cpu_sjf_v2.cpp`
- **Priority Scheduling:** `cpu_priority.c`, `cpu_priority.cpp`
- **Round Robin:** `round_robin.c`, `cpu_roundrobin.cpp`

---

## 2. Disk Scheduling Algorithms
**Location:** `/Disk_Scheduling/`

Disk scheduling manages incoming I/O requests to the hard disk to minimize seek time.
- **FCFS (First Come First Serve):** `disk_fcfs.c`, `disk_fcfs.cpp`
- **SSTF (Shortest Seek Time First):** `disk_sstf.c`, `disk_sstf.cpp`
- **SCAN (Elevator Algorithm):** `scan.c`, `disk_scan.cpp`
- **C-SCAN (Circular SCAN):** `cscan.c`, `disk_cscan.cpp`

---

## 3. Page Replacement Algorithms
**Location:** `/Page_Replacement/`

When memory is full, the OS must decide which memory pages to swap out to make room for new pages.
- **Consolidated Assignment:** `PageReplacement.cpp` (A combined C++ approach)
- **FIFO (First In First Out):** `fifo.c`
- **LRU (Least Recently Used):** `lru.c`
- **Optimal Page Replacement:** `optimal.c`

---

## 4. Deadlock Avoidance
**Location:** `/Deadlock_Avoidance/`

Evaluates system state dynamically to ensure resource allocation doesn't lead to a deadlock (identifying a Safe State).
- **Banker's Algorithm:** `banker.cpp`, `Bankers.cpp`

---

## 5. System Calls & Process Management
**Location:** `/System_Calls/`

Rich examples of UNIX system calls for process management using **C**.
- **Process Creation (`fork`):** 
  - `fork_basic.c`: Basic `fork()` demonstration.
  - `multiple_children.c`: Spawning multiple child processes.
  - `child_factorial.c`: Calculates factorial inside a child process.
- **Execution (`exec` family):** 
  - `execl_ls.c`: Demonstrates `execl` by running the `ls` command.
  - `execvp_ps.c`: Demonstrates `execvp` by running the `ps` command.
  - `exec_external.c`: General `exec` wrapper for external programs.
- **Process Synchronization & Exit (`wait` / `exit`):** 
  - `parent_wait.c`: Parent process waiting for a child to terminate using `wait()`.
  - `waitpid_demo.c`: Using `waitpid()` for specific child wait targeting.
  - `exit_status.c`: Handling and interpreting child process exit statuses.
- **Comprehensive Demo:** 
  - `sys_calls_demo.c`: A complete demonstration of multiple system calls combined.

---

## 6. Bash Shell Scripting Utilities
**Location:** `/Shell_Scripts/`

A robust collection of `.sh` scripts automating daily administrative OS tasks.
- **System & Disk Monitoring:** 
  - `disk_usage.sh`: Quickly checks disk usage.
  - `monitor_disk.sh`: Advanced continuous disk monitoring.
  - `count_stats.sh`: Counts lines, words, and characters.
- **File & Text Operations:** 
  - `file_ops_menu.sh` / `file_operations.sh`: Interactive menu for file operations (create, copy, delete).
  - `merge_files.sh`: Merges the content of multiple files.
  - `search_word.sh`: Searches for specific words/strings inside files.
  - `clean_tmp.sh`: Automatically cleans up temporary files.
- **Text Filtering & Sorting:** 
  - `head_n.sh`: Displays the top N lines of a file.
  - `tail_n.sh`: Displays the last N lines of a file.
  - `sort_nums.sh`: Reads and sorts numeric input.
- **Mathematics:** 
  - `calculator.sh`: Interactive terminal calculator for basic math operations.

---

## 🚀 Getting Started (Compilation & Execution)

### Prerequisites
- **GCC / G++ Compiler:** To compile the C and C++ files.
- **Bash Environment:** For shell scripts (Linux/macOS default, Git Bash or WSL on Windows).

### Compilation Guide

**For C programs (`.c` files):**
```bash
gcc filename.c -o output_name
./output_name
```

**For C++ programs (`.cpp` files):**
```bash
g++ filename.cpp -o output_name
./output_name
```

**For Shell Scripts (`.sh` files):**
```bash
chmod +x scriptname.sh
./scriptname.sh
```

---
*Maintained as an educational resource for mastering Operating System concepts through hands-on implementation.*
