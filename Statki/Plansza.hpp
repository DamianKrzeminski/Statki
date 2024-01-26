#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include "Statek.hpp"

#ifndef PLANSZA_HPP_
#define PLANSZA_HPP_
using namespace sf;
using namespace std;

class Plansza : public Statek
{
    public:
        //ZMIENNE DO WYGRANEJ//
        int wygrana=0;
        //TABLICE//
        int Statki_Gracz1[10][10];
        //METODY//
        void dwochGraczy();
        void graZbotem();

    private:
        int q=0;
        //ZMIENNE DO ROZDZIELCZOŚCI//
        int BokSize;
        int RozSrx;
        int RozSry;
        //ZMIENNE POMOCNICZE//
        int x;
        int y;
        //ZMIENNE DO WYGASZENIA//
        int OK=0;
        //ZMIENNE ODPOWIEDZIALNE ZA STRZELANIE//
        int ilosc_strzalow=0;
        int limit_strzalow=100;
        int jaki_strzal=0;
        //ZMIENNE DO ZMIANY TURY//
        int tura=1;
        //ZMIENNE DO ZMIANY GRACZA//
        int gracz=1;
        //TABLICE//
        int tab[10][10];
        int czat[3];
        int Statki_Gracz2[10][10];
        int Strzaly_Gracz1[10][10];
        int Strzaly_Gracz2[10][10];
        //ZMIENNE DO ZASAD//
        int zasada;
        //ZMIENNE POMOCNICZE POTRZEBNE DO OBRACANIA OBIEKTÓW//
        int obrot=0;
        //METODY//
        void zamknij();
        void dopasowanie();
        void uzupelnienie_tablicy();
        void tablica();
        void zasady();
        void Tura();
        void Jaki_Gracz();
        void Strzal();
        void Zasada_Strzaly();
        void Wygrana();
        bool sprawdzWygr();
};
#endif // PLANSZA_HPP_
