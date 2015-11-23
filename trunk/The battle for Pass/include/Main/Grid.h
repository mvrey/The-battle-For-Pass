/* 
 * File:   Grid.h
 * Author: Marcos Vazquez
 *
 * Created on November 8, 2015, 8:01 PM
 */

#ifndef GRID_H
#define GRID_H

class Grid {
  public:
    Grid() = default;
    Grid(int rows, int columns);
    Grid(const Grid& g);
    bool init();
    void zeros();
    void* getElement(int row, int column);
    void setElement(int row, int column, void* info);
    void print();
    
    int getNumRows();
    void setNumRows(int num);
    int getNumColumns();
    void setNumColumns(int num);
  
    void resize(int rows, int columns);
    
  private:
    
    struct Node {
        void* info;
        Node *next_row;
        Node *next_column;
        Node(void* info, Node* next_row, Node* next_column)
            : info(info)
            , next_row(next_row)
            , next_column(next_column) {
        }
    };
    typedef struct Node Node;
    
    // Methods
    bool checkLimits(int rows, int columns);
    void assertLimits(int rows, int columns);
      
    // Data members
    int rows_;
    int columns_;
    
    Node* root_ = nullptr;
};

#endif /* GRID_H */

