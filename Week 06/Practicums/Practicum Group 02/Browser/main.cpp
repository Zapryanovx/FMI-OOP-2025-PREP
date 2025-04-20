#include "Browser.h"

int main()
{
	WebPage page1;
	WebPage page2;
	WebPage page3("https://github.com/KristianIvanov24", "52.43.12.8");
	
	std::cin >> page1;
	std::cin >> page2;
	std::cout << std::endl;

	Browser browser;
	browser.addPage(page1);
	browser.addPage(page2);
	browser.addPage(page3);
	browser.print();

	browser -= 1;
	browser.print();

	return 0;

}