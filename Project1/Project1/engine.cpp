#include "engine.h"




void play(Team& team, std::istream& is, std::ostream& os)
{
    os << "Welcome to Battle of Pets!" << endl;
    os << "You have W,L and G. So does Enemy." << endl;

    bool side;
    int num_turns = 1;

    game_start(is,os,team);


    while(is)
    {

    }


}

void game_start(std::istream& is, std::ostream& os)
{
    while(is)
    {
        os << "Select your starting pet (1 for W, 2 for L, 3 for G):";

        int choice;
        if(query_choice())
    }

}
