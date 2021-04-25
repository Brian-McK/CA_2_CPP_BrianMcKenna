#include <iostream>
#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include <vector>
#include <list>
#include <fstream>      // file stream
#include <string>       // getline(), stoi(), stod()
#include <sstream>      // string stream

// TODO - SET THE PATH FOR EACH BUG

vector<Bug*> bugs;

void menu();
void menuOptions();
void parseLine(const string& str);
void DemoInputFileStream(const string& fileName);
void displayAllBugs(vector<Bug*> bugVector);
void findBug(int findId, vector<Bug*> bugVector);
void tapBoard(vector<Bug*> bugVector);

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

    do {
        menuOptions();
        cout << "\n\nEnter selection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                cout << "1) - Initialize Bug Board (load data from file)\n";
                DemoInputFileStream("bugs.txt");
                break;
            case 2:
                cout << "2) - Display all Bugs\n";
                displayAllBugs(bugs);
                break;
            case 3:
                int bugId;
                cout << "Find a Bug (given an id)\n";
                cout << "Enter bug id: " << endl;
                cin >> bugId;
                findBug(bugId, bugs);
                break;
            case 4:
                cout << "Tap the Bug Board (causes move all, then fight/eat)\n";
                tapBoard(bugs);
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

void tapBoard(vector<Bug*> bugVector)
{
    cout << "TAP THE BOARD" << endl;

    for (auto &i: bugVector){
        i->move();
    }
    displayAllBugs(bugVector);
}

