#ifndef FINDER_HPP
#define FINDER_HPP

#include <iostream>
#include <string>

using namespace std;

class Finder
{
    public:
        Finder(string const &woerterbuch);
        Finder &operator=(string const &suchbegriff);
        string nachPasswortSuchen();
        ~Finder();
    protected:
    private:
        string woerterbuch;
        string suchbegriff;
        unsigned int position;
};

#endif // FINDER_HPP
