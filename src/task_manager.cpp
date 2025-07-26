/**
 * @file task_manager.cpp
 * @brief Implementation of the TaskManager class for managing tasks (CRUD operations) in a CLI Task Manager application.
 * 
 * Provides task addition, deletion, update, status change, file saving/loading, and listing features.
 * Includes input validation for robust command-line interaction.
 * 
 * @author Mohamed Waaer
 * @date 2025-07-25
 */

#include "task_manager.hpp"

/**
 * @brief Constructor for TaskManager.
 * 
 * Initializes the next available task ID.
 */
TaskManager::TaskManager()
{
    nextId = 0;
}

/**
 * @brief Adds a new task to the task list.
 * 
 * @param title Title of the new task.
 * @param desc Description of the new task.
 * @param dueDate Due date of the new task.
 * @param priority Priority level of the new task.
 */
void TaskManager::addTask(const std::string &title, const std::string &desc, const std::string &dueDate, const std::string &priority)
{
    nextId = (tasks.size() > 0) ? (tasks.back().int32GetTaskID()) : 0 ;
    Task CreateNewTask(++nextId, title, desc, dueDate, priority);
    tasks.push_back(CreateNewTask);
}

/**
 * @brief Lists all existing tasks in the system.
 * 
 * Displays each task's information using its string representation.
 */
void TaskManager::listTasks(void) const
{
    int TaskCounter = 0;
    if (tasks.size() > 0)
    {
        std::cout << "\n------------------- List Of Tasks -------------------" << std::endl;
        for (auto &ref : tasks)
        {
            std::cout << "Task " << ++TaskCounter << " Data ==>" << std::endl;
            std::cout << ref.toString() << std::endl;
            std::cout<<"------------------------------------------------------"<<std::endl;
        }
    }
    else
    {
        std::cout << "\nNo Tasks Found !!" << std::endl;
    }
}

/**
 * @brief Updates an existing task's fields by its ID.
 * 
 * User can update title, description, due date, or priority interactively.
 * 
 * @param id ID of the task to update.
 */
void TaskManager::updateTask(int id)
{
    bool TaskIdExistance = false;
    std::string Update = "1- Title\n2- Description\n3- Due Date\n4- Priority\n5- Exit";
    for (auto &it : tasks)
    {
        if (it.int32GetTaskID() == id)
        {
            TaskIdExistance = true;
            std::cout << "PLease Select The Item You Want To Upgrade " << std::endl;
            std::cout << Update << std::endl;
            int Option;
            while (true)
            {
                std::cin >> Option;
                if (ValidateUserInput() == true)
                {
                    if (Option == 5)
                    {
                        std::cout << "You Choosed To Leave " << std::endl;
                        break;
                    }
                    switch (Option)
                    {
                    case 1:
                    {
                        std::string title;
                        std::cout << "Enter The New Title" << std::endl;
                        std::cin >> title;
                        it.vidSetTitle(title);
                        std::cout << "Title Is Upgraded Successfully" << std::endl;
                        break;
                    }
                    case 2:
                    {
                        std::string Description;
                        std::cout << "Enter The New Description" << std::endl;
                        std::cin >> Description;
                        it.vidSetDescription(Description);
                        std::cout << "Description Is Upgraded Successfully" << std::endl;
                        break;
                    }
                    case 3:
                    {
                        std::string DueDate;
                        std::cout << "Enter The New DueDate" << std::endl;
                        std::cin >> DueDate;
                        it.vidSetDueDate(DueDate);
                        std::cout << "Due Date Is Upgraded Successfully" << std::endl;
                        break;
                    }
                    case 4:
                    {
                        std::string Priority;
                        std::cout << "Enter The New Priority" << std::endl;
                        std::cin >> Priority;
                        it.vidSetPriority(Priority);
                        std::cout << "Priority Is Upgraded Successfully" << std::endl;
                        break;
                    }
                    default:
                        std::cout << "Undefined Choice !!!" << std::endl;
                        break;
                    }
                }
                std::cout << "PLease Select The Item You Want To Upgrade " << std::endl;
                std::cout << Update << std::endl;
            }
        }
    }
    if (TaskIdExistance == false)
    {
        std::cout << "Task Id Is Not Exist" << std::endl;
    }
}

/**
 * @brief Deletes a task from the list by its ID.
 * 
 * @param id ID of the task to delete.
 */
void TaskManager::deleteTask(int id)
{
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](auto &it)
                           { return it.int32GetTaskID() == id; });
    if (it == tasks.end())
    {
        std::cout << "NO Task With ID = " << id << " Exists" << std::endl;
    }
    else
    {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](auto &it)
                                   { return it.int32GetTaskID() == id; }),
                    tasks.end());

        for (auto &it : tasks)
        {
            std::cout << it.toString() << std::endl;
        }

        std::cout << "Task With ID = " << id << " Has Been Deleted Successfully" << std::endl;
    }
}

/**
 * @brief Changes the completion status of a task.
 * 
 * Allows the user to mark the task as "Done" or "Pending".
 * 
 * @param id ID of the task to update status.
 */
void TaskManager::ChangeTaskStatus(int id)
{
    int TaskID = id - 1;
    if (TaskID < 0)
    {
        std::cout << "NO Task With ID = Exists" << id << std::endl;
    }
    else
    {
        int TaskStatus;
        std::cout << "PLease Chose The New Task Status" << std::endl;
        std::cout << "1-Change The Task Status To Be Done" << std::endl;
        std::cout << "2-Change The Task Status To Be Pending" << std::endl;
        std::cin >> TaskStatus;
        if (ValidateUserInput() == true)
        {
            if (TaskStatus == 1)
            {
                tasks[TaskID].markDone();
                std::cout << "Task Status For Task ID = " << id << " Marked As Done Successfully" << std::endl;
            }
            else if (TaskStatus == 2)
            {
                tasks[TaskID].markPending();
                std::cout << "Task Status For Task ID = " << id << " Marked As Pending Successfully" << std::endl;
            }
            else
            {
                /*Do Nothing*/
            }
        }
    }
}

/**
 * @brief Saves all tasks to a file.
 * 
 * If the file does not exist, it will be created.
 * Content is overwritten using truncation mode.
 * 
 * @param filename Name of the file to save tasks.
 */
void TaskManager::SaveTasksToFile(const std::string &filename) const
{
    bool FileStatus = true;
    if (std::filesystem::exists(filename) != true)
    {
        std::cout << "File isn't exist so we will create it " << std::endl;
        std::ofstream CreateFile(filename);
        if (!CreateFile)
        {
            std::cerr << "Error While Creating The File" << std::endl;
            FileStatus = false;
        }
        else
        {
            std::cout << "File Has Been Created Successfully" << std::endl;
        }
    }

    if (FileStatus == true)
    {
        std::fstream FileHandler(filename, std::ios::in | std::ios::out | std::ios::trunc);
        if (!FileHandler)
        {
            std::cerr << "Error While Opening The File" << std::endl;
        }
        else
        {
            for (auto &it : tasks)
            {
                std::string TaskDetails;
                TaskDetails = "ID: " + std::to_string(it.int32GetTaskID()) + '|' + "Title: " + it.int32GetTaskTitle() + '|' + "Description: " + it.int32GetTaskDescription() + '|' + "Due Date: " + it.int32GetTaskdueDate() + '|' + "Priority: " + it.int32GetTaskpriority() + '|' + "Status: " + it.GetTaskStatus() + "\n";
                FileHandler << TaskDetails;
            }
            std::cout << "Tasks Contenet Saved Successfully" << std::endl;
            FileHandler.close();
        }
    }
}

/**
 * @brief Loads tasks from a file and reconstructs them into memory.
 * 
 * If the file does not exist, it will be created.
 * 
 * @param filename Name of the file to load tasks from.
 */
void TaskManager::LoadTasksFrom(const std::string &filename)
{
    bool FileStatus = true;
    if (!std::filesystem::exists(filename))
    {
        std::cout << "File isn't exist so we will create it " << std::endl;
        std::ofstream CreateFile(filename);
        if (!CreateFile)
        {
            std::cerr << "Error While Creating The File" << std::endl;
            FileStatus = false;
        }
        else
        {
            std::cout << "File Has Been Created Successfully" << std::endl;
            CreateFile.close();
        }
    }
    else
    {
        std::cout << "Opening File In Progress ... " << std::endl;
        std::fstream Content(filename, std::ios::in | std::ios::out);
        if (!Content)
        {
            std::cerr << "Error While Opening The File" << std::endl;
        }
        else
        {
            std::cout << "Loading Tasks From The Provided File In Progress ... " << std::endl;
            std::string Data;
            while (std::getline(Content, Data))
            {
                std::stringstream stream(Data);
                std::vector<std::string> ParsedData;
                std::string buffer;
                std::string key, value;
                while (std::getline(stream, buffer, '|'))
                {
                    std::stringstream str(buffer);
                    if (std::getline(str, key, ':') && std::getline(str, value))
                    {
                        ParsedData.push_back(&value[1]);
                    }
                }
                Task temp(std::stoi(ParsedData[0]), ParsedData[1], ParsedData[2], ParsedData[3], ParsedData[4]);
                temp.vidSetTaskStatus(ParsedData[5]);
                tasks.push_back(temp);
                ParsedData.clear();
            }
            Content.close();
            std::cout << "Tasks Loaded Successfully" << std::endl;
        }
    }
}

/**
 * @brief Validates the current user input from std::cin.
 * 
 * Clears the input stream if it is in a fail state.
 * 
 * @return true if input is valid, false otherwise.
 */
bool ValidateUserInput(void)
{
    bool status = false;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "PLease Enter Vaild Choice " << std::endl;
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        status = true;
    }
    return status;
}

/**
 * @brief Destructor for TaskManager.
 */
TaskManager::~TaskManager() = default;
