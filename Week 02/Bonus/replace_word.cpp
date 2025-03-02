#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning(disable:4996)
 
namespace CONSTANTS
{
    constexpr int MAX_ROWS = 50;
    constexpr int MAX_ROW_LENGTH = 300;
    constexpr int MAX_WORD_LENGTH = 50;
}
 
void saveInFile(std::ofstream& outFile, char newContent[][CONSTANTS::MAX_ROW_LENGTH][CONSTANTS::MAX_WORD_LENGTH], size_t rows, size_t words)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < words; j++)
        {
            outFile << newContent[i][j] << ' ';
        }
 
        outFile << std::endl;
    }
}
 
void generateNewContent(std::ifstream& inFile, const char* target, const char* newWord, 
                        char newContent[][CONSTANTS::MAX_ROW_LENGTH][CONSTANTS::MAX_WORD_LENGTH], size_t& rows, size_t& words)
{
    char currLine[CONSTANTS::MAX_ROW_LENGTH]{};
 
    while (!inFile.eof())
    {
        inFile.getline(currLine, CONSTANTS::MAX_ROW_LENGTH);
        std::stringstream ss(currLine);
 
        size_t lineWords = 0;
        while (!ss.eof())
        {
            char currWord[CONSTANTS::MAX_WORD_LENGTH]{};
            ss >> currWord;
 
            if (strcmp(currWord, target) == 0)
            {
                strcpy(newContent[rows][lineWords++], newWord);
            }
 
            else
            {
                strcpy(newContent[rows][lineWords++], currWord);
            }
        }   
        
        words = std::max(words, lineWords);
        rows++;
    }
}
 
void replaceWith(const char* fileName, const char* target, const char* newWord)
{
    if (!fileName || !target || !newWord)
    {
        return;
    }
 
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        return;
    }
 
    char newContent[CONSTANTS::MAX_ROWS][CONSTANTS::MAX_ROW_LENGTH][CONSTANTS::MAX_WORD_LENGTH]{};
    size_t rows = 0;
    size_t words = 0;
    generateNewContent(inFile, target, newWord, newContent, rows, words);
 
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        return;
    }
 
    saveInFile(outFile, newContent, rows, words);
 
    inFile.close();
    outFile.close();
}
 
int main()
{
    std::ofstream outFile("file.txt");
    outFile << "text tex word d d a" << std::endl << "word ddddd d da ";
    outFile.close();
 
    const char* fileName = "file.txt";
    const char* target = "word";
    const char* newWord = "drow";
 
    replaceWith(fileName, target, newWord);
    
    return 0;
}
