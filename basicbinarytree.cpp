#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

enum PrintType {INORDER, PREORDER, POSTORDER};

struct TreeNode
{
  int       keyValue;
  TreeNode* leftChild;
  TreeNode* rightChild;
};

class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();

  void      Insert(int key);
  void      PrintTree(PrintType type);

private:
  TreeNode *TreeRoot;
  void      Insert(int key, TreeNode* node);
  void      DestroyTree(TreeNode* Node);
  void      PrintTree (TreeNode* Node, PrintType type);

};

BinaryTree::BinaryTree(void) {
  TreeRoot = NULL;
}

BinaryTree::~BinaryTree(void) {
  DestroyTree(TreeRoot);
}

void BinaryTree::PrintTree(PrintType type){
  PrintTree(TreeRoot, type);
}

void BinaryTree::PrintTree( TreeNode* Node, PrintType type){
  if (Node == NULL) return;

  if (type  == PREORDER) {
    cout << Node->keyValue << " ";
    PrintTree(Node->leftChild, type);
    PrintTree(Node->rightChild, type);
  } else if (type == POSTORDER) {
    PrintTree(Node->leftChild, type);
    PrintTree(Node->rightChild, type);
    cout << Node->keyValue << " ";
  } else if (type == INORDER) {
    PrintTree(Node->leftChild, type);
    cout << Node->keyValue << " ";
    PrintTree(Node->rightChild, type);
  } else {
    cout << "Unexpected \n";
  }
}


void BinaryTree::Insert(int key, TreeNode* root) {
  TreeNode *newNode   = new TreeNode;
  newNode->keyValue   = key;
  newNode->leftChild  = NULL;
  newNode->rightChild = NULL;

  if(key < root->keyValue) {
    if(root->leftChild == NULL) {
      root->leftChild = newNode;
      cout << "Added node " << key << " as left child of " << root->keyValue << endl;
    } else {
      Insert(key, root->leftChild);
    }
  } else {
    if(root->rightChild == NULL) {
      root->rightChild = newNode;
      cout << "Added node " << key << " as right child of " << root->keyValue << endl;
    } else {
      Insert(key, root->rightChild);
    }
  }

}

void BinaryTree::Insert(int key) {
  if(TreeRoot != NULL){
    Insert(key, TreeRoot);
  } else {
    TreeRoot = new TreeNode;
    TreeRoot->keyValue   = key;
    TreeRoot->leftChild  = NULL;
    TreeRoot->rightChild = NULL;
    cout << "Added node " << key << " as root " << endl;
  }
}

void BinaryTree::DestroyTree(TreeNode* Node) {
  if (Node->leftChild != NULL) {
    DestroyTree(Node->leftChild);
  } 
  if (Node->rightChild != NULL) {
    DestroyTree(Node->rightChild);
  }
  
  cout << "Destroying node " << Node->keyValue << endl;

  delete Node;
}

int main(){
  BinaryTree* ExampleTreePtr = new BinaryTree();

  ExampleTreePtr->Insert(10);
  ExampleTreePtr->Insert(11);
  ExampleTreePtr->Insert(8);
  ExampleTreePtr->Insert(32);


  cout << "printing tree" << endl;
  ExampleTreePtr->PrintTree(PREORDER);
  cout << endl;

  delete ExampleTreePtr;


  BinaryTree ExampleTreeObj;

  ExampleTreeObj.Insert(12);
  ExampleTreeObj.Insert(9);
  ExampleTreeObj.Insert(-2);
  ExampleTreeObj.Insert(55);
  ExampleTreeObj.Insert(-6);
  ExampleTreeObj.Insert(17);
  ExampleTreeObj.Insert(11);
  ExampleTreeObj.Insert(2);

  cout << "printing tree" << endl;
  ExampleTreeObj.PrintTree(INORDER);
  cout << endl;
  ExampleTreeObj.PrintTree(POSTORDER);
  cout << endl;

}
