#include "Book.h"

int Book::id = 1;

void Book::setTitle(const char* title)
{
	if (!title)
	{
		return;
	}

	this->title = new char[std::strlen(title) + 1] {};
	strcpy(this->title, title);
}

void Book::setAuthor(const char* author)
{
	if (!author)
	{
		return;
	}

	this->author = new char[std::strlen(author) + 1] {};
	strcpy(this->author, author);
}

void Book::setPublished(unsigned published)
{
	this->published = published;
}

void Book::setPrice(double price)
{
	this->price = price;
}

void Book::copyFrom(const Book& other)
{

	this->title = new char[std::strlen(other.title) + 1] {};
	strcpy(this->title, other.title);

	this->author = new char[std::strlen(other.author) + 1] {};
	strcpy(this->author, other.author);

	this->published = other.published;
	this->price = other.price;
	this->currId = other.currId;
}

void Book::free()
{
	delete[] title;
	title = nullptr;

	delete[] author;
	author = nullptr;

	published = price = 0;
}

Book::Book(): Book("default", "default", 2025, 19.99){}

Book::Book(const char* title, const char* author, unsigned published, double price)
{
	setTitle(title);
	setAuthor(author);
	setPublished(published);
	setPrice(price);

	currId = id;
	id++;
}

Book::Book(const Book& other)
{
	copyFrom(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Book::~Book()
{
	free();
}

void Book::saveToBinary(std::ofstream& ofs)
{
	size_t titleSize = std::strlen(title);
	ofs.write((const char*)&titleSize, sizeof(size_t));
	ofs.write((const char*)title, sizeof(char) * titleSize);

	size_t authorSize = std::strlen(author);
	ofs.write((const char*)&authorSize, sizeof(size_t));
	ofs.write((const char*)author, sizeof(char) * authorSize);

	ofs.write((const char*)&published, sizeof(unsigned));
	ofs.write((const char*)&price, sizeof(double));
	ofs.write((const char*)&currId, sizeof(int));
}

void Book::readFromBinary(std::ifstream& ifs)
{
	free();

	size_t titleSize = 0;
	ifs.read((char*)&titleSize, sizeof(size_t));
	title = new char[titleSize + 1] {};
	ifs.read((char*)title, sizeof(char) * titleSize);

	size_t authorSize = 0;
	ifs.read((char*)&authorSize, sizeof(size_t));
	author = new char[authorSize + 1] {};
	ifs.read((char*)author, sizeof(char) * authorSize);

	ifs.read((char*)&published, sizeof(unsigned));
	ifs.read((char*)&price, sizeof(double));
	ifs.read((char*)&currId, sizeof(int));
}

void Book::print() const
{
	std::cout << title << " " 
			  << author << " " 
			  << published << " "
			  << price << " " 
			  << currId << std::endl;
}

double Book::getPrice() const
{
	return price;
}

int Book::getId() const
{
	return currId;
}