#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Gra
{
    friend class Plansza;

    public:
        Gra();
        void uruchom();
        enum StanGry{menu, statki, opcje, koniec};
        StanGry stan;
        int NewSize;

    private:
        Font czcionka;
        void wyswietlMenu();
        void wyswietlPlansze();
        void wyswietlOpcje();
};
