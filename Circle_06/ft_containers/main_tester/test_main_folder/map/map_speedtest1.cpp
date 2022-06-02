#include "../main.hpp"

int main(){
    map<int, int> m1;
    unsigned int i = 0;
    while ( i < 10000 ){
        m1.insert(pair<int, int>(i, i));
        i++;
    }
    std::cout << (*(m1.find(9999))).second << std::endl;
    std::cout << (*(m1.find(2))).second << std::endl;
    std::cout << (*(m1.find(4398))).second << std::endl;
}