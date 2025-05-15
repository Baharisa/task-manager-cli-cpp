# Task Manager CLI (C++)

A simple command-line task manager written in C++.  
It lets you add, view, delete, and mark tasks as completed, with persistent storage in a text file.

---

##  Features

- View all tasks
- Add new tasks
- Delete tasks by ID
- Mark tasks as completed
- Save/load from `tasks.txt`
- Fully interactive menu system

---

##  Technologies

- Language: C++
- STL: `vector`, `fstream`, `string`, `iostream`
- CLI: PowerShell / Command Prompt
- Build: GCC (MinGW-w64 recommended for Windows)

---

##  Folder Structure

Task Manager CLI Tool/
├── main.cpp # Main program logic and menu
├── Task.cpp # Task methods (display + save format)
├── Task.h # Task class definition
├── tasks.txt # Saved task data
├── taskmanager.exe # Compiled binary (Windows)
└── README.md # This file


---

##  How to Build & Run

### 1. Compile:

```bash
g++ main.cpp Task.cpp -o taskmanager

2. Run:
./taskmanager       # Or .\taskmanager.exe on Windows


Sample Output

What would you like to do?
1. View all tasks
2. Add a task
3. Delete a task
4. Mark a task as completed
5. Exit and save
Choice (1-5):

Each task is saved like:
1|Do homework|Math pages 12-15|2025-05-14|2|0

Which means:

ID: 1

Title: Do homework

Description: Math pages 12-15

Due Date: May 14, 2025

Priority: 2 (1 = High, 5 = Low)

Completed: 0 (No)


License
MIT License – Free to use, modify, and share.


