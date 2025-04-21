#include <iostream>

void throwSomething()
{
	int choice;

    std::cout
        << "What do you want to throw?\n"
        << " [1] char\n"
        << " [2] int\n"
        << " [3] double\n"
        << " [4] std::exception object\n"
        << " [5] std::out_of_range object\n"
        << "Your choice: ";

	std::cin >> choice;
    
    switch (choice)
    {
        case 1: throw 'E';
        case 2: throw -1;
        case 3: throw -1.5;
        case 4: throw std::runtime_error("Runtime err");
        case 5: throw std::out_of_range("Out of range err");
        default:
            throw std::logic_error("choice must be 1-5");
    }
}

void caller()
{
    try
    {
        throwSomething();
    }

    catch (char ch)
    {
        std::cout << "char caught";
    }

    catch (int n)
    {
        std::cout << "int";
    }
}

int main()
{
    try
    {
        caller();
    }

    catch(double n)
    {
        std::cout << "caught double";
    }

    catch (std::runtime_error& err)
    {
        std::cout << "caught runtime err" << err.what();
    }

    catch (std::out_of_range& err)
    {
        std::cout << "caught out of range " << err.what();

    }

    catch (...)
    {
        std::cout << "caught logic err ";
    }

	return 0;
}