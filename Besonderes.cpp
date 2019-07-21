/****************************************************************
 *                      Besonderes.cpp
 *																
 *	Autor: Michael R Bzdusek II                           
 *  Datum: 28.12.2017 2017(c)                                   
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
#include "umlaut.h"
#include "Besonderes.h"
#include <fstream>


using namespace std;

//Die Sammlung von Buchstaben und Zalhen, die verwendet wurden um die Passwörter zu generieren.
static const char bad[] =
"0123456789"
"!@#$%&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

enum speichernFrage: char
{
    ja = 'j',
    Ja = 'J',
};


int badGrosse = sizeof(bad) - 1;
int passwrtLaenge = 0;
int passwrtZahl = 0;
char temp = ' ';

// Menü
string menTitel ("\t  Passwort Generator\n");
string menSacheEins ("\t\tRegeln\n\n");
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


// Ausgaben: Fehleraufgetreten
string eingabeFehler ("Tut mir schrecklich leid aber die Eingabe stimmt nicht.\n");
string programmSchl ("Das Programm wird geschlossen\n");
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


// Linux/Mac oder Windows Ausgaben: Wiederholen
string linuxMacOS ("\nMöchten Sie wiederholen?\n");

string winOS ("\nM"); // Windows 1 + 2 + 3
char winOSTwo = Umlaut::oe;
string winOSThree ("chten Sie wiederholen?\n");
string windows = winOS + winOSTwo + winOSThree;



void Clearscreen()
{
	cout << string(100, '\n');
}// Ende der Clearscreenfunktion


//Diese Funktion generiert die zufällige Passwörter.
char zufallsZahlenGenerieren()
{
    return bad[rand() % badGrosse];
    
}// Ende des ZufallZahlenGenerieren


void speichern(string passwrt)
{
	ofstream sammlung;
    if (!sammlung)
    {
        cout << speichernFehler;
        wiederholen();
    }
    
	sammlung.open("Passwoerter.txt", ios::app);
	sammlung << passwrt << endl;
	sammlung.close();
    //cout << erfolgWin;

}// Ende der speichernfunktion

void wiederholen()
{
    char ende;
	cout << linuxMacOS;
    //cout << windows;
	cin  >> ende;
	switch (ende)
	{
        case 'N':
		case 'n': exit(0);
			break;
		case 'y':
		case 'Y': Clearscreen();
				  hauptprogramm();
			break;
		
		default: 
			cin.clear();
			cin.ignore();
			cout << eingabeFehler;
				 wiederholen();
	}// Ende der switchAussage

}// Ende der wiederholenfunktion


int hauptprogramm()
{
	Clearscreen();
    while (true)
    {
        
        srand((unsigned)time(0));
        string passwrt;
        
        cout << setfill('*') << setw(40) << "*" <<endl;
        cout << menTitel
             << menSacheEins
             << menSacheZwei
             << menSacheDrei;

        cout << allOS;
        cin  >> passwrtLaenge;

	// die eingabe prüfen.
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << eingabeFehler 
			 << programmSchl;
		hauptprogramm();
        
	}// Ende der ifAussgabe

	// zwei cout-aussagen wurden gemacht: windows und mac/linux systeme
	cout << linuxMacOSFrage;
	//cout << winFrage;
    cin  >> passwrtZahl;

	// die eingabe prüfen
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << eingabeFehler 
			 << programmSchl;
		hauptprogramm();

	}// Ende des ifAussgabe
        
    cout << dateiFrage;
    cin >> temp;
    
    // die eingabe prüfen
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << eingabeFehler
             << programmSchl;
        hauptprogramm();
        
    }// Ende des ifAussgabe
        
    cout.flush();
        
        
        //Ausgabe
        for (int zaehler = 0; zaehler < passwrtZahl; zaehler++)
        {
            for (int zaehler1 = 0; zaehler1 < passwrtLaenge; zaehler1++)
            {
                passwrt += zufallsZahlenGenerieren();
			}// Ende des ifAussgabe
			
            
            // Hier sollte doch ein Bool eingerichtet und geprüft: Speichen Ja oder nein
			if (temp == ja)
            {
                speichern(passwrt);
            }
            
            
			cout << passwrt << endl;
            passwrt = ""; //passwrt wurde gelöscht.
            
        }// Ende des Aussgabe
        
        
        cout << setfill('*') << setw(40) << "*" <<endl;
        cout << erfolg;
        wiederholen();
   
	}// Ende des whileAussage

}// Ende des Hauptprogramm
