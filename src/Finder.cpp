#include "Finder.hpp"
#include <iostream>
#include <string>
#include <fstream>

Finder::Finder(string const &woerterbuch)
{
    fstream datei;
    datei.open(woerterbuch, ios::in);
    if(!datei)
        throw "Die Datei existiert nicht.";
    this->woerterbuch = woerterbuch;
}

Finder &Finder::operator=(string const &suchbegriff)
{
    this->suchbegriff = suchbegriff;
    return *this;
}

string Finder::nachPasswortSuchen()
{
    this->position = 0;
    string s;
    ifstream f(this->woerterbuch, ios::in);
    while(!f.eof())
    {
        this->position++;
        getline(f,s);

        if(!s.compare(this->suchbegriff))
        {
          f.close();
          return "Passwort \"" + s +"\" in Zeile " + to_string(this->position) + " gefunden!";
        }
    }
    this->position--;
    f.close();
    return "Passwort nicht gefunden! --- Letzte Zeile: " + to_string(this->position);
}

Finder::~Finder()
{
}


