#include "Task.h"

int main()
{
    Task t1("desc1", 30, 30);
    Task t2("desc2", 30, 40);

    std::cout << t1.compareWith(t2) << std::endl;

    t1.saveToBinary("test.bin");

    Task t3("test.bin");

    std::cout << t3.getDesc() << " " << t3.getPriority() << " " << t3.getStatus() << " " << t3.getDuration() << std::endl;

    t3.setStatus(true);
    t3.setStatus(false);
    std::cout << t3.getStatus() << std::endl;


    return 0;
}