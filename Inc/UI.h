//
// Created by tompi on 29/09/2026.
//

#ifndef TICTACTOE_UI_H
#define TICTACTOE_UI_H
#include <SFML/Graphics.hpp>
#include <string>

class UI{
private:
    sf::Font font;
public:
    UI();
    bool loadFont(const std::string& path);
    void drawText(sf::RenderWindow& window,const std::string& text,float x,float y,unsigned int size);
};
#endif //TICTACTOE_UI_H
