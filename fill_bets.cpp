#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <istream>
#include <cstdio>
#include <stdio.h>
#include <vector>

using namespace std;

int testvalue; // Only for the test function

struct Wettdetails
{
    string Wettperson;
    int Note;
    double Betrag;
};
struct Wette
{
    string Wetter;
    vector<Wettdetails> Wettdetails1;
};

string LUT[] = {"Fellner", "Haumtratz", "Hauser",
                "Hinterbichler", "Hipf", "Hoellbacher",
                "Kilic", "Kurzmann", "Laireiter", "Maier",
                "Negi", "Oitner", "Otten", "Ploder",
                "Rezo", "Riedler", "Schratzberger",
                "Smajlovic", "Soellinger", "Strohbichler",
                "Urlesberger", "Winkler", "Yu"};
int LUTlen = 23;

string getTestname();
Wette getWette();
void changeFileValue(string filename);
void Test(string Testname, bool fileexist, int Wettpersonen_len, string Wettpersonen[], Wette Wette);

int main()
{

    string filename_bets; // wetten filename
    ifstream fin;
    ofstream fout;

    string Testname;
    bool fileexist;
    int Wettpersonen_len;
    Wette Wette;
    bool Name_correct = false;
    int help1 = 0;

    // Einlesen "Name Test"
    Testname = getTestname();

    // if "Name Test"_bets.txt ist nicht da
    fout.open(filename_bets);
    if (fout)
        fileexist = true;
    else
    {
        fileexist = false;
        // if exist is false
        // Anzahl Wettpersonen (wegen Arraylänge) und Wettpersonen einlesen -->in Array speichern
        cout << "Datei noch nicht erstellt." << endl
             << "Falls der eingegebene Testname falsch geschrieben wurde muss das Programm neu gestartet werden.Andernfalls ist eine Eingabe zur Erstellung benötigt." << endl
             << endl;
        cout << "Geben sie an auf wie viele Leute gewettet wird" << endl;
        cin >> Wettpersonen_len;

        // Error Handling
        if ((Wettpersonen_len < 0) | Wettpersonen_len > 10)
        {
            cout << "FEHLER: ZAHL NICHT IM GEWUENSCHTEM BEREICH" << endl;
            return 0;
        }
    }
    string Wettpersonen[Wettpersonen_len];
    if (fileexist == false)
    {
        while (Name_correct == false) // While for error handling
        {
            // Error Handling
            if (help1 > 0)
            {
                cout << "FEHLER BEI DER EINGABE DER WETTPERSONEN" << endl;
                cout << "Vorgang Bitte Wiederholen:" << endl;
            }
            help1++;

            cout << "Geben sie nun die Wettpersonen ein (Nur Nachname):" << endl;
            for (size_t i = 0; i < Wettpersonen_len; i++)
            {
                int n = i;
                cout << "Wettperson " << n + 1 << ": ";
                cin >> Wettpersonen[i];
            }

            // Error Handling
            for (size_t i = 0; i < Wettpersonen_len; i++)
            {
                Name_correct = false;
                for (size_t j = 0; j < LUTlen; j++)
                {
                    if (Wettpersonen[i] == LUT[j])
                    {
                        Name_correct = true;
                        break;
                    }
                }
                if (Name_correct == false)
                {
                    break;
                }
            }
        }
    }

    // struct Wette einlesen
    Wette = getWette();

    if (fileexist == true)
    {
        // if exist is true
        changeFileValue(filename_bets);
    }
    else
    {
        // String erstellen und mit Wettpersonenarray sowie Nullern an den richtigen Stellen, füllen
        // Betrag beim Index des Namens ändern
        // Als Datei rausschreiben
    }

    Test(Testname, fileexist, Wettpersonen_len, Wettpersonen, Wette);
}

// Functions

string getTestname()
{
    string Testname;
    cout << "Geben sie den Namen des Tests ein um den gewettet wird." << endl;
    cin >> Testname;
    return Testname + "_bets.txt";
}

Wette getWette()
{
    Wette Wette;
    int n;
    vector<Wettdetails> Wettdetails_storage;
    string Wettperson_storage;
    int Note_storage;
    double Betrag_storage;

    cout << "Wer bist du?" << endl;
    cin >> Wette.Wetter;
    cout << "Auf wie viele willst du setzen?" << endl;
    cin >> n;
    testvalue = n;

    for (size_t i = 0; i < n; i++)
    {
        cout << "Gib die Person ein auf die du wetten willst" << endl;
        cin >> Wettperson_storage;
        cout << "Auf welche Note willst du setzen?" << endl;
        cin >> Note_storage;
        cout << "Gib den Betrag ein den du auf die Person wetten willst" << endl;
        cin >> Betrag_storage;

        Wettdetails_storage.push_back({Wettperson_storage, Note_storage, Betrag_storage});
    }
    Wette.Wettdetails1 = Wettdetails_storage;
    return Wette;
}

void changeFileValue(string filename)
{
    ofstream fout;
    //"Name Test"_bets.txt einlesen
    // Betrag beim Index des Namens ändern
    // Datei wieder rausschreiben
}

void Test(string Testname, bool fileexist, int Wettpersonen_len, string Wettpersonen[], Wette Wette)
{

    cout << "Testfunction: Kontrolle aller Werte möglich:" << endl;
    cout << "Testname:" << Testname << endl; // TEST
    if (fileexist == true)
        cout << "File ist da" << endl; // TEST
    else
        cout << "Datei Nicht da" << endl; // TEST

    cout << "Wettpersonen Array:" << endl; // TEST ANFANG
    for (size_t i = 0; i < Wettpersonen_len; i++)
    {
        cout << Wettpersonen[i];
        cout << endl;
    } // TEST ENDE

    cout << "Wetter:" << Wette.Wetter << endl;
    cout << "Wettpersonen und jeweilige Beträge:" << endl;
    for (size_t i = 0; i < testvalue; i++)
    {
        cout << "Wettperson: " << Wette.Wettdetails1[i].Wettperson << endl;
        cout << "Auf die Note: " << Wette.Wettdetails1[i].Note << "Zugehöriger Betrag: " << Wette.Wettdetails1[i].Betrag << endl;
    }
}