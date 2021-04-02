#include <iostream>
#include "Bug.h"

void menu();

using namespace std;

int main() {
    menu();
    return 0;
}

void menu()
{
    int selection;

    cout << "\nMenu";
    cout << "\n============";
    cout << "\n\n1) - Initialize Bug Board (load data from file)";
    cout << "\n2) - Display all Bugs";
    cout << "\n3) - Find a Bug (given an id)";
    cout << "\n4) - Tap the Bug Board (causes move all, then fight/eat)";
    cout << "\n5) - Display Life History of all Bugs (path taken)";
    cout << "\n6) - Display all Cells listing their Bugs";
    cout << "\n7) - Exit (write Life History of all Bugs to file)";
    cout << "\n\nEnter selection: ";

    cin >> selection;

    cout << "Option " << selection << " selected";

}