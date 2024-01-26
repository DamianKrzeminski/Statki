#include <SFML/Graphics.hpp>
#include "Gra.hpp"
#include "Plansza.hpp"
#include "NPC.hpp"

Gra::Gra()
{
    czcionka.loadFromFile("Czcionka/arial.ttf");
}

void Gra::uruchom()
{
    stan = menu;
    while(stan != koniec)
    {
        switch(stan)
        {
            case menu:
                wyswietlMenu();
            break;

            case statki:
                wyswietlPlansze();
            break;

            case opcje:
                wyswietlOpcje();
                stan = menu;
            break;
        }
    }
}

void Gra::wyswietlMenu()
{
    RenderWindow menu(VideoMode::getDesktopMode(), "Menu", Style::None);

    int RozMP=468;
    int RozMN=menu.getSize().y-300;
    int RozM=RozMN-RozMP;
    RozM=RozM/5;
    NewSize=50+RozM;
    Texture bg;
    bg.loadFromFile("Grafika_Statki/watery.PNG");

    Sprite lel;

    Sprite tlo;
    tlo.setTexture(bg);

    RenderTexture texture;
    texture.create(menu.getSize().x, menu.getSize().y);

    Text tytul("Bitwa Morska", czcionka);
    tytul.setCharacterSize(NewSize*2);
    tytul.setColor(Color::White);
    tytul.setStyle(Text::Bold);
    tytul.setOrigin(tytul.getGlobalBounds().width/2,tytul.getGlobalBounds().height/2);
    tytul.setPosition(menu.getSize().x/2,(menu.getSize().y/2)-(NewSize*3)-40);

    Text start("Nowa Gra", czcionka);
    start.setCharacterSize(NewSize);
    start.setStyle(Text::Bold);
    start.setOrigin(start.getGlobalBounds().width/2,start.getGlobalBounds().height/2);
    start.setPosition(menu.getSize().x/2,(menu.getSize().y/2)-NewSize);

    Text ustawienia(L"Twórcy", czcionka);
    ustawienia.setCharacterSize(NewSize);
    ustawienia.setStyle(Text::Bold);
    ustawienia.setOrigin(ustawienia.getGlobalBounds().width/2,ustawienia.getGlobalBounds().height/2);
    ustawienia.setPosition(menu.getSize().x/2,(menu.getSize().y/2)+20);

    Text stop(L"Opuść Grę", czcionka);
    stop.setCharacterSize(NewSize);
    stop.setStyle(Text::Bold);
    stop.setOrigin(stop.getGlobalBounds().width/2,stop.getGlobalBounds().height/2);
    stop.setPosition(menu.getSize().x/2,(menu.getSize().y/2)+NewSize+40);

    while(menu.isOpen())
    {
        Event event;
        Vector2f mysz(Mouse::getPosition(menu));
        while(menu.pollEvent(event))
        {
            if(stop.getGlobalBounds().contains(mysz) && event.mouseButton.button == Mouse::Left)
            {
                menu.close();
                stan = koniec;
            }
            if(start.getGlobalBounds().contains(mysz) && event.mouseButton.button == Mouse::Left)
            {
                menu.close();
                stan = statki;
            }
            if(ustawienia.getGlobalBounds().contains(mysz) && event.mouseButton.button == Mouse::Left)
            {
                menu.close();
                stan = opcje;
            }
        }
        menu.setVerticalSyncEnabled(true);
        texture.clear();
        texture.draw(tlo);
        texture.display();
        menu.clear();
        lel.setTexture(texture.getTexture());
        menu.draw(lel);
        menu.draw(tytul);
        menu.draw(start);
        menu.draw(ustawienia);
        menu.draw(stop);
        if(start.getGlobalBounds().contains(mysz))
            start.setColor(Color::Red);
        else
            start.setColor(Color::White);
        if(ustawienia.getGlobalBounds().contains(mysz))
            ustawienia.setColor(Color::Red);
        else
            ustawienia.setColor(Color::White);
        if(stop.getGlobalBounds().contains(mysz))
            stop.setColor(Color::Red);
        else
            stop.setColor(Color::White);
        menu.display();
    }
}

void Gra::wyswietlPlansze()
{
    Plansza statki;
    Komputer sztucz;

    RenderWindow Wybor(VideoMode::getDesktopMode(), "Wybor", Style::None);

    Sprite lel;

    Texture bg;
    bg.loadFromFile("Grafika_Statki/watery.PNG");

    Sprite tlo;
    tlo.setTexture(bg);

    RenderTexture texture;
    texture.create(Wybor.getSize().x, Wybor.getSize().y);

    Text bot("Gra z komputerem", czcionka);
    bot.setCharacterSize(NewSize*2);
    bot.setStyle(Text::Bold);
    bot.setOrigin(bot.getGlobalBounds().width/2,bot.getGlobalBounds().height/2);
    bot.setPosition(Wybor.getSize().x/2, Wybor.getSize().y/2-(NewSize*2)-40);

    Text gracz("Gra z drugim graczem"   , czcionka);
    gracz.setCharacterSize(NewSize*2);
    gracz.setStyle(Text::Bold);
    gracz.setOrigin(gracz.getGlobalBounds().width/2,gracz.getGlobalBounds().height/2);
    gracz.setPosition(Wybor.getSize().x/2, Wybor.getSize().y/2+40);

    Event event;

    while(Wybor.isOpen())
    {
        Vector2f mysz(Mouse::getPosition(Wybor));
        while(Wybor.pollEvent(event))
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                Wybor.close();
                stan = menu;
            }
            if(Mouse::isButtonPressed(Mouse::Left) && bot.getGlobalBounds().contains(mysz))
            {
                Wybor.close();
                statki.graZbotem();
                stan = menu;
            }
            if(Mouse::isButtonPressed(Mouse::Left) && gracz.getGlobalBounds().contains(mysz))
            {
                Wybor.close();
                statki.dwochGraczy();
                stan = menu;
            }
        }
        Wybor.setVerticalSyncEnabled(true);
        texture.clear();
        texture.draw(tlo);
        texture.display();
        Wybor.clear();
        lel.setTexture(texture.getTexture());
        Wybor.draw(lel);
        Wybor.draw(bot);
        Wybor.draw(gracz);
        if(bot.getGlobalBounds().contains(mysz))
            bot.setColor(Color::Red);
        else
            bot.setColor(Color::White);
        if(gracz.getGlobalBounds().contains(mysz))
            gracz.setColor(Color::Red);
        else
            gracz.setColor(Color::White);
        Wybor.display();
    }
}

void Gra::wyswietlOpcje()
{
    RenderWindow Options(VideoMode::getDesktopMode(), "Twórcy", Style::None);

    Texture bg;
    bg.loadFromFile("Grafika_Statki/watery.PNG");

    Sprite lel;

    Sprite tlo;
    tlo.setTexture(bg);

    RenderTexture texture;
    texture.create(Options.getSize().x, Options.getSize().y);

    Text stop(L"Twórcy:", czcionka);
    stop.setCharacterSize(NewSize*2);
    stop.setStyle(Text::Bold);
    stop.setOrigin(stop.getGlobalBounds().width/2,stop.getGlobalBounds().height/2);
    stop.setPosition(Options.getSize().x/2,Options.getSize().y/2-(NewSize*2)-20);

    Text tworca1(L"Damian Krzemiński", czcionka);
    tworca1.setCharacterSize(NewSize);
    tworca1.setStyle(Text::Bold);
    tworca1.setOrigin(tworca1.getGlobalBounds().width/2,tworca1.getGlobalBounds().height/2);
    tworca1.setPosition(Options.getSize().x/2,Options.getSize().y/2+20);

    Text tworca2(L"Łukasz Skuza", czcionka);
    tworca2.setCharacterSize(NewSize);
    tworca2.setStyle(Text::Bold);
    tworca2.setOrigin(tworca2.getGlobalBounds().width/2,tworca2.getGlobalBounds().height/2);
    tworca2.setPosition(Options.getSize().x/2,Options.getSize().y/2+NewSize+40);

    while(Options.isOpen())
    {
        Event event;
        while(Options.pollEvent(event))
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                Options.close();
        }
        Options.setVerticalSyncEnabled(true);
        texture.clear();
        texture.draw(tlo);
        texture.display();
        Options.clear();
        lel.setTexture(texture.getTexture());
        Options.draw(lel);
        Options.draw(stop);
        Options.draw(tworca1);
        Options.draw(tworca2);
        Options.display();
    }
}
