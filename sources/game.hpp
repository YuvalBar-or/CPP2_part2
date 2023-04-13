#pragma once

#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
   class Game{
        private:
            Player &m_player1; 
            Player &m_player2;
            vector<std::string> play_log;
            int rounds; 
            int draws; 
            int player2_win;
            int player1_win;
   


        public:
            Game (Player &player1, Player &player2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();

    };
}