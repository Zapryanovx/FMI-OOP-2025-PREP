#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int USER_DATA_SIZE = 504;
	constexpr int START_INDEX = 0;
}

struct UserData
{
	uint64_t next = 0;
	char data[CONSTANTS::USER_DATA_SIZE]{};
};

void goAtLine(std::ifstream& inFile, size_t next)
{

	inFile.seekg(0, std::ios::beg);

	UserData buff;
	while (next--)
	{
		inFile.read((char*)&buff, sizeof(buff));
	}
}

void returnAtLine(std::ifstream& inFile, size_t at)
{
	inFile.seekg(at);
}

UserData readUserData(std::ifstream& inFile)
{
	UserData user;
	inFile.read((char*)&user, sizeof(user));
	return user;
}

void printUserData(const UserData& user)
{
	std::cout << user.data << std::endl;
}

void printUsedData(std::ifstream& inFile)
{
	UserData user = readUserData(inFile);
	printUserData(user);

	while (user.next != 0)
	{
		goAtLine(inFile, user.next);
		user = readUserData(inFile);
		printUserData(user);
	}
}

void printUsedData(const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open())
	{
		return;
	}

	printUsedData(inFile);
	inFile.close();
}


int main()
{
	std::ofstream outFile("text.dat");

	UserData user = { 1, {"aaaaaa"} };
	UserData user1 = { 2, {"bbbbbb"} };
	UserData user2 = { 0, {"ccccccc"} };

	outFile.write((const char*)&user, sizeof(UserData));
	outFile.write((const char*)&user1, sizeof(UserData));
	outFile.write((const char*)&user2, sizeof(UserData));
	outFile.write((const char*)&user1, sizeof(UserData));
	outFile.write((const char*)&user1, sizeof(UserData));
	outFile.write((const char*)&user1, sizeof(UserData));
	outFile.close();

	printUsedData("text.dat");

	return 0;
}
