#include <SFML/Graphics.hpp>
#include "Plansza.hpp"
#include "Gra.hpp"
#include "Statek.hpp"
#include "NPC.hpp"

Komputer BOT;

//METODA ODPOWIEDZIALNA ZA CZYSZCZENIE TABLICY//
void Plansza::tablica(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tab[i][j]=0;
        }
    }
}
//METODA ODPOWIEDZIALNA ZA USTAWIANIE OBIEKTÓW NA PLANSZY I ICH AUTODOPASOWANIE//
void Plansza::dopasowanie(){
    //ZMIENNE MIEJSCA NA PLANSZY//
    //x=120;
    //y=135;
    x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
    y=RozSry+BokSize+(BokSize/2)+7;
    //ZMIENNE MIEJSCA W TABLICY//
    int i=0;
    int j=0;
    //USTAWIANIE I DOPASOWANIE BEZ OBROTU OBIEKTÓW//
    while(i<10 && y<=RozSry+(BokSize*10)+(BokSize/2)+34){//621
        j=0;
        x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
        while(j<10 && x<=RozSrx-BokSize+((BokSize/2)+1)-43){//606
            if(jednMaszt.getGlobalBounds().contains(x,y)){
               jednMaszt.setPosition(x,y);
            }
            if(jednMaszt2.getGlobalBounds().contains(x,y)){
               jednMaszt2.setPosition(x,y);
            }
            if(jednMaszt3.getGlobalBounds().contains(x,y)){
               jednMaszt3.setPosition(x,y);
            }
            if(jednMaszt4.getGlobalBounds().contains(x,y)){
               jednMaszt4.setPosition(x,y);
            }
            if(dwuMaszt.getGlobalBounds().contains(x,y)){
                if(dwuMaszt.getGlobalBounds().contains(x+BokSize+3,y)){//54
                    dwuMaszt.setPosition(x,y);
                }
                if(dwuMaszt.getGlobalBounds().contains(x,y+BokSize+3)){
                    dwuMaszt.setPosition(x,y);
                }
            }
            if(dwuMaszt2.getGlobalBounds().contains(x,y)){
                if(dwuMaszt2.getGlobalBounds().contains(x+BokSize+3,y)){
                    dwuMaszt2.setPosition(x,y);
                }
                if(dwuMaszt2.getGlobalBounds().contains(x,y+BokSize+3)){
                    dwuMaszt2.setPosition(x,y);
                }
            }
            if(dwuMaszt3.getGlobalBounds().contains(x,y)){
                if(dwuMaszt3.getGlobalBounds().contains(x+BokSize+3,y)){
                    dwuMaszt3.setPosition(x,y);
                }
                if(dwuMaszt3.getGlobalBounds().contains(x,y+BokSize+3)){
                    dwuMaszt3.setPosition(x,y);
                }
            }
            if(trojMaszt.getGlobalBounds().contains(x,y)){
                if(trojMaszt.getGlobalBounds().contains(x+BokSize+3,y) && trojMaszt.getGlobalBounds().contains(x+(BokSize*2)+6,y)){
                    trojMaszt.setPosition(x,y);
                }
                if(trojMaszt.getGlobalBounds().contains(x,y+BokSize+3) && trojMaszt.getGlobalBounds().contains(x,y+(BokSize*2)+6)){
                    trojMaszt.setPosition(x,y);
                }
            }
            if(trojMaszt2.getGlobalBounds().contains(x,y)){
                if(trojMaszt2.getGlobalBounds().contains(x+BokSize+3,y) && trojMaszt2.getGlobalBounds().contains(x+(BokSize*2)+6,y)){//108
                    trojMaszt2.setPosition(x,y);
                }
                if(trojMaszt2.getGlobalBounds().contains(x,y+BokSize+3) && trojMaszt2.getGlobalBounds().contains(x,y+(BokSize*2)+6)){
                    trojMaszt2.setPosition(x,y);
                }
            }
            if(czteroMaszt.getGlobalBounds().contains(x,y)){
                if(czteroMaszt.getGlobalBounds().contains(x+BokSize+3,y) && czteroMaszt.getGlobalBounds().contains(x+(BokSize*2)+6,y) && czteroMaszt.getGlobalBounds().contains(x+(BokSize*3)+9,y)){//162
                    czteroMaszt.setPosition(x,y);
                }
                if(czteroMaszt.getGlobalBounds().contains(x,y+BokSize+3) && czteroMaszt.getGlobalBounds().contains(x,y+(BokSize*2)+6) && czteroMaszt.getGlobalBounds().contains(x,y+(BokSize*3)+9)){
                    czteroMaszt.setPosition(x,y);
                }
            }
            j++;
            x=x+BokSize+3;
        }
        i++;
        y=y+BokSize+3;
    }
}
//METODA ODPOWIEDZIALNA ZA WYPEŁNIANIE TABLICY WARTOŚCIAMI//
void Plansza::uzupelnienie_tablicy(){
    //ZMIENNE MIEJSCA NA PLANSZY//
    //x = 120;
    //y = 135;
    x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
    y=RozSry+BokSize+(BokSize/2)+7;
    //ZMIENNE MIEJSCA W TABLICY//
    int i=0;
    int j=0;
    //PĘTLA//
    while(i<10 && y<=RozSry+(BokSize*10)+(BokSize/2)+34){
        j=0;
        x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
        while(j<10 && x<=RozSrx-BokSize+((BokSize/2)+1)-43){
            if(jednMaszt.getGlobalBounds().contains(x,y)){
                tab[i][j]=1;
            }
            if(jednMaszt2.getGlobalBounds().contains(x,y)){
                tab[i][j]=11;
            }
            if(jednMaszt3.getGlobalBounds().contains(x,y)){
                tab[i][j]=111;
            }
            if(jednMaszt4.getGlobalBounds().contains(x,y)){
                tab[i][j]=1111;
            }
            if(dwuMaszt.getGlobalBounds().contains(x,y)){
                tab[i][j]=2;
            }
            if(dwuMaszt2.getGlobalBounds().contains(x,y)){
                tab[i][j]=22;
            }
            if(dwuMaszt3.getGlobalBounds().contains(x,y)){
                tab[i][j]=222;
            }
            if(trojMaszt.getGlobalBounds().contains(x,y)){
                tab[i][j]=3;
            }
            if(trojMaszt2.getGlobalBounds().contains(x,y)){
                tab[i][j]=33;
            }
            if(czteroMaszt.getGlobalBounds().contains(x,y)){
                tab[i][j]=4;
            }
            x=x+BokSize+3;
            j++;
        }
        y=y+BokSize+3;
        i++;
    }
}
//METODA ODPOWIEDZIALNA ZA ZASADY PRZECHODZENIA DO NASTĘPNEJ TURY//
void Plansza::zasady(){
    //ZASADA DOTYCZĄCA ILOŚCI STATKÓW NA PLANSZY//
    int a=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(tab[i][j]!=0){
                a++;
            }
        }
    }
    if(a!=20){
        zasada=1;
    }else{
        zasada=0;
    }
    //ZASADA DOTYCZĄCA TEGO, ŻE STATKI NIE MOGĄ STAĆ OBOK SIEBIE//
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((zasada==0) && (tab[i][j]==1 || tab[i][j]==11 || tab[i][j]==111 || tab[i][j]==1111)){
                if((i-1>=0 && j-1>=0 && j+1<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0)){
                    zasada=1;
                }
                if((i+1<=9 && j-1>=0 && j+1<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0)){
                    zasada=1;
                }
                if(j-1>=0 && tab[i][j-1]!=0){
                    zasada=1;
                }
                if(j+1<=9 && tab[i][j+1]!=0){
                    zasada=1;
                }
            }
            if(zasada==0 && tab[i][j]==2){
                if(j+1<=9 && tab[i][j+1]==2){
                    if((i-1>=0 && j-1>=0 && j+2<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0)){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+2<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0)){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+2<=9 && tab[i][j+2]!=0){
                        zasada=1;
                    }
                }
                if(i+1<=9 && tab[i+1][j]==2){
                    if((j-1>=0 && i-1>=0 && i+2<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+2<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+2<=9 && tab[i+2][j]!=0){
                        zasada=1;
                    }
                }
            }
            if(zasada==0 && tab[i][j]==22){
                if(j+1<=9 && tab[i][j+1]==22){
                    if((i-1>=0 && j-1>=0 && j+2<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0)){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+2<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0)){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+2<=9 && tab[i][j+2]!=0){
                        zasada=1;
                    }
                }
                if(i+1<=9 && tab[i+1][j]==22){
                    if((j-1>=0 && i-1>=0 && i+2<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+2<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+2<=9 && tab[i+2][j]!=0){
                        zasada=1;
                    }
                }
            }
            if(zasada==0 && tab[i][j]==222){
                if(j+1<=9 && tab[i][j+1]==222){
                    if((i-1>=0 && j-1>=0 && j+2<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0)){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+2<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0)){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+2<=9 && tab[i][j+2]!=0){
                        zasada=1;
                    }
                }
                if(i+1<=9 && tab[i+1][j]==222){
                    if((j-1>=0 && i-1>=0 && i+2<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+2<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+2<=9 && tab[i+2][j]!=0){
                        zasada=1;
                    }
                }
            }
            if(zasada==0 && tab[i][j]==3){
                if(j+2<=9 && tab[i][j+1]==3 && tab[i][j+2]==3){
                    if((i-1>=0 && j-1>=0 && j+3<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0 || tab[i-1][j+3]!=0)){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+3<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0 || tab[i+1][j+3]!=0)){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+3<=9 && tab[i][j+3]!=0){
                        zasada=1;
                    }
                }
                if(i+2<=9 && tab[i+1][j]==3 && tab[i+2][j]==3){
                    if((j-1>=0 && i-1>=0 && i+3<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0 || tab[i+3][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+3<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0 || tab[i+3][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+3<=9 && tab[i+3][j]!=0){
                        zasada=1;
                    }
                }
            }
            if(zasada==0 && tab[i][j]==33){
                if(j+2<=9 && tab[i][j+1]==33 && tab[i][j+2]==33){
                    if((i-1>=0 && j-1>=0 && j+3<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0 || tab[i-1][j+3]!=0)){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+3<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0 || tab[i+1][j+3]!=0)){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+3<=9 && tab[i][j+3]!=0){
                        zasada=1;
                    }
                }
                if(i+2<=9 && tab[i+1][j]==33 && tab[i+2][j]==33){
                    if((j-1>=0 && i-1>=0 && i+3<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0 || tab[i+3][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+3<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0 || tab[i+3][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+3<=9 && tab[i+3][j]!=0){
                        zasada=1;
                    }
                }
            }
            if(zasada==0 && tab[i][j]==4){
                if(j+3<=9 && tab[i][j+1]==4 && tab[i][j+2]==4 && tab[i][j+3]==4){
                    if((i-1>=0 && j-1>=0 && j+4<=9) && (tab[i-1][j-1]!=0 || tab[i-1][j]!=0 || tab[i-1][j+1]!=0 || tab[i-1][j+2]!=0 || tab[i-1][j+3]!=0 || tab[i-1][j+4])){
                        zasada=1;
                    }
                    if((i+1<=9 && j-1>=0 && j+4<=9) && (tab[i+1][j-1]!=0 || tab[i+1][j]!=0 || tab[i+1][j+1]!=0 || tab[i+1][j+2]!=0 || tab[i+1][j+3]!=0 || tab[i+1][j+4])){
                        zasada=1;
                    }
                    if(j-1>=0 && tab[i][j-1]!=0){
                        zasada=1;
                    }
                    if(j+4<=9 && tab[i][j+4]!=0){
                        zasada=1;
                    }
                }
                if(i+3<=9 && tab[i+1][j]==4 && tab[i+2][j]==4 && tab[i+3][j]==4){
                    if((j-1>=0 && i-1>=0 && i+4<=9) && (tab[i-1][j-1]!=0 || tab[i][j-1]!=0 || tab[i+1][j-1]!=0 || tab[i+2][j-1]!=0 || tab[i+3][j-1]!=0 || tab[i+4][j-1]!=0)){
                        zasada=1;
                    }
                    if((j+1<=9 && i-1>=0 && i+4<=9) && (tab[i-1][j+1]!=0 || tab[i][j+1]!=0 || tab[i+1][j+1]!=0 || tab[i+2][j+1]!=0 || tab[i+3][j+1]!=0 || tab[i+4][j+1]!=0)){
                        zasada=1;
                    }
                    if(i-1>=0 && tab[i-1][j]!=0){
                        zasada=1;
                    }
                    if(i+4<=9 && tab[i+4][j]!=0){
                        zasada=1;
                    }
                }
            }
        }
    }
}
//METODA PRZEŁĄCZANIA TURY//
void Plansza::Tura(){
    string tura_napis1;
    itoa(tura, (char*)tura_napis1.c_str(), 10);
    string tura_napis2 = tura_napis1.c_str();
    Tura_Napis.setString(tura_napis2);
    Tura_Napis.setFont(czcionka);
    Tura_Napis.setCharacterSize(BokSize/2);
    Tura_Napis.setOrigin(Tura_Napis.getGlobalBounds().width/2,Tura_Napis.getGlobalBounds().height/2);
    Tura_Napis.setColor(Color::White);
    Tura_Napis.setPosition(RozSrx+Tura_Numer_Napis.getGlobalBounds().width+45,28);
}
//METODA ODPOWIADAJĄCA ZA GRACZA//
void Plansza::Jaki_Gracz(){
   char numer_gracza=(char)(gracz+48);
   Napis_Jaki_Gracz.setString(numer_gracza);
   Napis_Jaki_Gracz.setFont(czcionka);
   Napis_Jaki_Gracz.setCharacterSize(BokSize/2);
   Napis_Jaki_Gracz.setOrigin(Napis_Jaki_Gracz.getGlobalBounds().width/2,Napis_Jaki_Gracz.getGlobalBounds().height/2);
   Napis_Jaki_Gracz.setColor(Color::White);
   Napis_Jaki_Gracz.setPosition(RozSrx-10,28);
}
//METODA ODPOWIEDZIALNA ZA STRZELANIE//
void Plansza::Strzal(){
    x=RozSrx+BokSize+46;//789
    y=RozSry+BokSize+6;//109
    int i=0;
    int j=0;
    if(gracz==1){
        while(i<10 && y<=RozSry+(BokSize*10)+33){//595
            j=0;
            x=RozSrx+BokSize+46;
            while(j<10 && x<=RozSrx+(BokSize*10)+73){//1275                   //x+51
                if((Mouse::getPosition().x>=x && Mouse::getPosition().x<=x+BokSize) && (Mouse::getPosition().y>=y && Mouse::getPosition().y<=y+BokSize) && ilosc_strzalow<limit_strzalow){
                    if(Strzaly_Gracz1[i][j]==0){
                        //PUDŁO//
                        jaki_strzal=1;
                        Strzaly_Gracz1[i][j]=5;
                        ilosc_strzalow++;
                    }
                    if(Strzaly_Gracz1[i][j]==1 || Strzaly_Gracz1[i][j]==2 || Strzaly_Gracz1[i][j]==3 || Strzaly_Gracz1[i][j]==4){
                        //TRAFIENIE//
                        jaki_strzal=2;
                        if(Strzaly_Gracz1[i][j]==1){
                            jaki_strzal=3;
                        }
                        if(Strzaly_Gracz1[i][j]==2){
                            if(i-1>=0 && Strzaly_Gracz1[i-1][j]==6){
                                jaki_strzal=3;
                            }
                            if(i+1<10 && Strzaly_Gracz1[i+1][j]==6){
                                jaki_strzal=3;
                            }
                            if(j-1>=0 && Strzaly_Gracz1[i][j-1]==6){
                                jaki_strzal=3;
                            }
                            if(j+1<10 && Strzaly_Gracz1[i][j+1]==6){
                                jaki_strzal=3;
                            }
                        }
                        if(Strzaly_Gracz1[i][j]==3){
                            if(j+1<10 && Strzaly_Gracz1[i][j+1]==6){
                                if(j+2<10 && Strzaly_Gracz1[i][j+2]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(i+1<10 && Strzaly_Gracz1[i+1][j]==6){
                                if(i+2<10 && Strzaly_Gracz1[i+2][j]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(j-1>=0 && Strzaly_Gracz1[i][j-1]==6){
                                if(j-2>=0 && Strzaly_Gracz1[i][j-2]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(i-1>=0 && Strzaly_Gracz1[i-1][j]==6){
                                if(i-2>=0 && Strzaly_Gracz1[i-2][j]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if((j-1>=0 && j+1<10) && (Strzaly_Gracz1[i][j-1]==6 && Strzaly_Gracz1[i][j+1]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i+1<10) && (Strzaly_Gracz1[i-1][j]==6 && Strzaly_Gracz1[i+1][j]==6)){
                                jaki_strzal=3;
                            }
                        }
                        if(Strzaly_Gracz1[i][j]==4){
                            if(j+1<10 && Strzaly_Gracz1[i][j+1]==6){
                                if(j+2<10 && Strzaly_Gracz1[i][j+2]==6){
                                    if(j+3<10 && Strzaly_Gracz1[i][j+3]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(j-1>=0 && Strzaly_Gracz1[i][j-1]==6){
                                if(j-2>=0 && Strzaly_Gracz1[i][j-2]==6){
                                    if(j-3>=0 && Strzaly_Gracz1[i][j-3]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(i-1>=0 && Strzaly_Gracz1[i-1][j]==6){
                                if(i-2>=0 && Strzaly_Gracz1[i-2][j]==6){
                                    if(i-3>=0 && Strzaly_Gracz1[i-3][j]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(i+1<10 && Strzaly_Gracz1[i+1][j]==6){
                                if(i+2<10 && Strzaly_Gracz1[i+2][j]==6){
                                    if(i+3<10 && Strzaly_Gracz1[i+3][j]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if((j+1<10 && j+2<10 && j-1>=0) && (Strzaly_Gracz1[i][j+1]==6 && Strzaly_Gracz1[i][j+2]==6 && Strzaly_Gracz1[i][j-1]==6)){
                                jaki_strzal=3;
                            }
                            if((j+1<10 && j-1>=0 && j-2>=0) && (Strzaly_Gracz1[i][j+1]==6 && Strzaly_Gracz1[i][j-1]==6 && Strzaly_Gracz1[i][j-2]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i-2>=0 && i+1<10) && (Strzaly_Gracz1[i-1][j]==6 && Strzaly_Gracz1[i-2][j]==6 && Strzaly_Gracz1[i+1][j]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i+1<10 && i+2<10) && (Strzaly_Gracz1[i-1][j]==6 && Strzaly_Gracz1[i+1][j]==6 && Strzaly_Gracz1[i+2][j]==6)){
                                jaki_strzal=3;
                            }
                        }
                        Strzaly_Gracz1[i][j]=6;
                        ilosc_strzalow++;
                        limit_strzalow++;
                    }
                }
                j++;
                x=x+BokSize+3;
            }
            i++;
            y=y+BokSize+3;
        }
    }
    if(gracz==2){
        while(i<10 && y<=RozSry+(BokSize*10)+33){
            j=0;
             x=RozSrx+BokSize+46;
            while(j<10 && x<=RozSrx+(BokSize*10)+73){
                if((Mouse::getPosition().x>=x && Mouse::getPosition().x<=x+BokSize) && (Mouse::getPosition().y>=y && Mouse::getPosition().y<=y+BokSize) && ilosc_strzalow<limit_strzalow){
                    if(Strzaly_Gracz2[i][j]==0){
                        //PUDŁO//
                        jaki_strzal=1;
                        Strzaly_Gracz2[i][j]=5;
                        ilosc_strzalow++;
                    }
                    if(Strzaly_Gracz2[i][j]==1 || Strzaly_Gracz2[i][j]==2 || Strzaly_Gracz2[i][j]==3 || Strzaly_Gracz2[i][j]==4){
                        //TRAFIENIE//
                        jaki_strzal=2;
                        if(Strzaly_Gracz2[i][j]==1){
                            jaki_strzal=3;
                        }
                        if(Strzaly_Gracz2[i][j]==2){
                            if(i-1>=0 && Strzaly_Gracz2[i-1][j]==6){
                                jaki_strzal=3;
                            }
                            if(i+1<10 && Strzaly_Gracz2[i+1][j]==6){
                                jaki_strzal=3;
                            }
                            if(j-1>=0 && Strzaly_Gracz2[i][j-1]==6){
                                jaki_strzal=3;
                            }
                            if(j+1<10 && Strzaly_Gracz2[i][j+1]==6){
                                jaki_strzal=3;
                            }
                        }
                        if(Strzaly_Gracz2[i][j]==3){
                            if(j+1<10 && Strzaly_Gracz2[i][j+1]==6){
                                if(j+2<10 && Strzaly_Gracz2[i][j+2]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(i+1<10 && Strzaly_Gracz2[i+1][j]==6){
                                if(i+2<10 && Strzaly_Gracz2[i+2][j]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(j-1>=0 && Strzaly_Gracz2[i][j-1]==6){
                                if(j-2>=0 && Strzaly_Gracz2[i][j-2]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if(i-1>=0 && Strzaly_Gracz2[i-1][j]==6){
                                if(i-2>=0 && Strzaly_Gracz2[i-2][j]==6){
                                    jaki_strzal=3;
                                }
                            }
                            if((j-1>=0 && j+1<10) && (Strzaly_Gracz2[i][j-1]==6 && Strzaly_Gracz2[i][j+1]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i+1<10) && (Strzaly_Gracz2[i-1][j]==6 && Strzaly_Gracz2[i+1][j]==6)){
                                jaki_strzal=3;
                            }
                        }
                        if(Strzaly_Gracz2[i][j]==4){
                            if(j+1<10 && Strzaly_Gracz2[i][j+1]==6){
                                if(j+2<10 && Strzaly_Gracz2[i][j+2]==6){
                                    if(j+3<10 && Strzaly_Gracz2[i][j+3]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(j-1>=0 && Strzaly_Gracz2[i][j-1]==6){
                                if(j-2>=0 && Strzaly_Gracz2[i][j-2]==6){
                                    if(j-3>=0 && Strzaly_Gracz2[i][j-3]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(i-1>=0 && Strzaly_Gracz2[i-1][j]==6){
                                if(i-2>=0 && Strzaly_Gracz2[i-2][j]==6){
                                    if(i-3>=0 && Strzaly_Gracz2[i-3][j]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if(i+1<10 && Strzaly_Gracz2[i+1][j]==6){
                                if(i+2<10 && Strzaly_Gracz2[i+2][j]==6){
                                    if(i+3<10 && Strzaly_Gracz2[i+3][j]==6){
                                        jaki_strzal=3;
                                    }
                                }
                            }
                            if((j+1<10 && j+2<10 && j-1>=0) && (Strzaly_Gracz2[i][j+1]==6 && Strzaly_Gracz2[i][j+2]==6 && Strzaly_Gracz2[i][j-1]==6)){
                                jaki_strzal=3;
                            }
                            if((j+1<10 && j-1>=0 && j-2>=0) && (Strzaly_Gracz2[i][j+1]==6 && Strzaly_Gracz2[i][j-1]==6 && Strzaly_Gracz2[i][j-2]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i-2>=0 && i+1<10) && (Strzaly_Gracz2[i-1][j]==6 && Strzaly_Gracz2[i-2][j]==6 && Strzaly_Gracz2[i+1][j]==6)){
                                jaki_strzal=3;
                            }
                            if((i-1>=0 && i+1<10 && i+2<10) && (Strzaly_Gracz2[i-1][j]==6 && Strzaly_Gracz2[i+1][j]==6 && Strzaly_Gracz2[i+2][j]==6)){
                                jaki_strzal=3;
                            }
                        }
                        Strzaly_Gracz2[i][j]=6;
                        ilosc_strzalow++;
                        limit_strzalow++;
                    }
                }
                j++;
                x=x+BokSize+3;
            }
            i++;
            y=y+BokSize+3;
        }
    }
}
//METODA ODPOWIEDZIALNA ZA PRZECHODZENIA DO NASTĘPNEJ TURY PRZY STRZALE//
void Plansza::Zasada_Strzaly(){
    if(ilosc_strzalow==limit_strzalow){
        zasada=0;
    }else{
        zasada=1;
    }
}
//METODA ODPOWIEDZIALNA ZA SPRAWDZANIE ZWYCIĘSTWA//
bool Plansza::sprawdzWygr()
{
    int a = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(BOT.strzaly[i][j] == 6)
                a++;
    if(a == 20)
    {
        wygrana = 1;
        return true;
    }
    else
        return false;
}

void Plansza::Wygrana(){
    int a=0;
    if(gracz==1){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(Strzaly_Gracz1[i][j]==6){
                    a++;
                }
            }
        }
        if(a==20){
            wygrana=1;
        }
    }
    if(gracz==2){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(Strzaly_Gracz2[i][j]==6){
                    a++;
                }
            }
        }
        if(a==20){
            wygrana=1;
        }
    }
}
//METODA ODPOWIADAJĄCA ZA WYŚWIETLANIE PLANSZY I PRZEPROWADZANIE OPERACJI NA PLANSZY//
void Plansza::dwochGraczy(){
    //WCZYTANIE OKNA//
    RenderWindow okno(VideoMode::getDesktopMode(),"Twoja Plansza", Style::None);
    int RozPodx=561;//(1366-80-46-46-36-36)/2
    int RozPody=561;//768-57-150
        int NewRozx=(okno.getSize().x-244)/2;//(-80-46-46-36-36)
        int NewRozy=okno.getSize().y-207;//-57-150
        int Rozx=NewRozx-RozPodx;
        int Rozy=NewRozy-RozPody;
        int Roz;
        if(Rozx>Rozy){
            Roz=Rozy;
        }else{
            Roz=Rozx;
        }
        Roz=Roz/11;
        if(Roz!=0){
            if(Roz%2!=0){
                Roz--;
            }
        }
        BokSize=51+Roz;
    RozSrx=okno.getSize().x/2;
    RozSry=57;
    //TŁO//
    Sprite lel;

    Sprite tlo;
    tlo.setTexture(bg);

    RenderTexture texture;
    texture.create(okno.getSize().x, okno.getSize().y);
    //STATKI//
    jednMaszt.setSize(Vector2f(BokSize,BokSize));//51,51
    jednMaszt.setTexture(&t);
    jednMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);//26,26

    jednMaszt2.setSize(Vector2f(BokSize,BokSize));
    jednMaszt2.setTexture(&t);
    jednMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt3.setSize(Vector2f(BokSize,BokSize));
    jednMaszt3.setTexture(&t);
    jednMaszt3.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt4.setSize(Vector2f(BokSize,BokSize));
    jednMaszt4.setTexture(&t);
    jednMaszt4.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //DWUMASZTOWCE//
    dwuMaszt.setSize(Vector2f((BokSize*2)+3,BokSize));//105,51
    dwuMaszt.setTexture(&t1);
    dwuMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    dwuMaszt2.setSize(Vector2f((BokSize*2)+3,BokSize));
    dwuMaszt2.setTexture(&t1);
    dwuMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    dwuMaszt3.setSize(Vector2f((BokSize*2)+3,BokSize));
    dwuMaszt3.setTexture(&t1);
    dwuMaszt3.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //TRÓJMASZTOWCE//
    trojMaszt.setSize(Vector2f((BokSize*3)+6,BokSize));//159,51
    trojMaszt.setTexture(&t2);
    trojMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    trojMaszt2.setSize(Vector2f((BokSize*3)+6,BokSize));
    trojMaszt2.setTexture(&t2);
    trojMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //CZTEROMASZTOWIEC//
    czteroMaszt.setSize(Vector2f((BokSize*4)+9,BokSize));//213,51
    czteroMaszt.setTexture(&t3);
    czteroMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt.setPosition(RozSrx+120,okno.getSize().y/2-(BokSize*2)-60);
    jednMaszt2.setPosition(RozSrx+BokSize+130,okno.getSize().y/2-(BokSize*2)-60);
    jednMaszt3.setPosition(RozSrx+(BokSize*2)+140,okno.getSize().y/2-(BokSize*2)-60);
    jednMaszt4.setPosition(RozSrx+(BokSize*3)+150,okno.getSize().y/2-(BokSize*2)-60);
    dwuMaszt.setPosition(RozSrx+120,okno.getSize().y/2-BokSize-40);
    dwuMaszt2.setPosition(RozSrx+(BokSize*2)+130,okno.getSize().y/2-BokSize-40);
    dwuMaszt3.setPosition(RozSrx+(BokSize*4)+140,okno.getSize().y/2-BokSize-40);
    trojMaszt.setPosition(RozSrx+120,okno.getSize().y/2-20);
    trojMaszt2.setPosition(RozSrx+(BokSize*3)+130,okno.getSize().y/2-20);
    czteroMaszt.setPosition(RozSrx+120,okno.getSize().y/2+BokSize);
    //KSZTAŁTY//
    Trafienie.setSize(Vector2f(BokSize,BokSize));
    Trafienie.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    Pudlo.setSize(Vector2f(BokSize,BokSize));
    Pudlo.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    LiniaPozioma.setSize(Vector2f((BokSize*11)+33,3));

    LiniaPionowa.setSize(Vector2f(3,(BokSize*11)+36));

    OKK.setSize(Vector2f(BokSize*8,BokSize*4));
    OKK.setOrigin(OKK.getSize().x/2,OKK.getSize().y/2);
    OKK.setPosition(RozSrx,okno.getSize().y/2);

    Plansza_Czat.setSize(Vector2f((BokSize*11)+30,100));
    Plansza_Czat.setPosition(RozSrx-(BokSize*11)-73,RozSry+(BokSize*11)+46);//41,664

    int RozCzy=Plansza_Czat.getSize().y-40;
    RozCzy=RozCzy/3;
    //TEKSTY//
    NastepnaTura.setCharacterSize((BokSize*2)-40);
    NastepnaTura.setOrigin(NastepnaTura.getGlobalBounds().width/2,NastepnaTura.getGlobalBounds().height/2);
    NastepnaTura.setPosition(RozSrx+(BokSize*5)+(BokSize/2)+59,RozSry+(BokSize*11)+36+NastepnaTura.getCharacterSize());//(okno.getSize().x - NastepnaTura.getGlobalBounds().width*1.43, 658);

    Plansza1.setCharacterSize((BokSize*3)/4);
    Plansza1.setOrigin(Plansza1.getGlobalBounds().width/2,Plansza1.getGlobalBounds().height/2);
    Plansza1.setPosition(RozSrx-(BokSize*6)+((BokSize/2)+1)-58,RozSry-Plansza1.getGlobalBounds().height);

    Plansza2.setCharacterSize((BokSize*3)/4);
    Plansza2.setOrigin(Plansza2.getGlobalBounds().width/2,Plansza2.getGlobalBounds().height/2);
    Plansza2.setPosition(RozSrx+(BokSize*5)+(BokSize/2)+59,RozSry-Plansza1.getGlobalBounds().height);

    Napis_Wygrana_Gracz1.setCharacterSize(BokSize*2);
    Napis_Wygrana_Gracz1.setOrigin(Napis_Wygrana_Gracz1.getGlobalBounds().width/2,Napis_Wygrana_Gracz1.getGlobalBounds().height/2);
    Napis_Wygrana_Gracz1.setPosition(RozSrx,okno.getSize().y/2);

    Napis_Wygrana_Gracz2.setString(L"WYGRAŁ GRACZ 2");
    Napis_Wygrana_Gracz2.setCharacterSize(BokSize*2);
    Napis_Wygrana_Gracz2.setOrigin(Napis_Wygrana_Gracz2.getGlobalBounds().width/2,Napis_Wygrana_Gracz2.getGlobalBounds().height/2);
    Napis_Wygrana_Gracz2.setPosition(RozSrx,okno.getSize().y/2);

    Tura_Gracza_1.setCharacterSize(BokSize);
    Tura_Gracza_1.setOrigin(Tura_Gracza_1.getGlobalBounds().width/2,Tura_Gracza_1.getGlobalBounds().height/2);
    Tura_Gracza_1.setPosition(RozSrx,okno.getSize().y/2-Tura_Gracza_1.getCharacterSize()-10);

    Tura_Gracza_2.setCharacterSize(BokSize);
    Tura_Gracza_2.setOrigin(Tura_Gracza_2.getGlobalBounds().width/2,Tura_Gracza_2.getGlobalBounds().height/2);
    Tura_Gracza_2.setPosition(RozSrx,okno.getSize().y/2-Tura_Gracza_2.getCharacterSize());

    Przycisk_OK.setCharacterSize(BokSize);
    Przycisk_OK.setOrigin(Przycisk_OK.getGlobalBounds().width/2,Przycisk_OK.getGlobalBounds().height/2);
    Przycisk_OK.setPosition(RozSrx,okno.getSize().y/2+(Przycisk_OK.getCharacterSize()/2));

    Jaki_Numer_Gracza.setCharacterSize(BokSize/2);
    Jaki_Numer_Gracza.setOrigin(Jaki_Numer_Gracza.getGlobalBounds().width/2,Jaki_Numer_Gracza.getGlobalBounds().height/2);

    Tura_Numer_Napis.setCharacterSize(BokSize/2);
    Tura_Numer_Napis.setOrigin(Tura_Numer_Napis.getGlobalBounds().width/2,Tura_Numer_Napis.getGlobalBounds().height/2);
    Tura_Numer_Napis.setPosition(RozSrx+(Tura_Numer_Napis.getGlobalBounds().width/2)+30,28);

    Napis.setCharacterSize(BokSize-6);

    Cyfry.setCharacterSize(BokSize-6);

    Pudlo_Tekst.setCharacterSize(RozCzy);

    Trafienie_Tekst.setCharacterSize(RozCzy);

    Trafiony_Zatopiony.setCharacterSize(RozCzy);
    //ZMIENNE POMOCNICZE POTRZEBNE DO PRZESUWANIA OBIEKTÓW//
    int i=1;
    int j=0;
    //ZMIENNA DO TEGO JAKI TO STATEK//
    int jaki_maszt;
    //ZMIENNE OD CZATU//
    int k;
    int l;
    //ZMIENNE DO WYŚWIETLANIA LITER I CYFR//
    char napis_litery;
    int cyfry_licznik;
    string napis_cyfry1;
    string napis_cyfry2;
    //ZMIENNE POMOCNICZE DO TURY//
    int przelacz_ture=0;
    //PĘTLA//
    while(okno.isOpen()){
        //OBSŁUGA MYSZY//
        Vector2f mysz(Mouse::getPosition(okno));
        Event e;
        while(okno.pollEvent(e)){
            if(e.type==Event::Closed){
                okno.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                okno.close();
            }
            if(tura==1){
                //PRZESUWANIE OBIEKTÓW//
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && (Mouse::isButtonPressed(Mouse::Left)) && (i==1)){
                    i=2;
                    if(jednMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=1;
                    }
                    if(jednMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=11;
                    }
                    if(jednMaszt3.getGlobalBounds().contains(mysz)){
                        jaki_maszt=111;
                    }
                    if(jednMaszt4.getGlobalBounds().contains(mysz)){
                        jaki_maszt=1111;
                    }
                    if(dwuMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=2;
                    }
                    if(dwuMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=22;
                    }
                    if(dwuMaszt3.getGlobalBounds().contains(mysz)){
                        jaki_maszt=222;
                    }
                    if(trojMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=3;
                    }
                    if(trojMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=33;
                    }
                    if(czteroMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=4;
                    }
                }
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && (Mouse::isButtonPressed(Mouse::Left)) && (j==1)){
                    i=1;
                    j=0;
                }
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && ((e.type==Event::MouseButtonReleased && e.mouseButton.button==Mouse::Left)) && (i==2)){
                    i=2;
                    j=1;
                }
                //OBRACANIE//
                if(Mouse::isButtonPressed(Mouse::Right) && i==2){
                    obrot=1;
                }
            }
            //STRZELANIE//
            if(tura!=1 && wygrana==0){
                if(Mouse::isButtonPressed(Mouse::Left) && ((Mouse::getPosition().x>=RozSrx+BokSize+46) && (Mouse::getPosition().x<=RozSrx+(BokSize*11)+76)) && ((Mouse::getPosition().y>=RozSry+BokSize+6) && (Mouse::getPosition().y<=RozSry+(BokSize*11)+36))){//x(2)1329//y(2)649
                    Strzal();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::S)){
                q++;
                dwuMaszt.setSize(Vector2f((102/q)+3,51/q));
            }
            //PRZEŁĄCZANIE TURY//
            if((NastepnaTura.getGlobalBounds().contains(mysz)) && (Mouse::isButtonPressed(Mouse::Left)) && (zasada==0)){
                przelacz_ture=1;
            }
            //PRZEŁĄCZNIE "OK"//
            if(Przycisk_OK.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left)){
                OK=1;
            }
            if(Napis_Wygrana_Gracz1.getGlobalBounds().contains(mysz)){
                Napis_Wygrana_Gracz1.setColor(Color::Red);
            }else{
                Napis_Wygrana_Gracz1.setColor(Color::White);
            }
            if(Napis_Wygrana_Gracz1.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left) && wygrana==1){
                okno.close();
            }
            if(Napis_Wygrana_Gracz2.getGlobalBounds().contains(mysz)){
                Napis_Wygrana_Gracz2.setColor(Color::Red);
            }else{
                Napis_Wygrana_Gracz2.setColor(Color::White);
            }
            if(Napis_Wygrana_Gracz2.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left) && wygrana==1){
                okno.close();
            }
        }
    //WYGASZENIE//
    if(OK==0){
        for(int d=0;d==0;d++){
            okno.clear(Color::Black);
        }
        if(Przycisk_OK.getGlobalBounds().contains(mysz)){
            Przycisk_OK.setColor(Color::Red);
        }else{
            Przycisk_OK.setColor(Color::White);
        }
        okno.draw(OKK);
        okno.draw(Przycisk_OK);
        if(gracz==1){
            okno.draw(Tura_Gracza_1);
        }else{
            okno.draw(Tura_Gracza_2);
        }
    }else{
        //ROZGRYWKA//
        if(tura==1){
            tablica();
            dopasowanie();
            uzupelnienie_tablicy();
            zasady();
        }
        Tura();
        Jaki_Gracz();
        Jaki_Numer_Gracza.setPosition(RozSrx-Napis_Jaki_Gracz.getGlobalBounds().width-(Jaki_Numer_Gracza.getGlobalBounds().width/2)-10,28);
        //WYZNACZANIE LINII PÓL//
        okno.setVerticalSyncEnabled(true);
        texture.clear();
        texture.draw(tlo);
        texture.display();
        okno.clear();
        lel.setTexture(texture.getTexture());
        okno.draw(lel);
        /*for(int y=52;y<=646;y=y+54){
            LiniaPozioma.setPosition(37,y);
            okno.draw(LiniaPozioma);
                if(tura!=1){
                LiniaPozioma.setPosition(732,y);
                okno.draw(LiniaPozioma);
            }
        }
        for(int x=631;x>=37;x=x-54){
            LiniaPionowa.setPosition(x,52);
            okno.draw(LiniaPionowa);
        }
        if(tura!=1){
            for(int x=732;x<=1326;x=x+54){
                LiniaPionowa.setPosition(x,52);
                okno.draw(LiniaPionowa);
            }
        }*/
        for(int y=57;y<=((BokSize*11)+93);y=(y+(BokSize+3))){
            LiniaPozioma.setPosition((((okno.getSize().x/2)-(BokSize*11))-73),y);
            okno.draw(LiniaPozioma);
                if(tura!=1){
                LiniaPozioma.setPosition(((okno.getSize().x/2)+40),y);
                okno.draw(LiniaPozioma);
            }
        }
        for(int x=(((okno.getSize().x/2)-(BokSize*11))-76);x<=((okno.getSize().x/2)-43);x=(x+(BokSize+3))){
            LiniaPionowa.setPosition(x,57);
            okno.draw(LiniaPionowa);
        }
        if(tura!=1){
            for(int x=((okno.getSize().x/2)+40);x<=(((okno.getSize().x/2)+(BokSize*11))+76);x=(x+(BokSize+3))){
                LiniaPionowa.setPosition(x,57);
                okno.draw(LiniaPionowa);
            }
        }
        //WSTAWIANIE LITER I CYFR//
        napis_litery=65;
        for(int u=RozSry+BokSize+(BokSize/2)+7;u<=RozSry+(BokSize*10)+(BokSize/2)+34;u=u+BokSize+3){//112;598;54
            Napis.setString(napis_litery);
            Napis.setOrigin(Napis.getGlobalBounds().width/2,Napis.getCharacterSize()/2);
            Napis.setPosition(RozSrx-(BokSize*11)+((BokSize/2)+1)-73,u);
            okno.draw(Napis);
            if(tura!=1){
                Napis.setPosition(RozSrx+(BokSize/2)+44,u);
                okno.draw(Napis);
            }
            napis_litery++;
        }
        cyfry_licznik=1;
        for(int u=RozSrx-(BokSize*10)+((BokSize/2)+1)-73;u<=RozSrx-BokSize+((BokSize/2)+1)-43;u=u+BokSize+3){//95;581;54
            itoa(cyfry_licznik, (char*)napis_cyfry1.c_str(), 10);
            napis_cyfry2 = napis_cyfry1.c_str();
            Cyfry.setString(napis_cyfry2);
            Cyfry.setOrigin(Cyfry.getGlobalBounds().width/2,Cyfry.getGlobalBounds().height/2);
            Cyfry.setPosition(u,RozSry+BokSize/2-3);
            okno.draw(Cyfry);
            cyfry_licznik++;
        }
            if(tura!=1){
                cyfry_licznik=1;
                for(int u=RozSrx+BokSize+BokSize/2+47;u<=RozSrx+(BokSize*10)+(BokSize/2)+74;u=u+BokSize+3){
                    itoa(cyfry_licznik, (char*)napis_cyfry1.c_str(), 10);
                    napis_cyfry2 = napis_cyfry1.c_str();
                    Cyfry.setString(napis_cyfry2);
                    Cyfry.setOrigin(Cyfry.getGlobalBounds().width/2,Cyfry.getGlobalBounds().height/2);
                    Cyfry.setPosition(u-3,RozSry+BokSize/2-3);
                    okno.draw(Cyfry);
                    cyfry_licznik++;
                }
            }
        if(tura==1){
            //PRZESUWANIE I OBRACANIE OBIEKTÓW//
            int r;
            if(i==2){
                if(jaki_maszt==1){
                    jednMaszt.setPosition(mysz);
                    jednMaszt.setOutlineThickness(2);
                    jednMaszt.setOutlineColor(Color::Yellow);
                    r=jednMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt.setRotation(90);
                        }else{
                            jednMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==11){
                    jednMaszt2.setPosition(mysz);
                    jednMaszt2.setOutlineThickness(2);
                    jednMaszt2.setOutlineColor(Color::Yellow);
                    r=jednMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt2.setRotation(90);
                        }else{
                            jednMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==111){
                    jednMaszt3.setPosition(mysz);
                    jednMaszt3.setOutlineThickness(2);
                    jednMaszt3.setOutlineColor(Color::Yellow);
                    r=jednMaszt3.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt3.setRotation(90);
                        }else{
                            jednMaszt3.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==1111){
                    jednMaszt4.setPosition(mysz);
                    jednMaszt4.setOutlineThickness(2);
                    jednMaszt4.setOutlineColor(Color::Yellow);
                    r=jednMaszt4.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt4.setRotation(90);
                        }else{
                            jednMaszt4.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==2){
                    dwuMaszt.setPosition(mysz);
                    dwuMaszt.setOutlineThickness(2);
                    dwuMaszt.setOutlineColor(Color::Yellow);
                    r=dwuMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt.setRotation(90);
                        }else{
                            dwuMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==22){
                    dwuMaszt2.setPosition(mysz);
                    dwuMaszt2.setOutlineThickness(2);
                    dwuMaszt2.setOutlineColor(Color::Yellow);
                    r=dwuMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt2.setRotation(90);
                        }else{
                            dwuMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==222){
                    dwuMaszt3.setPosition(mysz);
                    dwuMaszt3.setOutlineThickness(2);
                    dwuMaszt3.setOutlineColor(Color::Yellow);
                    r=dwuMaszt3.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt3.setRotation(90);
                        }else{
                            dwuMaszt3.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==3){
                    trojMaszt.setPosition(mysz);
                    trojMaszt.setOutlineThickness(2);
                    trojMaszt.setOutlineColor(Color::Yellow);
                    r=trojMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            trojMaszt.setRotation(90);
                        }else{
                            trojMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==33){
                    trojMaszt2.setPosition(mysz);
                    trojMaszt2.setOutlineThickness(2);
                    trojMaszt2.setOutlineColor(Color::Yellow);
                    r=trojMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            trojMaszt2.setRotation(90);
                        }else{
                            trojMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==4){
                    czteroMaszt.setPosition(mysz);
                    czteroMaszt.setOutlineThickness(2);
                    czteroMaszt.setOutlineColor(Color::Yellow);
                    r=czteroMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            czteroMaszt.setRotation(90);
                        }else{
                            czteroMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
            }else{
                jednMaszt.setOutlineThickness(0);
                jednMaszt2.setOutlineThickness(0);
                jednMaszt3.setOutlineThickness(0);
                jednMaszt4.setOutlineThickness(0);
                dwuMaszt.setOutlineThickness(0);
                dwuMaszt2.setOutlineThickness(0);
                dwuMaszt3.setOutlineThickness(0);
                trojMaszt.setOutlineThickness(0);
                trojMaszt2.setOutlineThickness(0);
                czteroMaszt.setOutlineThickness(0);
            }
        }
        //RYSOWANIE CZATU//
        okno.draw(Plansza_Czat);
        //RYSOWANIE STATKÓW W DALSZYCH TURACH//
        if(tura!=1){
            int ilosc=0;
            int rzeczywista_ilosc=0;
            if(gracz==1){
                x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                y=RozSry+BokSize+(BokSize/2)+7;
                int i=0;
                int j=0;
                int ii;
                int jj;
                while((i<10) && (y<=RozSry+(BokSize*10)+(BokSize/2)+34)){
                    j=0;
                    x=x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    while((j<10) && (x<=RozSrx-BokSize+((BokSize/2)+1)-43)){
                        ii=i;
                        jj=j;
                        if(Statki_Gracz1[i][j]==1){
                            jednMaszt.setPosition(x,y);
                            okno.draw(jednMaszt);
                        }
                        if(Statki_Gracz1[i][j]==2){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=2){
                                j++;
                                if(Statki_Gracz1[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(0);
                                dwuMaszt.setPosition(x,y);
                                okno.draw(dwuMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=2){
                                i++;
                                if(Statki_Gracz1[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(90);
                                dwuMaszt.setPosition(x,y);
                                okno.draw(dwuMaszt);
                            }
                            i=ii;
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz1[i][j]==3){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=3){
                                j++;
                                if(Statki_Gracz1[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(0);
                                trojMaszt.setPosition(x,y);
                                okno.draw(trojMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=3){
                                i++;
                                if(Statki_Gracz1[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(90);
                                trojMaszt.setPosition(x,y);
                                okno.draw(trojMaszt);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz1[i][j]==4){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=4){
                                j++;
                                if(Statki_Gracz1[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(0);
                                czteroMaszt.setPosition(x,y);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=4){
                                i++;
                                if(Statki_Gracz1[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(90);
                                czteroMaszt.setPosition(x,y);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        j++;
                        x=x+BokSize+3;
                    }
                    i++;
                    y=y+BokSize+3;
                }
            }
            if(gracz==2){
                x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                y=RozSry+BokSize+(BokSize/2)+7;
                int i=0;
                int j=0;
                int ii;
                int jj;
                while(i<10 && y<=RozSry+(BokSize*10)+(BokSize/2)+34){
                    j=0;
                    x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    while(j<10 && x<=RozSrx-BokSize+((BokSize/2)+1)-43){
                        ii=i;
                        jj=j;
                        if(Statki_Gracz2[i][j]==1){
                            jednMaszt.setPosition(x,y);
                            okno.draw(jednMaszt);
                        }
                        if(Statki_Gracz2[i][j]==2){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=2){
                                j++;
                                if(Statki_Gracz2[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(0);
                                dwuMaszt.setPosition(x,y);
                                okno.draw(dwuMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=2){
                                i++;
                                if(Statki_Gracz2[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(90);
                                dwuMaszt.setPosition(x,y);
                                okno.draw(dwuMaszt);
                            }
                            i=ii;
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz2[i][j]==3){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=3){
                                j++;
                                if(Statki_Gracz2[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(0);
                                trojMaszt.setPosition(x,y);
                                okno.draw(trojMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=3){
                                i++;
                                if(Statki_Gracz2[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(90);
                                trojMaszt.setPosition(x,y);
                                okno.draw(trojMaszt);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz2[i][j]==4){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=4){
                                j++;
                                if(Statki_Gracz2[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(0);
                                czteroMaszt.setPosition(x,y);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=4){
                                i++;
                                if(Statki_Gracz2[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(90);
                                czteroMaszt.setPosition(x,y);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        j++;
                        x=x+BokSize+3;
                    }
                    i++;
                    y=y+BokSize+3;
                }
            }
            //RYSOWANIE OBIEKTÓW//
            okno.draw(czteroMaszt);
            //RYSOWANIE PUDEŁ I TRAFIEŃ//
            int i=0;
            int j=0;
            int x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
            int y1=RozSry+BokSize+(BokSize/2)+7;
            int x2=RozSrx+BokSize+(BokSize/2)+47;//815
            if(gracz==1){
                while(i<10 && y1<=RozSry+(BokSize*10)+(BokSize/2)+34){
                    x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    x2=RozSrx+BokSize+(BokSize/2)+47;
                    j=0;
                    while(j<10 && x1<=RozSrx-BokSize+((BokSize/2)+1)-43 && x2<=RozSrx+(BokSize*10)+(BokSize/2)+74){//x2=1301
                        if(Strzaly_Gracz2[i][j]==5){
                            Pudlo.setPosition(x1,y1);
                            okno.draw(Pudlo);
                        }
                        if(Strzaly_Gracz2[i][j]==6){
                            Trafienie.setPosition(x1,y1);
                            okno.draw(Trafienie);
                        }
                        if(Strzaly_Gracz1[i][j]==5){
                            Pudlo.setPosition(x2,y1);
                            okno.draw(Pudlo);
                        }
                        if(Strzaly_Gracz1[i][j]==6){
                            Trafienie.setPosition(x2,y1);
                            okno.draw(Trafienie);
                        }
                        j++;
                        x1=x1+BokSize+3;
                        x2=x2+BokSize+3;
                    }
                    i++;
                    y1=y1+BokSize+3;
                }
            }
            i=0;
            j=0;
            x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
            y1=RozSry+BokSize+(BokSize/2)+7;
            x2=RozSrx+BokSize+(BokSize/2)+47;//815
            if(gracz==2){
                while(i<10 && y1<=RozSry+(BokSize*10)+(BokSize/2)+34){
                    x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    x2=RozSrx+BokSize+(BokSize/2)+47;
                    j=0;
                    while(j<10 && x1<=RozSrx-BokSize+((BokSize/2)+1)-43 && x2<=RozSrx+(BokSize*10)+(BokSize/2)+74){
                        if(Strzaly_Gracz1[i][j]==5){
                            Pudlo.setPosition(x1,y1);
                            okno.draw(Pudlo);
                        }
                        if(Strzaly_Gracz1[i][j]==6){
                            Trafienie.setPosition(x1,y1);
                            okno.draw(Trafienie);
                        }
                        if(Strzaly_Gracz2[i][j]==5){
                            Pudlo.setPosition(x2,y1);
                            okno.draw(Pudlo);
                        }
                        if(Strzaly_Gracz2[i][j]==6){
                            Trafienie.setPosition(x2,y1);
                            okno.draw(Trafienie);
                        }
                        j++;
                        x1=x1+BokSize+3;
                        x2=x2+BokSize+3;
                    }
                    i++;
                    y1=y1+BokSize+3;
                }
            }
            //CZAT//
            if(jaki_strzal==1){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=1;
            }
            if(jaki_strzal==2){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=2;
            }
            if(jaki_strzal==3){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=3;
            }
            jaki_strzal=0;
            k=0;
            l=Plansza_Czat.getPosition().y+(RozCzy*2)+30;//722
            while(k<3 && l>=Plansza_Czat.getPosition().y+10){//668
                if(czat[k]==1){
                    Pudlo_Tekst.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    okno.draw(Pudlo_Tekst);
                }
                if(czat[k]==2){
                    Trafienie_Tekst.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    okno.draw(Trafienie_Tekst);
                }
                if(czat[k]==3){
                    Trafiony_Zatopiony.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    okno.draw(Trafiony_Zatopiony);
                }
                k++;
                l=l-RozCzy-10;//l-47
            }
            //ZASADY I WYGRANA//
            Zasada_Strzaly();
            Wygrana();
            if(gracz==1 && wygrana==1){
                for(int d=0;d<=0;d++){
                    okno.clear(Color::Black);
                }
                okno.draw(Napis_Wygrana_Gracz1);
            }
            if(gracz==2 && wygrana==1){
                for(int d=0;d<=0;d++){
                    okno.clear(Color::Black);
                }
                okno.draw(Napis_Wygrana_Gracz2);
            }
        }
        //NAPIS "TURA" I ZASADA PRZECHODZENIA DO NASTĘPNEJ TURY
        if(wygrana==0){
            if((NastepnaTura.getGlobalBounds().contains(mysz)) && (zasada==0)){
                NastepnaTura.setColor(Color::Red);
                if(przelacz_ture==1){
                    if(tura==1){
                        if(gracz==1){
                            for(int i=0;i<10;i++){
                                for(int j=0;j<10;j++){
                                    if(tab[i][j]==11 || tab[i][j]==111 || tab[i][j]==1111){
                                        tab[i][j]=1;
                                    }
                                    if(tab[i][j]==22 || tab[i][j]==222){
                                        tab[i][j]=2;
                                    }
                                    if(tab[i][j]==33){
                                        tab[i][j]=3;
                                    }
                                    Statki_Gracz1[i][j]=tab[i][j];
                                    Strzaly_Gracz2[i][j]=tab[i][j];
                                }
                            }
                        }
                        if(gracz==2){
                            for(int i=0;i<10;i++){
                                for(int j=0;j<10;j++){
                                    if(tab[i][j]==11 || tab[i][j]==111 || tab[i][j]==1111){
                                        tab[i][j]=1;
                                    }
                                    if(tab[i][j]==22 || tab[i][j]==222){
                                        tab[i][j]=2;
                                    }
                                    if(tab[i][j]==33){
                                        tab[i][j]=3;
                                    }
                                    Statki_Gracz2[i][j]=tab[i][j];
                                    Strzaly_Gracz1[i][j]=tab[i][j];
                                }
                            }
                        }
                    }
                    gracz++;
                    for(int o=0;o<3;o++){
                        czat[o]=0;
                    }
                    l=668;
                    k=0;
                    ilosc_strzalow=0;
                    limit_strzalow=1;
                    jaki_strzal=0;
                    przelacz_ture=0;
                    zasada=1;
                    if(gracz==3){
                        tura++;
                        gracz=1;
                    }
                    if(tura==1 && gracz==2){
                        jednMaszt.setRotation(0);
                        jednMaszt2.setRotation(0);
                        jednMaszt3.setRotation(0);
                        jednMaszt4.setRotation(0);
                        dwuMaszt.setRotation(0);
                        dwuMaszt2.setRotation(0);
                        dwuMaszt3.setRotation(0);
                        trojMaszt.setRotation(0);
                        trojMaszt2.setRotation(0);
                        czteroMaszt.setRotation(0);
                        jednMaszt.setPosition(RozSrx+120,okno.getSize().y/2-(BokSize*2)-60);
                        jednMaszt2.setPosition(RozSrx+BokSize+130,okno.getSize().y/2-(BokSize*2)-60);
                        jednMaszt3.setPosition(RozSrx+(BokSize*2)+140,okno.getSize().y/2-(BokSize*2)-60);
                        jednMaszt4.setPosition(RozSrx+(BokSize*3)+150,okno.getSize().y/2-(BokSize*2)-60);
                        dwuMaszt.setPosition(RozSrx+120,okno.getSize().y/2-BokSize-40);
                        dwuMaszt2.setPosition(RozSrx+(BokSize*2)+130,okno.getSize().y/2-BokSize-40);
                        dwuMaszt3.setPosition(RozSrx+(BokSize*4)+140,okno.getSize().y/2-BokSize-40);
                        trojMaszt.setPosition(RozSrx+120,okno.getSize().y/2-20);
                        trojMaszt2.setPosition(RozSrx+(BokSize*3)+130,okno.getSize().y/2-20);
                        czteroMaszt.setPosition(RozSrx+120,okno.getSize().y/2+BokSize);
                    }
                    OK=0;
                }
            }else{
                NastepnaTura.setColor(Color::White);
            }
        }
        //RYSOWANIE NAPISÓW//
        if(wygrana==0){
            okno.draw(NastepnaTura);
            okno.draw(Tura_Napis);
            okno.draw(Napis_Jaki_Gracz);
            okno.draw(Plansza1);
            okno.draw(Jaki_Numer_Gracza);
            okno.draw(Tura_Numer_Napis);
            if(tura!=1){
                okno.draw(Plansza2);
            }
            if(tura==1){
                //RYSOWANIE OBIEKTÓW//
                okno.draw(jednMaszt);
                okno.draw(jednMaszt2);
                okno.draw(jednMaszt3);
                okno.draw(jednMaszt4);
                okno.draw(dwuMaszt);
                okno.draw(dwuMaszt2);
                okno.draw(dwuMaszt3);
                okno.draw(trojMaszt);
                okno.draw(trojMaszt2);
                okno.draw(czteroMaszt);
            }
        }
    }
        //KONIEC//
        okno.display();
    }
}

void Plansza::graZbotem()
{
    RenderWindow graBot(VideoMode::getDesktopMode(),"Gra z komputerem", Style::None);
    int RozPodx=561;//(1366-80-46-46-36-36)/2
    int RozPody=561;//768-57-150
    int NewRozx=(graBot.getSize().x-244)/2;//(-80-46-46-36-36)
    int NewRozy=graBot.getSize().y-207;//-57-150
    int Rozx=NewRozx-RozPodx;
    int Rozy=NewRozy-RozPody;
    int Roz;
    if(Rozx>Rozy){
        Roz=Rozy;
    }else{
        Roz=Rozx;
    }
    Roz=Roz/11;
    if(Roz!=0){
        if(Roz%2!=0){
            Roz--;
        }
    }
    BokSize=51+Roz;
    RozSrx=graBot.getSize().x/2;
    RozSry=57;
    //TŁO//
    Sprite lel;

    Sprite tlo;
    tlo.setTexture(bg);

    RenderTexture texture;
    texture.create(graBot.getSize().x, graBot.getSize().y);

//STATKI//
    jednMaszt.setSize(Vector2f(BokSize,BokSize));//51,51
    jednMaszt.setTexture(&t);
    jednMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);//26,26

    jednMaszt2.setSize(Vector2f(BokSize,BokSize));
    jednMaszt2.setTexture(&t);
    jednMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt3.setSize(Vector2f(BokSize,BokSize));
    jednMaszt3.setTexture(&t);
    jednMaszt3.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt4.setSize(Vector2f(BokSize,BokSize));
    jednMaszt4.setTexture(&t);
    jednMaszt4.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //DWUMASZTOWCE//
    dwuMaszt.setSize(Vector2f((BokSize*2)+3,BokSize));//105,51
    dwuMaszt.setTexture(&t1);
    dwuMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    dwuMaszt2.setSize(Vector2f((BokSize*2)+3,BokSize));
    dwuMaszt2.setTexture(&t1);
    dwuMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    dwuMaszt3.setSize(Vector2f((BokSize*2)+3,BokSize));
    dwuMaszt3.setTexture(&t1);
    dwuMaszt3.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //TRÓJMASZTOWCE//
    trojMaszt.setSize(Vector2f((BokSize*3)+6,BokSize));//159,51
    trojMaszt.setTexture(&t2);
    trojMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    trojMaszt2.setSize(Vector2f((BokSize*3)+6,BokSize));
    trojMaszt2.setTexture(&t2);
    trojMaszt2.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    //CZTEROMASZTOWIEC//
    czteroMaszt.setSize(Vector2f((BokSize*4)+9,BokSize));//213,51
    czteroMaszt.setTexture(&t3);
    czteroMaszt.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    jednMaszt.setPosition(RozSrx+120,graBot.getSize().y/2-(BokSize*2)-60);
    jednMaszt2.setPosition(RozSrx+BokSize+130,graBot.getSize().y/2-(BokSize*2)-60);
    jednMaszt3.setPosition(RozSrx+(BokSize*2)+140,graBot.getSize().y/2-(BokSize*2)-60);
    jednMaszt4.setPosition(RozSrx+(BokSize*3)+150,graBot.getSize().y/2-(BokSize*2)-60);
    dwuMaszt.setPosition(RozSrx+120,graBot.getSize().y/2-BokSize-40);
    dwuMaszt2.setPosition(RozSrx+(BokSize*2)+130,graBot.getSize().y/2-BokSize-40);
    dwuMaszt3.setPosition(RozSrx+(BokSize*4)+140,graBot.getSize().y/2-BokSize-40);
    trojMaszt.setPosition(RozSrx+120,graBot.getSize().y/2-20);
    trojMaszt2.setPosition(RozSrx+(BokSize*3)+130,graBot.getSize().y/2-20);
    czteroMaszt.setPosition(RozSrx+120,graBot.getSize().y/2+BokSize);
    //KSZTAŁTY//
    Trafienie.setSize(Vector2f(BokSize,BokSize));
    Trafienie.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    Pudlo.setSize(Vector2f(BokSize,BokSize));
    Pudlo.setOrigin((BokSize/2)+1,(BokSize/2)+1);

    LiniaPozioma.setSize(Vector2f((BokSize*11)+33,3));

    LiniaPionowa.setSize(Vector2f(3,(BokSize*11)+36));

    OKK.setSize(Vector2f(BokSize*8,BokSize*4));
    OKK.setOrigin(OKK.getSize().x/2,OKK.getSize().y/2);
    OKK.setPosition(RozSrx,graBot.getSize().y/2);

    Plansza_Czat.setSize(Vector2f((BokSize*11)+30,100));
    Plansza_Czat.setPosition(RozSrx-(BokSize*11)-73,RozSry+(BokSize*11)+46);//41,664

    int RozCzy=Plansza_Czat.getSize().y-40;
    RozCzy=RozCzy/3;
    //TEKSTY//
    NastepnaTura.setCharacterSize((BokSize*2)-40);
    NastepnaTura.setOrigin(NastepnaTura.getGlobalBounds().width/2,NastepnaTura.getGlobalBounds().height/2);
    NastepnaTura.setPosition(RozSrx+(BokSize*5)+(BokSize/2)+59,RozSry+(BokSize*11)+36+NastepnaTura.getCharacterSize());//(okno.getSize().x - NastepnaTura.getGlobalBounds().width*1.43, 658);

    Plansza1.setCharacterSize((BokSize*3)/4);
    Plansza1.setOrigin(Plansza1.getGlobalBounds().width/2,Plansza1.getGlobalBounds().height/2);
    Plansza1.setPosition(RozSrx-(BokSize*6)+((BokSize/2)+1)-58,RozSry-Plansza1.getGlobalBounds().height);

    Plansza2.setCharacterSize((BokSize*3)/4);
    Plansza2.setOrigin(Plansza2.getGlobalBounds().width/2,Plansza2.getGlobalBounds().height/2);
    Plansza2.setPosition(RozSrx+(BokSize*5)+(BokSize/2)+59,RozSry-Plansza1.getGlobalBounds().height);

    Napis_Wygrana_Gracz1.setCharacterSize(BokSize*2);
    Napis_Wygrana_Gracz1.setOrigin(Napis_Wygrana_Gracz1.getGlobalBounds().width/2,Napis_Wygrana_Gracz1.getGlobalBounds().height/2);
    Napis_Wygrana_Gracz1.setPosition(RozSrx,graBot.getSize().y/2);


    Napis_Wygrana_Gracz2.setString(L"WYGRAŁ KOMPUTER");
    Napis_Wygrana_Gracz2.setCharacterSize(BokSize*2);
    Napis_Wygrana_Gracz2.setOrigin(Napis_Wygrana_Gracz2.getGlobalBounds().width/2,Napis_Wygrana_Gracz2.getGlobalBounds().height/2);
    Napis_Wygrana_Gracz2.setPosition(RozSrx,graBot.getSize().y/2);

    Tura_Gracza_1.setCharacterSize(BokSize);
    Tura_Gracza_1.setOrigin(Tura_Gracza_1.getGlobalBounds().width/2,Tura_Gracza_1.getGlobalBounds().height/2);
    Tura_Gracza_1.setPosition(RozSrx,graBot.getSize().y/2-Tura_Gracza_1.getCharacterSize()-10);

    Tura_Gracza_2.setCharacterSize(BokSize);
    Tura_Gracza_2.setOrigin(Tura_Gracza_2.getGlobalBounds().width/2,Tura_Gracza_2.getGlobalBounds().height/2);
    Tura_Gracza_2.setPosition(RozSrx,graBot.getSize().y/2-Tura_Gracza_2.getCharacterSize());

    Przycisk_OK.setCharacterSize(BokSize);
    Przycisk_OK.setOrigin(Przycisk_OK.getGlobalBounds().width/2,Przycisk_OK.getGlobalBounds().height/2);
    Przycisk_OK.setPosition(RozSrx,graBot.getSize().y/2+(Przycisk_OK.getCharacterSize()/2));

    Jaki_Numer_Gracza.setCharacterSize(BokSize/2);
    Jaki_Numer_Gracza.setOrigin(Jaki_Numer_Gracza.getGlobalBounds().width/2,Jaki_Numer_Gracza.getGlobalBounds().height/2);

    Tura_Numer_Napis.setCharacterSize(BokSize/2);
    Tura_Numer_Napis.setOrigin(Tura_Numer_Napis.getGlobalBounds().width/2,Tura_Numer_Napis.getGlobalBounds().height/2);
    Tura_Numer_Napis.setPosition(RozSrx+(Tura_Numer_Napis.getGlobalBounds().width/2)+30,28);

    Napis.setCharacterSize(BokSize-6);

    Cyfry.setCharacterSize(BokSize-6);

    Pudlo_Tekst.setCharacterSize(RozCzy);

    Trafienie_Tekst.setCharacterSize(RozCzy);

    Trafiony_Zatopiony.setCharacterSize(RozCzy);
    //ZMIENNE POMOCNICZE POTRZEBNE DO PRZESUWANIA OBIEKTÓW//
    int i=1;
    int j=0;
    int jaki_maszt;
    int k;
    int l;
    char napis_litery;
    int cyfry_licznik;
    string napis_cyfry1;
    string napis_cyfry2;

    //ZMIENNE POMOCNICZE DO TURY//
    int przelacz_ture=0;
    //PĘTLA//
    Event e;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            BOT.bot[i][j] = 0;
            BOT.strzaly[i][j] = 0;
        }
    BOT.wybUst();

    while(graBot.isOpen())
    {
        Vector2f mysz(Mouse::getPosition(graBot));
        while(graBot.pollEvent(e))
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                graBot.close();
                if(e.type==Event::Closed){
                graBot.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                graBot.close();
            }
            if(tura==1){
                //PRZESUWANIE OBIEKTÓW//
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && (Mouse::isButtonPressed(Mouse::Left)) && (i==1)){
                    i=2;
                    if(jednMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=1;
                    }
                    if(jednMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=11;
                    }
                    if(jednMaszt3.getGlobalBounds().contains(mysz)){
                        jaki_maszt=111;
                    }
                    if(jednMaszt4.getGlobalBounds().contains(mysz)){
                        jaki_maszt=1111;
                    }
                    if(dwuMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=2;
                    }
                    if(dwuMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=22;
                    }
                    if(dwuMaszt3.getGlobalBounds().contains(mysz)){
                        jaki_maszt=222;
                    }
                    if(trojMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=3;
                    }
                    if(trojMaszt2.getGlobalBounds().contains(mysz)){
                        jaki_maszt=33;
                    }
                    if(czteroMaszt.getGlobalBounds().contains(mysz)){
                        jaki_maszt=4;
                    }
                }
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && (Mouse::isButtonPressed(Mouse::Left)) && (j==1)){
                    i=1;
                    j=0;
                }
                if(((jednMaszt.getGlobalBounds().contains(mysz)) || (jednMaszt2.getGlobalBounds().contains(mysz)) || (jednMaszt3.getGlobalBounds().contains(mysz)) || (jednMaszt4.getGlobalBounds().contains(mysz)) || (dwuMaszt.getGlobalBounds().contains(mysz)) || (dwuMaszt2.getGlobalBounds().contains(mysz)) || (dwuMaszt3.getGlobalBounds().contains(mysz)) || (trojMaszt.getGlobalBounds().contains(mysz)) || (trojMaszt2.getGlobalBounds().contains(mysz)) || (czteroMaszt.getGlobalBounds().contains(mysz))) && ((e.type==Event::MouseButtonReleased && e.mouseButton.button==Mouse::Left)) && (i==2)){
                    i=2;
                    j=1;
                }
                //OBRACANIE//
                if(Mouse::isButtonPressed(Mouse::Right) && i==2){
                    obrot=1;
                }
            }
            if(tura!=1 && wygrana==0){
                if(Mouse::isButtonPressed(Mouse::Left) && ((Mouse::getPosition().x>=RozSrx+BokSize+46) && (Mouse::getPosition().x<=RozSrx+(BokSize*11)+76)) && ((Mouse::getPosition().y>=RozSry+BokSize+6) && (Mouse::getPosition().y<=RozSry+(BokSize*11)+36))){//x(2)1329//y(2)649
                    Strzal();
                }
            }
                if((NastepnaTura.getGlobalBounds().contains(mysz)) && (Mouse::isButtonPressed(Mouse::Left)) && (zasada==0)){
                    przelacz_ture=1;
                }
                if(Przycisk_OK.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left)){
                    OK=1;
                }
            if(Napis_Wygrana_Gracz1.getGlobalBounds().contains(mysz)){
                Napis_Wygrana_Gracz1.setColor(Color::Red);
            }else{
                Napis_Wygrana_Gracz1.setColor(Color::White);
            }
            if(Napis_Wygrana_Gracz1.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left) && wygrana==1){
                graBot.close();
            }
            if(Napis_Wygrana_Gracz2.getGlobalBounds().contains(mysz)){
                Napis_Wygrana_Gracz2.setColor(Color::Red);
            }else{
                Napis_Wygrana_Gracz2.setColor(Color::White);
            }
            if(Napis_Wygrana_Gracz2.getGlobalBounds().contains(mysz) && Mouse::isButtonPressed(Mouse::Left) && wygrana==1){
                graBot.close();
            }

        }
    if(OK==0){
        for(int d=0;d==0;d++){
            graBot.clear(Color::Black);
        }
        if(Przycisk_OK.getGlobalBounds().contains(mysz)){
            Przycisk_OK.setColor(Color::Red);
        }else{
            Przycisk_OK.setColor(Color::White);
        }
        przelacz_ture=0;
        graBot.draw(OKK);
        graBot.draw(Przycisk_OK);
        if(gracz==1){
            graBot.draw(Tura_Gracza_1);
        }
    }else{
        if(tura==1){
            tablica();
            dopasowanie();
            uzupelnienie_tablicy();
            zasady();
        }
        Tura();
        Jaki_Gracz();
        Jaki_Numer_Gracza.setPosition(RozSrx-Napis_Jaki_Gracz.getGlobalBounds().width-(Jaki_Numer_Gracza.getGlobalBounds().width/2)-10,28);
        //WYZNACZANIE LINII PÓL//
    graBot.setVerticalSyncEnabled(true);
    texture.clear();
    texture.draw(tlo);
    texture.display();
    graBot.clear();
    lel.setTexture(texture.getTexture());
    graBot.draw(lel);
        /*for(int y=52;y<=646;y=y+54){
            LiniaPozioma.setPosition(37,y);
            graBot.draw(LiniaPozioma);
                if(tura!=1){
                LiniaPozioma.setPosition(732,y);
                graBot.draw(LiniaPozioma);
            }
        }
        for(int x=37;x<=631;x=x+54){
            LiniaPionowa.setPosition(x,52);
            graBot.draw(LiniaPionowa);
        }
        if(tura!=1){
            for(int x=732;x<=1326;x=x+54){
                LiniaPionowa.setPosition(x,52);
                graBot.draw(LiniaPionowa);
            }
        }*/
        for(int y=57;y<=((BokSize*11)+93);y=(y+(BokSize+3))){
            LiniaPozioma.setPosition((((graBot.getSize().x/2)-(BokSize*11))-73),y);
            graBot.draw(LiniaPozioma);
                if(tura!=1){
                LiniaPozioma.setPosition(((graBot.getSize().x/2)+40),y);
                graBot.draw(LiniaPozioma);
            }
        }
        for(int x=(((graBot.getSize().x/2)-(BokSize*11))-76);x<=((graBot.getSize().x/2)-43);x=(x+(BokSize+3))){
            LiniaPionowa.setPosition(x,57);
            graBot.draw(LiniaPionowa);
        }
        if(tura!=1){
            for(int x=((graBot.getSize().x/2)+40);x<=(((graBot.getSize().x/2)+(BokSize*11))+76);x=(x+(BokSize+3))){
                LiniaPionowa.setPosition(x,57);
                graBot.draw(LiniaPionowa);
            }
        }
        napis_litery=65;
        for(int u=RozSry+BokSize+(BokSize/2)+7;u<=RozSry+(BokSize*10)+(BokSize/2)+34;u=u+BokSize+3){//112;598;54
            Napis.setString(napis_litery);
            Napis.setOrigin(Napis.getGlobalBounds().width/2,Napis.getCharacterSize()/2);
            Napis.setPosition(RozSrx-(BokSize*11)+((BokSize/2)+1)-73,u);
            graBot.draw(Napis);
            if(tura!=1){
                Napis.setPosition(RozSrx+(BokSize/2)+44,u);
                graBot.draw(Napis);
            }
            napis_litery++;
        }
        cyfry_licznik=1;
        for(int u=RozSrx-(BokSize*10)+((BokSize/2)+1)-73;u<=RozSrx-BokSize+((BokSize/2)+1)-43;u=u+BokSize+3){//95;581;54
            itoa(cyfry_licznik, (char*)napis_cyfry1.c_str(), 10);
            napis_cyfry2 = napis_cyfry1.c_str();
            Cyfry.setString(napis_cyfry2);
            Cyfry.setOrigin(Cyfry.getGlobalBounds().width/2,Cyfry.getGlobalBounds().height/2);
            Cyfry.setPosition(u,RozSry+BokSize/2-3);
            graBot.draw(Cyfry);
            cyfry_licznik++;
        }
            if(tura!=1){
                cyfry_licznik=1;
                for(int u=RozSrx+BokSize+BokSize/2+47;u<=RozSrx+(BokSize*10)+(BokSize/2)+74;u=u+BokSize+3){
                    itoa(cyfry_licznik, (char*)napis_cyfry1.c_str(), 10);
                    napis_cyfry2 = napis_cyfry1.c_str();
                    Cyfry.setString(napis_cyfry2);
                    Cyfry.setOrigin(Cyfry.getGlobalBounds().width/2,Cyfry.getGlobalBounds().height/2);
                    Cyfry.setPosition(u-3,RozSry+BokSize/2-3);
                    graBot.draw(Cyfry);
                    cyfry_licznik++;
                }
            }
        if(tura==1){
            //PRZESUWANIE I OBRACANIE OBIEKTÓW//
            int r;
            if(i==2){
                if(jaki_maszt==1){
                    jednMaszt.setPosition(mysz);
                    jednMaszt.setOutlineThickness(2);
                    jednMaszt.setOutlineColor(Color::Yellow);
                    r=jednMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt.setRotation(90);
                        }else{
                            jednMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==11){
                    jednMaszt2.setPosition(mysz);
                    jednMaszt2.setOutlineThickness(2);
                    jednMaszt2.setOutlineColor(Color::Yellow);
                    r=jednMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt2.setRotation(90);
                        }else{
                            jednMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==111){
                    jednMaszt3.setPosition(mysz);
                    jednMaszt3.setOutlineThickness(2);
                    jednMaszt3.setOutlineColor(Color::Yellow);
                    r=jednMaszt3.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt3.setRotation(90);
                        }else{
                            jednMaszt3.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==1111){
                    jednMaszt4.setPosition(mysz);
                    jednMaszt4.setOutlineThickness(2);
                    jednMaszt4.setOutlineColor(Color::Yellow);
                    r=jednMaszt4.getRotation();
                    if(obrot==1){
                        if(r==0){
                            jednMaszt4.setRotation(90);
                        }else{
                            jednMaszt4.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==2){
                    dwuMaszt.setPosition(mysz);
                    dwuMaszt.setOutlineThickness(2);
                    dwuMaszt.setOutlineColor(Color::Yellow);
                    r=dwuMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt.setRotation(90);
                        }else{
                            dwuMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==22){
                    dwuMaszt2.setPosition(mysz);
                    dwuMaszt2.setOutlineThickness(2);
                    dwuMaszt2.setOutlineColor(Color::Yellow);
                    r=dwuMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt2.setRotation(90);
                        }else{
                            dwuMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==222){
                    dwuMaszt3.setPosition(mysz);
                    dwuMaszt3.setOutlineThickness(2);
                    dwuMaszt3.setOutlineColor(Color::Yellow);
                    r=dwuMaszt3.getRotation();
                    if(obrot==1){
                        if(r==0){
                            dwuMaszt3.setRotation(90);
                        }else{
                            dwuMaszt3.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==3){
                    trojMaszt.setPosition(mysz);
                    trojMaszt.setOutlineThickness(2);
                    trojMaszt.setOutlineColor(Color::Yellow);
                    r=trojMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            trojMaszt.setRotation(90);
                        }else{
                            trojMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==33){
                    trojMaszt2.setPosition(mysz);
                    trojMaszt2.setOutlineThickness(2);
                    trojMaszt2.setOutlineColor(Color::Yellow);
                    r=trojMaszt2.getRotation();
                    if(obrot==1){
                        if(r==0){
                            trojMaszt2.setRotation(90);
                        }else{
                            trojMaszt2.setRotation(0);
                        }
                        obrot=0;
                    }
                }
                if(jaki_maszt==4){
                    czteroMaszt.setPosition(mysz);
                    czteroMaszt.setOutlineThickness(2);
                    czteroMaszt.setOutlineColor(Color::Yellow);
                    r=czteroMaszt.getRotation();
                    if(obrot==1){
                        if(r==0){
                            czteroMaszt.setRotation(90);
                        }else{
                            czteroMaszt.setRotation(0);
                        }
                        obrot=0;
                    }
                }
            }else{
                jednMaszt.setOutlineThickness(0);
                jednMaszt2.setOutlineThickness(0);
                jednMaszt3.setOutlineThickness(0);
                jednMaszt4.setOutlineThickness(0);
                dwuMaszt.setOutlineThickness(0);
                dwuMaszt2.setOutlineThickness(0);
                dwuMaszt3.setOutlineThickness(0);
                trojMaszt.setOutlineThickness(0);
                trojMaszt2.setOutlineThickness(0);
                czteroMaszt.setOutlineThickness(0);
            }
        }
        graBot.draw(Plansza_Czat);
        if(tura!=1){
            int ilosc=0;
            int rzeczywista_ilosc=0;
            if(gracz==1){
                x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                y=RozSry+BokSize+(BokSize/2)+7;
                int i=0;
                int j=0;
                int ii;
                int jj;
                while((i<10) && (y<=RozSry+(BokSize*10)+(BokSize/2)+34)){
                    j=0;
                    x=x=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    while((j<10) && (x<=RozSrx-BokSize+((BokSize/2)+1)-43)){
                        ii=i;
                        jj=j;
                        if(Statki_Gracz1[i][j]==1){
                            jednMaszt.setPosition(x,y);
                            graBot.draw(jednMaszt);
                        }
                        if(Statki_Gracz1[i][j]==2){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=2){
                                j++;
                                if(Statki_Gracz1[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(0);
                                dwuMaszt.setPosition(x,y);
                                graBot.draw(dwuMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=2){
                                i++;
                                if(Statki_Gracz1[i][j]==2){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            if(rzeczywista_ilosc==2){
                                dwuMaszt.setRotation(90);
                                dwuMaszt.setPosition(x,y);
                                graBot.draw(dwuMaszt);
                            }
                            i=ii;
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz1[i][j]==3){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=3){
                                j++;
                                if(Statki_Gracz1[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(0);
                                trojMaszt.setPosition(x,y);
                                graBot.draw(trojMaszt);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=3){
                                i++;
                                if(Statki_Gracz1[i][j]==3){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==3){
                                trojMaszt.setRotation(90);
                                trojMaszt.setPosition(x,y);
                                graBot.draw(trojMaszt);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        if(Statki_Gracz1[i][j]==4){
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(j<10 && ilosc!=4){
                                j++;
                                if(Statki_Gracz1[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            j=jj;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(0);
                                czteroMaszt.setPosition(x,y);
                            }
                            ilosc=1;
                            rzeczywista_ilosc=1;
                            while(i<10 && ilosc!=4){
                                i++;
                                if(Statki_Gracz1[i][j]==4){
                                    rzeczywista_ilosc++;
                                }
                                ilosc++;
                            }
                            i=ii;
                            if(rzeczywista_ilosc==4){
                                czteroMaszt.setRotation(90);
                                czteroMaszt.setPosition(x,y);
                            }
                        }
                        ilosc=0;
                        rzeczywista_ilosc=0;
                        j++;
                        x=x+BokSize+3;
                    }
                    i++;
                    y=y+BokSize+3;
                }
            }
            //RYSOWANIE OBIEKTÓW//
            graBot.draw(czteroMaszt);
            int i=0;
            int j=0;
            int x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
            int y1=RozSry+BokSize+(BokSize/2)+7;
            int x2=RozSrx+BokSize+(BokSize/2)+47;//815
            if(gracz==1){
                while(i<10 && y1<=RozSry+(BokSize*10)+(BokSize/2)+34){
                    x1=RozSrx-(BokSize*10)+((BokSize/2)+1)-70;
                    x2=RozSrx+BokSize+(BokSize/2)+47;
                    j=0;
                    while(j<10 && x1<=RozSrx-BokSize+((BokSize/2)+1)-43 && x2<=RozSrx+(BokSize*10)+(BokSize/2)+74){//x2=1301
                        if(BOT.strzaly[i][j]==5){
                            Pudlo.setPosition(x1,y1);
                            graBot.draw(Pudlo);
                        }
                        if(BOT.strzaly[i][j]==6){
                            Trafienie.setPosition(x1,y1);
                            graBot.draw(Trafienie);
                        }
                        if(Strzaly_Gracz1[i][j]==5){
                            Pudlo.setPosition(x2,y1);
                            graBot.draw(Pudlo);
                        }
                        if(Strzaly_Gracz1[i][j]==6){
                            Trafienie.setPosition(x2,y1);
                            graBot.draw(Trafienie);
                        }
                        j++;
                        x1=x1+BokSize+3;
                        x2=x2+BokSize+3;
                    }
                    i++;
                    y1=y1+BokSize+3;
                }
            }
            if(jaki_strzal==1){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=1;
            }
            if(jaki_strzal==2){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=2;
            }
            if(jaki_strzal==3){
                czat[2]=czat[1];
                czat[1]=czat[0];
                czat[0]=3;
            }
            jaki_strzal=0;
            k=0;
            l=Plansza_Czat.getPosition().y+(RozCzy*2)+30;//722
            while(k<3 && l>=Plansza_Czat.getPosition().y+10){//668
                if(czat[k]==1){
                    Pudlo_Tekst.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    graBot.draw(Pudlo_Tekst);
                }
                if(czat[k]==2){
                    Trafienie_Tekst.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    graBot.draw(Trafienie_Tekst);
                }
                if(czat[k]==3){
                    Trafiony_Zatopiony.setPosition(RozSrx-(BokSize*11)+(BokSize/2)-76,l);//46
                    graBot.draw(Trafiony_Zatopiony);
                }
                k++;
                l=l-RozCzy-10;//l-47
            }
            Zasada_Strzaly();
            Wygrana();
            if(gracz==1 && wygrana==1 && sprawdzWygr() == false){
                for(int d=0;d<=0;d++){
                    graBot.clear(Color::Black);
                }
                graBot.draw(Napis_Wygrana_Gracz1);
            }
            sprawdzWygr();
            gracz++;
            if(gracz==2 && wygrana==1 && sprawdzWygr() == true){
                for(int d=0;d<=0;d++){
                    graBot.clear(Color::Black);
                }
                graBot.draw(Napis_Wygrana_Gracz2);
            }
            gracz = 1;
        }
        //NAPIS "TURA" I ZASADA PRZECHODZENIA DO NASTĘPNEJ TURY
        if(wygrana==0){
            if((NastepnaTura.getGlobalBounds().contains(mysz)) && (zasada==0)){
                NastepnaTura.setColor(Color::Red);
                if(przelacz_ture==1){
                    if(tura==1){
                        if(gracz==1){
                            for(int i=0;i<10;i++){
                                for(int j=0;j<10;j++){
                                    if(tab[i][j]==11 || tab[i][j]==111 || tab[i][j]==1111){
                                        tab[i][j]=1;
                                    }
                                    if(tab[i][j]==22 || tab[i][j]==222){
                                        tab[i][j]=2;
                                    }
                                    if(tab[i][j]==33){
                                        tab[i][j]=3;
                                    }
                                    Statki_Gracz1[i][j]=tab[i][j];
                                }
                            }
                        }
                        if(gracz==1){
                            for(int i=0;i<10;i++){
                                for(int j=0;j<10;j++){
                                    Strzaly_Gracz1[i][j]=BOT.bot[i][j];
                                    BOT.strzaly[i][j] = Statki_Gracz1[i][j];
                                }
                            }
                        }
                    }
                    gracz++;
                    tura++;
                    for(int o=0;o<3;o++){
                        czat[o]=0;
                    }
                    l=668;
                    k=0;
                    ilosc_strzalow=0;
                    limit_strzalow=1;
                    jaki_strzal=0;
                    przelacz_ture=0;
                    OK=0;
                    zasada=1;
                }
            }else{
                NastepnaTura.setColor(Color::White);
                przelacz_ture=0;
            }
            if(gracz == 2 && wygrana==0)
            {
                if(tura != 2)
                    BOT.botStrz();
                gracz++;
                if(gracz == 3){
                    gracz = 1;
                }
            }
        }
        if(wygrana==0){
            //RYSOWANIE NAPISÓW//
            graBot.draw(NastepnaTura);
            graBot.draw(Tura_Napis);
            graBot.draw(Napis_Jaki_Gracz);
            graBot.draw(Plansza1);
            graBot.draw(Jaki_Numer_Gracza);
            graBot.draw(Tura_Numer_Napis);
            if(tura!=1){
                graBot.draw(Plansza2);
            }
            if(tura==1){
                //RYSOWANIE OBIEKTÓW//
                graBot.draw(jednMaszt);
                graBot.draw(jednMaszt2);
                graBot.draw(jednMaszt3);
                graBot.draw(jednMaszt4);
                graBot.draw(dwuMaszt);
                graBot.draw(dwuMaszt2);
                graBot.draw(dwuMaszt3);
                graBot.draw(trojMaszt);
                graBot.draw(trojMaszt2);
                graBot.draw(czteroMaszt);
            }
        }
    }
    graBot.display();
    }
}
