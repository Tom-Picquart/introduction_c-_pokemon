//
// Created by tompi on 18/09/2026.
//

#ifndef TICTACTOE_STARTSTATE_H
#define TICTACTOE_STARTSTATE_H
#include "GameState.h"
class StartState : public GameState
{
public:
    void handleEvent(Game& game, const sf::Event& event) override;
    void update(Game& game) override;
    void render(Game& game) override;
};
#endif //TICTACTOE_STARTSTATE_H
