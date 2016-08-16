//
//  computerplayer.hpp
//  TTT
//
//  Created by Dipti Karmarkar on 8/16/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef computerplayer_hpp
#define computerplayer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include <stdlib.h>

class Computerplayer
{
public:
    Computerplayer(sf::RenderWindow &window, Board &board,int playernum);
    void nextmove();
    
    
    
private:
     sf::RenderWindow &window;
    Board &board;
    Token playertoken;
    
    
    
};


#endif /* computerplayer_hpp */
