//#include <iostream>
//#include <fstream>
//
//const char NEW_LINE_CHAR = '\n';
//
//int getCharCount(std::ifstream& ifs, char ch)
//{
//	int count = 0;
//	while (!ifs.eof())
//	{
//		char curr = ifs.get();
//
//		if (curr == ch)
//		{
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int getLinesCount(const char* fileName)
//{
//	if (!fileName)
//	{
//		return -1;
//	}
//
//	std::ifstream ifs(fileName);
//	if (!ifs.is_open())
//	{
//		return -1;
//	}
//
//	return getCharCount(ifs, NEW_LINE_CHAR) + 1;
//}
//
//int main()
//{
//	std::ofstream ofs("file.txt");
//	ofs << "asdasdasdd" << std::endl;
//	ofs << std::endl;
//	ofs << std::endl;
//	ofs << "a" << std::endl;
//	ofs.close();
//
//	std::ifstream ifs("file.txt");
//	std::cout << getCharCount(ifs, 'd') << std::endl;
//	ifs.close();
//
//	std::cout << getLinesCount("file.txt") << std::endl;
//
//	return 0;
//}