//
//  board.hpp
//  TTT
//
//  Created by Dipti Karmarkar on 8/15/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

enum Token
{
    Empty,
    Red,
    Yellow,
    
};



class Board
{
public:
    Board(int xSize, int ySize,  sf::RenderWindow &window);
    void draw();
    void playermove(sf::Vector2i position, Token playercolor);
    Token getstatus(sf::Vector2i pos);
    bool endofGame();
    Token horizontal();
    Token vertical();
    Token diagonal();
    
    
    
private:
    float tilesize;
    float outlinesize;
    
    Token board[3][3];
    
    // Colors of the board
    sf::Color redColor;
    sf::Color yellowColor;
    sf::Color emptyColor;
    sf::Color boardColor;
    
    //sf::RectangleShape rect;
    
    sf::RenderWindow &window;
    
    
    
    
};

#endif /* board_hpp */
