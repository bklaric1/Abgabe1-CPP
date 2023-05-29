/*
 * datebank.h
 *
 *  Created on: 26.03.2023
 *      Author: bklaric01
 */

#ifndef DATENBANK_H_
#define DATENBANK_H_

#pragma once
#define DB_LIMIT 10
#include "kennzeichen.h"
#include <string>

namespace db
{
	struct datenbank
	{
		std::string name;
		kfz::kennzeichen* schilder[DB_LIMIT];
		int eintraege = 0;
	};
typedef struct datenbank datenbank;

bool einfuegen(datenbank* db, kfz::kennzeichen* schild)
{
	for(int i = 0; i < DB_LIMIT; i++)
	{
		if(db->schilder[i] == NULL)
		{
			db->schilder[i] = new kfz::kennzeichen;
			db->schilder[i]->buchstaben = schild->buchstaben;
			db->schilder[i]->ort = schild->ort;
			db->schilder[i]->zahl = schild->zahl;
			db->eintraege++;

			return true;
		}
	}

	return false;
}

std::string ausgabe(const datenbank* db)
{
	std::string ausgabe;
	std::cout << "\nDatenbank: " + db->name + "\n-----------------------\n";

	for(int i = 0; i < DB_LIMIT; i++)
	{
		if(db->schilder[i] != NULL)
		{
			std::string platzhalter = kfz::ausgabe(db->schilder[i]);
			ausgabe += "\n" + platzhalter;
		}
	}
	std::cout << ausgabe << std::endl;

	return ausgabe;
}

}

#endif /* DATEBANK_H_ */
