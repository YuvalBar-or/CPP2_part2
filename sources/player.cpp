# include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace ariel{

    Player :: Player (string str){
        this-> name = str;
        this->stack.clear(); 
        this -> takenCardes = 0;
        this -> playedRound =0;
        this -> isPlaying = false;
        this -> wonRounds =0; 
    }

    void Player::roundsUpdate(int cards){
        playedRound++;
        takenCardes += cards;
        if (cards>0){
            wonRounds++;
        }
    }

    Card Player :: popCard(){
        Card card = Player :: stack.back();
        Player :: stack.pop_back();
        return card;
    }

    void Player::addCard(Card card){
        this -> stack.push_back(card);
    }

    string Player::getName(){
        return name;
    }

    string Player::printTurn(Card card){
      return this->name + " played " + card.tostring();  
    }

}
  

    



    














