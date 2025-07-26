# 🗂️ Task Manager CLI App

A simple and efficient **Command-Line Task Manager** written in **C++**. This project helps users manage tasks with features like adding, listing, updating, deleting, and changing task status. Tasks are persisted to a file across runs.

---

## 📌 Project Structure

TaskManagerApp/
├── src/
│   ├── main.cpp
│   ├── task.cpp
│   ├── task_manager.cpp
│   ├── task.hpp
│   └── task_manager.hpp
├── README.md


## 📌 Features

- Add new tasks with title, description, due date, and priority
- List all existing tasks in a clear format
- Update task details
- Change task status (`Pending` ↔ `Done`)
- Delete tasks by ID
- Load tasks from a file and save on exit
- Input validation and error handling
- Fully documented using **Doxygen**

---

## 📂 Project Compilation and Execution 

- PLease Use The Following Command to build and execute the program

## g++ -std=c++17 main.cpp task.cpp task_manager.cpp -o TaskManager

