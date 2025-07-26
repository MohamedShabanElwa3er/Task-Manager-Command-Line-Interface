/**
 * @file task_manager.hpp
 * @brief Declaration of the TaskManager class and related functionality for task management.
 *
 * The TaskManager class is responsible for adding, listing, updating, deleting,
 * changing task status, and handling file input/output operations.
 * Also includes a helper function for input validation.
 * 
 * @author Mohamed Waaer
 * @date 2025-07-25
 */

#ifndef __TASK__MANAGER__
#define __TASK__MANAGER__

#include <iostream>
#include <vector>
#include "task.hpp"
#include <functional>
#include <limits>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <regex>

/**
 * @class TaskManager
 * @brief Manages a collection of tasks and provides operations to manipulate them.
 *
 * Handles creation, retrieval, updating, deletion, and persistence of tasks.
 */
class TaskManager {
private:
    std::vector<Task> tasks;  /**< List of all tasks. */
    int nextId;               /**< Tracks the next available task ID. */

public:
    /**
     * @brief Constructor for TaskManager.
     */
    TaskManager();

    /**
     * @brief Adds a new task to the list.
     *
     * @param title Title of the task.
     * @param desc Description of the task.
     * @param dueDate Due date of the task.
     * @param priority Priority level of the task.
     */
    void addTask(const std::string& title, const std::string& desc, const std::string& dueDate, const std::string& priority);

    /**
     * @brief Lists all current tasks.
     */
    void listTasks() const;

    /**
     * @brief Updates task fields based on task ID.
     *
     * @param id ID of the task to update.
     */
    void updateTask(int id);

    /**
     * @brief Deletes a task from the list by ID.
     *
     * @param id ID of the task to delete.
     */
    void deleteTask(int id);

    /**
     * @brief Changes the status of a task (Pending/Done).
     *
     * @param id ID of the task whose status to change.
     */
    void ChangeTaskStatus(int id);

    /**
     * @brief Saves the current task list to a file.
     *
     * @param filename Name of the file to save tasks.
     */
    void SaveTasksToFile(const std::string& filename) const;

    /**
     * @brief Loads tasks from a file into memory.
     *
     * @param filename Name of the file to load tasks from.
     */
    void LoadTasksFrom(const std::string& filename);

    /**
     * @brief Destructor for TaskManager.
     */
    ~TaskManager();
};

/**
 * @brief Validates user input from standard input.
 * 
 * Clears any input errors and discards invalid characters.
 *
 * @return true if input is valid, false otherwise.
 */
bool ValidateUserInput(void);

#endif // __TASK__MANAGER__
