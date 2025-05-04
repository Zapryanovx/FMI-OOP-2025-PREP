#include "StudentDB.h"
#include "SortedStudentDB.h"
#include "FilteredStudentDB.h"

bool pred1(const Student& st1, const Student& st2)
{

	return st1.getFn() > st2.getFn();

}

bool cr1(const Student& st)
{

	return st.getFn() > 50;

}

int main()
{

	Student st1("Yoan Baychev", 47, 1);
	Student st2("Ivailo Kunchev", 14, 1);
	Student st3("Kaloyan Markov", 67, 0);
	Student st4("Ilian Zapryanov", 53, 2);
	Student st5("Nikola Topalov", 98, 1);

	SortedStudentDB db;
	db.add(st1);
	db.add(st2);
	db.add(st3);
	db.add(st4);
	db.add(st5);
	db.display();
	std::cout << std::endl;

	db.remove(14);
	db.display();

	std::cout << "here" << std::endl;
	const Student& found = db.find(47);
	found.print();
	std::cout << "here" << std::endl;

	std::cout << std::endl;

	db.sortBy(pred1);
	db.display();
	std::cout << std::endl;

	FilteredStudentDB fdb1;
	fdb1.add(st1);
	fdb1.add(st2);
	fdb1.add(st3);
	fdb1.add(st4);
	fdb1.add(st5);
	fdb1.display();
	fdb1.filter(cr1);
	fdb1.display();
	std::cout << std::endl;

	fdb1.limit(2);
	fdb1.display();
	std::cout << std::endl;

	return 0;

}