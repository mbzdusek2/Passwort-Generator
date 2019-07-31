/****************************************************************
 *  Besonderes.h
 *																
 *	Autor: Michael R Bzdusek II
 *  Datum: 28.12.2017 Copyright © 2017                                   
 *																
 *  Dieses Programm generiert zufällige Passwörter.				
 *
 *																
 *																
 ****************************************************************/

#ifndef Besonderes_h
#define Besonderes_h


#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib> 
#include <stdlib.h>
#include <stdio.h>
#include "Besonderes.h"

int hauptprogramm();
void Clearscreen();
char zufallsZahlenGenerieren();
void speichern(std::string passwrt);


#endif /* Besonderes_h */
