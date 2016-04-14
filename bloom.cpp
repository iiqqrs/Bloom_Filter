#include <iostream>
#include <bitset>
#include "bloom.h"
using namespace std;

bloom::bloom(){
}

unsigned int bloom::hash(const void * key, int len, unsigned int seed ){
    	// 'm' and 'r' are mixing constants generated offline.
    	// They're not really 'magic', they just happen to work well.
    
    	const unsigned int m = 0x5bd1e995;
    	const int r = 24;
    
    	// Initialize the hash to a 'random' value
    
    	unsigned int h = seed ^ len;
    
    	// Mix 4 bytes at a time into the hash
    
    	const unsigned char * data = (const unsigned char *)key;
    
    	while(len >= 4){
    	    unsigned int k = *(unsigned int *)data;
    	    
    	    k *= m; 
    		k ^= k >> r; 
    		k *= m; 
    		h *= m; 
    		h ^= k;
    		data += 4;
    		len -= 4;
    	}
    	
    	// Handle the last few bytes of the input array
    
    	switch(len){
    	    case 3: h ^= data[2] << 16;
    	    case 2: h ^= data[1] << 8;
    	    case 1: h ^= data[0];
    	        h *= m;
    	};
    
    	// Do a few final mixes of the hash to ensure the last few
    	// bytes are well-incorporated.
    
    	h ^= h >> 13;
    	h *= m;
    	h ^= h >> 15;
    
    	return (h % 800000);
}

bool bloom::isIn(string key){
    bool allIn = true;
    for (int i = 0; i < 8; i++) {
        if(array[hash(&*key.begin(), key.size(), seeds[i])]){
            continue;
        }else{
            allIn = false;
            break;
        }
    }
    return allIn;
}

void bloom::insert(string key){
    for(int i=0; i<8; i++){
        array.set(hash(&*key.begin(), key.size(), seeds[i]), true);
    }
}