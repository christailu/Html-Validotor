// ---------------------------------------------------------------------------
// Name: Christelle Mbemba
// Course-Section: CS255-01
// Assignment: Project #7
// Date due: 24/03/2023
// Description: The program is a html validor, is supposed to accepte a txt file and
//				add analyse it, and found if it respect the the html standard
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#ifndef arrayStack_h
#define arrayStack_h
#include "arrayStack.h"

#endif
using namespace std;

class Verifier
{
    public:
        Verifier();
        void setFile();
        int verify();
    private:
        arrayStack<char>* balance;
        string filename;
        ifstream inFile;
};
