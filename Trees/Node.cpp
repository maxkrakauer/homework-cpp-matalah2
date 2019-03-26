
#include "Node.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 

using namespace std;


void Node::setLeft(Node* left) {
	_left = left;
    }



void Node::setRight(Node* right) {
	_right = right;

}

void Node::setParent(Node* parent) {
	_parent = parent;
}

string Node::to_string(){
    return "value is: " + std::to_string(getValue()) + "\n";
}

string Node::print(string str){
    if(this->getLeft()!=NULL)
    str=str+this->getLeft()->print(str);
    if(this->getRight()!=NULL)
    str=str+this->getRight()->print(str);
    return to_string();
}




void Node::remove(){
    free(this);
}


Node*  Node::minimum(){
    Node* x = this;
    while(x->getLeft()!=NULL)
    x=(*x).getLeft();
    return x;
}






Node::Node() {
    _value=0;
}

Node::Node(int x) {
    _value=x;
}

