#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "functions.h"
#include "menu.h"
#include "Item.h"

using namespace std;

void menu::add(string s, int r = 0, string d = " ")
{
    num++;
    if(r == 0)
    {
        r = num;
    }
    elements.push_back(item(s, r, d));
}

void menu::menu_head(string s)
{
    head.name = s;
    return;
}

int menu::display()
{
    system("clear");
    int selected = 0, opt=66, last_x = getmax_x(), last_y = getmax_y();
    while(true)
    {
        int MAX_Y = getmax_y(), i;
        head.y = (MAX_Y - head.name.size())/2;
        for(item &a : elements)
        {
            a.y = (MAX_Y - a.name.size())/2;
        }
        int MAX_X = getmax_x();
        if (!(MAX_X == last_x && MAX_Y == last_y))
        {
            system("clear");
            last_x = MAX_X;
            last_y = MAX_Y;
        }
        int x = (MAX_X - num)/2 - 2;
        gotoxy(0, 0);
        for(i = 2; i < x; i++)
        {
            cout << endl;
        }
        head.display_();
        cout<<"\n\n";
        for(i=0;i<(int)elements.size();i++)
        {
            if ( i == selected)
            {
                elements[i].display_selected();
            }
            else
            {
                elements[i].display_();
            }
        }
        cout << "\n\n\n\n\n\n\n";
        cout << ">>> " << elements[selected].description;
        int previous = (opt==66)?(selected-1):(selected+1);
        if (previous < 0)
        {
            previous = num-1;
        }
        if(previous == num)
        {
            previous = 0;
        }
        int temp = (elements[previous].description.length() - elements[selected].description.length());
        for(int i=0; i < temp; i++)
        {
            cout << " ";
        }
        cout<<'\n';
        opt = GETCH();
        if (opt == 10)
        {
            return elements[selected].returnval;
        }
        switch(opt)
        {
            case 66:
                selected++;
                break;
            case 65:
                selected--;
                break;
        }
        if(selected == num)
        {
            selected = 0;
        }
        if(selected == -1)
        {
            selected = num -1;
        }
    }
}