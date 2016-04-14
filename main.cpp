#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include "bloom.cpp"
using namespace std;

int main(){
    bloom d;
    string line;
    ifstream wrds ("wrds.txt");
    ifstream wrds_check ("wrds_check.txt"); //The file to spell check (as of now its line by line not by spaces in a string)
    
    while(getline(wrds,line)){
        d.insert(line); //Inserts every line in wrds.txt as a new word into the dictionary
    }
    cout << "Finished loading dictionary" << endl;
    
    //Time to spellcheck
    while(getline(wrds_check,line)){
        if(!d.isIn(line)){
            cout <<"\"" << line << "\"" << " is not in the loaded dictionary!" << endl;
        }
    }
    cout << "Done All" << endl;
}