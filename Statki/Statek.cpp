#include <SFML/Graphics.hpp>
#include "Statek.hpp"

Statek::Statek()
{
    //CZCIONKA//
    czcionka.loadFromFile("Czcionka/arial.ttf");
    //TEKSTURY//
    t.loadFromFile("Grafika_Statki/Statki_Alianci/USS Prichett (DD-561) alianci nowy 51x51.PNG");
    t1.loadFromFile("Grafika_Statki/Statki_Alianci/USS Houston (CA-30) alianci 51x105.PNG");
    t2.loadFromFile("Grafika_Statki/Statki_Alianci/USS Iowa (BB-61) alianci 51x159.PNG");
    t3.loadFromFile("Grafika_Statki/Statki_Alianci/USS Lake Champlain (CV-39) alianci 51x213.PNG");
    traf.loadFromFile("Grafika_Statki/Trafienie.PNG");
    pudl.loadFromFile("Grafika_Statki/Pudlo.PNG");
    bg.loadFromFile("Grafika_Statki/watery.PNG");
    //TEKSTY//
    NastepnaTura.setString(L"Zakończ Turę");
    NastepnaTura.setFont(czcionka);
    NastepnaTura.setColor(Color::White);
    NastepnaTura.setStyle(Text::Bold);

    Plansza1.setString("Twoja Plansza");
    Plansza1.setFont(czcionka);
    Plansza1.setColor(Color::White);
    Plansza1.setStyle(Text::Bold);

    Plansza2.setString("Plansza Wroga");
    Plansza2.setFont(czcionka);
    Plansza2.setColor(Color::White);
    Plansza2.setStyle(Text::Bold);

    Napis_Wygrana_Gracz1.setString(L"WYGRAŁ GRACZ 1");
    Napis_Wygrana_Gracz1.setFont(czcionka);
    Napis_Wygrana_Gracz1.setStyle(Text::Bold);
    Napis_Wygrana_Gracz1.setColor(Color::White);

    Napis_Wygrana_Gracz2.setFont(czcionka);
    Napis_Wygrana_Gracz2.setStyle(Text::Bold);
    Napis_Wygrana_Gracz2.setColor(Color::White);

    Przycisk_OK.setString("OK");
    Przycisk_OK.setFont(czcionka);
    Przycisk_OK.setStyle(Text::Bold);
    Przycisk_OK.setColor(Color::White);

    Pudlo_Tekst.setString(L"Pudło !");
    Pudlo_Tekst.setFont(czcionka);
    Pudlo_Tekst.setColor(Color::Black);

    Trafienie_Tekst.setString(L"Trafienie !!");
    Trafienie_Tekst.setFont(czcionka);
    Trafienie_Tekst.setColor(Color::Black);

    Trafiony_Zatopiony.setString(L"Trafiony Zatopiony !!!");
    Trafiony_Zatopiony.setFont(czcionka);
    Trafiony_Zatopiony.setColor(Color::Black);

    Jaki_Numer_Gracza.setString(L"Gracz:");
    Jaki_Numer_Gracza.setFont(czcionka);
    Jaki_Numer_Gracza.setColor(Color::White);

    Tura_Numer_Napis.setString(L"Tura:");
    Tura_Numer_Napis.setFont(czcionka);
    Tura_Numer_Napis.setColor(Color::White);

    Napis.setFont(czcionka);
    Napis.setColor(Color::White);

    Cyfry.setFont(czcionka);
    Cyfry.setColor(Color::White);

    Tura_Gracza_1.setString("Tura Gracza 1:");
    Tura_Gracza_1.setFont(czcionka);
    Tura_Gracza_1.setStyle(Text::Bold);
    Tura_Gracza_1.setColor(Color::White);

    Tura_Gracza_2.setString("Tura Gracza 2:");
    Tura_Gracza_2.setFont(czcionka);
    Tura_Gracza_2.setStyle(Text::Bold);
    Tura_Gracza_2.setColor(Color::White);
    //KSZTAŁTY//
    Pudlo.setTexture(&pudl);

    Trafienie.setTexture(&traf);

    LiniaPozioma.setFillColor(Color(255, 50, 0));
    LiniaPozioma.setOutlineColor(Color(255, 50, 0));

    LiniaPionowa.setFillColor(Color(255, 50, 0));
    LiniaPionowa.setOutlineColor(Color(255, 50, 0));

    OKK.setOutlineThickness(8);
    OKK.setOutlineColor(Color::White);
    OKK.setFillColor(Color::Blue);

    Plansza_Czat.setOutlineThickness(4);
    Plansza_Czat.setOutlineColor(Color(50,0,255));
    Plansza_Czat.setFillColor(Color::White);
    //STATKI//
    //JEDNOMASZTOWCE//
    /*jednMaszt.setSize(Vector2f(51,51));//51,51
    jednMaszt.setTexture(&t);
    jednMaszt.setOrigin(26,26);//26,26

    jednMaszt2.setSize(Vector2f(51,51));
    jednMaszt2.setTexture(&t);
    jednMaszt2.setOrigin(26,26);

    jednMaszt3.setSize(Vector2f(51,51));
    jednMaszt3.setTexture(&t);
    jednMaszt3.setOrigin(26,26);

    jednMaszt4.setSize(Vector2f(51,51));
    jednMaszt4.setTexture(&t);
    jednMaszt4.setOrigin(26,26);

    //DWUMASZTOWCE//
    dwuMaszt.setSize(Vector2f(105,51));//105,51
    dwuMaszt.setTexture(&t1);
    dwuMaszt.setOrigin(26,26);

    dwuMaszt2.setSize(Vector2f(105,51));
    dwuMaszt2.setTexture(&t1);
    dwuMaszt2.setOrigin(26,26);

    dwuMaszt3.setSize(Vector2f(105,51));
    dwuMaszt3.setTexture(&t1);
    dwuMaszt3.setOrigin(26,26);

    //TRÓJMASZTOWCE//
    trojMaszt.setSize(Vector2f(159,51));//159,51
    trojMaszt.setTexture(&t2);
    trojMaszt.setOrigin(26,26);

    trojMaszt2.setSize(Vector2f(159,51));
    trojMaszt2.setTexture(&t2);
    trojMaszt2.setOrigin(26,26);

    //CZTEROMASZTOWIEC//
    czteroMaszt.setSize(Vector2f(213,51));//213,51
    czteroMaszt.setTexture(&t3);
    czteroMaszt.setOrigin(26,26);*/
}
