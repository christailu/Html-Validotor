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
#include "Verifier.h"


Verifier::Verifier()
{
    balance = new arrayStack<char>();
}

void Verifier::setFile() {
	cout << "Enter the name of the file to be verified" <<endl;
	getline(cin,filename);
	
    cout << "Verifying "<< filename << " for balanced angle brackets..."<< endl <<endl;
    filename += ".txt";
}

int Verifier::verify() 
{
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Error: Failed to open file " << filename << endl;
        return -1;
    }

    char c;
    int lineNumber = 1;
    while (inFile >> c) {
        if (c == '<') {
            balance->push(c);
             
        } else if (c == '>') {
            if (balance->isEmptyStack()) {
                cout << "Found extra > with no matching < "<< endl;
                inFile.close();
                
               return 0;
            }
            balance->pop();
        } else if (c == '\n') {
            lineNumber++;
        }
    }

    inFile.close();

    if (!balance->isEmptyStack()) {
        cout << "Found extra < with no matching >" << endl;
        
        return 0;
       
	}

    return -1;
}
