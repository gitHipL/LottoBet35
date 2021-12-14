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
    double Betrag;
};
struct Wette
{
    string Wetter;
    vector<Wettdetails> Wettdetails1;
};

string LUT[] = {"Fellner Thomas", "Haumtratz Andre", "Hauser Nicolas",
                "Hinterbichler Noah", "Hipf Leon", "Hoellbacher Christoph",
                "Kilic Eray", "Kurzmann Samuel", "Laireiter Noah", "Maier Sebastian",
                "Negi Manish", "Oitner Jakob", "Otten Andreas", "Ploder Thomas",
                "Rezo Adrian", "Riedler Martin", "Schratzberger Alexander",
                "Smajlovic Suad", "Soellinger Marco", "Strohbichler Gabriel",
                "Urlesberger Simon", "Winkler Josef", "Yu Juergen"};
int LUTlen = 23;

string getTestname();
Wette getWette();
void Test(string Testname, bool fileexist, int Wettpersonen_len, string Wettpersonen[], Wette Wette);

int main()
{

    const int SIZE = 500;
    char input[SIZE];     // Input for reading in lines of txt files
    string filename_bets; // wetten filename
    fstream fout;

    string Testname;
    bool fileexist;
    int Wettpersonen_len;
    Wette Wette;

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
        cout << "Datei noch nicht erstellt. Eingabe zur Erstellung is benötigt." << endl;
        cout << "Geben sie an auf wie viele Leute gewettet wird" << endl;
        cin >> Wettpersonen_len;
    }
    string Wettpersonen[Wettpersonen_len];
    if (fileexist == false)
    {
        cout << "Geben sie nun die Wettpersonen ein (Nur Nachname):" << endl;
        for (size_t i = 0; i < Wettpersonen_len; i++)
        {
            int n = i;
            cout << "Wettperson " << n + 1 << ": ";
            cin >> Wettpersonen[i];
        }
    }

    // struct Wette einlesen
    Wette = getWette();

    if (fileexist == true)
    {
        // if exist is true
        //"Name Test"_bets.txt einlesen
        // Betrag beim Index des Namens ändern
        // Datei wieder rausschreiben
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
        cout << "Gib den Betrag ein den du auf die Person wetten willst" << endl;
        cin >> Betrag_storage;

        Wettdetails_storage.assign(1, {Wettperson_storage, Betrag_storage});
    }
    Wette.Wettdetails1 = Wettdetails_storage;
    return Wette;
}

void Test(string Testname, bool fileexist, int Wettpersonen_len, string Wettpersonen[], Wette Wette)
{

    cout << "Testfunction: Kontrolle aller Werte möglich:" << endl;
    cout << "Testname:" << Testname << endl; // TEST
    if (fileexist = true)
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
        cout << "Zugehöriger Betrag" << Wette.Wettdetails1[i].Betrag << endl;
    }
}