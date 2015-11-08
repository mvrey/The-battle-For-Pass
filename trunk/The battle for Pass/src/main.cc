/* 
 * File:   main.cpp
 * Author: smuchy
 *
 * Created on November 8, 2015, 7:53 PM
 */

#include <cstdlib>
#include <stdio.h>
#include "../include/grid.h"

int main(int argc, char** argv) {
    Grid* grid = new Grid(5,5);
    grid->init();
    
    grid->setElement(2,3,42);
    
    grid->print();
    return 0;
}

