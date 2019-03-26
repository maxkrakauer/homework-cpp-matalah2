
#include "Tree.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 

using namespace std;



void Tree::insert(int value){
    Node* y = NULL;
    Node* x = _root;
    Node* z = new Node(value);
    while(x!=NULL){
        y=x;
        if(value<x->getValue())
        x = x->getLeft();
        else
        x = x->getRight();
    }
    z->setParent(y);
    if(y==NULL){
    _root=z;
    _size++;
    }
    else if(value<y->getValue()){
    y->setLeft(z);
    _size++;
    }
    else if(value>y->getValue()){
    y->setRight(z);
    _size++;
    }
    else throw "already contains number";
    
}


void Tree::transplant(Node* u, Node* v){
    if(u->getParent()==NULL)
    _root=v;
    else if(u==u->getParent()->getLeft())
    u->getParent()->setLeft(v);
    else
    u->getParent()->setRight(v);
    if(v!=NULL)
    v->setParent(u->getParent());
}

Node* Tree::findNode(int i){
      Node* temp = _root;
      while(temp!=NULL && temp->getValue()!=i){
          if(temp->getValue()>i)
          temp = temp->getLeft();
          else if(temp->getValue()<i)
          temp = temp->getRight();
      }
      return temp;
    }


void Tree::remove(int i){
    Node* z = findNode(i);
    if(z!=NULL){
    _size--;
    if(z->getLeft()==NULL)
    transplant(z,z->getRight());
    else if(z->getRight()==NULL)
    transplant(z,z->getLeft());
    else{
        Node* y = z->getRight()->minimum();
        if(y->getParent()!=z){
            transplant(y,y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }
        transplant(z,y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
    }
    z->remove();
    }
    else throw "no such number";
}

int Tree::parent(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getParent();
    if(y==NULL)
    throw "The node has no parent";
    return y->getValue();
}

int Tree::left(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getLeft();
    if(y==NULL)
    throw "The node has no left child";
    return y->getValue();
}


int Tree::right(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getRight();
    if(y==NULL)
    throw "The node has no right child";
    return y->getValue();
}


int Tree::size(){
    return _size;
}

int Tree::contains(int i){
    Node* x = findNode(i);
    if(x==NULL)
    return 0;
    else return 1;
}

string Tree::print(){
    string str="";
    if(_root!=NULL)
    return _root->print(str);
    else return "no root. sorry";
}


Tree::Tree() {
    _root = new Node();
    _size=0;
}

Tree::Tree(int x) {
    _root = new Node(x);
    _size=0;
}

Tree::Tree(Node* node){
    _root = node;
    _size=0;
}

