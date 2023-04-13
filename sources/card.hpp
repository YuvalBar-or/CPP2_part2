#pragma once 

#include <iostream>
#include <string>
using namespace std;
namespace ariel
{
    
    enum Suits {diamond, club, heart, spade};
    class Card{
    
    private:
        int number; 
        Suits suit;

        string getSuits();
        int getnum();

    public:
        Card (int number , Suits suit);
        std:: string tostring ();
        Card (); 
        int getNum();





    };
} 