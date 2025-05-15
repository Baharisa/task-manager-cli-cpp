#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include "Task.h"

// Load tasks from tasks.txt
void loadTasksFromFile(std::vector<Task>& taskList, int& idCounter) {
    std::ifstream inFile("tasks.txt");
    if (!inFile) {
        std::cout << "No existing task file found. Starting fresh.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        Task t;
        std::stringstream ss(line);
        std::string field;

        std::getline(ss, field, '|'); t.id = std::stoi(field);
        std::getline(ss, t.title, '|');
        std::getline(ss, t.description, '|');
        std::getline(ss, t.dueDate, '|');
        std::getline(ss, field, '|'); t.priority = std::stoi(field);
        std::getline(ss, field, '|'); t.completed = (field == "1");

        taskList.push_back(t);
        if (t.id >= idCounter) idCounter = t.id + 1;
    }

    inFile.close();
}

// Delete task by ID
void deleteTaskById(std::vector<Task>& taskList) {
    int idToDelete;
    std::cout << "Enter the ID of the task to delete: ";
    std::cin >> idToDelete;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool found = false;

    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->id == idToDelete) {
            taskList.erase(it);
            found = true;
            std::cout << "Task with ID " << idToDelete << " deleted.\n";
            break;
        }
    }

    if (!found) {
        std::cout << "No task found with ID " << idToDelete << ".\n";
    }
}

// Mark task as completed
void markTaskAsCompleted(std::vector<Task>& taskList) {
    int idToMark;
    std::cout << "Enter the ID of the task to mark as completed: ";
    std::cin >> idToMark;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool found = false;

    for (Task& t : taskList) {
        if (t.id == idToMark) {
            t.completed = true;
            found = true;
            std::cout << "Task with ID " << idToMark << " marked as completed.\n";
            break;
        }
    }

    if (!found) {
        std::cout << "No task found with ID " << idToMark << ".\n";
    }
}

int main() {
    std::vector<Task> taskList;
    int idCounter = 1;

    loadTasksFromFile(taskList, idCounter);

    if (!taskList.empty()) {
        std::cout << "\nLoaded Tasks:\n";
        for (const Task& t : taskList) {
            t.display();
        }
    }

    char choice;

    do {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. View all tasks\n";
        std::cout << "2. Add a task\n";
        std::cout << "3. Delete a task\n";
        std::cout << "4. Mark a task as completed\n";
        std::cout << "5. Exit and save\n";
        std::cout << "Choice (1-5): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == '1') {
            if (taskList.empty()) {
                std::cout << "No tasks available.\n";
            } else {
                for (const Task& t : taskList) {
                    t.display();
                }
            }

        } else if (choice == '2') {
            Task t;
            t.id = idCounter++;

            std::cout << "Enter task title: ";
            std::getline(std::cin >> std::ws, t.title);

            std::cout << "Enter description: ";
            std::getline(std::cin, t.description);

            std::cout << "Enter due date (e.g. 2025-05-14): ";
            std::getline(std::cin, t.dueDate);

            while (true) {
                std::cout << "Enter priority (1 = high, 5 = low): ";
                if (std::cin >> t.priority && t.priority >= 1 && t.priority <= 5) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    std::cout << "Invalid. Enter a number between 1 and 5.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            while (true) {
                std::cout << "Is the task completed? (0 = no, 1 = yes): ";
                int input;
                if (std::cin >> input && (input == 0 || input == 1)) {
                    t.completed = static_cast<bool>(input);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    std::cout << "Please enter 0 or 1.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            taskList.push_back(t);
            std::cout << "Task added.\n";

        } else if (choice == '3') {
            deleteTaskById(taskList);

        } else if (choice == '4') {
            markTaskAsCompleted(taskList);

        } else if (choice != '5') {
            std::cout << "Invalid choice. Please enter 1 through 5.\n";
        }

    } while (choice != '5');

    std::ofstream outFile("tasks.txt");
    if (outFile.is_open()) {
        for (const Task& t : taskList) {
            outFile << t.toFileString();
        }
        outFile.close();
        std::cout << "\nTasks saved to 'tasks.txt'\n";
    } else {
        std::cerr << "Failed to save tasks to file.\n";
    }

    return 0;
}
