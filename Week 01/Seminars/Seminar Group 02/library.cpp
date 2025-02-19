#include <iostream>
#pragma warning(disable: 4996)

namespace CONSTANTS
{
	constexpr int TITLE_SIZE = 128;
	constexpr int AUTHOR = 32;
	constexpr int LIBRARY_NAME_SIZE = 128;
	constexpr int LIBRARY_CAPACITY = 10;
}

enum class Status
{
	Available,
	Borrowed,
	Reserved,
	None,
};

struct Book
{
	char bookName[CONSTANTS::TITLE_SIZE]{};
	char author[CONSTANTS::AUTHOR]{};
	int publicationYear = 1;
	Status status = Status::None;
};

Book createBook(const char* bookName, const char* author, int publicationYear)
{
	Book book;

	strncpy(book.bookName, bookName, strlen(bookName));
	book.bookName[strlen(bookName)] = '\0';

	strncpy(book.author, author, strlen(author));
	book.author[strlen(author)] = '\0';

	book.publicationYear = publicationYear;
	book.status = Status::Available;

	return book;
}

struct Library
{
	char libraryName[CONSTANTS::LIBRARY_NAME_SIZE]{};
	Book books[CONSTANTS::LIBRARY_CAPACITY]{};
	int booksCount = 0;

	void borrowBook(Book& book)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (strcmp(books[i].bookName, book.bookName) == 0)
			{
				books[i].status = Status::Borrowed;
			}
		}
	}

	void reserveBook(Book& book)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (strcmp(books[i].bookName, book.bookName) == 0)
			{
				books[i].status = Status::Reserved;
			}
		}
	}

};

void addBook(Library& library, const char* bookName, const char* author, int publicationYear)
{
	Book book = createBook(bookName, author, publicationYear);

	if (library.booksCount >= CONSTANTS::LIBRARY_CAPACITY)
	{
		std::cout << "library is full" << std::endl;
	}

	library.books[library.booksCount++] = book;
}

void printBook(const Book& book)
{
	std::cout << book.bookName << " " << book.author << " " << book.publicationYear << " ";

	switch (book.status)
	{
	case Status::Available:
		std::cout << "available" << std::endl;
		break;
	case Status::Borrowed:
		std::cout << "borrowed" << std::endl;
		break;
	case Status::Reserved:
		std::cout << "reserved" << std::endl;
		break;
	case Status::None:
		std::cout << "none" << std::endl;
		break;
	}
}

void printLibrary(const Library& library)
{
	for (int i = 0; i < library.booksCount; i++)
	{
		printBook(library.books[i]);
	}
}

int main()
{
	const char* bookName = "book";
	const char* author = "author";
	int publicationYear = 1234;

	Library library;
	
	addBook(library, bookName, author, publicationYear);
	
	Book book = createBook(bookName, author, publicationYear);
	library.borrowBook(book);

	printLibrary(library);

	return 0;
}