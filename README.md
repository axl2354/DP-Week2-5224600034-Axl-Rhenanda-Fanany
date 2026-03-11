# DP-Week2-5224600034-Axl-Rhenanda-Fanany
Game Concept:
Balatro clone

Step 1 — Core Loop
The core loop is:
1.Player chooses play or discard
2.player chooses index of card to play and discard
3.system calculates score or discards card
4.tokers adds score
5.updates total score, remaining hand and discards
6.system checks if target is reached
7.if target is reached player gets rewards if not goes to step 1 or until no hands left in which case player loses
8.player goes to shop and chooses to buy or not
9.if player doesnt buy, target increases and goes back to step 1. if player buys go to step 8 again

Step 2 — Invariant Identification
The following sequence must remain fixed:
1.	Player action
2.	Card selection
3.	System resolution (play or discard)
4.	Modifier application
5.	Game state update
6.	Target check
7.	Reward decision
8.	Shop interaction
This order is required because each step depends on the result of the previous one.
For example:
•	The system cannot calculate the score before the player selects cards.
•	Tokers cannot modify the score before it is calculated.
•	The target cannot be checked before the score is updated.


Required Components
The game must always have:
•	RunSession / GameSession 
•	Deck 
•	Hand 
•	ScoringSystem 
•	Toker / Modifier system 
•	GameState 
•	ShopSystem 
Without these, the loop cannot function. These are structural necessities.

Step 3 — Mutable Elements
The following parts are mutable:
1. Target score
Can change target according to difficulty
Does not affect loop structure
2. Toker Effects
Can be added without changing core loop
3. Reward amount
Changes amount of dooller can change.
4. Number of hands and discards
Can change depending on tokers or upgrades.

Step 4 — C++ Core Loop Skeleton
Below is my minimal OOP skeleton reflecting the invariant loop.
File structure :
RunSession.h
RunSession.cpp
GameState.h
GameState.cpp
ScoringSystem.h
ScoringSystem.cpp
ShopSystem.h
ShopSystem.cpp
main.cpp

Character.h
#ifndef CHARACTER_H
#define CHARACTER_H
class Character {
public:
Character(int hp, int attack);
int GetHP() const;
int GetAttack() const;
void TakeDamage(int damage);
private:
int hp_;
int attack_;
};
#endif

4

Character.cpp
#include "Character.h"
Character::Character(int hp, int attack)
: hp_(hp), attack_(attack) {}
int Character::GetHP() const {
return hp_;
}
int Character::GetAttack() const {
return attack_;
}
void Character::TakeDamage(int damage) {
hp_ -= damage;
}

CombatResolver.h
#ifndef COMBAT_RESOLVER_H
#define COMBAT_RESOLVER_H
class CombatResolver {
public:
int ComputeDamage(int attackValue) const;
};
#endif
CombatResolver.cpp
#include "CombatResolver.h"
int CombatResolver::ComputeDamage(int attackValue) const {
return attackValue; // placeholder logic
}

GameSession.h
#ifndef GAME_SESSION_H
#define GAME_SESSION_H
#include "Character.h"
#include "CombatResolver.h"
class GameSession {
public:
GameSession();
void StartGame();
private:
void PlayerTurn();
void EnemyTurn();
void CheckOutcome();

5

bool IsGameOver() const;
Character player_;
Character enemy_;
CombatResolver resolver_;
};
#endif

GameSession.cpp
#include <iostream>
#include "GameSession.h"
GameSession::GameSession()
: player_(100, 10),
enemy_(50, 8) {}
void GameSession::StartGame() {
while (!IsGameOver()) {
PlayerTurn();
EnemyTurn();
CheckOutcome();
}
std::cout << "Game Over\n";
}
void GameSession::PlayerTurn() {
std::cout << "Player attacks\n";
int damage = resolver_.ComputeDamage(player_.GetAttack());
enemy_.TakeDamage(damage);
}
void GameSession::EnemyTurn() {
std::cout << "Enemy attacks\n";
int damage = resolver_.ComputeDamage(enemy_.GetAttack());
player_.TakeDamage(damage);
}
void GameSession::CheckOutcome() {
if (enemy_.GetHP() <= 0) {
std::cout << "Player wins!\n";
}
if (player_.GetHP() <= 0) {
std::cout << "Enemy wins!\n";
}
}
bool GameSession::IsGameOver() const {
return player_.GetHP() <= 0 || enemy_.GetHP() <= 0;
}

6

main.cpp
#include "GameSession.h"
int main() {
GameSession game;
game.StartGame();
return 0;
}

Explanation of Architectural Discipline
1.	RunSession controls the invariant loop order of the game.
2.	ScoringSystem handles score calculation, keeping game logic separate from the session loop.
3.	GameState stores all mutable game data, such as score, hands, discards, and target.
4.	ShopSystem handles purchasing mechanics, keeping shop logic independent.
5.	The loop order is fixed inside StartGame() to preserve the invariant gameplay structure.
6.	If the scoring formula changes, only ScoringSystem needs modification.
7.	If shop behavior changes, only ShopSystem changes.
Because responsibilities are separated, new features can be added without modifying the core loop, preserving the architecture of the game.

