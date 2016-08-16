//
//  computerplayer.cpp
//  TTT
//
//  Created by Dipti Karmarkar on 8/16/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "computerplayer.hpp"

Computerplayer::Computerplayer(sf::RenderWindow &window, Board &board, int playernum): board(board), window(window)
{
    if (playernum ==1)
    {
        playertoken = Red;
    }
    else
        playertoken = Yellow;
    
}

void Computerplayer::nextmove()
{
    std::srand(time(NULL));
    while (true)
    {
        int x = std::rand() % 600;
        int y = std::rand() % 600;
        sf::Vector2i pos(x,y);
        
        if (board.getstatus(pos)== Empty)
        {
            board.playermove(pos,playertoken);
            break;
        }
    
    }
    
}