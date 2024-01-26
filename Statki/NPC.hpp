#include <SFML/Graphics.hpp>
#include <ctime>

#ifndef NPC_HPP_
#define NPC_HPP_

using namespace sf;
using namespace std;

class Komputer
{
    public:
        void wybUst();
        void botStrz();
        bool sprawdz(int k, int l);
        int bot[10][10];
        int strzaly[10][10];
};

#endif
