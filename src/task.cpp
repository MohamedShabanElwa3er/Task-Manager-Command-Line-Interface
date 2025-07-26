/**
 * @file task.cpp
 * @brief Implementation of the Task class used to represent and manage individual tasks.
 *
 * This file provides functionality for creating, displaying, modifying, and tracking the status
 * of a single task within the Task Manager system.
 * Each task contains an ID, title, description, due date, priority, and status.
 * 
 * @author Mohamed Waaer
 * @date 2025-07-25
 */

#include "task.hpp"

/**
 * @brief Default constructor for Task.
 */
Task::Task() = default;

/**
 * @brief Parameterized constructor for Task.
 * 
 * Initializes a task with the given ID, title, description, due date, and priority.
 *
 * @param id Unique identifier for the task.
 * @param title Title of the task.
 * @param desc Description of the task.
 * @param dueDate Due date of the task.
 * @param priority Priority level of the task.
 */
Task::Task(int id, std::string title, std::string desc, std::string dueDate, std::string priority)
{
    this->id = id;
    this->title = title;
    this->description = desc;
    this->dueDate = dueDate;
    this->priority = priority;
}

/**
 * @brief Marks the task as done.
 */
void Task::markDone(void)
{
    this->TaskStatus = "Done";
}

/**
 * @brief Marks the task as pending.
 */
void Task::markPending(void)
{
    this->TaskStatus = "Pending";
}

/**
 * @brief Returns a string representation of the task's details.
 *
 * @return Formatted string containing task attributes.
 */
std::string Task::toString(void) const
{
    std::string TaskDetails;
    TaskDetails = "ID: " + std::to_string(id) + '\n' +
                  "Title: " + this->title + '\n' +
                  "Description: " + this->description + '\n' +
                  "Due Date: " + this->dueDate + '\n' +
                  "Priority: " + this->priority + '\n' +
                  "Status: " + this->TaskStatus;
    return TaskDetails;
}

/**
 * @brief Gets the ID of the task.
 *
 * @return Integer ID of the task.
 */
int Task::int32GetTaskID(void) const
{
    return this->id;
}

/**
 * @brief Gets the current status of the task.
 *
 * @return Task status as a string ("Done" or "Pending").
 */
std::string Task::GetTaskStatus(void) const
{
    return this->TaskStatus;
}

/**
 * @brief Sets the task's status.
 *
 * @param status New status value for the task.
 */
void Task::vidSetTaskStatus(std::string status)
{
    this->TaskStatus = status;
}

/**
 * @brief Gets the title of the task.
 *
 * @return Task title as a string.
 */
std::string Task::int32GetTaskTitle(void) const
{
    return title;
}

/**
 * @brief Gets the description of the task.
 *
 * @return Task description as a string.
 */
std::string Task::int32GetTaskDescription(void) const
{
    return description;
}

/**
 * @brief Gets the due date of the task.
 *
 * @return Due date as a string.
 */
std::string Task::int32GetTaskdueDate(void) const
{
    return dueDate;
}

/**
 * @brief Gets the priority of the task.
 *
 * @return Priority as a string.
 */
std::string Task::int32GetTaskpriority(void) const
{
    return priority;
}

/**
 * @brief Sets the title of the task.
 *
 * @param strNewTitle New title string to assign.
 */
void Task::vidSetTitle(std::string strNewTitle)
{
    this->title = strNewTitle;
}

/**
 * @brief Sets the description of the task.
 *
 * @param strNewDescription New description string to assign.
 */
void Task::vidSetDescription(std::string strNewDescription)
{
    this->description = strNewDescription;
}

/**
 * @brief Sets the due date of the task.
 *
 * @param strNewDueDate New due date string to assign.
 */
void Task::vidSetDueDate(std::string strNewDueDate)
{
    this->dueDate = strNewDueDate;
}

/**
 * @brief Sets the priority of the task.
 *
 * @param strNewPriority New priority string to assign.
 */
void Task::vidSetPriority(std::string strNewPriority)
{
    this->priority = strNewPriority;
}

/**
 * @brief Destructor for Task.
 */
Task::~Task() = default;
