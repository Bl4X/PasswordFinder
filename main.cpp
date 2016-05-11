#include <iostream>
#include <string>
#include "Finder.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    char antwort;
    string suchbegriff;

    try
    {
        if(argv[1] == NULL)
        {
            throw "Bitte geben Sie eine gültige Passwortdatei an.";
        }

        Finder finderOOP(argv[1]);

	do
        {
            cout << "Bitte geben Sie den Suchbegriff ein:";
            getline(cin,suchbegriff);
            finderOOP = suchbegriff;
            cout << endl << finderOOP.nachPasswortSuchen() << "\n\n";
            cout << "Neue Suche? ([ENTER]/n)";
            cin.get(antwort);
            cin.sync();
            if(antwort == '\n')
            {
                cout << "\n\n\n";
            }
        } while(antwort == '\n');
        return 0;
    }
    catch ( char const* &ex )
    {
        cout << ex << endl;
        return 0;
    }
}
//Kommentar
