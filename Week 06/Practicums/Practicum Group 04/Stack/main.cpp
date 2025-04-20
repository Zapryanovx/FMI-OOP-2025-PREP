#include "Stack.h"

int main()
{
    Stack st;

    for (size_t i = 0; i < 10; i++)
    {
        st.push(i);
    }

    std::cout << st.peek() << std::endl;
    st.pop();
    std::cout << st.peek();

    return 0;
}