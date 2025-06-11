#include <iostream>
#include <string>
#include "MyStack.hpp"

int main() {
    std::cout << std::boolalpha;

    MyStack<int> s;
    std::cout << "s.empty() initially: " << s.empty() << std::endl;

    for (int i = 1; i <= 5; ++i) {
        s.push(i * 10);
        std::cout << "pushed " << i * 10 << ", top=" << s.top()
            << ", size=" << s.getSize() << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "pop(), removing " << s.top() << std::endl;
        s.pop();
        std::cout << " now top=" << (s.empty() ? -1 : s.top())
            << ", size=" << s.getSize() << std::endl;
    }

    MyStack<int> copyStack = s;
    std::cout << "copyStack top=" << (copyStack.empty() ? -1 : copyStack.top())
        << ", size=" << copyStack.getSize() << std::endl;

    MyStack<int> movedStack = std::move(copyStack);
    std::cout << "movedStack top=" << movedStack.top()
        << ", size=" << movedStack.getSize() << std::endl;
    std::cout << "copyStack.empty() after move: " << copyStack.empty() << std::endl;

    MyStack<std::string> strStack;
    strStack.push("hello");
    strStack.push("world");
    std::cout << "strStack top=" << strStack.top()
        << ", size=" << strStack.getSize() << std::endl;

    strStack.pop();
    std::cout << "after pop, strStack top=" << strStack.top()
        << ", size=" << strStack.getSize() << std::endl;

    return 0;
}
