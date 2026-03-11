#include <iostream>
#include "RunSession.h"

RunSession::RunSession() {}

void RunSession::StartGame()
{
    while (!IsGameOver())
    {
        PlayerAction();     // Step 1–2
        ResolveSystem();    // Step 3–4
        UpdateState();      // Step 5
        CheckTarget();      // Step 6–7
    }

    std::cout << "Game Over\n";
}

void RunSession::PlayerAction()
{
    std::cout << "Player chooses play or discard and selects card indexes.\n";
}

void RunSession::ResolveSystem()
{
    std::cout << "System calculates score or discards cards.\n";
    std::cout << "Tokers modify the score.\n";
}

void RunSession::UpdateState()
{
    std::cout << "Updating total score, hands remaining, and discards.\n";
}

void RunSession::CheckTarget()
{
    std::cout << "Checking if target score is reached.\n";

    bool targetReached = false; // placeholder

    if (targetReached)
    {
        std::cout << "Target reached. Reward granted.\n";
        OpenShop();
    }
}

void RunSession::OpenShop()
{
    std::cout << "Player enters shop and decides whether to buy Tokers.\n";
}

bool RunSession::IsGameOver()
{
    return false; // placeholder condition
}