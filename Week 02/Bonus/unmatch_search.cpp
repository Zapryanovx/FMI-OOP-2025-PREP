#include <iostream>
#include <fstream>

namespace CONSTANTS
{
    constexpr int BUFFER_SIZE = 1024;
}

int getLineOfUnmatch(std::ifstream& ifsFile1, std::ifstream& ifsFile2)
{
    char buffFile1[CONSTANTS::BUFFER_SIZE]{};
    char buffFile2[CONSTANTS::BUFFER_SIZE]{};

    int atLine = 1;
    while (!ifsFile1.eof() && !ifsFile2.eof())
    {
        ifsFile1.getline(buffFile1, CONSTANTS::BUFFER_SIZE);
        ifsFile2.getline(buffFile2, CONSTANTS::BUFFER_SIZE);

        if (strcmp(buffFile1, buffFile2) != 0)
        {
            return atLine;
        }

        atLine++;
    }

    return -1;
}


int getLineOfUnmatch(const char* file1, const char* file2)
{
    if (!file1 || !file2)
    {
        return -1;
    }

    std::ifstream ifsFile1(file1);
    std::ifstream ifsFile2(file2);

    if (!ifsFile1.is_open() || !ifsFile2.is_open())
    {
        return 0;
    }

    return getLineOfUnmatch(ifsFile1, ifsFile2);
}

int main() {

    std::ofstream ofs1("file1.txt");
    ofs1 << "asd" << std::endl;
    ofs1 << "asd" << std::endl;
    ofs1.close();

    std::ofstream ofs2("file2.txt");
    ofs2 << "asd" << std::endl;
    ofs2.close();

    std::cout << getLineOfUnmatch("file1.txt", "file2.txt");

    return 0;
}
