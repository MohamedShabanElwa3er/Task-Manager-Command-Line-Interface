/**
 * @file task.hpp
 * @brief Declaration of the Task class representing individual tasks.
 *
 * The Task class encapsulates task-related data such as ID, title, description,
 * due date, priority, and status. It provides methods to access and modify these fields,
 * as well as utility functions like marking as done/pending and converting to string format.
 * 
 * @author Mohamed Waaer
 * @date 2025-07-25
 */

#ifndef __TASK__
#define __TASK__

#include <iostream>

/**
 * @class Task
 * @brief Represents a single task in the task management system.
 */
class Task
{
private:
    int id = 0;                     /**< Unique identifier of the task. */
    std::string title = "";         /**< Title of the task. */
    std::string description = "";   /**< Description of the task. */
    std::string dueDate = "";       /**< Due date of the task. */
    std::string priority = "";      /**< Priority level of the task. */
    std::string TaskStatus = "Pending"; /**< Current status of the task (e.g., Pending, Done). */

public:
    /**
     * @brief Default constructor for Task.
     */
    Task();

    /**
     * @brief Parameterized constructor for Task.
     *
     * @param id Task ID.
     * @param title Task title.
     * @param desc Task description.
     * @param dueDate Task due date.
     * @param priority Task priority level.
     */
    Task(int id, std::string title, std::string desc, std::string dueDate, std::string priority);

    /**
     * @brief Marks the task as done.
     */
    void markDone(void);

    /**
     * @brief Marks the task as pending.
     */
    void markPending(void);

    /**
     * @brief Returns a string representation of the task.
     *
     * @return Formatted task details.
     */
    std::string toString(void) const;

    /**
     * @brief Gets the task ID.
     *
     * @return Integer ID of the task.
     */
    int int32GetTaskID(void) const;

    /**
     * @brief Gets the task title.
     *
     * @return Task title as a string.
     */
    std::string int32GetTaskTitle(void) const;

    /**
     * @brief Gets the task description.
     *
     * @return Task description as a string.
     */
    std::string int32GetTaskDescription(void) const;

    /**
     * @brief Gets the task due date.
     *
     * @return Due date as a string.
     */
    std::string int32GetTaskdueDate(void) const;

    /**
     * @brief Gets the task priority level.
     *
     * @return Priority as a string.
     */
    std::string int32GetTaskpriority(void) const;

    /**
     * @brief Gets the current status of the task.
     *
     * @return Task status as a string.
     */
    std::string GetTaskStatus(void) const;

    /**
     * @brief Sets the task status.
     *
     * @param status New status string.
     */
    void vidSetTaskStatus(std::string status);

    /**
     * @brief Sets a new title for the task.
     *
     * @param strNewTitle New title.
     */
    void vidSetTitle(std::string strNewTitle);

    /**
     * @brief Sets a new description for the task.
     *
     * @param strNewDescription New description.
     */
    void vidSetDescription(std::string strNewDescription);

    /**
     * @brief Sets a new due date for the task.
     *
     * @param strNewDueDate New due date.
     */
    void vidSetDueDate(std::string strNewDueDate);

    /**
     * @brief Sets a new priority level for the task.
     *
     * @param strNewPriority New priority.
     */
    void vidSetPriority(std::string strNewPriority);

    /**
     * @brief Destructor for Task.
     */
    ~Task();
};

#endif // __TASK__
