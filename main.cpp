/* Wettbuero.cpp
by Sebastian Maier and Leon Hipf
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    // declare variables
    const int SIZE = 500;
    char list_noten[SIZE];                 // array for the noten file
    char list_wetten[SIZE];                // array for the wetten file
    string filename_noten = "Noten.txt";   // noten filename
    string filename_wetten = "Wetten.txt"; // wetten filename
    ifstream file_noten;                   // storage for file_noten
    ifstream file_wetten;                  // storage for file_wetten

    /////////////// read the noten file //////////////////
    file_noten.open(filename_noten.c_str()); // open input file
    if (file_noten.is_open())                // if the input file is open
    {
        while (!file_noten.eof()) // eof = end of file
        {
            file_noten >> list_noten;              // write the file in the array
            char *namen = strtok(list_noten, ":"); // split at : -> print names
            char *noten = strtok(NULL, "\n");      // split at \n -> print noten
            cout << "Noten: " << noten << endl;
        }
    }
    else // Error message
        cerr
            << "Can't find noten file " << filename_noten << endl;
    file_noten.close(); // Close input file

    /////////////// read the wetten file //////////////////
    file_wetten.open(filename_wetten.c_str()); // open input file
    if (file_wetten.is_open())                 // if the input file is open
    {
        while (!file_wetten.eof()) // eof = end of file
        {
            file_wetten >> list_wetten;             // write the file in the array
            char *namen = strtok(list_wetten, ":"); // split at : -> print names
            char *wetten = strtok(NULL, ",");       // split at , -> print noten
            char *einsatz = strtok(NULL, "\n");     // split at \n -> print einsatz
            cout << "Einsatz: " << einsatz << endl;
        }
    }
    else // Error message
        cerr
            << "Can't find wetten file " << filename_wetten << endl;
    file_wetten.close(); // Close input file

    //***********************************Hipf Plan*******************************

    // Abfrage User: Name des Tests, Anzahl Wettpersonen, Namen der Wettpersonen, Note der Wettperson (Eingabe muss abgesichert werden, DAU sicher)

    // Backup accounts.txt before doing anything

    // open bets.txt
    // for x Wettpersonen
    // Methode die bets.txt ausließt, return string Wettperson, schreibt auf Array die Beträge (quasi zweiter return)

    // Auswertung der Daten:
    // Methode die Gesamtbetrag auf jede Note berechnet
    // Methode die Anzahl der Wetten auf jede Note berechnet -->Nur für Zusammenfassung
    // Gesamtwetteinsatz auf eine Wettperson -->Nur für Zusammenfassung

    // Berechnung des Arrays[23] mit Gewinn und Verlust

    // Methode die Kontostand aktualisiert, Input array[23] mit Gewinn und Verlust, no return:
    // open accounts.txt
    // Inhalt einlesen
    // Nach \n aufsplitten, wenn im Array wo != 0 dann Zeile aktualisieren (Alter Wert + Gewinn/Verlust)

    // Methode die Zusammenfassung erzeugt
}