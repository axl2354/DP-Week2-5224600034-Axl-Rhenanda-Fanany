#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState
{
public:
    GameState();

    int score;
    int handsRemaining;
    int discardsRemaining;
    int target;
};

#endif