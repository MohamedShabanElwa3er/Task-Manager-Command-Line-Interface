/**
 * @file main.cpp
 * @brief Entry point for the Task Manager CLI application.
 *
 * This file contains the main loop that allows users to interact with the task manager.
 * Users can add, list, update, delete, and change the status of tasks through a text-based menu.
 * The application also handles loading from and saving to a file.
 *
 * @author Mohamed Waaer
 * @date 2025-07-25
 */

#include "task_manager.hpp"
#include <limits>

/**
 * @brief Main function to drive the task manager application.
 *
 * Provides a console-based menu to perform various task-related operations.
 * Loads tasks from file at startup and saves them on exit.
 *
 * @return int Exit status code.
 */
int main()
{
    TaskManager manager;
    manager.LoadTasksFrom("tasks.txt");

    int choice;
    bool condition = true;

    while (condition)
    {
        std::cout << "\n1. Add Task\n2. List Tasks\n3. Update Task\n4. Delete Task\n5. Change Task Status\n6. Save & Exit\nChoice: ";
        std::cin >> choice;

        if (ValidateUserInput() == true)    /*Check If The User Enters Invalid Input Format*/
        {
            switch (choice)
            {
            case 1:
            {
                std::string TaskTitle;
                std::string TaskDescription;
                std::string TaskDueDate;
                std::string TaskPriority;

                std::cout << "Please Provide The Following Task Details:\n";
                std::cout << "Task Title: ";
                std::getline(std::cin, TaskTitle);
                std::cout << "Task Description: ";
                std::getline(std::cin, TaskDescription);
                std::cout << "Task Due Date: ";
                std::getline(std::cin, TaskDueDate);
                std::cout << "Task Priority: ";
                std::getline(std::cin, TaskPriority);

                manager.addTask(TaskTitle, TaskDescription, TaskDueDate, TaskPriority);
                break;
            }
            case 2:
            {
                manager.listTasks();
                break;
            }
            case 3:
            {
                int TaskID;
                std::cout << "Enter Task ID To Update The Task Specifications: ";
                std::cin >> TaskID;
                if (ValidateUserInput())    /*Check If The User Enters Invalid Input Format*/
                {
                    manager.updateTask(TaskID);
                }
                break;
            }
            case 4:
            {
                int TaskID;
                std::cout << "Enter Task ID For The Task You Want To Delete: ";
                std::cin >> TaskID;
                if (ValidateUserInput())    /*Check If The User Enters Invalid Input Format*/
                {
                    manager.deleteTask(TaskID);
                }
                break;
            }
            case 5:
            {
                int TaskID;
                std::cout << "Enter Task ID To Update The Task Status: ";
                std::cin >> TaskID;
                if (ValidateUserInput())    /*Check If The User Enters Invalid Input Format*/
                {
                    manager.ChangeTaskStatus(TaskID);
                }
                break;
            }
            case 6:
                std::cout << "Saving Modifications In Progress...\n";
                condition = false;
                break;

            default:
                std::cout << "Wrong Choice! Please Try Again.\n";
                break;
            }
        }
        else
        {
            std::cout << "Invalid input! Please try again.\n";
        }
    }

    manager.SaveTasksToFile("tasks.txt");
    return 0;
}
