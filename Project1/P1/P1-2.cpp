#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//skills
enum skill_type {Tackle, Leaf, Flame, Stream};

class Skill
{
public:
    Skill(skill_type t)
    {
        power = 20;
        type = t;
    }
    string get_name()
    {
        switch(type)
        {
        case Leaf:
            return "Leaf";
            break;
        case Flame:
            return "Flame";
            break;
        case Stream:
            return "Stream";
            break;
        }
    }
private:
    int power;
    skill_type type;
};
//pets
enum pet_type {W, L, G};
class Pet
{
public:
    Pet(int i)
    {
        Skill T(Tackle);
        Skill Le(Leaf);
        Skill F(Flame);
        Skill S(Stream);

        id = i;
        alive = true;

        switch(i)
        {
        case 1:
            type = W;
            hp = 110;
            attack = 10;
            defence = 10;
            skill_list = {T,Le};
            break;
        case 2:
            type = L;
            hp = 100;
            attack = 11;
            defence = 10;
            skill_list = {T,F};
            break;
        case 3:
            type = G;
            hp = 100;
            attack = 10;
            defence = 11;
            skill_list = {T,S};
            break;
        }
    }

    string get_name()
    {
        switch(type)
        {
        case W:
            return "W";
            break;
        case L:
            return "L";
            break;
        case G:
            return "G";
            break;
        }
    }

    void death()
    {
        alive = false;
    }
    int get_id()
    {
        return id;
    }
    int get_attack()
    {
        return attack;
    }
    int get_defence()
    {
        return defence;
    }
    bool is_alive()
    {
        return alive;
    }
    void lose_hp(int i)
    {
        hp-=i;
    }
    string get_unique_skill()
    {
        return skill_list[1].get_name();
    }
    int get_hp()
    {
        return hp;
    }
private:
    pet_type type;
    int hp, attack, defence,id;
    vector<Skill> skill_list;
    bool alive;
};
//team
class Team
{
public:
    Team()
    {
        player_team = {};
        enemy_team = {};

        for(int i = 1; i < 4; i++)
        {
            Pet* pet1 = new Pet(i);
            Pet* pet2 = new Pet(i);
            player_team.push_back(pet1);
            enemy_team.push_back(pet2);
        }
    }

    Pet* getpet(bool side, int i)
    {
        if(side)
        {
            return player_team[i-1];
        }
        else
        {
            return enemy_team[i-1];
        }
    }
private:
    vector<Pet*> player_team;
    vector<Pet*> enemy_team;
};
//actions


//engine
void play(Team& team, std::istream& is, std::ostream& os);
int game_start(std::istream& is, std::ostream& os,Team team,bool side);
bool query_choice(std::istream& is,int& choice,Team team,bool side);
int select_action(std::istream& is,std::ostream& os,Team team);
bool query_action(std::istream& is,int& choice);
void perform_change(std::istream& is,std::ostream& os, Pet*& pet, Team team);
bool query_change(std::istream& is,int& choice, int now_pet,bool side,Team team);
void perform_skill(std::istream& is, std::ostream& os,Pet* player_pet,Pet* enemy_pet);
void perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os);
void enemy_skill(std::ostream& os,Team team,Pet* enemy_pet,Pet* player_pet,int player_id);
void enemy_change(std::ostream& os,Pet*& enemy_pet,Team team,int player_id);
int enemy_level(Team team,Pet* enemy_pet,int player_id);
int still_alive(Team team, bool side);
int is_win(Team team, int num_turns);
void enemy_change_output(std::ostream& os,Pet*& enemy_pet,bool on);

int main()
{
    Team team;
    play(team, cin, cout);
}


//engine
void play(Team& team, std::istream& is, std::ostream& os)
{
    os << "Welcome to Battle of Pets!" << endl;
    os << "You have W,L and G. So does Enemy." << endl;

    bool side;
    bool on;
    int num_turns = 1;

    int player_pet_num = game_start(is,os,team,1);
    srand((unsigned)time(NULL));

    int enemy_pet_num = (rand() % 3) + 1;

    Pet* player_pet = team.getpet(1, player_pet_num);
    Pet* enemy_pet = team.getpet(0, enemy_pet_num);

    os << "You start with " << (player_pet)->get_name() <<endl;
    os << "Enemy starts with "<< (enemy_pet)->get_name() <<endl;
    os << "Battle starts!" << endl;
    os << "_______________________________________________________" << endl;

    while(is)
    {
        os << "Round " << num_turns <<endl;

        int action_num = select_action(is,os,team);
        int player_id = player_pet->get_id();
        int player_action_level;
        int enemy_action_level = enemy_level(team,enemy_pet,player_id);

        switch(action_num)
        {
        case 0:
            player_action_level = 6;
            break;
        case 1:
            player_action_level = 0;
            break;
        }

        if(player_action_level >= enemy_action_level)
        {
           switch(action_num)
            {
            case 0:
                perform_change(is,os,player_pet,team);
                break;
            case 1:
                perform_skill(is,os,player_pet,enemy_pet);
                break;
            }

           switch(enemy_action_level)
            {
            case 0:
                on = false;
                enemy_skill(os,team,enemy_pet,player_pet,player_id);
                break;
            case 6:
                on = true;
                enemy_change(os,enemy_pet,team,player_id);
                break;
            }
            enemy_change_output(os,enemy_pet,on);
            on = false;
        }
        else
        {
           switch(enemy_action_level)
            {
            case 0:
                on = false;
                enemy_skill(os,team,enemy_pet,player_pet,player_id);
                break;
            case 6:
                on = true;
                enemy_change(os,enemy_pet,team,player_id);
                break;
            }

            switch(action_num)
            {
            case 0:
                perform_change(is,os,player_pet,team);
                break;
            case 1:
                perform_skill(is,os,player_pet,enemy_pet);
                break;
            }
            enemy_change_output(os,enemy_pet,on);
            on = false;
        }

        if(enemy_pet->get_hp()<=0 )
        {
            enemy_pet->death();
            os << "Enemy's " << enemy_pet->get_name() << " is beaten" <<endl;
        }

        if(player_pet->get_hp() <=0 )
        {
            player_pet->death();
            os << "Your " << player_pet->get_name() << " is beaten" <<endl;

        }

        int flag = is_win(team,num_turns);
        if( flag == 0)
        {
            os << "Draw" << endl;
            break;
        }
        else if(flag == 1)
        {
            enemy_change(os, enemy_pet, team, player_id);
            enemy_change_output(os,enemy_pet,true);
            os << "You Lose" << endl;
            break;
        }
        else if(flag == 2)
        {
            perform_change(is, os, player_pet, team);
            os << "You Win" <<endl;
            break;
        }
        else
        {
            if(player_pet->get_hp() <= 0)
            {
                perform_change(is, os, player_pet, team);
            }

            if(enemy_pet->get_hp() <= 0)
            {
                enemy_change(os, enemy_pet, team, player_id);
                enemy_change_output(os,enemy_pet,true);
            }
            os << "Your " << (player_pet)->get_name() << ": HP" <<(player_pet)->get_hp() << "||";
            os << "Enemy's " << (enemy_pet)->get_name() << ": HP" <<(enemy_pet)->get_hp() <<endl;

            os << "_______________________________________________________" << endl;
            num_turns++;
        }
    }

}

int still_alive(Team team,bool side)
{
    int alive_total = 0;
    for(int i = 1; i < 4; i++)
    {
        if(team.getpet(side,i)->is_alive())
        {
            alive_total++;
        }
    }
    return alive_total;
}

void enemy_change_output(std::ostream& os,Pet*& enemy_pet,bool on)
{
    if(on)
    {
        os << "Enemy sends " << enemy_pet->get_name() << endl;
    }
}

int enemy_level(Team team,Pet* enemy_pet,int player_id)
{
    int enemy_id = enemy_pet->get_id();
    int best = (player_id%3)+1;
    int second = player_id;
    int worst = (player_id+2)%3;

    int level;

    if(enemy_id == player_id+1 || ( enemy_id== 1 && player_id == 3))
    {
        level = 0;
    }
    else if(team.getpet(0,best)->is_alive())
    {
        level = 6;
    }
    else if(team.getpet(0,second)->is_alive())
    {
        level = 6;
    }
    else
    {
        level = 0;
    }

    return level;
}

void enemy_change(std::ostream& os,Pet*& enemy_pet,Team team,int player_id)
{
    int best = (player_id%3)+1;
    int second = player_id;
    int worst = (player_id+2)%3;

    if(worst == 0)
    {
        worst = 3;
    }

    if(team.getpet(0,best)->is_alive())
    {
        enemy_pet = team.getpet(0,best);
    }
    else if(team.getpet(0,second)->is_alive())
    {
        enemy_pet = team.getpet(0,second);
    }
    else if(team.getpet(0,worst)->is_alive())
    {
        enemy_pet = team.getpet(0,worst);
    }

}

void enemy_skill(std::ostream& os,Team team,Pet* enemy_pet,Pet* player_pet,int player_id)
{
    int id = player_pet->get_id();
    int enemy_id = enemy_pet->get_id();
    int attack = enemy_pet->get_attack();
    int defence = player_pet->get_defence();
    int  damage = 20*attack/defence;
    int choice = 1;
    if(enemy_id == player_id+1 || ( enemy_id== 1 && player_id == 3))
    {
        choice = 2;
    }

    if(choice == 2 && (enemy_id == id+1 || ( enemy_id== 1 && id == 3)))
    {
        damage*=2;
    }
    else if(choice == 2 )
    {
        damage*=0.5;
    }

    player_pet->lose_hp(damage);

    if(choice == 1)
    {
        os << "Enemy's " << enemy_pet->get_name() << " uses Tackle! Damage: " <<damage<<endl;
    }
    else
    {
        os << "Enemy's " << enemy_pet->get_name() << " uses " <<enemy_pet->get_unique_skill() <<"! Damage: " << damage << endl;
    }
}


void perform_skill(std::istream& is, std::ostream& os,Pet* player_pet,Pet* enemy_pet)
{
    int choice_skill;
    while(is)
    {
        os << "Select the skill (";
        os <<"1 for Tackle,2 for "<< player_pet->get_unique_skill() <<"):";
        is >> choice_skill;
        if(choice_skill==1 || choice_skill==2)
        {
            break;
        }
    }
    perform_damage(player_pet,enemy_pet,choice_skill,os);

}

void perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os)
{
    int attack = player_pet->get_attack();
    int defence = enemy_pet->get_defence();
    int player_id = player_pet->get_id();
    int enemy_id = enemy_pet->get_id();

    int  damage = 20*attack/defence;
    if(choice == 2)
    {
        if(player_id == enemy_id+1 || (player_id == 1 && enemy_id == 3))
        {
            damage*=2;
        }
        else
        {
            damage*=0.5;
        }
    }
    enemy_pet->lose_hp(damage);

    if(choice == 1)
    {
        os << "Your " << player_pet->get_name() << " uses Tackle! Damage: " <<damage<<endl;
    }
    else
    {
        os << "Your " << player_pet->get_name() << " uses " <<player_pet->get_unique_skill() <<"! Damage: " << damage << endl;
    }

}

void perform_change(std::istream& is, std::ostream& os,Pet*& pet, Team team)
{
    int choice_pet;
    while(is)
    {
        os << "Select your next pet (";
        int now_pet = pet->get_id();

        int alive_total = 0;
        for(int i = 1; i < 4; i++)
        {
            if(i != now_pet && team.getpet(1,i)->is_alive())
            {
                alive_total++;
            }
        }
        if(alive_total == 1)
        {
            for(int i = 1; i < 4; i++)
            {
                if(i != now_pet && team.getpet(1,i)->is_alive())
                {
                        os << i << " for " << (team.getpet(1, i))->get_name();
                }
            }
        }
        else
        {
            for(int i = 1; i < 4; i++)
            {
                if(i != now_pet && team.getpet(1,i)->is_alive())
                {
                    if(i == 3||(i==2&&(3==now_pet)))
                    {
                        os << i << " for " << (team.getpet(1, i))->get_name();
                    }
                    else
                    {
                        os << i << " for " << (team.getpet(1, i))->get_name() << ", ";
                    }
                }
            }
        }


        os << "):";
        if(query_change(is, choice_pet,now_pet,1,team))
        {
            os << "You send " << (team.getpet(1, choice_pet))->get_name() << endl;
            break;
        }
    }
    pet = team.getpet(1,choice_pet);

}


int select_action(std::istream& is, std::ostream& os, Team team)
{
    int action_choice;
    int alive = still_alive(team,1);

    if(alive == 1)
    {
        while(is)
        {
            os << "Select your action (1 for skill):";
            if(query_action(is,action_choice))
            {
                break;
            }
        }
    }
    else
    {
        while(is)
        {
            os << "Select your action (0 for change, 1 for skill):";
            if(query_action(is,action_choice))
            {
                break;
            }
        }
    }
    return action_choice;
}

bool query_action(std::istream& is, int& choice)
{
    if(!is)
    {
        cout << "Read line failed!" <<endl;
        return false;
    }
    else
    {
        is >> choice;
        if(choice > 1 || choice < 0)
        {
            return false;
        }
        return true;
    }
}

int game_start(std::istream& is, std::ostream& os,Team team,bool side)
{
    int choice;
    while(is)
    {
        os << "Select your starting pet (1 for W, 2 for L, 3 for G):";

        if(query_choice(is, choice,team,side))
        {
            break;
        }
    }

    return choice;
}

bool query_change(std::istream& is,int &choice,int now_pet,bool side,Team team)
{

    if(!is)
    {
        cout << "Read line failed!" <<endl;
        return false;
    }
    else
    {
        is >> choice;
        if(choice > 3 || choice < 0 || choice == now_pet)
        {
            return false;
        }
        if(!(team.getpet(side,choice))->is_alive())
        {
            return false;
        }
        return true;
    }
}
//not completed function
bool query_choice(std::istream& is,int& choice,Team team,bool side)
{

    if(!is)
    {
        cout << "Read line failed!" <<endl;
        return false;
    }
    else
    {
        is >> choice;
        if(choice > 3 || choice < 0)
        {
            return false;
        }
        if(!(team.getpet(side,choice))->is_alive())
        {
            return false;
        }
        return true;
    }
}

int is_win(Team team,int num_turns)
{
    int flag;

    int player_alive = still_alive(team,true);
    int enemy_alive = still_alive(team,false);

    if((player_alive == 0 && enemy_alive == 0) || num_turns == 100)
    {
        flag = 0;
    }
    else if(player_alive == 0)
    {
        flag = 1;
    }
    else if(enemy_alive == 0)
    {
        flag = 2;
    }
    else
    {
        flag = 4;
    }
    return flag;
}
//actions



