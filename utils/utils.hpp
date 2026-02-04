#include <ctime>
#include <cstdlib>

namespace util{
    inline int random(int min, int max){
        return rand() % (max - min +1) +min;
    }
}

