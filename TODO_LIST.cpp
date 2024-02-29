#include <iostream>
#include <string>

#define MAX_TASKS 100

std::string tasks[MAX_TASKS];
bool completed[MAX_TASKS] = {false};
int taskCount = 0;

void addTask(const std::string& description) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount] = description;
        ++taskCount;
        std::cout << "Task added." << std::endl;
    } else {
        std::cout << "Cannot add more tasks. Task limit reached." << std::endl;
    }
}

void viewTasks() {
    if (taskCount == 0) {
        std::cout << "No tasks in the list." << std::endl;
    } else {
        std::cout << "Tasks:" << std::endl;
        for (int i = 0; i < taskCount; ++i) {
            std::cout << i + 1 << ". " << tasks[i] << " - " << (completed[i] ? "Completed" : "Pending") << std::endl;
        }
    }
}

void markTaskCompleted(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        completed[taskIndex - 1] = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }
        --taskCount;
        std::cout << "Task removed." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore the newline character left in the buffer
                std::getline(std::cin, taskDescription);
                addTask(taskDescription);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please choose again." << std::endl;
        }
    }

    return 0;
}
