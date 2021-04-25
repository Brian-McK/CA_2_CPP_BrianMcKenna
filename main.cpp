#include <iostream>
#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include <vector>
#include <list>
#include <fstream>      // file stream
#include <string>       // getline(), stoi(), stod()
#include <sstream>      // string stream

// TODO - FIX THE MENU
// TODO - FIX THE DISPLAY OUTPUT LIKE THE BRIEF
// TODO - SET THE PATH FOR EACH BUG

vector<Bug*> bugs;

void menu();
void menuOptions();
void parseLine(const string& str);
void DemoInputFileStream(const string& fileName);
void displayAllBugs(vector<Bug*> bugVector);
void findBug(int findId, vector<Bug*> bugVector);

using namespace std;

int main() {

//    menu();

    Hopper myHopper;
    myHopper.setId(1234); // Unique integer ID value (e.g. 101,102,... etc.)
    myHopper.setPosition(pair<int, int>(7,5)); // (X,Y) coordinate system where (0,0) is top left hand cell
    myHopper.setDirection(4); // Direction values : 1=North, 2=East, 3=South, 4=West (or use enum)
    myHopper.setSize(1); // Measure of bug size (1-20), bigger bugs eat smaller bugs and grow accordingly
    myHopper.setAlive(true); // Flag indicating life status of a bug. All bugs set to ‘true’ initially. When eaten, this flag is set to ‘false’.
    myHopper.setHopLength(4); //
    // myHopper.setPath() // history of what positions on the board the bug has been, dont need yet

    myHopper.print();

    myHopper.move();

    myHopper.print();

//    DemoInputFileStream("bugs.txt");
//
//    displayAllBugs(bugs);
//
//    findBug(103,bugs);

    return 0;
}

void menu()
{
    int selection;
    cout << "\nMenu";
    cout << "\n============";

    do {
        menuOptions();
        cout << "\n\nEnter selection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                cout << "1) - Initialize Bug Board (load data from file)\n";
                break;
            case 2:
                cout << "2) - Display all Bugs\n";
                break;
            case 3:
                cout << "Find a Bug (given an id)\n";
                break;
            case 4:
                cout << "Tap the Bug Board (causes move all, then fight/eat)\n";
                break;
            case 5:
                cout << "Display Life History of all Bugs (path taken)\n";
                break;
            case 6:
                cout << "Display all Cells listing their Bugs\n";
                break;
            case 7:
                cout << "Exit (write Life History of all Bugs to file)\n";
                return;
            default:
                cout << "Wrong input\n";
        }
    } while (selection != 7);
}

void DemoInputFileStream(const string& fileName) {

    string line;
    ifstream inStream(fileName); // open file as input file stream

    if ( inStream.good() )  // if file opened successfully, and not empty
    {
        while ( getline( inStream, line) )   // read a line until false returned , getLine() from <string> library
        {
            parseLine( line );
        }
        inStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.\n";
}

void parseLine(const string& str) {

    stringstream strStream( str ); //create string stream from the string
    string bugType;

    int id = 0;
    int xCoordinate = 0;
    int yCoordinate = 0;
    int direction = 0;
    int sizeOfBug = 0;
    bool alive = true;
    // pathway??? // TODO
    list<pair<int, int>> path;
    path.push_back(pair<int, int>(xCoordinate,yCoordinate));
    int hopLength = 0;

    try
    {
        string str;

        getline(strStream, str, ';');
        bugType = str;

        getline(strStream, str, ';');
        id = stoi(str);

        getline(strStream, str, ';');
        xCoordinate = stoi(str);

        getline(strStream, str, ';');
        yCoordinate = stoi(str);

        getline(strStream, str, ';');
        direction = stoi(str);

        getline(strStream, str, ';');
        sizeOfBug = stoi(str);

        if(bugType == "H")
        {
            getline(strStream, str, ';');
            hopLength = stoi(str);
            bugs.push_back(new Hopper(id,pair<int, int>(xCoordinate,yCoordinate),direction,sizeOfBug,alive,path,hopLength));
        } else {
            bugs.push_back(new Crawler(id, pair<int, int>(xCoordinate, yCoordinate), direction, sizeOfBug, alive, path));
        }
    }
    catch (std::invalid_argument const& e)
    {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const& e)
    {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
}

void displayAllBugs(vector<Bug*> bugVector)
{
    cout << "\nDisplay All Bugs" << endl;

    for (int i = 0; i < bugVector.size(); ++i) {
        bugVector[i]->print();
        cout << "," << endl;
    }
}

void findBug(int findId, vector<Bug*> bugVector)
{
    cout << "\nFind the bug with id: " << findId << endl;

    bool foundBug = false;

    for (auto &i: bugVector){
        if(i->getId() == findId){
            foundBug = true;
            i->print();
        }
    }

    if(!foundBug)
    {
        cout << "Bug: " << findId << " not found";
    }
}

void menuOptions()
{
    cout << "\n\n1) - Initialize Bug Board (load data from file)";
    cout << "\n2) - Display all Bugs";
    cout << "\n3) - Find a Bug (given an id)";
    cout << "\n4) - Tap the Bug Board (causes move all, then fight/eat)";
    cout << "\n5) - Display Life History of all Bugs (path taken)";
    cout << "\n6) - Display all Cells listing their Bugs";
    cout << "\n7) - Exit (write Life History of all Bugs to file)";
}

