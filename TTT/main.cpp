
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "board.hpp"
#include <sstream>
#include "computerplayer.hpp"


int main(int, char const**)
{
    // Create the main window
    int windowHeight = 600;
    int windowWidth = 1000;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic Tac Toe");

    Board board(600, 600, window);
    
    
    int turn = 1;
    int beginning =1;
    
    //set a color for the computer
    int tosetcomp = 0;

    // Start the game loop
    while (window.isOpen())
    {
        //create player designation
        sf::Text intro;
        
        //choose a font
        sf::Font font;
        font.loadFromFile("/Users/diptikarmarkar/Documents/GD/TicTacToe/TTT/HighlandGothicFLF.ttf");
        
        //set the font to our message
        intro.setFont(font);
        
        //set size
        intro.setCharacterSize(20);
        
        //set position
        intro.setPosition(605, 250);
        
        //choose a color
        intro.setColor(sf::Color::White);
        
        // Process events
        sf::Event event;
        
        
        
        if (beginning ==1)
        {
            intro.setString("Would you like to be\n player 1 or player 2,\n enter 1 or 2");
            //get the input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                tosetcomp =0;
                beginning =0;
                //intro.setString("Player 1(Human) is Red \nPlayer 2(Computer) is Yellow");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                tosetcomp =1;
                beginning =0;
                //intro.setString("Player 1(Computer) is Red \nPlayer 2(Human) is Yellow");
            }
            
            
        }
        
        if (beginning ==0)
        {
            if (tosetcomp==1)
            {
                intro.setString("Player 1(Computer) is Red \nPlayer 2(Human) is Yellow");
            }
            if(tosetcomp==0)
            {
                intro.setString("Player 1(Human) is Red \nPlayer 2(Computer) is Yellow");
            }
        
            
        }
        
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
        }
        
         // Clear screen
        window.clear();
        
        //see if there's a click, and make the color of the grid at that position change
        //if the game is still going
        
        Token playercolor = Red;
        
        if (turn%2==0){ playercolor = Yellow;}
    
        if(beginning ==0 && turn%2==tosetcomp && board.endofGame()!=true)
        {
            Computerplayer play(window, board, tosetcomp);
            play.nextmove();
            turn++;
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && board.endofGame()!=true && beginning ==0 && turn%2!=tosetcomp)
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            if (board.getstatus(pos)==Empty)
            {
                board.playermove(pos, playercolor);
                turn++;
            }
        }
        
        
        
        // Draw the sprite
        board.draw();
        //create a text object called message
        sf::Text message;
        
        //draw intro
        window.draw(intro);
        
        //set the font to our message
        message.setFont(font);
        
        
        //make it really big
        message.setCharacterSize(75);
        
        //set position
        message.setPosition(20, 250);
        
        //choose a color
        message.setColor(sf::Color::Black);
        
        
        //check if a player wins
        Token a = board.horizontal();
        Token b = board.vertical();
        Token c = board.diagonal();
        
    
        if (a != 0)
        {
            std::stringstream ss;
            ss << "Player " << a << " wins";
            message.setString(ss.str());
        }
        
        else if (b != 0)
        {
            std::stringstream ss;
            ss << "Player " << b << " wins";
            message.setString(ss.str());
        }
        
        else if (c != 0)
        {
            std::stringstream ss;
            ss << "Player " << c << " wins";
            message.setString(ss.str());
        }

        else if (board.endofGame()==true)
        {
            message.setString("Draw");

        }
        
        
        // Draw the string
        window.draw(message);

        // Update the window
        window.display();
        
    }
    

    return EXIT_SUCCESS;
}
