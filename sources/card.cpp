#include "card.hpp"
#include <string>
using namespace std;


namespace ariel{


Card :: Card (int number , Suits suit){
    this->number= number;
    this ->suit = suit;
}

Card :: Card(){
    this -> number =1; 
    this -> suit = club;
}


string Card :: getSuits(){
    switch (this->suit)
    {
    case diamond:
        return "diamond";
        break;
    
    case club:
        return "club";
        break;
    
    case heart:
        return "heart";
        break;
    
    default:
        return "spade";
    }
}

string Card:: tostring (){
  switch (number)
  {
  case  1:
    return "Ace of" + getSuits();
    break;

  case  11:
    return "Prince of" + getSuits();
    break;

  case  12:
    return "Queen of" + getSuits();
    break;

  case  13:
    return "King of" + getSuits();
    break;

  default:
    return to_string(number) + "of"+ getSuits();
  }  
}

int Card :: getNum(){
    return this->number;
}

}


