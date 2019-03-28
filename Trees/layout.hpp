



#pragma once

#include "Node.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


#define COUNT 10


// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
    cout<<"here it went wrong"<<root->getValue()<<"\n";
    // Increase distance between levels  
    space += COUNT;  
    // Process right child first  
    print2DUtil(root->getRight(), space);  
    cout<<"right went alright"<<root->getValue()<<"\n";
    // Print current node after space  
    // count  
    cout<<endl;  

    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    
    cout<<root->getValue()<<"\n";  
    // Process left child
    cout<<"for loop went alright"<<root->getValue()<<"\n";
    print2DUtil(root->getLeft(), space); 
    cout<<"left went alright"<<root->getValue()<<"\n";
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{ 
    cout<<"Tree's layout is"<<"\n"; 
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  
	
	
	


    

   




