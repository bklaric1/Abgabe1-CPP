/*
 * kennzeichen.h
 *
 *  Created on: 26.03.2023
 *      Author: bklaric01
 */

#ifndef KENNZEICHEN_H_
#define KENNZEICHEN_H_

#pragma once
#include <string>
#include <iostream>

namespace kfz
{
      struct kennzeichen
      {
            std::string ort;
            std::string buchstaben;
            short zahl;
};
typedef struct kennzeichen kennzeichen;

std::string einlesenOrt()
{
	std::string ort;

	do{
		std::cout << "Bitte geben Sie Ortsabkürzung ein: ";
		std::cin >> ort;
	}while(!((ort.length() > 0) && (ort.length() < 4)));

	return ort;
}

std::string einlesenBuchstabe()
{
	std::string buchstabe;

	do{
		std::cout << "Bitte geben Sie gewünschten Buchstaben ein: ";
		std::cin >> buchstabe;
	}while(!((buchstabe.length() > 0) && (buchstabe.length() < 4)));

	return buchstabe;
}

short einlesenZahl()
{
	short zahl;

	do{
		std::cout << "Bitte geben eine Zahl ein: ";
		std::cin >> zahl;
	}while(!((zahl > 0) && (zahl < 10000)));

	return zahl;
}

kennzeichen* einlesen()
{
	kennzeichen* kZeiger = new kennzeichen;
	std::cout << "\nSie können ihre Wunschkennzeichen wählen.\n" << std::endl;
	kZeiger->ort = einlesenOrt();
	kZeiger->buchstaben = einlesenBuchstabe();
	kZeiger->zahl = einlesenZahl();

	return kZeiger;
}

bool istSchnapszahl(const kennzeichen* pKennzeichen)
{
    std::string zahl = std::to_string(pKennzeichen->zahl);
    char ersteZiffer = zahl[0];

    for (long unsigned int i = 1; i < zahl.length(); i++)
    {
        if (zahl[i] != ersteZiffer)
        {
            return false;
        }
    }
    return true;
}

bool istZehner(const kennzeichen* pKennzeichen)
{
	short zahl = pKennzeichen->zahl % 10;

	if((zahl == 0) && (pKennzeichen->zahl < 100))
	{
		return true;
	}

	return false;
}

bool istHunderter(const kennzeichen* pKennzeichen)
{

	short zahl = pKennzeichen->zahl % 10;

	if((zahl == 0) && (pKennzeichen->zahl < 1000) && (pKennzeichen->zahl > 99))
	{
		return true;
	}

	return false;
}

bool istTausender(const kennzeichen* pKennzeichen)
{

	short zahl = pKennzeichen->zahl % 10;

	if((zahl == 0) && (pKennzeichen->zahl < 10000) && (pKennzeichen->zahl > 999))
	{
		return true;
	}

	return false;
}

void schildTest(kennzeichen* schild)
{
	bool zehner = istZehner(schild);
	bool hunderter = istHunderter(schild);
	bool tausender = istTausender(schild);

	if(zehner)
	{
		std::cout << " Ein 10er Kennzeichen! Gute Wahl!" <<std::endl;
	}

	else if(hunderter)
	{
		std::cout << " Ein 100er Kennzeichen! Gute Wahl!" <<std::endl;
	}

	else if(tausender)
	{
		std::cout << " Ein 1000er Kennzeichen! Gute Wahl!" <<std::endl;
	}
}

std::string ausgabe(const kennzeichen* pKennzeichen)
{
	std::string zahl = std::to_string(pKennzeichen->zahl);
	std::string kennzeichenAusgabe = pKennzeichen->ort + "-" +pKennzeichen->buchstaben + "-" + zahl;

	return kennzeichenAusgabe;
}

}


#endif /* KENNZEICHEN_H_ */
