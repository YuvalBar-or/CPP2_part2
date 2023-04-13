#include "game.hpp"
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace ariel{

void create_cards(vector<Card>& deck){
    deck.clear();
    // Create all 52 cards and add them to the deck
    for (int i = 1; i <= 13; i++) {
        deck.push_back(Card(i, spade)); 
        deck.push_back(Card(i, heart));
        deck.push_back(Card(i, diamond)); 
        deck.push_back(Card(i, club)); 
    }

}

void shuffle_deck(vector<Card>& deck){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

}

void divide(vector<Card>& deck, Player& p1, Player& p2){
    for (unsigned long int i = 0; i < 26; i++) {
        p1.addCard(deck[i]);
        p2.addCard(deck[i + 26]);
   }
}

Game::Game(Player &player1, Player &player2) : m_player1(player1), m_player2(player2){
    this ->draws =0;
    this -> rounds =0;
    this -> player2_win =0;
    this -> player1_win=0;

    vector <Card> deck; 
    create_cards (deck);
    shuffle_deck (deck);
    divide(deck, player1, player2);
}

void Game:: playTurn(){
    if (&m_player1 == &m_player2){
       throw invalid_argument("you can't play agains yourself"); 
    }
    if (m_player1.stacksize() == 0 ||m_player2.stacksize() == 0 )
        throw runtime_error("the game has ended");

    std::string str = "";
    bool flag = true;
    int cards_won = 0;
    while (flag){
      this-> rounds += 1;
      flag = false;

      Card playerCard1;
      Card playerCard2;
      if (this->m_player1.stacksize() > 0 && this->m_player2.stacksize() > 0){
        playerCard1 = this->m_player1.popCard();
        playerCard2 = this->m_player2.popCard();
        cards_won += 2;
      }
      else{
        if (cards_won == 0)
        {
          throw "out of cards";
        }
        // no more card to draw everyone get the card he throws
        m_player1.roundsUpdate(cards_won / 2);
        m_player2.roundsUpdate(cards_won / 2);
        break;
      }
      // setting the first part of the str;
      str += m_player1.printTurn(playerCard1) + " " + m_player2.printTurn(playerCard2) + ". ";
      if (playerCard1.getNum() == playerCard2.getNum()){
        flag = true;
        str += "Draw.";
        this->draws++;
        // for poping
        if (this->m_player1.stacksize() > 0 && this->m_player2.stacksize() > 0){
          playerCard1 = this->m_player1.popCard();
          playerCard2 = this->m_player2.popCard();

          cards_won += 2;
        }
        else{
          // no more card to draw
          m_player1.roundsUpdate(cards_won / 2);
          m_player2.roundsUpdate(cards_won / 2);
          flag = false;
        }
      }
      else if ((playerCard1.getNum() == 1 && playerCard2.getNum() != 2) || (playerCard1.getNum() > playerCard2.getNum())){
        str += this->m_player1.getName() + " wins.";
        m_player1.roundsUpdate(cards_won);
        m_player2.roundsUpdate(0);
      }
      else{ // p2 wins
        str += this->m_player2.getName() + " wins.";
        m_player2.roundsUpdate(cards_won);
        m_player1.roundsUpdate(0);
      }
    }
    str += "\n"; // round end
    this->play_log.push_back(str);
  };



void Game:: printLastTurn(){
    cout << this -> play_log.back() << endl;
}


void Game::  playAll(){
    while (this -> m_player1.stacksize() && this -> m_player2.stacksize() ){
        playTurn();
    }
}

void Game:: printWiner(){
    
    if (m_player1.stacksize() != 0){
        cout << "the game is still running" << endl;
    }
    
    if (m_player1.cardesTaken() == m_player2.cardesTaken()){
        cout << "tie" << endl;
    }
    
    else if (m_player1.cardesTaken() > m_player2.cardesTaken()){
        cout << m_player1.getName() + " won" << endl;
    }
    else{
        cout << m_player2.getName() + " won" << endl;
    }
      

}


void Game :: printLog(){
    for (std::string log : this->play_log){
        cout << log << endl;
    }
}


void Game :: printStats(){
    
    cout << "PLAYER1 STATS" << endl;
    cout << m_player1.getName() + ": ";
    cout << "Cards taken: " + to_string(m_player1.cardesTaken()) << endl;
    cout << "win rate:" + to_string((float) player1_win /play_log.size()) << endl;

    cout << "PLAYER2 STATS" << endl;
    cout << m_player2.getName() + ": ";
    cout << "win rate;" + to_string((float)player1_win / play_log.size()) + ", ";
    cout << "cards taken: " + to_string(m_player2.cardesTaken()) << endl;
    
    cout << "GAME STATS" << endl;
    cout << "draw rate: " + to_string((float)draws / rounds) + ", ";
    cout << "draws amount: " + to_string(draws) << endl;

}

}