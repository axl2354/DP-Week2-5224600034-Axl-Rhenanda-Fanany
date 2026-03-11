#include <iostream>
using namespace std;

class PlayerAction {
public:
    void Execute() {
        cout << "Player choosing the hand or discard." << endl;
    }
};

class SystemResolver {
public:
    void EvaluateHand() {
        cout << "Evaluating the Poker hand." << endl;
    }

    void CalculateScore() {
        cout << "Calculating the score." << endl;
    }
};

class GameState {
public:
    int score = 0;

    void Update() {
        cout << "Updating the game state." << endl;
    }

    bool IsGameOver() {
        return false;
    }
};

class GameSession {
private:
    PlayerAction player;
    SystemResolver system;
    GameState state;

public:
    void StartGame() {

        while (!state.IsGameOver()) {

            player.Execute();         
            system.EvaluateHand();     
            system.CalculateScore();    
            state.Update();             

            cout << "Loops the rooms https://www.youtube.com/watch?v=icBDYkfxpMs\n" << endl;
            break; 
        }
    }
};

int main() {

    GameSession session;
    session.StartGame();

    return 0;

}
