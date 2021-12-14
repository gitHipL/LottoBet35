/* Wettbuero.cpp
by Sebastian Maier and Leon Hipf
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <filesystem>
#include <sstream>

using namespace std;

string getTestname();
int getWettpersonen_anzahl();
int backup_accounts();

int main()
{
    /*
    // declare variables
    const int SIZE = 500;
    char list_noten[SIZE];                // array for the noten file
    char list_wetten[SIZE];               // array for the wetten file
    string filename_noten = "grades.txt"; // noten filename
    string filename_wetten = "bets.txt";  // wetten filename
    ifstream file_noten;                  // storage for file_noten
    ifstream file_wetten;                 // storage for file_wetten

    /////////////// read the noten file //////////////////
    file_noten.open(filename_noten.c_str()); // open input file
    if (file_noten.is_open())                // if the input file is open
    {
        while (!file_noten.eof()) // eof = end of file
        {
            file_noten >> list_noten;               // write the file in the array
            string namen = strtok(list_noten, ":"); // split at : -> print names
            string noten = strtok(NULL, "\n");      // split at \n -> print noten
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
            file_wetten >> list_wetten;              // write the file in the array
            string namen = strtok(list_wetten, ":"); // split at : -> print names
            string wetten = strtok(NULL, ",");       // split at , -> print noten
            string einsatz = strtok(NULL, "\n");     // split at \n -> print einsatz
            cout << "Einsatz: " << einsatz << endl;
        }
    }
    else // Error message
        cerr
            << "Can't find wetten file " << filename_wetten << endl;
    file_wetten.close(); // Close input file


*/
    // Abfrage User: Name des Tests, Anzahl Wettpersonen, Namen der Wettpersonen, Note der Wettperson (Eingabe muss abgesichert werden, DAU sicher)

    getTestname();
    int wettpersonen_anzahl = getWettpersonen_anzahl();
    int noten_wettpersonen[wettpersonen_anzahl];
    string wettpersonen[wettpersonen_anzahl];
    for (int i = 0; i < wettpersonen_anzahl; i++)
    {
        cout << "Wettperson " << i << " :" << endl;
        cin >> wettpersonen[i];
        cout << "Note von " << wettpersonen[i] << " :" << endl;
        cin >> noten_wettpersonen[i];
    }

    // Backup accounts.txt before doing anything
    backup_accounts();

    //***********************************Hipf Plan*******************************

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
/////////////////////////////Abfrage User: Name des Tests, Anzahl Wettpersonen, Namen der Wettpersonen, Note der Wettperson (Eingabe muss abgesichert werden, DAU sicher)//////////////////////////////
string getTestname()
{
    string testname;
    cout << "Name des Tests eingeben: " << endl;
    cin >> testname;
    return testname;
}

int getWettpersonen_anzahl()
{
    int wettpersonen_anzahl = 0;

    cout << "Anzahl der Wettpersonen: " << endl;
    cin >> wettpersonen_anzahl;
    return wettpersonen_anzahl;
}

////////////////////////////////////////////back up accounts before doing anything/////////////////////////////////////////////////////////////
int backup_accounts()
{
    string line;
    ifstream in_file{"accounts.txt"};
    string date;
    stringstream ss;
    ofstream out_file;
    //getting date for backup
    cout
        << "insert date like this 14-12-2021: " << endl;
    cin >> date;
    //creating the filename
    ss << "backups/backup_accounts_" << date << ".txt";
    out_file.open(ss.str().c_str());
    //Copying the file
    cout << "Copying accounts \n";
    if (in_file && out_file)
    {
        while (getline(in_file, line))
        {
            out_file << line << "\n";
        }
        cout << "Copy Finished \n";
    }
    else
    {
        //Something went wrong
        printf("Can't read File \n");
    }
    //Closing file
    in_file.close();
    out_file.close();

    return 0;
}