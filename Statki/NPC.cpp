#include <SFML/Graphics.hpp>
#include "NPC.hpp"
#include "Plansza.hpp"

Plansza pole;

bool Komputer::sprawdz(int k, int l)
{
    if(k - 1 > 0 && k + 1 < 10 && l - 1 > 0 && l + 1 < 10)
        if(bot[k - 1][l] == 0 && bot[k - 1][l - 1] == 0 && bot[k][l - 1] == 0 && bot[k + 1][l - 1] == 0 && bot[k + 1][l] == 0 && bot[k + 1][l + 1] == 0 && bot[k][l + 1] == 0 && bot[k - 1][l + 1] == 0)
            return true;
    if(k - 1 < 0 && l - 1 < 0)
        if(bot[k + 1][l] == 0 && bot[k + 1][l + 1] == 0 && bot[k][l + 1] == 0)
            return true;
    if(k - 1 < 0 && l + 1 > 10)
        if(bot[k][l - 1] == 0 && bot[k + 1][l - 1] == 0 && bot[k + 1][l] == 0)
            return true;
    if(k + 1 > 10 && l + 1 > 10)
        if(bot[k - 1][l] == 0 && bot[k - 1][l - 1] == 0 && bot[k][l - 1] == 0)
            return true;
    if(k + 1 > 10 && l - 1 < 0)
        if(bot[k - 1][l] == 0 && bot[k][l + 1] == 0 && bot[k - 1][l + 1] == 0)
            return true;
    if(k - 1 < 0)
        if(bot[k][l - 1] == 0 && bot[k + 1][l - 1] == 0 && bot[k + 1][l] == 0 && bot[k + 1][l + 1] == 0 && bot[k][l + 1] == 0)
            return true;
    if(k + 1 > 10)
        if(bot[k - 1][l] == 0 && bot[k - 1][l - 1] == 0 && bot[k][l - 1] == 0 && bot[k][l + 1] == 0 && bot[k - 1][l + 1] == 0)
            return true;
    if(l - 1 < 0)
        if(bot[k - 1][l] == 0 && bot[k + 1][l] == 0 && bot[k + 1][l + 1] == 0 && bot[k][l + 1] == 0 && bot[k - 1][l + 1] == 0)
            return true;
    if(l + 1 > 10)
        if(bot[k - 1][l] == 0 && bot[k - 1][l - 1] == 0 && bot[k][l - 1] == 0 && bot[k + 1][l - 1] == 0 && bot[k + 1][l] == 0)
            return true;
    return false;
}

void Komputer::wybUst()
{
    int k, l, m = 10;
    while(m > 0)
    {
        k = (rand() % 10) + 0;
        l = (rand() % 10) + 0;
        if(bot[k][l] == 0)
        {
            if(m < 5)
                if(sprawdz(k, l) == true)
                {
                    bot[k][l] = 1;
                    m--;
                    continue;
                }
            if(m < 8)
            {
                if(sprawdz(k, l) == true)
                {
                    if(k - 1 >= 0)
                    {
                        if(sprawdz(k - 1, l) == true)
                        {
                            bot[k][l] = 2;
                            bot[k - 1][l] = 2;
                            m--;
                            continue;
                        }
                        else
                        {
                            if(l + 1 < 10)
                            {
                                if(sprawdz(k, l + 1) == true)
                                {
                                    bot[k][l] = 2;
                                    bot[k][l + 1] = 2;
                                    m--;
                                    continue;
                                }
                                else
                                {
                                    if(k + 1 < 10)
                                    {
                                        if(sprawdz(k + 1, l) == true)
                                        {
                                            bot[k][l] = 2;
                                            bot[k + 1][l] = 2;
                                            m--;
                                            continue;
                                        }
                                        else
                                            if(l - 1 > 0)
                                                if(sprawdz(k, l - 1) == true)
                                                {
                                                    bot[k][l] = 2;
                                                    bot[k][l - 1] = 2;
                                                    m--;
                                                    continue;
                                                }
                                    }
                                    else
                                    {
                                        if(l - 1 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                            {
                                                bot[k][l] = 2;
                                                bot[k][l - 1] = 2;
                                                m--;
                                                continue;
                                            }
                                    }
                                }
                            }
                            else
                            {
                                if(k + 1 < 10)
                                {
                                    if(sprawdz(k + 1, l) == true)
                                    {
                                        bot[k][l] = 2;
                                        bot[k + 1][l] = 2;
                                        m--;
                                        continue;
                                    }
                                    else
                                        if(l - 1 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                            {
                                                bot[k][l] = 2;
                                                bot[k][l - 1] = 2;
                                                m--;
                                                continue;
                                            }
                                }
                                else
                                {
                                    if(l - 1 >= 0)
                                        if(sprawdz(k, l - 1) == true)
                                        {
                                            bot[k][l] = 2;
                                            bot[k][l - 1] = 2;
                                            m--;
                                            continue;
                                        }
                                }
                            }
                        }
                    }
                    else
                    {
                        if(l + 1 < 10)
                        {
                            if(sprawdz(k, l + 1) == true)
                            {
                                bot[k][l] = 2;
                                bot[k][l + 1] = 2;
                                m--;
                                continue;
                            }
                            else
                            {
                                if(k + 1 < 10)
                                {
                                    if(sprawdz(k + 1, l) == true)
                                    {
                                        bot[k][l] = 2;
                                        bot[k + 1][l] = 2;
                                        m--;
                                        continue;
                                    }
                                    else
                                        if(l - 1 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                            {
                                                bot[k][l] = 2;
                                                bot[k][l - 1] = 2;
                                                m--;
                                                continue;
                                            }
                                }
                                else
                                {
                                    if(l - 1 >= 0)
                                        if(sprawdz(k, l - 1) == true)
                                        {
                                            bot[k][l] = 2;
                                            bot[k][l - 1] = 2;
                                            m--;
                                            continue;
                                        }
                                }
                            }
                        }
                        else
                        {
                            if(k + 1 < 10)
                            {
                                if(sprawdz(k + 1, l) == true)
                                {
                                    bot[k][l] = 2;
                                    bot[k + 1][l] = 2;
                                    m--;
                                    continue;
                                }
                                else
                                    if(l - 1 >= 0)
                                        if(sprawdz(k, l - 1) == true)
                                        {
                                            bot[k][l] = 2;
                                            bot[k][l - 1] = 2;
                                            m--;
                                            continue;
                                        }
                            }
                            else
                            {
                                if(l - 1 >= 0)
                                    if(sprawdz(k, l - 1) == true)
                                    {
                                        bot[k][l] = 2;
                                        bot[k][l - 1] = 2;
                                        m--;
                                        continue;
                                    }
                            }
                        }
                    }
                }
            }
            if(m < 10)
            {
                if(sprawdz(k, l) == true)
                {
                    if(k - 2 >= 0)
                    {
                        if(sprawdz(k - 1, l) == true)
                        {
                            if(sprawdz(k - 2, l) == true)
                            {
                                bot[k][l] = 3;
                                bot[k - 1][l] = 3;
                                bot[k - 2][l] = 3;
                                m--;
                                continue;
                            }
                            else
                            {
                                if(l + 2 < 10)
                                {
                                    if(sprawdz(k, l + 1) == true)
                                    {
                                        if(sprawdz(k, l + 2) == true)
                                        {
                                            bot[k][l] = 3;
                                            bot[k][l + 1] = 3;
                                            bot[k][l + 2] = 3;
                                            m--;
                                            continue;
                                        }
                                        else
                                        {
                                            if(k + 2 < 10)
                                            {
                                                if(sprawdz(k + 1, l) == true)
                                                {
                                                    if(sprawdz(k + 2, l) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k + 1][l] = 3;
                                                        bot[k + 2][l] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                                    else
                                                    {
                                                        if(l - 2 >= 0)
                                                            if(sprawdz(k, l - 1) == true)
                                                                if(sprawdz(k, l - 2) == true)
                                                                {
                                                                    bot[k][l] = 3;
                                                                    bot[k][l - 1] = 3;
                                                                    bot[k][l - 2] = 3;
                                                                    m--;
                                                                    continue;
                                                                }
                                                    }
                                                }
                                                else
                                                {
                                                    if(l - 2 >= 0)
                                                        if(sprawdz(k, l - 1) == true)
                                                            if(sprawdz(k, l - 2) == true)
                                                            {
                                                                bot[k][l] = 3;
                                                                bot[k][l - 1] = 3;
                                                                bot[k][l - 2] = 3;
                                                                m--;
                                                                continue;
                                                            }
                                                }
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                        if(sprawdz(k, l - 1) == true)
                                                            if(sprawdz(k, l - 2) == true)
                                                            {
                                                                bot[k][l] = 3;
                                                                bot[k][l - 1] = 3;
                                                                bot[k][l - 2] = 3;
                                                                m--;
                                                                continue;
                                                            }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(k + 2 < 10)
                                        {
                                            if(sprawdz(k + 1, l) == true)
                                            {
                                                if(sprawdz(k + 2, l) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k + 1][l] = 3;
                                                    bot[k + 2][l] = 3;
                                                    m--;
                                                    continue;
                                                }
                                                else
                                                {
                                                    if(l - 2 >= 0)
                                                        if(sprawdz(k, l - 1) == true)
                                                            if(sprawdz(k, l - 2) == true)
                                                            {
                                                                bot[k][l] = 3;
                                                                bot[k][l - 1] = 3;
                                                                bot[k][l - 2] = 3;
                                                                m--;
                                                                continue;
                                                            }
                                                }
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                        }
                                    }
                                }
                                else
                                {
                                    if(k + 2 < 10)
                                        {
                                            if(sprawdz(k + 1, l) == true)
                                            {
                                                if(sprawdz(k + 2, l) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k + 1][l] = 3;
                                                    bot[k + 2][l] = 3;
                                                    m--;
                                                    continue;
                                                }
                                                else
                                                {
                                                    if(l - 2 >= 0)
                                                        if(sprawdz(k, l - 1) == true)
                                                            if(sprawdz(k, l - 2) == true)
                                                            {
                                                                bot[k][l] = 3;
                                                                bot[k][l - 1] = 3;
                                                                bot[k][l - 2] = 3;
                                                                m--;
                                                                continue;
                                                            }
                                                }
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                if(sprawdz(k, l - 1) == true)
                                                    if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                        }
                                }
                            }
                        }
                        else
                        {
                            if(l + 2 < 10)
                            {
                                if(sprawdz(k, l + 1) == true)
                                {
                                    if(sprawdz(k, l + 2) == true)
                                    {
                                        bot[k][l] = 3;
                                        bot[k][l + 1] = 3;
                                        bot[k][l + 2] = 3;
                                        m--;
                                        continue;
                                    }
                                    else
                                    {
                                        if(k + 2 < 10)
                                        {
                                            if(sprawdz(k + 1, l) == true)
                                            {
                                                if(sprawdz(k + 2, l) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k + 1][l] = 3;
                                                    bot[k + 2][l] = 3;
                                                    m--;
                                                    continue;
                                                }
                                                else
                                                {
                                                    if(l - 2 >= 0)
                                                        if(sprawdz(k, l - 1) == true)
                                                            if(sprawdz(k, l - 2) == true)
                                                            {
                                                                bot[k][l] = 3;
                                                                bot[k][l - 1] = 3;
                                                                bot[k][l - 2] = 3;
                                                                m--;
                                                                continue;
                                                            }
                                                }
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                        }
                                    }
                                }
                                else
                                {
                                    if(k + 2 < 10)
                                    {
                                        if(sprawdz(k + 1, l) == true)
                                        {
                                            if(sprawdz(k + 2, l) == true)
                                            {
                                                bot[k][l] = 3;
                                                bot[k + 1][l] = 3;
                                                bot[k + 2][l] = 3;
                                                m--;
                                                continue;
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                if(sprawdz(k, l - 1) == true)
                                                    if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                        }
                                    }
                                    else
                                    {
                                        if(l - 2 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                                if(sprawdz(k, l - 2) == true)
                                                {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                }
                                    }
                                }
                            }
                            else
                            {
                                if(k + 2 < 10)
                                    {
                                        if(sprawdz(k + 1, l) == true)
                                        {
                                            if(sprawdz(k + 2, l) == true)
                                            {
                                                bot[k][l] = 3;
                                                bot[k + 1][l] = 3;
                                                bot[k + 2][l] = 3;
                                                m--;
                                                continue;
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                if(sprawdz(k, l - 1) == true)
                                                    if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                        }
                                    }
                                    else
                                    {
                                        if(l - 2 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                                if(sprawdz(k, l - 2) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k][l - 1] = 3;
                                                    bot[k][l - 2] = 3;
                                                    m--;
                                                    continue;
                                                }
                                    }
                            }
                        }
                    }
                    else
                    {
                        if(l + 2 < 10)
                        {
                            if(sprawdz(k, l + 1) == true)
                            {
                                if(sprawdz(k, l + 2) == true)
                                {
                                    bot[k][l] = 3;
                                    bot[k][l + 1] = 3;
                                    bot[k][l + 2] = 3;
                                    m--;
                                    continue;
                                }
                                else
                                {
                                    if(k + 2 < 10)
                                    {
                                        if(sprawdz(k + 1, l) == true)
                                        {
                                            if(sprawdz(k + 2, l) == true)
                                            {
                                                bot[k][l] = 3;
                                                bot[k + 1][l] = 3;
                                                bot[k + 2][l] = 3;
                                                m--;
                                                continue;
                                            }
                                            else
                                            {
                                                if(l - 2 >= 0)
                                                    if(sprawdz(k, l - 1) == true)
                                                        if(sprawdz(k, l - 2) == true)
                                                        {
                                                            bot[k][l] = 3;
                                                            bot[k][l - 1] = 3;
                                                            bot[k][l - 2] = 3;
                                                            m--;
                                                            continue;
                                                        }
                                            }
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                if(sprawdz(k, l - 1) == true)
                                                    if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                        }
                                    }
                                    else
                                    {
                                        if(l - 2 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                                if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                    }
                                }
                            }
                            else
                            {
                                if(k + 2 < 10)
                                {
                                    if(sprawdz(k + 1, l) == true)
                                    {
                                        if(sprawdz(k + 2, l) == true)
                                        {
                                            bot[k][l] = 3;
                                            bot[k + 1][l] = 3;
                                            bot[k + 2][l] = 3;
                                            m--;
                                            continue;
                                        }
                                        else
                                        {
                                            if(l - 2 >= 0)
                                                if(sprawdz(k, l - 1) == true)
                                                    if(sprawdz(k, l - 2) == true)
                                                    {
                                                        bot[k][l] = 3;
                                                        bot[k][l - 1] = 3;
                                                        bot[k][l - 2] = 3;
                                                        m--;
                                                        continue;
                                                    }
                                        }
                                    }
                                    else
                                    {
                                        if(l - 2 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                                if(sprawdz(k, l - 2) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k][l - 1] = 3;
                                                    bot[k][l - 2] = 3;
                                                    m--;
                                                    continue;
                                                }
                                    }
                                }
                                else
                                {
                                    if(l - 2 >= 0)
                                        if(sprawdz(k, l - 1) == true)
                                            if(sprawdz(k, l - 2) == true)
                                            {
                                                bot[k][l] = 3;
                                                bot[k][l - 1] = 3;
                                                bot[k][l - 2] = 3;
                                                m--;
                                                continue;
                                            }
                                }
                            }
                        }
                        else
                        {
                            if(k + 2 < 10)
                            {
                                if(sprawdz(k + 1, l) == true)
                                {
                                    if(sprawdz(k + 2, l) == true)
                                    {
                                        bot[k][l] = 3;
                                        bot[k + 1][l] = 3;
                                        bot[k + 2][l] = 3;
                                        m--;
                                        continue;
                                    }
                                    else
                                    {
                                        if(l - 2 >= 0)
                                            if(sprawdz(k, l - 1) == true)
                                                if(sprawdz(k, l - 2) == true)
                                                {
                                                    bot[k][l] = 3;
                                                    bot[k][l - 1] = 3;
                                                    bot[k][l - 2] = 3;
                                                    m--;
                                                    continue;
                                                }
                                    }
                                }
                                else
                                {
                                    if(l - 2 >= 0)
                                        if(sprawdz(k, l - 1) == true)
                                            if(sprawdz(k, l - 2) == true)
                                            {
                                                bot[k][l] = 3;
                                                bot[k][l - 1] = 3;
                                                bot[k][l - 2] = 3;
                                                m--;
                                                continue;
                                            }
                                }
                            }
                            else
                            {
                                if(l - 2 >= 0)
                                    if(sprawdz(k, l - 1) == true)
                                        if(sprawdz(k, l - 2) == true)
                                        {
                                            bot[k][l] = 3;
                                            bot[k][l - 1] = 3;
                                            bot[k][l - 2] = 3;
                                            m--;
                                            continue;
                                        }
                            }
                        }
                    }
                }
            }
            if(m == 10)
            {
                if(k - 3 >= 0)
                {
                    bot[k][l] = 4;
                    bot[k - 1][l] = 4;
                    bot[k - 2][l] = 4;
                    bot[k - 3][l] = 4;
                    m--;
                    continue;
                }
                else
                {
                    if(l + 3 < 10)
                    {
                       bot[k][l] = 4;
                       bot[k][l + 1] = 4;
                       bot[k][l + 2] = 4;
                       bot[k][l + 3] = 4;
                       m--;
                       continue;
                    }
                    else
                    {
                        if(k + 3 < 10)
                        {
                            bot[k][l] = 4;
                            bot[k + 1][l] = 4;
                            bot[k + 2][l] = 4;
                            bot[k + 3][l] = 4;
                            m--;
                            continue;
                        }
                        else
                        {
                            if(l - 3 >= 0)
                            {
                                bot[k][l] = 4;
                                bot[k][l - 1] = 4;
                                bot[k][l - 2] = 4;
                                bot[k][l - 3] = 4;
                                m--;
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Komputer::botStrz()
{
    int k, l;
    while(true)
    {
        k = (rand() % 10) + 0;
        l = (rand() % 10) + 0;
        if(strzaly[k][l] < 5)
        {
            if(strzaly[k][l] == 0)
            {
                strzaly[k][l] = 5;
                break;
            }
            else
            {
                if(strzaly[k][l] == 1)
                {
                    strzaly[k][l] = 6;
                    if(strzaly[k - 1][l] == 0)
                        strzaly[k - 1][l] = 7;
                    if(strzaly[k - 1][l + 1] == 0)
                        strzaly[k - 1][l + 1] = 7;
                    if(strzaly[k][l + 1] == 0)
                        strzaly[k][l + 1] = 7;
                    if(strzaly[k + 1][l + 1] == 0)
                        strzaly[k + 1][l + 1] = 7;
                    if(strzaly[k + 1][l] == 0)
                        strzaly[k + 1][l] = 7;
                    if(strzaly[k + 1][l - 1] == 0)
                        strzaly[k + 1][l - 1] = 7;
                    if(strzaly[k][l - 1] == 0)
                        strzaly[k][l - 1] = 7;
                    if(strzaly[k - 1][l - 1] == 0)
                        strzaly[k - 1][l - 1] = 7;
                    continue;
                }
                if(strzaly[k][l] == 2)
                {
                    strzaly[k][l] = 6;
                    if(strzaly[k - 1][l] == 2)
                    {
                        strzaly[k - 1][l] = 6;
                        if(strzaly[k - 2][l] == 0)
                            strzaly[k - 2][l] = 7;
                        if(strzaly[k - 2][l + 1] == 0)
                            strzaly[k - 2][l + 1] = 7;
                        if(strzaly[k - 1][l + 1] == 0)
                            strzaly[k - 1][l + 1] = 7;
                        if(strzaly[k][l + 1] == 0)
                            strzaly[k][l + 1] = 7;
                        if(strzaly[k + 1][l + 1] == 0)
                            strzaly[k + 1][l + 1] = 7;
                        if(strzaly[k + 1][l] == 0)
                            strzaly[k + 1][l] = 7;
                        if(strzaly[k + 1][l - 1] == 0)
                            strzaly[k + 1][l - 1] = 7;
                        if(strzaly[k][l - 1] == 0)
                            strzaly[k][l - 1] = 7;
                        if(strzaly[k - 1][l - 1] == 0)
                            strzaly[k - 1][l - 1] = 7;
                        if(strzaly[k - 2][l - 1] == 0)
                            strzaly[k - 2][l - 1] = 7;
                        continue;
                    }
                    if(strzaly[k][l + 1] == 2)
                    {
                        strzaly[k][l + 1] = 6;
                        if(strzaly[k][l + 2] == 0)
                            strzaly[k][l + 2] = 7;
                        if(strzaly[k + 1][l + 2] == 0)
                            strzaly[k + 1][l + 2] = 7;
                        if(strzaly[k + 1][l + 1] == 0)
                            strzaly[k + 1][l + 1] = 7;
                        if(strzaly[k + 1][l] == 0)
                            strzaly[k + 1][l] = 7;
                        if(strzaly[k + 1][l - 1] == 0)
                            strzaly[k + 1][l - 1] = 7;
                        if(strzaly[k][l - 1] == 0)
                            strzaly[k][l - 1] = 7;
                        if(strzaly[k - 1][l - 1] == 0)
                            strzaly[k - 1][l - 1] = 7;
                        if(strzaly[k - 1][l] == 0)
                            strzaly[k - 1][l] = 7;
                        if(strzaly[k - 1][l + 1] == 0)
                            strzaly[k - 1][l + 1] = 7;
                        if(strzaly[k - 1][l + 2] == 0)
                            strzaly[k - 1][l + 2] = 7;
                        continue;
                    }
                    if(strzaly[k + 1][l] == 2)
                    {
                        strzaly[k + 1][l] = 6;
                        if(strzaly[k + 2][l] == 0)
                            strzaly[k + 2][l] = 7;
                        if(strzaly[k + 2][l - 1] == 0)
                            strzaly[k + 2][l - 1] = 7;
                        if(strzaly[k + 1][l - 1] == 0)
                            strzaly[k + 1][l - 1] = 7;
                        if(strzaly[k][l - 1] == 0)
                            strzaly[k][l - 1] = 7;
                        if(strzaly[k - 1][l - 1] == 0)
                            strzaly[k - 1][l - 1] = 7;
                        if(strzaly[k - 1][l] == 0)
                            strzaly[k - 1][l] = 7;
                        if(strzaly[k - 1][l + 1] == 0)
                            strzaly[k - 1][l + 1] = 7;
                        if(strzaly[k][l + 1] == 0)
                            strzaly[k][l + 1] = 7;
                        if(strzaly[k + 1][l + 1] == 0)
                            strzaly[k + 1][l + 1] = 7;
                        if(strzaly[k + 2][l + 1] == 0)
                            strzaly[k + 2][l + 1] = 7;
                        continue;
                    }
                    if(strzaly[k][l - 1] == 2)
                    {
                        strzaly[k][l - 1] = 6;
                        if(strzaly[k][l - 2] == 0)
                            strzaly[k][l - 2] = 7;
                        if(strzaly[k - 1][l - 2] == 0)
                            strzaly[k - 1][l - 2] = 7;
                        if(strzaly[k - 1][l - 1] == 0)
                            strzaly[k - 1][l - 1] = 7;
                        if(strzaly[k - 1][l] == 0)
                            strzaly[k - 1][l] = 7;
                        if(strzaly[k - 1][l + 1] == 0)
                            strzaly[k - 1][l + 1] = 7;
                        if(strzaly[k][l + 1] == 0)
                            strzaly[k][l + 1] = 7;
                        if(strzaly[k + 1][l + 1] == 0)
                            strzaly[k + 1][l + 1] = 7;
                        if(strzaly[k + 1][l] == 0)
                            strzaly[k + 1][l] = 7;
                        if(strzaly[k + 1][l - 1] == 0)
                            strzaly[k + 1][l - 1] = 7;
                        if(strzaly[k + 1][l - 2] == 0)
                            strzaly[k + 1][l - 2] = 7;
                        continue;
                    }
                }
                if(strzaly[k][l] == 3)
                {
                    strzaly[k][l] = 6;
                    if(strzaly[k - 1][l] == 3 && strzaly[k + 1][l] == 3)
                    {
                        strzaly[k + 1][l] = 6;
                        strzaly[k - 1][l] = 6;
                        continue;
                    }
                    if(strzaly[k][l - 1] == 3 && strzaly[k][l + 1] == 3)
                    {
                        strzaly[k][l - 1] = 6;
                        strzaly[k][l + 1] = 6;
                        continue;
                    }
                    if(strzaly[k - 1][l] == 3 && strzaly[k - 2][l] == 3)
                    {
                        strzaly[k - 1][l] = 6;
                        strzaly[k - 2][l] = 6;
                        continue;
                    }
                    if(strzaly[k + 1][l] == 3 && strzaly[k + 2][l] == 3)
                    {
                        strzaly[k + 1][l] = 6;
                        strzaly[k + 2][l] = 6;
                        continue;
                    }
                    if(strzaly[k][l - 1] == 3 && strzaly[k][l - 2] == 3)
                    {
                        strzaly[k][l - 1] = 6;
                        strzaly[k][l - 2] = 6;
                        continue;
                    }
                    if(strzaly[k][l + 1] == 3 && strzaly[k][l + 2] == 3)
                    {
                        strzaly[k][l + 1] = 6;
                        strzaly[k][l + 2] = 6;
                        continue;
                    }
                }
                if(strzaly[k][l] == 4)
                {
                    strzaly[k][l] = 6;
                    if(strzaly[k][l + 1] == 4 && strzaly[k][l + 2] == 4 && strzaly[k][l + 3] == 4)
                    {
                        strzaly[k][l + 1] = 6;
                        strzaly[k][l + 2] = 6;
                        strzaly[k][l + 3] = 6;
                        continue;
                    }
                    if(strzaly[k][l - 1] == 4 && strzaly[k][l + 1] == 4 && strzaly[k][l + 2] == 4)
                    {
                        strzaly[k][l - 1] = 6;
                        strzaly[k][l + 1] = 6;
                        strzaly[k][l + 2] = 6;
                        continue;
                    }
                    if(strzaly[k][l - 2] == 4 && strzaly[k][l - 1] == 4 && strzaly[k][l + 1] == 4)
                    {
                        strzaly[k][l - 2] = 6;
                        strzaly[k][l - 1] = 6;
                        strzaly[k][l + 1] = 6;
                        continue;
                    }
                    if(strzaly[k][l - 1] == 4 && strzaly[k][l - 2] == 4 && strzaly[k][l - 3] == 4)
                    {
                        strzaly[k][l - 1] = 6;
                        strzaly[k][l - 2] = 6;
                        strzaly[k][l - 3] = 6;
                        continue;
                    }
                    if(strzaly[k + 1][l] == 4 && strzaly[k + 2][l] == 4 && strzaly[k + 3][l] == 4)
                    {
                        strzaly[k + 1][l] = 6;
                        strzaly[k + 2][l] = 6;
                        strzaly[k + 3][l] = 6;
                        continue;
                    }
                    if(strzaly[k - 1][l] == 4 && strzaly[k + 1][l] == 4 && strzaly[k + 2][l] == 4)
                    {
                        strzaly[k - 1][l] = 6;
                        strzaly[k + 1][l] = 6;
                        strzaly[k + 2][l] = 6;
                        continue;
                    }
                    if(strzaly[k - 2][l] == 4 && strzaly[k - 1][l] == 4 && strzaly[k + 1][l] == 4)
                    {
                        strzaly[k - 2][l] = 6;
                        strzaly[k - 1][l] = 6;
                        strzaly[k + 1][l] = 6;
                        continue;
                    }
                    if(strzaly[k - 1][l] == 4 && strzaly[k - 2][l] == 4 && strzaly[k - 3][l] == 4)
                    {
                        strzaly[k - 1][l] = 6;
                        strzaly[k - 2][l] = 6;
                        strzaly[k - 3][l] = 6;
                        continue;
                    }
                }
            }
        }
    }
}
