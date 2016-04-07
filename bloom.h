#include <bitset>
using namespace std;

class bloom {
    private:
    bitset<800000> array;
    int seeds[8] = {6234422, 1234654, 898765, 335234, 62344, 147483647, 74719222, 987654}; 
    static unsigned int hash(const void * key, int len, unsigned int seed);    
    public:
    bloom();
    void insert(string key);
    bool isIn(string key);
};