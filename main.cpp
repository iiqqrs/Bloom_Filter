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
    ifstream wrds_check ("wrds_check.txt");
    
    while(getline(wrds,line)){
        d.insert(line);
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