/* 
 * File:   GameOver.h
 * Author: Marcos Vazquez
 *
 * Created on November 24, 2015, 12:54 PM
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H 1

#include "MainMenu.h"
#include "../Main/Manager.h"

class GameOver: public Screen {
public:
    GameOver();
    GameOver(const GameOver& orig);
    virtual ~GameOver();
    
    void Input();
    void Update();
    void Draw();
    
private:

};

#endif /* GAMEOVER_H */

