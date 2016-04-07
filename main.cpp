#include <iostream>
#include "bloom.cpp"
#include <bitset>
using namespace std;

int main(){
    string dictionary[5] = {"this", "group", "is", "the", "best"};
    bloom d;
    
    for(int i=0; i<5; i++){
        d.insert(dictionary[i]);
    }
    
    //Tests
    for(int i=0; i<5; i++){
        if(d.isIn(dictionary[i])){
            cout << "Aye" <<endl;
        }else{
            cout << "Nope." << endl;
        }
    }
}