#include <iostream>
#include "Forms.h"
#include "TextBox.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "Option.h"
#include "Size.h"
#include "Location.h"

int main() {
    Size initialSize(10, 20);
    Location initialLocation(5, 5);
    Forms form("TestForm", initialSize);

    TextBox textbox(initialSize, initialLocation, "Initial text");
    form.addControl(textbox);

    CheckBox checkbox(initialSize, initialLocation, "Accept Terms", true);
    form.addControl(checkbox);

    Option options[] = { Option("Option1", true), Option("Option2", false) };
    RadioButton radiobutton(initialSize, initialLocation, options, 2);
    form.addControl(radiobutton);

    std::cout << "Changing form size to (5,5)" << std::endl;
    form.changeSize(Size(5, 5));

    std::cout << "Changing form location to (1,1)" << std::endl;
    form.changeLocation(Location(1, 1));

    for (size_t i = 0; i < 3; ++i) {
        std::cout << "Modify control " << i << ":" << std::endl;
        form.change(i);
    }

    return 0;
}
