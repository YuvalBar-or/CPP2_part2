#pragma once 
#include <vector>
#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;


namespace ariel{



    class Player {
    private:
        string name;
        vector<Card> stack;
        int takenCardes;
        int playedRound; 
        bool isPlaying; 
        int wonRounds;
    
    
    public:
        Player(string);
        
        int stacksize()const {
            return (int) this -> stack.size();
        }
        int cardesTaken () const{
            return this -> takenCardes;
        }
        void roundsUpdate(int cards);
        void addCard(Card card);
        string getName();
        string printTurn(Card card);
        Card popCard();

    };
}




