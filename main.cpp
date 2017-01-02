#include <iostream>
#include <fstream>
#include <math.h>
bool game=true;
int menu;
char Map[10][21][30];
char Menu[2][21][30];

using namespace std;
void LoadResurces();
void LoadMenu();
void NewGame();
void PrintMenu(int NumberMenu);


void LoadResurces()
{
    ifstream MenuGetNull("Menu0.txt");
    for(int i=0;i<2;i++)
        for(int j=0;j<30;j++)
            MenuGetNull>>Menu[0][i][j];

    ifstream MenuGetOne("Menu1.txt");
    for(int i=0;i<21;i++)
        for(int j=0;j<30;j++)
            MenuGetOne>>Menu[1][i][j];






}

void PrintMenu(int NumberMenu)
{
        for(int i=0;i<21;i++)
        {
            for(j=0;j<21;j++)
                cout<<Menu[NumberMenu][i][j];
            cout<<"\n";
        }

}

void NewGame()
{
    char input;
    int position=0;

}


void LoadMenu()
{

        char input;
        int position=0;
        Print_Menu(0);
        while(true)
        {
            cin>>input;
            if(input==NULL)
            {
                if(position==1)
                    NewGame();
                else
                    {break;game=false;}
            }
            else if(input=='s')
            {
                if(pisition==1)
                    position--;
                else
                    position++;
            }
            else if(input=='w')
            {
                if(position==0)
                    position++;
                else
                    position--;
            }
        }
}

int main()
{
    menu=1;
    LoadSources();
    while(game)
    {
        if(menu==1)
        {
            LoadMenu();
        }
        else
        {

        }

    }


    return ;
}
