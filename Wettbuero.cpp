/* Wettbuero.cpp
by Sebastian Maier and Leon Hipf
*/
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    const int SIZE = 500;
    char list[SIZE]; //array for the input file
    string filename = "Noten.txt";
    ifstream file;

    file.open(filename.c_str()); //open input file
    if (file.is_open())          //if the input file is open
    {
        while (!file.eof()) //eof = end of file
        {
            file >> list;                     //write the file in the array
            char *namen = strtok(list, ":");  //split at : -> print names
            char *noten = strtok(NULL, "\n"); //split at \n -> print noten
            cout << noten << endl;
        }
    }
    else //Error message
        cerr
            << "Can't find input file " << filename << endl;
    file.close(); // Close input file
}