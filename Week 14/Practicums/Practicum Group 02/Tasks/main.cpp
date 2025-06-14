#include "SingleTask.h"
#include "TaskGroup.h"
#include <iostream>

int main() {
    
    SingleTask* task1 = new SingleTask("Send email", 10, 5);
    SingleTask* task2 = new SingleTask("Submit report", 15, 3);
    SingleTask* task3 = new SingleTask("Call client", 5, 2);
    
    TaskGroup* group = new TaskGroup("Morning tasks");
    group->add(task1);
    group->add(task2);
    group->add(task3);

    std::cout << "=== Task hierarchy ===" << std::endl;
    group->print(1);

    long currentTime = 16;
    bool done = group->status(currentTime);
    std::cout << "\nAll tasks completed at time "
        << currentTime << "? "
        << (done ? "Yes" : "No") << std::endl;

    delete group;

    return 0;
}
