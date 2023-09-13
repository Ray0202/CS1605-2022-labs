#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
//weathers
enum weather_type {normal, rainy, sunny};

class Weather
{
public:
    Weather(weather_type t)
    {
        type = t;
    }
    Weather(weather_type t, int len)
    {
        type = t;
        length  = len;
    }

    void change_type(weather_type t, int len)
    {
        type  = t;
        length = len;
    }

    void length_decrease()
    {
        length -- ;
        if(length == 0)
        {
            type = normal;
            is_changed_value = true;
        }
        else if(length < 0)
        {
            length = 0;
        }
    }
    int get_length()
    {
        return length;
    }
    bool is_changed()
    {
        return is_changed_value;
    }
    void reset()
    {
        is_changed_value = false;
    }
    weather_type get_type()
    {
        return type;
    }
private:
    weather_type type;
    int length;
    bool is_changed_value;
};
//skills
enum skill_type {Tackle, Leaf, Flame, Stream, Claw, Quick, Slap, Paint, Sing, Sunny, Rainy, Synthesis, Volt, Thunder};

class Skill
{
public:
    Skill(skill_type t)
    {
        level = 0;
        type = t;
        nature = 0;
        switch(t)
        {
        case Leaf:
            power = 20;
            name = "Leaf";
            nature = 1;
            break;
        case Flame:
            power = 20;
            nature = 2;
            name = "Flame";
            break;
        case Stream:
            power = 20;
            nature = 3;
            name = "Stream";
            break;
        case Tackle:
            power = 20;
            name = "Tackle";
            break;
        case Claw:
            power = 15;
            name = "Claw";
            break;
        case Quick:
            power = 15;
            name = "Quick";
            level = 1;
            break;
        case Sing:
            power = 0;
            name = "Sing";
            break;
        case Paint:
            power = 0;
            name = "Paint";
            break;
        case Synthesis:
            power = 0;
            name = "Synthesis";
            break;
        case Sunny:
            power = 0;
            name = "Sunny";
            level = 1;
            break;
        case Rainy:
            power = 0;
            name = "Rainy";
            level  = 1;
            break;
        case Volt:
            power  = 25;
            nature = 4;
            name = "Volt";
            break;
        case Thunder:
            power = 50;
            nature = 4;
            name = "Thunder";
            break;
        case Slap:
            power = 15;
            name = "Slap";

        }
    }
    string get_name()
    {
        return name;
    }

    int get_power()
    {
        return power;
    }

    int get_level()
    {
        return level;
    }

    int get_nature()
    {
        return nature;
    }

private:
    int power;
    skill_type type;
    string name;
    int level;
    int nature;
};
//pets
enum pet_type {W, L, G, Q, D};
class Pet
{
public:
    Pet(int i)
    {
        Skill Tac(Tackle);
        Skill Lea(Leaf);
        Skill Fla(Flame);
        Skill Str(Stream);
        Skill Cla(Claw);
        Skill Qui(Quick);
        Skill Sla(Slap);
        Skill Sin(Sing);
        Skill Pai(Paint);
        Skill Syn(Synthesis);
        Skill Sun(Sunny);
        Skill Rai(Rainy);
        Skill Vol(Volt);
        Skill Thu(Thunder);

        id = i;
        alive = true;

        switch(i)
        {
        case 1:
            type = W;
            hp = 110;
            attack = 10;
            defence = 10;
            skill_list = {Tac,Lea,Syn};
            speed = 10;
            break;
        case 2:
            type = L;
            hp = 100;
            attack = 11;
            defence = 10;
            skill_list = {Cla,Fla,Sun};
            speed = 11;
            break;
        case 3:
            type = G;
            hp = 100;
            attack = 10;
            defence = 11;
            skill_list = {Tac,Str,Rai};
            speed = 9;
            break;
        case 4:
            type = Q;
            hp = 90;
            attack = 10;
            defence = 10;
            skill_list = {Qui,Vol,Thu};
            speed = 12;
            break;
        case 5:
            type = D;
            hp = 120;
            attack = 9;
            defence = 8;
            skill_list = {Sla,Sin,Pai};
            speed = 7;
            break;
        case 0:
            alive = false;
        }
        hp_max = hp;
        used_potion = false;
        attack_default = attack;
        sleep_time =0;
        is_painted = false;
        sleep_time = 0;
        asleep_changed = false;
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
        case Q:
            return "Q";
            break;
        case D:
            return "D";
            break;
        }
    }
    void revival()
    {
        alive = true;
        hp = hp_max/2;
    }
    bool is_used_potion()
    {
        return used_potion;
    }
    void attack_double()
    {
        attack*=2;
        used_potion = true;
    }
    void attack_reset()
    {
        attack = attack_default;
    }
    void death()
    {
        alive = false;
        attack = attack_default;
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
    string get_unique_skill(int i)
    {
        return skill_list[i].get_name();
    }
    Skill get_skill(int i)
    {
        return skill_list[i];
    }
    int get_hp()
    {
        return hp;
    }
    int get_hp_max()
    {
        return hp_max;
    }
    void be_painted()
    {
        if(!is_painted)
        {
            is_painted = true;
            defence/=2;
        }
    }
    void fall_asleep()
    {
        sleep_time = 3;
    }
    bool is_asleep()
    {
        return (sleep_time>0);
    }
    void wake()
    {
        sleep_time--;
        if(sleep_time == 0)
        {
            asleep_changed = true;
        }
    }
    void wake_up()
    {
        sleep_time = 0;
    }
    int get_speed()
    {
        return speed;
    }
    void reset()
    {
        asleep_changed = false;
    }
    bool whether_painted()
    {
        return is_painted;
    }
    bool is_changed()
    {
        return asleep_changed;
    }

    int synthesis(int i)
    {
        int num = (hp_max*i)/100;
        if(hp+num > hp_max)
        {
            hp = hp_max;
        }
        else
        {
            hp+=num;

        }
        return num;
    }
private:
    pet_type type;
    int hp, attack, defence,id,attack_default;
    int hp_max;
    vector<Skill> skill_list;
    bool alive, asleep_changed;
    bool used_potion;
    int speed;
    int sleep_time;
    bool is_painted;
};
//team
class Team
{
public:
    Team()
    {
        player_team = {};
        enemy_team = {};
        Pet* pet1 = new Pet(1);
        Pet* pet2 = new Pet(3);
        Pet* pet5 = new Pet(4);
        enemy_team.push_back(pet5);
        enemy_team.push_back(pet1);
        enemy_team.push_back(pet2);
    }

    void player_team_add(int i)
    {
        Pet* pet = new Pet(i);
        player_team.push_back(pet);
    }

    bool player_team_exist(int id)
    {
        if(player_team.size() == 0)
        {
            return false;
        }
        for(int i = 0; i < player_team.size();i++)
        {
            if(player_team[i]->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    Pet* getpet(bool side, int id)
    {
        if(side)
        {
            for(int i = 0; i < player_team.size();i++)
            {
                if(player_team[i]->get_id() == id)
                {
                    return player_team[i];
                }
            }
        }
        else
        {
            for(int i = 0; i < enemy_team.size();i++)
            {
                if(enemy_team[i]->get_id() == id)
                {
                    return enemy_team[i];
                }
            }
        }
        Pet* ghost = new Pet(0);
        return ghost;
    }

    Pet* get_pet_by_num(int i)
    {
        return player_team[i-1];
    }

    Pet* get_enemy_by_num(int i)
    {
        return enemy_team[i-1];
    }
private:
    vector<Pet*> player_team;
    vector<Pet*> enemy_team;
};
//actions


//engine
void play(Team& team, std::istream& is, std::ostream& os);
int game_start(std::istream& is, std::ostream& os,Team& team,bool side);
bool query_choice(std::istream& is,int& choice,Team team,bool side);
int select_action(std::istream& is,std::ostream& os,Team team);
bool query_action(std::istream& is,int& choice);
void perform_change(std::istream& is,std::ostream& os, Pet*& pet, Team team,int choice);
bool query_change(std::istream& is,int& choice, int now_pet,bool side,Team team);
void perform_skill(std::istream& is, std::ostream& os,Pet* player_pet,Pet* enemy_pet,int choice,Weather& weather, bool can_paint);
void perform_enemy_skill(std::istream& is, std::ostream& os,Pet* player_pet,Pet* enemy_pet,int choice,Weather& weather, bool can_paint);
void perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os,Weather weather);
void enemy_perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os,Weather weather);
int enemy_skill(std::ostream& os,Team team,Pet* enemy_pet,Pet* player_pet,int player_id,Weather weather);
void enemy_change(std::ostream& os,Pet*& enemy_pet,Team team,int player_id);
int enemy_level(Team team,Pet* enemy_pet,int player_id,int r_potion,int a_potion,Weather weather);
int still_alive(Team team, bool side);
int is_win(Team team, int num_turns);
void enemy_change_output(std::ostream& os,Pet*& enemy_pet,bool on);
int Revival_Potion(Team& team);
int Attack_Potion(Pet*& enemy_pet);
void enemy_potion_output(std::ostream& os,int target_id,int potion_kind,Team team);
void skill_choice(std::istream& is, std::ostream& os,int& choice,Pet* pet);
void change_choice(std::istream& is, std::ostream& os,int& choice,Team team,Pet* pet);
int dead_choice(std::istream& is, std::ostream& os,Team team,Pet* pet);
void enemy_death_change(std::ostream& os,Pet*& enemy_pet,Team team);

int main()
{
    Team team;
    play(team, cin, cout);
}


//engine
void play(Team& team, std::istream& is, std::ostream& os)
{
    os << "Welcome to Battle of Pets!" << endl;
    os << "Enemy has W, G and Q." << endl;
    os << "You can select three from five (1 for W, 2 for L, 3 for G, 4 for Q, 5 for D)." << endl;

    Weather weather(normal);
    bool side;
    bool on;
    int potion_kind;
    int num_turns = 1;

    int player_pet_num = game_start(is,os,team,1);

    srand((unsigned)time(NULL));
    int enemy_pet_num = (rand() % 3) + 1;

    Pet* player_pet = team.getpet(1, player_pet_num);
    Pet* enemy_pet = team.get_enemy_by_num(enemy_pet_num);

    int r_potion = 1;
    int a_potion = 0;

    os << "You start with " << (player_pet)->get_name() <<endl;
    os << "Enemy starts with "<< (enemy_pet)->get_name() <<endl;
    os << "Your " << (player_pet)->get_name() << ": HP" <<(player_pet)->get_hp() << "||";
    os << "Enemy's " << (enemy_pet)->get_name() << ": HP" <<(enemy_pet)->get_hp() <<endl;
    os << "Battle starts!" << endl;
    os << "_______________________________________________________" << endl;

    while(is)
    {
        weather.length_decrease();
        if(weather.is_changed())
        {
            os << "Weather becomes normal" <<endl;
            weather.reset();
        }

        os << "Round " << num_turns <<endl;
        int target_id;

        int player_id = player_pet->get_id();
        int player_action_level;
        int enemy_action_level = enemy_level(team,enemy_pet,player_id,r_potion,a_potion,weather);
        int action_num;

        while(is)
        {
            int action_choice = 5 ;
            action_num = select_action(is,os,team);
            int enemy_skill_choice;
            //decide the player_level
            switch(action_num)
            {
            case 0:
                enemy_action_level = 8;
                break;
            case 1:
                player_action_level = 0;
                break;
            case 2:
                player_action_level = 6;
                break;
            }

            switch(action_num)
            {
            case 0:
                enemy_action_level = 8;
                break;
            case 1:
                skill_choice(is,os,action_choice,player_pet);
                break;
            case 2:
                change_choice(is,os,action_choice,team,player_pet);
                break;
            }

            if(action_num == 0)
            {
                break;
            }

            if(action_choice == 0)
            {
                continue;
            }

            if(player_pet->is_asleep()&&action_num==1)
            {
                os << "Your " << player_pet->get_name() << " is sleeping" <<endl;
            }
            if(enemy_pet->is_asleep())
            {
                os << "Enemy's " <<enemy_pet->get_name() << " is sleeping" <<endl;
            }
            if(action_num == 1)
            {
                Skill player_skill = player_pet->get_skill(action_choice-1);
                player_action_level = player_skill.get_level();
            }

            if(enemy_action_level == 0)
            {
                enemy_skill_choice = enemy_skill(os,team,enemy_pet,player_pet,player_id,weather);
                Skill enemy_skill = enemy_pet->get_skill(enemy_skill_choice);
                enemy_action_level = enemy_skill.get_level();
            }

            if(enemy_action_level < 2 && player_action_level < 2)
            {
                int player_speed = player_pet->get_speed();
                int enemy_speed = enemy_pet->get_speed();
                if(player_action_level > enemy_action_level)
                {
                    perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,true);
                    on = false;
                    if(player_pet->is_asleep())
                    {
                        perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,true);
                    }
                    else
                    {
                        perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,false);
                    }

                }
                else if(player_action_level < enemy_action_level)
                {
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,true);
                    if(enemy_pet->is_asleep())
                    {
                        perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,true);
                    }
                    else
                    {
                        perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,false);
                    }
                }
                else if(player_speed > enemy_speed)
                {
                    perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,true);
                    on = false;
                    if(player_pet->is_asleep())
                    {
                        perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,true);
                    }
                    else
                    {
                        perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,false);
                    }
                }
                else
                {
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,true);
                    if(enemy_pet->is_asleep())
                    {
                        perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,true);
                    }
                    else
                    {
                        perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,false);
                    }
                }
            }
            else if(player_action_level >= enemy_action_level)
            {
                switch(action_num)
                {
                case 0:
                    enemy_action_level = 8;
                    break;
                case 1:
                    perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,true);
                    break;
                case 2:
                    perform_change(is,os,player_pet,team,action_choice);
                    break;
                }

               switch(enemy_action_level)
                {
                case 0:
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,false);
                    break;
                case 1:
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,false);
                    break;
                case 6:
                    on = true;
                    enemy_change(os,enemy_pet,team,player_id);
                    break;
                case 5:
                    target_id = Revival_Potion(team);
                    r_potion--;
                    potion_kind = 1;
                    break;

                case 8:
                    break;
                }
                enemy_change_output(os,enemy_pet,on);
                on = false;
                enemy_potion_output(os,target_id,potion_kind,team);
                potion_kind = 0;
            }
            else
            {
               switch(enemy_action_level)
                {
                case 0:
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,true);
                    break;
                case 1:
                    on = false;
                    perform_enemy_skill(is,os,player_pet,enemy_pet,enemy_skill_choice,weather,false);
                    break;
                case 6:
                    on = true;
                    enemy_change(os,enemy_pet,team,player_id);
                    break;
                case 5:
                    target_id = Revival_Potion(team);
                    r_potion--;
                    potion_kind = 1;
                    break;

                case 8:
                    break;
                }
                enemy_change_output(os,enemy_pet,on);
                on = false;
                enemy_potion_output(os,target_id,potion_kind,team);
                potion_kind = 0;
                switch(action_num)
                {
                case 0:
                    perform_change(is,os,player_pet,team,action_choice);
                    break;
                case 1:
                    perform_skill(is,os,player_pet,enemy_pet,action_choice,weather,false);
                    break;
                }

            }
            break;
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
            perform_change(is, os, player_pet, team,2);//here
            os << "You Win" <<endl;
            break;
        }
        else if(flag == 3 && action_num == 0)
        {
            os<< "You Escape" <<endl;
            break;
        }
        else
        {
            if(player_pet->get_hp() <= 0)
            {
                int re_choice = dead_choice(is,os,team,player_pet);
                perform_change(is, os, player_pet, team,re_choice);
            }

            if(enemy_pet->get_hp() <= 0)
            {
                enemy_death_change(os,enemy_pet,team);
            }

            if(player_pet->is_asleep())
            {
                player_pet->wake();
            }
            if(player_pet->is_changed())
            {
                os << "Your " << player_pet->get_name() <<" wakes up" <<endl;
                player_pet->reset();
            }
            if(enemy_pet->is_asleep())
            {
                enemy_pet->wake();
            }
            if(enemy_pet->is_changed())
            {
                os << "Enemy's " << enemy_pet->get_name() <<" wakes up" <<endl;
                enemy_pet->reset();
            }

            os << "Your " << (player_pet)->get_name() << ": HP" <<(player_pet)->get_hp() << "||";
            os << "Enemy's " << (enemy_pet)->get_name() << ": HP" <<(enemy_pet)->get_hp() <<endl;

            os << "_______________________________________________________" << endl;
            num_turns++;
        }
    }

}
void enemy_death_change(std::ostream& os,Pet*& enemy_pet,Team team)
{
    if(team.getpet(0,3)->get_hp() > 0)
    {
        enemy_pet = team.getpet(0,3);
        os << "Enemy sends G" <<endl;
    }
    else if(team.getpet(0,1)->get_hp() > 0)
    {
        enemy_pet = team.getpet(0,1);
        os << "Enemy sends W" <<endl;
    }
    else
    {
        enemy_pet = team.getpet(0,4);
        os << "Enemy sends Q" <<endl;
    }
}

int still_alive(Team team,bool side)
{
    int alive_total = 0;
    for(int i = 1; i < 6; i++)
    {
        if(team.getpet(side,i)->is_alive())
        {
            alive_total++;
        }
    }
    return alive_total;
}

int Revival_Potion(Team& team)
{
    int target;
    for(int i = 1; i < 4; i++)
    {
        if(!(team.getpet(0,i))->is_alive())
        {
            (team.getpet(0,i))->revival();
            target = i;
        }
    }
    return target;
}
int Attack_Potion(Pet*& enemy_pet)
{
    enemy_pet->attack_double();
    return enemy_pet->get_id();
}
void enemy_potion_output(std::ostream& os,int target_id,int potion_kind,Team team)
{
    if(potion_kind == 1)
    {
       os<< "Enemy uses Revival Potion on " << team.getpet(0,target_id)->get_name()<<endl;
    }
    else if(potion_kind == 2)
    {
       os<< "Enemy uses Attack Potion on " << team.getpet(0,target_id)->get_name()<<endl;
    }
}

void enemy_change_output(std::ostream& os,Pet*& enemy_pet,bool on)
{
    if(on)
    {
        os << "Enemy sends " << enemy_pet->get_name() << endl;
    }
}

int enemy_level(Team team,Pet* enemy_pet,int player_id,int r_potion,int a_potion,Weather weather)
{
    int enemy_id = enemy_pet->get_id();
    int level;

    if(team.getpet(0,3)->get_hp() <= 0 && r_potion > 0)
    {
        level = 5;
    }
    else if(enemy_id == 1)
    {
        if(player_id == 2)
        {
            if(team.getpet(0,3)->get_hp()<=0)
            {
                level = 0;
            }
            else
            {
                level = 6;
            }
        }
        else
        {
            level = 0;
        }

    }
    else if(enemy_id == 3)
    {
        if(weather.get_type() == sunny)
        {
            level = 0;
        }
        else if(player_id == 4 || player_id == 1)
        {
            if(weather.get_type() == rainy)
            {
                level = 6;
            }
        }
        else
        {
            level = 0;
        }

    }
    else if(enemy_id == 4)
    {
        if(team.getpet(1,player_id)->get_hp() < team.getpet(1,player_id)->get_hp_max()/5)
        {
            level = 0;
        }
        else if(player_id == 2 && team.getpet(0,3)->get_hp()>0)
        {
            level = 6;
        }
        else if(player_id != 2 &&weather.get_type() != rainy && team.getpet(0,1)->get_hp()>0)
        {
            level = 6;
        }
        else
        {
            level = 0;
        }
    }
    return level;
}

void enemy_change(std::ostream& os,Pet*& enemy_pet,Team team,int player_id)
{
    int id = enemy_pet->get_id();

    if(player_id == 2 && id == 1 && team.getpet(0,3)->get_hp()>0)
    {
        enemy_pet = team.getpet(0,3);
    }
    else if(id == 3)
    {
        if(team.getpet(0,1)->get_hp() > 0 )
        {
            enemy_pet = team.getpet(0,1);
        }
        else
        {
            enemy_pet = team.getpet(0,4);
        }
    }
    else
    {
        if(player_id == 2)
        {
            enemy_pet = team.getpet(0,3);
        }
        else
        {
            enemy_pet = team.getpet(0,1);
        }
    }

}

int enemy_skill(std::ostream& os,Team team,Pet* enemy_pet,Pet* player_pet,int player_id,Weather weather)
{
    int id = player_id;
    int enemy_id = enemy_pet->get_id();
    int hp_max = player_pet->get_hp_max();
    int hp = player_pet->get_hp();
    int enemy_hp = enemy_pet->get_hp();
    int enemy_hp_max = enemy_pet->get_hp_max();

    if(enemy_id == 4)
    {
        if(enemy_hp < enemy_hp_max/5)
        {
            return 0;
        }
        else if(player_id == 2 && team.getpet(0,3)->get_hp() <= 0)
        {
            return 1;
        }
        else if(player_id !=2 && weather.get_type() == rainy)
        {
            return 2;
        }
        else if(player_id == 4 || player_id == 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(enemy_id == 1)
    {
        if(player_id == 2 && team.getpet(0,3)->get_hp() <=0)
        {
            if(enemy_hp >= enemy_hp_max*2/3)
            {
                return 0;
            }
            else
            {
                return 2;
            }
        }
        else if(player_id == 1)
        {
            if(enemy_hp >= enemy_hp_max/2)
            {
                return 0;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            if(enemy_hp >= enemy_hp_max/2 || hp < hp_max/5)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        if(weather.get_type() == sunny)
        {
            cout <<"herer" <<endl;
            return  2;
        }
        else
        {
            if(id == 4 || (id == 1 && weather.get_type() == rainy))
            {
                return 1;
            }
            else if(player_id == 3)
            {
                return 0;
            }
            else if(weather.get_type() == rainy)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}

void skill_choice(std::istream& is, std::ostream& os,int& choice,Pet* pet)
{
    while(is)
    {
        os << "Select the skill (0 for back, ";
        for(int i = 0; i < 2;i++)
        {
            os << (i+1) << " for " << pet->get_unique_skill(i) << ", ";
        }
        os << "3 for " << pet->get_unique_skill(2) << "):";
        is >> choice;
        if(choice >= 0 && choice <= 3)
        {
            break;
        }
    }
}
void change_choice(std::istream& is, std::ostream& os,int& choice,Team team,Pet* pet)
{

    while(is)
    {
        os << "Select your next pet(0 for back, ";
        int id = pet->get_id();
        string output = "";
        for(int i = 1;i<4;i++)
        {
            Pet* choice_pet = team.get_pet_by_num(i);
            if(choice_pet->get_id() != id && choice_pet->is_alive())
            {
                char num = '0'+i;
                output+=num;
                output+=" for ";
                string name = choice_pet->get_name();
                output+=name;
                output+="-HP";
                int hp = choice_pet->get_hp();
                string hp_str = to_string(hp);
                output+=hp_str;
                output+=", ";
            }

        }
        output.erase(output.size()-1);
        output.erase(output.size()-1);
        output+="):";
        os << output;

        if(query_change(is, choice,id,1,team))
        {
            break;
        }
    }

}

int dead_choice(std::istream& is, std::ostream& os,Team team,Pet* pet)
{
    int choice;
    while(is)
    {
        os << "Select your next pet( ";
        int id = pet->get_id();
        string output = "";
        for(int i = 1;i<4;i++)
        {
            Pet* choice_pet = team.get_pet_by_num(i);
            if(choice_pet->get_id() != id && choice_pet->is_alive())
            {
                char num = '0'+i;
                output+=num;
                output+=" for ";
                string name = choice_pet->get_name();
                output+=name;
                output+="-HP";
                int hp = choice_pet->get_hp();
                string hp_str = to_string(hp);
                output+=hp_str;
                output+=", ";
            }

        }
        output.erase(output.size()-1);
        output.erase(output.size()-1);
        output+="):";
        os << output;

        if(query_change(is, choice,id,1,team))
        {
            break;
        }
    }
    return choice;
}
void perform_enemy_skill(std::istream& is, std::ostream& os,Pet* enemy_pet,Pet* player_pet,int choice,Weather& weather, bool can_paint)
{
    string skill_name = player_pet->get_unique_skill(choice);
    if(player_pet->is_asleep() || player_pet->get_hp() <= 0 )
    {

    }
    else if(skill_name == "Sing")
    {
        if(enemy_pet->is_asleep())
        {
            os << "Enemy's D uses Sing! Waste" <<endl;
        }
        else
        {
            enemy_pet->fall_asleep();
            os << "Enemy's D uses Sing! Your " << enemy_pet->get_name() << " falls asleep" <<endl;
        }
    }
    else if(skill_name == "Paint")
    {
        if(can_paint)
        {
            enemy_pet->be_painted();
            os << "Enemy's D uses Paint! Your " << enemy_pet->get_name() << " is painted"<<endl;
        }
        else
        {
            os << "Enemy's D uses Paint! Failure"<<endl;
        }

    }
    else if(skill_name == "Synthesis")
    {
        int recovery;
        weather_type type = weather.get_type();
        if(type == sunny)
        {
            recovery = player_pet->synthesis(40);
        }
        else if(type == rainy)
        {
            recovery = player_pet->synthesis(20);
        }
        else
        {
            recovery = player_pet->synthesis(30);
        }
        os << "Enemy's W uses Synthesis! Recovery: "<< recovery <<endl;
    }
    else if(skill_name == "Sunny")
    {
        weather.change_type(sunny,5);
        os << "Enemy's L uses Sunny! Weather becomes sunny" <<endl;
    }
    else if(skill_name == "Rainy")
    {
        weather.change_type(rainy,5);
        os << "Enemy's G uses Rainy! Weather becomes rainy" <<endl;
    }
    else if(skill_name == "Thunder")
    {
        if(weather.get_type()!=rainy)
        {
            os << "Enemy's Q uses Thunder! Failure"<<endl;
        }
        else
        {
            int attack = player_pet->get_attack();
            int defence = enemy_pet->get_defence();
            int damage = 50*attack/defence;
            int enemy_id = enemy_pet->get_id();

            if(enemy_id == 1 || enemy_id == 4)
            {
                damage*=0.5;
            }
            else if(enemy_id == 3)
            {
                damage*=2;
            }
            enemy_pet->lose_hp(damage);

            os << "Enemy's Q uses Thunder! Damage: " << damage << endl;
            if(enemy_pet->is_asleep())
            {
                enemy_pet->wake_up();
                if(enemy_pet->get_hp() > 0)
                {
                    os << "Your " << enemy_pet->get_name() << " wakes up" <<endl;
                }
            }
        }
    }
    else
    {
        enemy_perform_damage(player_pet,enemy_pet,choice,os,weather);
    }
}
void perform_skill(std::istream& is, std::ostream& os,Pet* player_pet,Pet* enemy_pet,int choice,Weather& weather,bool can_paint)
{
    string skill_name = player_pet->get_unique_skill(choice-1);
    if(player_pet->is_asleep() || player_pet->get_hp() <= 0 )
    {

    }
    else if(skill_name == "Sing")
    {
        if(enemy_pet->is_asleep())
        {
            os << "Your D uses Sing! Waste" <<endl;
        }
        else
        {
            enemy_pet->fall_asleep();
            os << "Your D uses Sing! Enemy's " << enemy_pet->get_name() << " falls asleep" <<endl;
        }
    }
    else if(skill_name == "Paint")
    {
        if(can_paint)
        {
            enemy_pet->be_painted();
            os << "Your D uses Paint! Enemy's " << enemy_pet->get_name() << " is painted"<<endl;
        }
        else
        {
            os << "Your D uses Paint! Failure"<<endl;
        }

    }
    else if(skill_name == "Synthesis")
    {
        int recovery;
        weather_type type = weather.get_type();
        if(type == sunny)
        {
            recovery = player_pet->synthesis(40);
        }
        else if(type == rainy)
        {
            recovery = player_pet->synthesis(20);
        }
        else
        {
            recovery = player_pet->synthesis(30);
        }
        os << "Your W uses Synthesis! Recovery: "<< recovery <<endl;
    }
    else if(skill_name == "Sunny")
    {
        weather.change_type(sunny,5);
        os << "Your L uses Sunny! Weather becomes sunny" <<endl;
    }
    else if(skill_name == "Rainy")
    {
        weather.change_type(rainy,5);
        os << "Your G uses Rainy! Weather becomes rainy" <<endl;
    }
    else if(skill_name == "Thunder")
    {
        if(weather.get_type()!=rainy)
        {
            os << "Your Q uses Thunder! Failure"<<endl;
        }
        else
        {
            int attack = player_pet->get_attack();
            int defence = enemy_pet->get_defence();
            int damage = 50*attack/defence;
            int enemy_id = enemy_pet->get_id();

            if(enemy_id == 1 || enemy_id == 4)
            {
                damage*=0.5;
            }
            else if(enemy_id == 3)
            {
                damage*=2;
            }
            enemy_pet->lose_hp(damage);

            os << "Your Q uses Thunder! Damage: " << damage << endl;
            if(enemy_pet->is_asleep())
            {
                enemy_pet->wake_up();
                if(enemy_pet->get_hp() > 0)
                {
                    os << "Enemy's " << enemy_pet->get_name() << " wakes up" <<endl;
                }
            }
        }
    }
    else
    {
    perform_damage(player_pet,enemy_pet,choice,os,weather);
    }

}

void perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os,Weather weather)
{
    Skill skill = player_pet->get_skill(choice-1);
    string skill_name = player_pet->get_unique_skill(choice-1);
    weather_type type = weather.get_type();
    int nature = skill.get_nature();

    int attack = player_pet->get_attack();
    int defence = enemy_pet->get_defence();
    int player_id = player_pet->get_id();
    int enemy_id = enemy_pet->get_id();

    int  damage = (skill.get_power())*attack/defence;

    if(type == sunny)
    {
        if(nature == 2)
        {
            damage*=1.5;
        }
        else if(nature == 3)
        {
            damage*=0.5;
        }
    }

    if(type == rainy)
    {
        if(nature == 2)
        {
            damage*=0.5;
        }
        else if(nature == 3)
        {
            damage*=1.5;
        }
    }

    if((nature == 2 && enemy_id == 1)||(nature == 3 && enemy_id == 2)||
       (nature == 4 && enemy_id == 3)||(nature == 1 && enemy_id == 3))
    {
        damage*=2;
    }

    if((nature == enemy_id && nature != 5)||(nature == 1 && enemy_id == 2)||
       (nature == 2 && enemy_id == 3)||(nature == 3 && enemy_id == 1)||
       (nature == 4 && enemy_id == 1))
    {
        damage*=0.5;
    }
    if(skill_name == "Slap" && enemy_pet->is_asleep())
    {
        damage*=2;
    }
    enemy_pet->lose_hp(damage);

    os << "Your " << player_pet->get_name() << " uses " <<skill_name<<"! Damage: " << damage << endl;

    if(enemy_pet->is_asleep())
    {
        enemy_pet->wake_up();
        if(enemy_pet->get_hp()> 0)
        {
            os << "Enemy's " << enemy_pet->get_name() << " wakes up" <<endl;
        }
    }

}

void enemy_perform_damage(Pet* player_pet,Pet* enemy_pet,int choice,std::ostream& os,Weather weather)
{
    Skill skill = player_pet->get_skill(choice);
    string  skill_name = player_pet->get_unique_skill(choice);
    weather_type type = weather.get_type();
    int nature = skill.get_nature();

    int attack = player_pet->get_attack();
    int defence = enemy_pet->get_defence();
    int player_id = player_pet->get_id();
    int enemy_id = enemy_pet->get_id();

    int  damage = (skill.get_power())*attack/defence;

    if(type == sunny)
    {
        if(nature == 2)
        {
            damage*=1.5;
        }
        else if(nature == 3)
        {
            damage*=0.5;
        }
    }

    if(type == rainy)
    {
        if(nature == 2)
        {
            damage*=0.5;
        }
        else if(nature == 3)
        {
            damage*=1.5;
        }
    }

    if((nature == 2 && enemy_id == 1)||(nature == 3 && enemy_id == 2)||
       (nature == 4 && enemy_id == 3)||(nature == 1 && enemy_id == 3))
    {
        damage*=2;
    }

    if((nature == enemy_id && nature != 5)||(nature == 1 && enemy_id == 2)||
       (nature == 2 && enemy_id == 3)||(nature == 3 && enemy_id == 1)||
       (nature == 4 && enemy_id == 1))
    {
        damage*=0.5;
    }
    if(skill_name == "Slap" && enemy_pet->is_asleep())
    {
        damage*=2;
    }

    enemy_pet->lose_hp(damage);

    os << "Enemy's " << player_pet->get_name() << " uses " <<skill.get_name()<<"! Damage: " << damage << endl;

    if(enemy_pet->is_asleep())
    {
        enemy_pet->wake_up();
        if(enemy_pet->get_hp()> 0)
        {
            os << "Your " << enemy_pet->get_name() << " wakes up" <<endl;
        }
    }

}

void perform_change(std::istream& is, std::ostream& os,Pet*& pet, Team team,int choice)
{
    pet = team.get_pet_by_num(choice);
    os << "You send " << pet->get_name() << endl;
}


int select_action(std::istream& is, std::ostream& os, Team team)
{
    int action_choice;
    int alive = still_alive(team,1);

    if(alive == 1)
    {
        while(is)
        {
            os << "Select your action (0 for escape, 1 for skill):";
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
            os << "Select your action (0 for escape, 1 for skill, 2 for change):";
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
        if(choice > 2 || choice < 0)
        {
            return false;
        }
        return true;
    }
}

int game_start(std::istream& is, std::ostream& os,Team& team,bool side)
{
    int choice;
    int first;
    while(is)
    {
        os << "Select your 1st pet:";

        if(query_choice(is, first,team,side))
        {
            team.player_team_add(first);
            break;
        }
    }
    while(is)
    {
        os << "Select your 2nd pet:";

        if(query_choice(is, choice,team,side))
        {
            team.player_team_add(choice);
            break;
        }
    }
    while(is)
    {
        os << "Select your 3rd pet:";

        if(query_choice(is, choice,team,side))
        {
            team.player_team_add(choice);
            break;
        }
    }
    return first;
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

        if(choice == 0)
        {
            return true;
        }
        else
        {
            if(choice > 3 || choice < 0  )
            {
                return false;
            }
            int choice_id = team.get_pet_by_num(choice)->get_id();
            if(choice_id == now_pet)
            {
                return false;
            }
            if(!(team.get_pet_by_num(choice))->is_alive())
            {
                return false;
            }
            return true;
        }

    }

}

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
        if(choice > 5 || choice <= 0)
        {
            return false;
        }
        if(team.player_team_exist(choice))
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
        flag = 3;
    }
    return flag;
}
//actions



