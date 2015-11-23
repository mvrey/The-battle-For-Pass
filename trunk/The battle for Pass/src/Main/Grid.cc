/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 *                                              
 * A class that implements a bidimensional grid of integers                              
 *                                              
 */

#include <stdio.h>
#include <assert.h>
#include "../../include/Main/Grid.h"


//Parametrized constructor
Grid::Grid(int rows, int columns) {
  rows_ = rows;
  columns_ = columns;
  root_ = new Node(0, nullptr, nullptr);
}

/**
* Copy constructor
**/
Grid::Grid(const Grid& g) {
  //empty
}

/**
* @brief  Initializes grid by creating nodes
**/
bool Grid::init() {
  Node* previous_row = root_;
  Node* previous_column = root_;
  Node* node = root_;
  
  for (int i=0; i<rows_; i++) {
    
    for (int j=0; j<columns_; j++) {
      Node* cnode = new Node(0, nullptr, nullptr);
      previous_column->next_column = cnode;
      previous_column = cnode;
    }
    
    node = new Node(0, nullptr, nullptr);
    previous_row->next_row = node;
    
    previous_row = node;
    previous_column = node;
  }
  
  this->zeros();
  
  return true;
}

/**
* @brief  Checks and returns whether the parametrized number
* of rows and columns is smaller than the current ones, or not.
**/
bool Grid::checkLimits(int rows, int columns) {
  return (rows <= rows_ && columns <= columns_);
}

/**
* @brief  Checks if the parametrized number of rows and columns are valid.
* Throws and assert and aborts the execution of the program if they're not.
**/
void Grid::assertLimits(int rows, int columns) {
  assert(rows>=0 && columns>=0 && rows <= rows_ && columns <= columns_);
}

/**
* @brief  Fills the entire Grid with zeros
**/
void Grid::zeros() {
  Node* row = root_;
  Node* column = root_;
  
  while (row->next_row) {
    row->info = 0;
    column = row->next_column;
    
    while (column->next_column) {
      column->info = 0;
      column = column->next_column;
    }
    
    row = row->next_row;
  }
}

/**
* @brief  Returns the element value at row,column 
**/
void* Grid::getElement(int row, int column) {
  Node* node = root_;
  
  //Makes sure the position is valid
  assertLimits(row, column);
  
  for (int i=0; i<row; i++) {
    node = node->next_row;
  }
  for (int j=0; j<column; j++) {
    node = node->next_column;
  }
  
  return node->info;
}

/**
* @brief  Sets the value of an element at position row,column
**/
void Grid::setElement(int row, int column, void* info) {
  Node* node = root_;
    
  //Makes sure the position is valid
  assertLimits(row, column);
    
  for (int i=0; i<row; i++) {
    node = node->next_row;
  }
  for (int j=0; j<column; j++) {
    node = node->next_column;
  }

  node->info = info;
}

/**
* @brief  Prints out the contents of the grid
**/
void Grid::print() {
  Node* row = root_;
  Node* column = root_;
  
  while (row->next_row) {
    printf("%p  :  ", &row->info);
    column = row->next_column;
    
    while (column->next_column) {
      printf("%p, ", &column->info);
      column = column->next_column;
    }
    
    row = row->next_row;
    printf("\n");
  }
}

int Grid::getNumRows() {
  return this->rows_;
}

/**
* @brief  Resizes the grid. 
* If the new number of rows is fewer than currently, data out of limits will be lost.
**/
void Grid::setNumRows(int num) {
  Node* row = root_;
  Node* previous_column = root_;
  Node* previous_row = root_;
  Node* node = root_;
  
  assert(num>=0);
  
  if (checkLimits(num, 0)) {
    int i=0;
    
    while (node->next_row && i<num) {
      node = node->next_row;
      i++;  
    }
    
    previous_row = node;

    while (node->next_row) {
      row = node;
      node = row->next_row;
      delete row;
    }

    node->next_row = nullptr;
    previous_row->next_row = nullptr;
    
  } else {
    int i=0;
    
    while (node->next_row->next_row && i<num) {
      node = node->next_row;
      i++;  
    }

    for (int k=i; k<num; k++) {
    
      previous_column = node;
      previous_row = node;
      
      for (int j=0; j<columns_; j++) {
        Node* cnode = new Node(0, nullptr, nullptr);
        previous_column->next_column = cnode;
        previous_column = cnode;
      }
      
      node = new Node(0, nullptr, nullptr);
      previous_row->next_row = node;
      
      previous_row = node;
      previous_column = node;
    } 
  }
  
  rows_ = num;
}

int Grid::getNumColumns() {
  return this->columns_;
}

/**
* @brief  Resizes the grid. 
* If the new number of columns is fewer than currently, data out of limits will be lost.
**/
void Grid::setNumColumns(int num) {
  Node* column = root_;
  Node* previous_column = root_;
  Node* node = root_;
  Node* cnode = root_;
  
  assert(num>=0);
  
  if (checkLimits(0, num)) {
    
    while (node->next_row) {
      int i=0;
      cnode = node;
      
      while (cnode->next_column && i<num) {
        cnode = cnode->next_column;
        i++;  
      }
    
      previous_column = cnode;

      while (cnode->next_column) {
        column = cnode;
        cnode = column->next_column;
        delete column;
      }

      cnode->next_column = nullptr;
      previous_column->next_column = nullptr;
    
      node = node->next_row;
    }
  } else {

     while (node->next_row) {
       int i=0;
       cnode = node;
       
        while (cnode->next_column) {
          cnode = cnode->next_column;
          i++;
        }
        
        for (int k=i; k<num; k++) {
    
          previous_column = cnode;
          
          cnode = new Node(0, nullptr, nullptr);
          previous_column->next_column = cnode;
        }
        
        node = node->next_row;
     }
  }
  
  columns_ = num;
}

/**
* @brief  Resizes the grid. 
* If the new number of rows/columns is fewer than the current one, data out of limits will be lost.
**/
void Grid::resize(int rows, int columns) {
  this->setNumRows(rows);
  this->setNumColumns(columns);
}