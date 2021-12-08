#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <istream>
#include <cstdio>

using namespace std;

int main()
{

    const int SIZE = 500;
    char input[SIZE];                      // Input for reading in lines of txt files
    string filename_grades = "grades.txt"; // noten filename
    string filename_bets = "bets.txt";     // wetten filename
    ifstream file_bets;                    // storage for file_noten
    ifstream file_grades;                  // storage for file_wetten

    string Testname;
    bool fileexist = false;

    // Einlesen "Name Test"
    cout << "Geben sie den Namen des Tests ein um den gewettet wird." << endl;
    cin >> Testname;
    cout << "Testname:" << Testname << endl;

    // if "Name Test"_bets.txt ist nicht da
    // bool exist = false;
    // Anzahl Wettpersonen (wegen Arraylänge) und Wettpersonen einlesen -->in Array speichern

    // Name des Wetters und Betrag einlesen

    // if exist is true
    //"Name Test"_bets.txt einlesen
    // Betrag beim Index des Namens ändern
    // Datei wieder rausschreiben

    // if exist is false
    // String erstellen und mit Wettpersonenarray sowie Nullern an den richtigen Stellen, füllen
    // Betrag beim Index des Namens ändern
    // Als Datei rausschreiben
}