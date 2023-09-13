#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <vector>


class Team
{
public:
    Team();

private:
    vector<pet> player_team;
    vector<pet> enemy_team;
};

#endif // TEAM_H_INCLUDED
