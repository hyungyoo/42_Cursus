#include "../main.hpp"

int     main(){
map<int, int> m;
m.insert(pair<int, int>(1, 1));
m.insert(pair<int, int>(3, 3));
// srand (time(NULL));
std::cout << std::endl;
std::cout << "second constructor : "; 
for (int i = 0; i < 10000; i++){
    std::cout << (*(m.insert(m.begin(), pair<int, int>(i, i)))).second << " ";
}
std::cout << std::endl;
}