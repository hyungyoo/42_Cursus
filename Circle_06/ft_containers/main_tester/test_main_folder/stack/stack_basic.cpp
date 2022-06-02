#include "../main.hpp"
#include <list>

int main()
{
    std::cout << "-------" << std::endl;
    std::cout << "Testing default (vector) stack :" << std::endl;
    stack<int> c1;
    c1.push(5);
    std::cout << "Taille de la stack par defaut apres un ajout : " << c1.size() << std::endl;
    std::cout << "Default stack OK !" << std::endl;
    std::cout << "-------" << std::endl;
    //test avec vecteur
    stack<int, vector<int> > c2;
    c2.push(1);
    c2.push(2);
    std::cout << "Taille de la stack de vecteur apres 2 ajouts : " << c2.size() << std::endl;
    std::cout << "Vector stack OK !" << std::endl;
    std::cout << "-------" << std::endl;
    //test avec deque
    stack<int, std::deque<int> > c3;
    c3.push(1);
    c3.push(2);
    std::cout << "Taille de la stack de vecteur apres 2 ajouts : " << c3.size() << std::endl;
    std::cout << "Deque stack OK !" << std::endl;
    std::cout << "-------" << std::endl;

    //test avec list
    stack<int, std::list<int> > c4;
    c4.push(1);
    c4.push(2);
    std::cout << "Taille de la stack de vecteur apres 2 ajouts : " << c4.size() << std::endl;
    std::cout << "List stack OK !" << std::endl;
    std::cout << "-------" << std::endl;
    return (0);
}