#pragma once

#include "Node.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;




class Tree {

  private:    // Not required. All is private by default.

    Node* _root;
    int _size;

    
    

  public:

    // methods defined inline:



    Node* findNode(int i);

    void insert(int i);

    void transplant(Node* u, Node* v);


    void remove(int i);

    int size();

    int contains(int i);

    int root(){
      return _root->getValue();
    }

    int parent(int i);

    int left(int i);

    int right(int i);

    string print();

   
  Tree();
  
  Tree(Node* node);

  Tree(int i);

};