#include <iostream>

namespace CONSTANTS
{
	constexpr int QUESTIONS_IN_TEST_SIZE = 5;
	constexpr int TITLE_MAX_SIZE = 50;
	constexpr int QUESTION_SIZE = 50;
	constexpr int OPTIONS_SIZE = 4;
}

enum class Options
{
	A,
	B,
	C,
	D,
	None,
};

struct Question
{
	char title[CONSTANTS::TITLE_MAX_SIZE + 1]{};
	char options[CONSTANTS::OPTIONS_SIZE][CONSTANTS::QUESTION_SIZE + 1]{};
	Options answer = Options::None;
	int points = 0;
};

struct Test
{
	Question questions[CONSTANTS::QUESTIONS_IN_TEST_SIZE]{};
};

int main()
{

	Question q1 = { "1 ^ 0 = ?", "1", "2", "3", "4", Options::A, 10 };
	Question q2 = { "1 ^ 0 = ?", "2", "1", "3", "4", Options::B, 10 };
	Question q3 = { "1 ^ 0 = ?", "2", "3", "1", "4", Options::C, 10 };
	Question q4 = { "1 ^ 0 = ?", "2", "3", "4", "1", Options::D, 10 };
	Question q5 = { "1 ^ 0 = ?", "1", "2", "3", "4", Options::A, 10 };

	Test test;
	test.questions[0] = q1;
	test.questions[1] = q2;
	test.questions[2] = q3;
	test.questions[3] = q4;
	test.questions[4] = q5;

	int points = 0;
	for (int i = 0; i < CONSTANTS::QUESTIONS_IN_TEST_SIZE; i++)
	{
		std::cout << test.questions[i].title << "( " << test.questions[i].points << " )" << std::endl;

		std::cout << "A) " << test.questions[i].options[0] << std::endl;
		std::cout << "B) " << test.questions[i].options[1] << std::endl;
		std::cout << "C) " << test.questions[i].options[2] << std::endl;
		std::cout << "D) " << test.questions[i].options[3] << std::endl;

		char choice = ' ';
		std::cin >> choice;

		if (choice == (int) test.questions[i].answer + 'A')
		{
			points += test.questions[i].points;
		}
	}

	std::cout << std::endl;
	std::cout << "Total points: " << points << std::endl;

	return 0;

}