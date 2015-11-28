/* 
 * File:   GameWon.h
 * Author: Marcos Vazquez
 *
 * Created on November 24, 2015, 3:22 PM
 */

#ifndef GAMEWON_H
#define GAMEWON_H 1

#include "MainMenu.h"
#include "../Main/Manager.h"

class GameWon: public Screen {
public:
    GameWon();
    GameWon(const GameWon& orig);
    virtual ~GameWon();
    
    void Input();
    void Update();
    void Draw();
    
private:

};

#endif /* GAMEWON_H */

