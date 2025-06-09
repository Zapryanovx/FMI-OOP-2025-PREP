#include <iostream>
#include "GrString.h"

int main() {
    using std::cout;
    using std::endl;

    // Test construction
    GrString s1("Hello");
    GrString s2("World");
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    // Test concatenation operator+
    GrString s3 = s1 + GrString(", ") + s2;
    cout << "Concatenated s3: " << s3 << endl;

    // Test operator+=
    s1 += GrString("!!!");
    cout << "After s1 += \"!!!\": " << s1 << endl;

    // Test removal operator/=
    GrString s4("abcdefg");
    GrString toRemove("bd");
    s4 /= toRemove;
    cout << "\"abcdefg\" /= \"bd\" => " << s4 << endl;

    // Test weight()
    cout << "Weight of s2 (\"World\"): " << s2.weight() << endl;

    // Test copy constructor
    GrString s5 = s2;
    cout << "Copied s5 from s2: " << s5 << endl;

    // Test copy assignment
    s5 = s3;
    cout << "Assigned s5 = s3: " << s5 << endl;

    // Test move constructor
    GrString s6 = std::move(s5);
    cout << "Move-constructed s6 from s5: " << s6 << endl;

    // Test move assignment
    s6 = std::move(s4);
    cout << "Move-assigned s6 from s4: " << s6 << endl;

    // Test input operator
    GrString userInput("");
    cout << "Enter a word: ";
    std::cin >> userInput;
    cout << "You entered: " << userInput << endl;

    // Test equality operator==
    GrString a("ABC"), b("CBA");
    cout << "\"ABC\" == \"CBA\"? " << (a == b ? "true" : "false") << endl;

    return 0;
}
