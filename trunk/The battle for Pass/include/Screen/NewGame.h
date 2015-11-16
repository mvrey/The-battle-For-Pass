/* 
 * File:   NewGame.h
 * Author: Marcos Vazquez
 *
 * Created on November 15, 2015, 11:55 PM
 */

#ifndef NEWGAME_H
#define NEWGAME_H

#include "Screen.h"
#include "MainMenu.h"
#include "../../include/Main/Manager.h"

class NewGame: public Screen {
public:
    NewGame();
    NewGame(const NewGame& orig);
    virtual ~NewGame();
    
    void Init();
    void Update();
    void Draw();
    void CreateButtons();
private:

};

#endif /* NEWGAME_H */

