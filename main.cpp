#include <iostream>
#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include <vector>


void menu();

using namespace std;

int main() {
    Bug* myHopper;
    myHopper = new Hopper();
    myHopper->setId(1234); // Unique integer ID value (e.g. 101,102,... etc.)
    myHopper->setPosition(pair<int, int>(20,10)); // (X,Y) coordinate system where (0,0) is top left hand cell
    myHopper->setDirection(2); // Direction values : 1=North, 2=East, 3=South, 4=West (or use enum)
    myHopper->setSize(1); // Measure of bug size (1-20), bigger bugs eat smaller bugs and grow accordingly
    myHopper->setAlive(true); // Flag indicating life status of a bug. All bugs set to ‘true’ initially. When eaten, this flag is set to ‘false’.
    myHopper->setHopLength(10); //
    // myHopper.setPath() // history of what positions on the board the bug has been, dont need yet

    cout << "myHopper ID: " << myHopper->getId() << endl;
    cout << "myHopper hopLength: " << myHopper->getHopLength() << endl;


    cout << "Coordinates for: myHopper(x,y): (" << myHopper->getPosition().first << "," << myHopper->getPosition().second << ")\n";

    // try to move the hopper e.g myHopper.move(direction,)

    myHopper->move();

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
