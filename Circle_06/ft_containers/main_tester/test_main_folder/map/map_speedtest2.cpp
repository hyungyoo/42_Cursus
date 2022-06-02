#include "../main.hpp"

int main()
{
    map<int, int> m1;

    unsigned int i = 0;

    while ( i < 10000 )
    {
        m1.insert(pair<int, int>(i, i));
        i++;
    }

    return(0);
}