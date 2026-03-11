#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include "GameState.h"
#include "ScoringSystem.h"
#include "ShopSystem.h"

class RunSession
{
public:
    RunSession();
    void StartGame();

private:
    void PlayerAction();      // Step 1–2
    void ResolveSystem();     // Step 3–4
    void UpdateState();       // Step 5
    void CheckTarget();       // Step 6–7
    void OpenShop();          // Step 8–9
    bool IsGameOver();

    GameState state_;
    ScoringSystem scoring_;
    ShopSystem shop_;
};

#endif