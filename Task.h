#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    int id;
    std::string title;
    std::string description;
    std::string dueDate;
    int priority;
    bool completed;

    void display() const;
    std::string toFileString() const;
};

#endif
