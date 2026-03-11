#include <iostream>
using namespace std;

class PlayerInput {
public:
    void ChooseAction() {
        cout << "Player chooses play or discard." << endl;
    }

    void ChooseIndexes() {
        cout << "Player chooses card indexes." << endl;
    }
};

class SystemLogic {
public:
    void ResolveAction() {
        cout << "System calculates score or discards cards." << endl;
    }

    void ApplyTokers() {
        cout << "Tokers modify the score." << endl;
    }
};

class GameState {
public:
    void UpdateState() {
        cout << "Updating score, hands, and discards." << endl;
    }

    bool CheckTarget() {
        cout << "Checking if target score is reached." << endl;
        return false;
    }

    bool NoHandsLeft() {
        return false;
    }
};

class ShopSystem {
public:
    void OpenShop() {
        cout << "Player enters shop and chooses to buy or not." << endl;
    }
};

class GameSession {

private:
    PlayerInput player;
    SystemLogic system;
    GameState state;
    ShopSystem shop;

public:

    void StartGame() {

        while (true) {

            player.ChooseAction();      // Step 1
            player.ChooseIndexes();    // Step 2

            system.ResolveAction();    // Step 3
            system.ApplyTokers();      // Step 4

            state.UpdateState();       // Step 5

            if (state.CheckTarget()) { // Step 6–7
                shop.OpenShop();       // Step 8–9
            }

            if (state.NoHandsLeft()) {
                cout << "Player loses." << endl;
                break;
            }

            cout << "Loops the rooms https://www.youtube.com/watch?v=icBDYkfxpMs\n" << endl;
            break; 
        }
    }
};

int main() {

    GameSession game;
    game.StartGame();

    return 0;
}
