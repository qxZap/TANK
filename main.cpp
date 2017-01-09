#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
bool game=true;
int menu;
char Map[12][21][30];
char Menu[3][21][30];
int difficulty;
int tank;
int play_map;
using namespace std;
void LoadResurces();
void LoadMenu();
void NewGame();
void PrintMenu(int NumberMenu);
void SelectTank();
void SelectMap();

void LoadResurces()
{
    ifstream MenuGetNull("Menu0.txt");
    ifstream MenuGetOne("Menu1.txt");
    ifstream MenuGetTwo("Menu2.txt");
    ifstream MenuGetThree("Menu3.txt");
    ifstream MenuGetFour("Menu4.txt");
    ifstream MenuGetFive("Menu5.txt");
    ifstream MenuGetSix("Menu6.txt");
    ifstream MenuGetSeven("Menu7.txt");
    ifstream MenuGetEight("Menu8.txt");
    ifstream MenuGetNine("Menu9.txt");
    ifstream MenuGetTen("Menu10.txt");
    ifstream MenuGetOneOne("Menu11.txt");
    ifstream MapGetNull("Map0.txt");
    ifstream MapGetOne("Map1.txt");
    ifstream MapGetTwo("Map2.txt");

    for(int i=0;i<21;i++)
        for(int j=0;j<30;j++)
            {
                //std::noskipws>>
                MenuGetNull>>Menu[0][i][j];
                MenuGetOne>>Menu[1][i][j];
                MenuGetTwo>>Menu[2][i][j];
                MenuGetThree>>Menu[3][i][j];
                MenuGetFour>>Menu[4][i][j];
                MenuGetFive>>Menu[5][i][j];
                MenuGetSix>>Menu[6][i][j];
                MenuGetSeven>>Menu[7][i][j];
                MenuGetEight>>Menu[8][i][j];
                MenuGetNine>>Menu[9][i][j];
                MenuGetTen>>Menu[10][i][j];
                MenuGetOneOne>>Menu[11][i][j];
                MapGetNull>>Map[0][i][j];
                MapGetOne>>Map[1][i][j];
                MapGetTwo>>Map[2][i][j];
            }

}


void SelectMap()
{
    srand (time(NULL));
    play_map=rand() % 5 + 1;

}

void PrintMenu(int NumberMenu)
{
        system("CLS");
        for(int i=0;i<21;i++)
        {
            for(int j=0;j<30;j++)
                cout<<Menu[NumberMenu][i][j];
            cout<<"\n";
        }

}

void SelectTank()
{
    char input;
    int position=0;
    PrintMenu(position+6);
    while(game)
    {
        PrintMenu(position+6);
        cin>>input;
        if(input=='q')
        {
            if(position==5)
            {
                break;
                NewGame();
            }
            else
            {
                break;
                tank=position;
                SelectMap();
            }
        }
        else if(input=='a')
        {
            if(position==0)
            {
                position=5;
            }
            else
            {
                position--;
            }
        }
        else if(input=='d')
        {
            if(position==5)
            {
                position=0;
            }
            else
            {
                position++;
            }
        }



    }
}

void NewGame()
{
    char input;
    int position=0;
    PrintMenu(position+2);
    while(game)
    {

        PrintMenu(position+2);
        cin>>input;
        if(input=='q')
        {

            if(position==3)
            {
                LoadMenu();
            }
            else
            {

                difficulty=position;
                SelectTank();
            }

        }
        else if(input=='s')
        {
            if(position==3)
                position=0;
            else position++;
        }
        else if(input=='w')
        {
            if(position==0)
                position=3;
            else position--;
        }

    }

}


void LoadMenu()
{

        char input;
        int position=0;
        PrintMenu(0);
        while(game)
        {
            cin>>input;
            if(input=='q')
            {
                if(position==0)
                    NewGame();
                else
                {game=false;exit(0);}
            }
            else if(input=='s')
            {
                if(position==1)
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
            PrintMenu(position);
        }
}

int main()
{
    LoadResurces();
    while(game)
        LoadMenu();
    return 0;



}
