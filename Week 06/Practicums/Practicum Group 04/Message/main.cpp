#include "Message.h"

int main()
{
    Message m("s", "r", "m", 12);

    Message m2(m);
    Message m3;
    m3 = m2;

    std::cout << m3.getSender() << " " << m3.getReceiver() << " " << m3.getMessage() << " " << m3.getFont();

    return 0;
}