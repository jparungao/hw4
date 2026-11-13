#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
static int leafDepth(Node* node); //Returns # of nodes on the path if every leaf is the same depth, return -1 if not same depth


bool equalPaths(Node * root)
{
    // Add your code below
  return leafDepth(root) != -1;
}

static int leafDepth(Node* node)
{
  if(node == nullptr) return 0; //empty tree

  if(node->left == nullptr && node->right == nullptr) return 1; //leaf

  if(node->left == nullptr){
    int ri = leafDepth(node->right);
    return (ri == -1) ? -1 : ri + 1;
  }
  if(node->right == nullptr){
    int le = leafDepth(node->left);
    return(le == -1) ? -1 : le + 1;
  }

  int le = leafDepth(node->left);
  int ri = leafDepth(node->right);
  if(le == -1 || ri == -1 || le != ri) return -1;
  return le + 1;

}

