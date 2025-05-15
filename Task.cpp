#include <iostream>
#include "Task.h"

void Task::display() const {
    std::cout << "--------------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Due Date: " << dueDate << "\n";
    std::cout << "Priority: " << priority << "\n";
    std::cout << "Completed: " << (completed ? "Yes" : "No") << "\n";
    std::cout << "--------------------------\n";
}

std::string Task::toFileString() const {
    return std::to_string(id) + "|" + title + "|" + description + "|" + dueDate + "|" +
           std::to_string(priority) + "|" + (completed ? "1" : "0") + "\n";
}
