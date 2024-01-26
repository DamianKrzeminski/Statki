#include<SFML/Graphics.hpp>

#ifndef STATEK_HPP_
#define STATEK_HPP_

using namespace sf;
using namespace std;

class Statek
{
    public:
        Statek();
        //CZCIONKI//
        Font czcionka;
        //TEKSTURY//
        Texture t;
        Texture t1;
        Texture t2;
        Texture t3;
        Texture traf;
        Texture pudl;
        Texture bg;
        //TEKSTY//
        Text NastepnaTura;
        Text Plansza1;
        Text Plansza2;
        Text Tura_Gracza_1;
        Text Tura_Gracza_2;
        Text Przycisk_OK;
        Text Pudlo_Tekst;
        Text Trafienie_Tekst;
        Text Trafiony_Zatopiony;
        Text Napis;
        Text Cyfry;
        Text Jaki_Numer_Gracza;
        Text Tura_Numer_Napis;
        Text Tura_Napis;
        Text Napis_Jaki_Gracz;
        Text Napis_Wygrana_Gracz1;
        Text Napis_Wygrana_Gracz2;
        //KSZTAŁTY//
        RectangleShape LiniaPozioma;
        RectangleShape LiniaPionowa;
        RectangleShape OKK;
        RectangleShape Plansza_Czat;
        RectangleShape Pudlo;
        RectangleShape Trafienie;
        //STATKI//
        //JEDNOMASZT//
        RectangleShape jednMaszt;
        RectangleShape jednMaszt2;
        RectangleShape jednMaszt3;
        RectangleShape jednMaszt4;
        //DWUMASZT//
        RectangleShape dwuMaszt;
        RectangleShape dwuMaszt2;
        RectangleShape dwuMaszt3;
        //TRÓJMASZT//
        RectangleShape trojMaszt;
        RectangleShape trojMaszt2;
        //CZTEROMASZT//
        RectangleShape czteroMaszt;
};

#endif // STATEK_HPP_
