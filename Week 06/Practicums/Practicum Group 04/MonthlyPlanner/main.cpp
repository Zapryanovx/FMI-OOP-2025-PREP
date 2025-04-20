#include "MonthlyPlanner.h"

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

    MonthlyPlanner mp;
    mp.addTask(t1, 1, 1);
    mp.addTask(t2, 1, 4);
    mp.addTask(t3, 1, 10);

    mp.printUnfinishedOn(1);

    mp.saveToBinary("mp.bin");

    MonthlyPlanner mp2;
    mp2.readFromBinary("mp.bin");
    mp2.printUnfinishedOn(1);


    return 0;
}