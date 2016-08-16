//
//  board.cpp
//  TTT
//
//  Created by Dipti Karmarkar on 8/15/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "board.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>



Board::Board(int xSize, int ySize, sf::RenderWindow &window) : window(window)
{
    tilesize = xSize/3;
    
    // Set the colors of the board
    boardColor      = sf::Color::Color(0, 102, 153);
    redColor        = sf::Color::Color(214, 71, 0);
    yellowColor     = sf::Color::Color(235,235,0);
    emptyColor      = sf::Color::Color(224,224,224);
  
    
    //other dimensions
    outlinesize = 2;
    //tilesize = tilesize ;
    
    for (int x = 0; x<3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            board[x][y]= Empty;

        }
    }
}

void Board::draw()
{
    for (int x = 0; x<3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            sf::Color fillcolor;
            if (board[x][y] == Empty)
            {
                fillcolor = emptyColor;
            }
            else if (board[x][y] == Red)
            {
                fillcolor = redColor;
            }
            else
                fillcolor = yellowColor;
            
            //now to draw the actual shape
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(tilesize, tilesize));
            rect.setPosition(x*(tilesize+1),y*(tilesize+1));
            rect.setFillColor(fillcolor);
            rect.setOutlineThickness(outlinesize);
            rect.setOutlineColor(sf::Color::Black);
            window.draw(rect);
        }
    }
}

void Board::playermove(sf::Vector2i position, Token playercolor)
{
    //want to get the x and y of the board that has been clicked
    int x = position.x;
    int y = position.y;
    
    x = x/tilesize;
    y = y/tilesize;
    
    board[x][y]=playercolor;
    
}


Token Board::getstatus(sf::Vector2i position)
{
    int x = position.x;
    int y = position.y;
    
    x = x/tilesize;
    y = y/tilesize;
    
    return board[x][y];
}

bool Board::endofGame()
{
    int count_empty = 0;
    for (int x = 0; x<3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y]==Empty)
                count_empty++;
        }
    }
    
    if (count_empty==0)
    {
        return true;
    }
    
    if (horizontal()!= Empty || vertical()!= Empty || diagonal()!= Empty)
    {
        return true;
    }
    
    else return false;
    
}

Token Board::horizontal()
{
    if (board[0][0]==board[0][1] && board[0][1]==board[0][2])
    {
        return board[0][0];
    }
    
    if (board[1][0]==board[1][1] && board[1][1]==board[1][2])
    {
        return board[1][0];
    }
    if (board[2][0]==board[2][1] && board[2][1]==board[2][2])
    {
        return board[2][0];
    }
    return Empty;
}

Token Board::vertical()
{
    if (board[0][0]==board[1][0] && board[1][0]==board[2][0])
    {
        return board[0][0];
    }
    if (board[0][1]==board[1][1] && board[1][1]==board[2][1])
    {
        return board[0][1];
    }
    if (board[0][2]==board[1][2] && board[1][1]==board[2][2])
    {
        return board[0][2];
    }
    return Empty;
    
}

Token Board::diagonal()
{
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return board[0][0];
    }

    if (board[2][0]==board[1][1] && board[1][1]==board[0][2])
    {
        return board[0][2];
    }
    return Empty;
    
}


















