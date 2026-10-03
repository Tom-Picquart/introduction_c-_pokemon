//
// Created by tompi on 27/09/2026.
//
#include "../Inc/RestState.h"
#include "../Inc/BattleState.h"
#include "../Inc/Game.h"

#include <iostream>
#include <memory>

#include "../Inc/RestState.h"

#include "../Inc/Game.h"
#include "../Inc/BattleState.h"

#include <iostream>
RestState::RestState() {
};

RestState::RestState(std::unique_ptr<Pokemon> defeatedPokemon): defeatedPokemon(std::move(defeatedPokemon)){
}

void RestState::initializeSprites(Game& game){
    if (!partySprites.empty())
        return;
    Pokemon_Party& party = game.getParty();
    for (int i = 0; i < party.getSize(); i++){
        Pokemon* pokemon = party.getPokemon(i);
        if (pokemon == nullptr) {
            continue;
        }
        auto sprite = std::make_unique<PokemonSprite>();
        if (sprite->load(*pokemon)){sprite->setScale(2.5f, 2.5f);}
        partySprites.push_back(std::move(sprite));
    }
}
void RestState::handleEvent(Game& game,const sf::Event& event) {
    if (event.type != sf::Event::MouseButtonPressed)
        return;
    if (event.mouseButton.button != sf::Mouse::Left)
        return;
    float x = static_cast<float>(event.mouseButton.x);
    float y = static_cast<float>(event.mouseButton.y);
    handleMouseClick(game, x, y);
}

void RestState::handleMouseClick(Game& game,float x,float y){
    if (selectingPokemon){
        int index = getPokemonIndexAt(x, y);
        if (index != -1){
            selectPokemon(game, index);
        }
        return;
    }

    if (x >= 100.f &&x <= 450.f &&y >= 630.f &&y <= 800.f){
        healParty(game);
        return;
    }

    if (x >= 500.f &&x <= 850.f &&y >= 630.f &&y <= 800.f){
        selectingPokemon = true;
        return;
    }

    if (x >= 900.f &&x <= 1250.f &&y >= 630.f &&y <= 800.f){
        capturePokemon(game);
        return;
    }
}
void RestState::capturePokemon(Game& game){
    if (defeatedPokemon == nullptr) {
        return;
    }

    if (capturedPokemon) {
        return;
    }

    Pokemon_Party& party = game.getParty();
    if (party.getSize() >= 6){
        std::cout<< "Your party is full!"<< std::endl;
        return;
    }
    std::cout<< defeatedPokemon->getName()<< " was captured!"<< std::endl;

    party.addToParty(*defeatedPokemon);
    capturedPokemon = true;
    defeatedPokemon.reset();
    partySprites.clear();
}

void RestState::healParty(Game& game){
    if (!game.canHeal())
    {
        std::cout << "No heals remaining!"<< std::endl;
        return;
    }

    game.healParty();
    std::cout << "Your entire party has been healed!"<< std::endl;
}

void RestState::selectPokemon(Game& game,int index){
    Pokemon* pokemon = game.getParty().getPokemon(index);
    if (pokemon == nullptr) {
        return;
    }
    game.getParty().sendtoBattle(index);
    game.setState(std::make_unique<BattleState>());
}

int RestState::getPokemonIndexAt(float x,float y) const{
    const float cardWidth = 500.f;
    const float cardHeight = 170.f;

    const float startX = 100.f;
    const float startY = 50.f;

    const float gapX = 40.f;
    const float gapY = 40.f;

    for (int i = 0; i < 6; i++)
    {
        int column = i % 2;
        int row = i / 2;

        float cardX =startX + column * (cardWidth + gapX);
        float cardY =startY + row * (cardHeight + gapY);

        if (x >= cardX && x <= cardX + cardWidth && y >= cardY && y <= cardY + cardHeight){
            return i;
        }
    }
    return -1;
}

void RestState::update(Game& game){
    initializeSprites(game);
    if (defeatedPokemon != nullptr && defeatedSprite == nullptr){
        defeatedSprite =std::make_unique<PokemonSprite>();
        defeatedSprite->load(*defeatedPokemon);
        defeatedSprite->setScale(2.5f,2.5f);
        defeatedSprite->setPosition(850.f,300.f);
    }
}

void RestState::render(Game& game){
    sf::RenderWindow& window =game.getWindow();
    Pokemon_Party& party =game.getParty();

    sf::Text title;
    title.setFont(game.getFont());
    title.setString(selectingPokemon? "CHOOSE YOUR POKEMON": "REST");
    title.setCharacterSize(36);
    title.setPosition(500.f, 15.f);
    window.draw(title);

    if (defeatedPokemon != nullptr)
    {
        sf::Text captureTitle;
        captureTitle.setFont(game.getFont());
        captureTitle.setString("DEFEATED POKEMON");
        captureTitle.setCharacterSize(24);
        captureTitle.setPosition(850.f,230.f);
        window.draw(captureTitle);

        if (defeatedSprite != nullptr){
            defeatedSprite->draw(window);
        }
        sf::Text defeatedName;
        defeatedName.setFont(game.getFont());
        defeatedName.setString(defeatedPokemon->getName());
        defeatedName.setCharacterSize(24);
        defeatedName.setPosition(850.f,250.f);
        window.draw(defeatedName);
    }

    for (int i = 0;i < party.getSize();i++)
    {
        Pokemon* pokemon =party.getPokemon(i);
        if (pokemon == nullptr)
            continue;
        int column = i % 2;
        int row = i / 2;
        float cardX = 100.f + column * 540.f;
        float cardY = 50.f + row * 180.f;

        if (i < static_cast<int>(partySprites.size())){
            partySprites[i]->setPosition(cardX ,cardY );
            partySprites[i]->draw(window);
        }

        sf::Text name;
        name.setFont(game.getFont());
        name.setString(pokemon->getName());
        name.setCharacterSize(24);
        name.setPosition(cardX -30.f ,cardY +50.f );
        window.draw(name);

        sf::Text hp;
        hp.setFont(game.getFont());
        hp.setString("HP: "+ std::to_string((int)pokemon->getHitPoint())+ " / "+ std::to_string((int)pokemon->getMaxHitPoint()));
        hp.setCharacterSize(20);
        hp.setPosition(cardX -30.f ,cardY + 70.f);
        window.draw(hp);
    }

    sf::Text healText;
    healText.setFont(game.getFont());
    healText.setString("HEAL ALL");
    healText.setCharacterSize(26);
    healText.setPosition(190.f,650.f);
    window.draw(healText);

    sf::Text healCount;
    healCount.setFont(game.getFont());
    healCount.setString(std::to_string(game.getRemainingHeals())+ " heals remaining");
    healCount.setCharacterSize(18);
    healCount.setPosition(180.f,680.f);
    window.draw(healCount);

    sf::Text changeText;
    changeText.setFont(game.getFont());

    if (selectingPokemon){
        changeText.setString("SELECT A POKEMON");
    }
    else
    {
        changeText.setString("SELECT A POKEMON TO \n SEND TO BATTLE");
    }

    changeText.setCharacterSize(24);
    changeText.setPosition(550.f,650.f);
    window.draw(changeText);
    sf::Text captureText;
    captureText.setFont(game.getFont());

    if (defeatedPokemon != nullptr && !capturedPokemon){
        captureText.setString("CAPTURE");
    }
    else
    {
        captureText.setString("NO POKEMON \n TO CAPTURE");
    }
    captureText.setCharacterSize(26);
    captureText.setPosition(1000.f,650.f);
    window.draw(captureText);
}