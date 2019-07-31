/****************************************************************
 *  Besonderes.cpp
 *																
 *	Autor: Michael R Bzdusek II                           
 *  Datum: 28.12.2017 Copyright © 2017
 *																
 *  Dieses Programm generiert zufällige Passwörter.
 *
 *																
 *																
 ****************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <limits>
#include "umlaut.h"
#include "Besonderes.h"



using namespace std;

//Die Sammlung von Buchstaben und Zalhen, die verwendet wurden um die Passwörter zu generieren.
static const char bad[] =
"0123456789"
"!@#$%&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

enum speichernFrage: char { ja = 'j', Ja = 'J', };

int badGrosse = sizeof(bad) - 1;
int passwrtLaenge = 0;
int passwrtZahl = 0;
char temp = ' ';

// Menü
string menTitel ("Passwort Generator\n");
string menSacheEins ("Regeln\n\n");
string menSacheZwei ("I)   Nur Nummern sind erlaubt.\n");
string menSacheDrei ("II)  strg + c beendet das Programm\n\n");


string allOS ("Wie lang soll das Passwort sein?\n");

string linuxMacOSFrage ("Wie viele Passwörter möchten Sie generieren\n");
string winOSFrageEins ("Wie viele Passw"); // Windows: 1,2,3,2,4
char winOSFrageZwei = Umlaut::oe;
string winOSFrageDrei ("rter m");
string winOSFrageVier ("chten Sie generieren\n");
string winFrage = winOSFrageEins + winOSFrageZwei + winOSFrageDrei + winOSFrageZwei + winOSFrageVier;


string dateiFrage ("Möchten Sie die Ergebnisse speicheern? Ja/nein\n");
string dateiWinNull ("M"); // Windows 0 + 1 + 2
char dateiWinEins = Umlaut::oe;
string dateiWinZwei ("chten Sie die Ergebnisse speicheern? Ja/nein\n");
string dateiWin = dateiWinNull + dateiWinEins + dateiWinZwei;


// Nachrichten
string eingabeFehler ("Die Eingabe stimmt nicht. Versuchen Sie es noch einmal\n");
string speichernFehler ("Etwas ist schiefgelaufen! Der Datei kann nicht geöffnet werden\n");

string speichWinFehler ("Etwas ist schiefgelaufen! Der Datei kann nicht ge"); // Windows 0 + 1 + 2
char speichWinFehlerEins = Umlaut::oe;
string speichWinFehlerZwei ("ffnet werden\n");
string speichWin = speichWinFehler + speichWinFehlerEins + speichWinFehlerZwei;


// Infos
string erfolg ("Passwörter.txt wurde erfolgreich gespeichert!\n");

string erfolgWinNull ("Passw"); // Windows 0 + 1 + 2
char erfolgWinEins = Umlaut::oe;
string erfolgWinZwei ("rter.txt wurde erfolgreich gespeichert!\n");
string erfolgWin = erfolgWinNull + erfolgWinEins + erfolgWinZwei;



void Clearscreen()
{
	cout << string(100, '\n');
}

char zufallsZahlenGenerieren()
{
    return bad[rand() % badGrosse];
}

void speichern(string passwrt)
{
	ofstream sammlung;
    if (!sammlung) { cerr << speichernFehler; hauptprogramm(); }
    
	sammlung.open("Passwoerter.txt", ios::app);
	sammlung << passwrt << endl;
	sammlung.close();
}

int hauptprogramm()
{
    while (true)
    {
        
        srand((unsigned)time(0));
        string passwrt;
        
        int lenNull = int (menTitel.length());
        int lenEins = int (menSacheEins.length());
        
        cout << setfill('*') << setw(40) << "*" <<endl;
        if (lenNull % 2 == 0) { menTitel += " "; }
        if (lenEins % 2 == 0) { menSacheEins += " "; }
        cout << setfill (' ') << setw((40/2) + lenNull/2) << menTitel
             << setfill (' ') << setw((40/2) + lenEins/2) << menSacheEins
             << menSacheZwei
             << menSacheDrei;

        cout << allOS;
        cin  >> passwrtLaenge;

	// die eingabe prüfen.
        if (cin.fail())
        { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cerr << eingabeFehler; hauptprogramm(); }

	// zwei cout-aussagen wurden gemacht: windows und mac/linux systeme
        cout << linuxMacOSFrage;
	//cout << winFrage;
        cin  >> passwrtZahl;

	// die eingabe prüfen
        if (cin.fail())
        { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cerr << eingabeFehler; hauptprogramm(); }
        
        cout << dateiFrage;
        cin >> temp;
    
    // die eingabe prüfen
        if (cin.fail())
        { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cerr << eingabeFehler; hauptprogramm(); }
        
        cout.flush();
        
        
        //Ausgabe
        for (int zaehler = 0; zaehler < passwrtZahl; zaehler++)
        {
            for (int zaehler1 = 0; zaehler1 < passwrtLaenge; zaehler1++)
            {
                passwrt += zufallsZahlenGenerieren();
			}// Ende des ifAussgabe
			
			if (temp == ja) { speichern(passwrt); }
            
			cout << passwrt << endl;
            passwrt = ""; //passwrt wurde gelöscht.
            
        }// Ende des Aussgabe
        
        
        cout << setfill('*') << setw(40) << "*" <<endl;
        cout << erfolg;
        hauptprogramm();
   
	}// Ende des whileAussage

}
