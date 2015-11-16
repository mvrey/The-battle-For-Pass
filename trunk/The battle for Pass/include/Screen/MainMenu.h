/* 
 * File:   MainMenu.h
 * Author: Marcos Vazquez
 *
 * Created on November 15, 2015, 11:55 PM
 */

#ifndef MAINMENU_H
#define MAINMENU_H 1

#include "Screen.h"
#include "NewGame.h"
#include "../../include/Main/Manager.h"

class MainMenu: public Screen {
public:
    MainMenu();
    MainMenu(const MainMenu& orig);
    virtual ~MainMenu();
    
    void Update();
    void Draw();
    
private:

};

#endif /* MAINMENU_H */

