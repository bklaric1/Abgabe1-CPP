//============================================================================
// Name        : main.cpp
// Author      : Benjamin Klaric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "kennzeichen.h"
#include "datenbank.h"

void schnapszahlTest()
{
	kfz::kennzeichen meineKennzeichen;
	meineKennzeichen.ort = "LL";
	meineKennzeichen.buchstaben = "VB";
	meineKennzeichen.zahl = 444;

	bool schnaps = kfz::istSchnapszahl(&meineKennzeichen);

	if(schnaps == true)
	{
		std::cout << kfz::ausgabe(&meineKennzeichen) << " hat eine Schnapszahl.\n" << std::endl;
	}

	else{
		std::cout << kfz::ausgabe(&meineKennzeichen) << " hat keine Schnapszahl.\n" << std::endl;
	}
}

void einlesenTest()
{
	kfz::kennzeichen* kennzeichenZeiger = kfz::einlesen();
	std::cout << kfz::ausgabe(kennzeichenZeiger);
	kfz::schildTest(kennzeichenZeiger);
	std::cout << "\n";
}

void datenbankTest()
{
	db::datenbank* meineDatenbank = new db::datenbank;
	meineDatenbank->name = "Stadt";
	db::einfuegen(meineDatenbank, kfz::einlesen());
	std::cout << "\n";
	db::einfuegen(meineDatenbank, kfz::einlesen());
	std::cout << "\n";
	db::ausgabe(meineDatenbank);
	std::cout << "\n";
}

int main()
{
	char c;

	schnapszahlTest();
	einlesenTest();
	datenbankTest();

	std::cin >> c;
	return 0;
}
