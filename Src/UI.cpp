//
// Created by tompi on 29/09/2026.
//
#include "../Inc/UI.h"

#include <iostream>

UI::UI(){}

bool UI::loadFont(const std::string& path){
    if (!font.loadFromFile(path)){
        std::cerr << "Unable to load font: "<< path<< std::endl;
        return false;}
    return true;
}

void UI::drawText(sf::RenderWindow& window,const std::string& text,float x,float y,unsigned int size){
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(size);
    sfText.setPosition(x, y);
    window.draw(sfText);}