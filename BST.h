#ifndef __BST_H
#define __BST_H
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;
/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */
template <typename Comparable>
class BST
{
public:
BST();
~BST();
void makeEmpty();
const Comparable & findMin() const;
const Comparable & findMax() const;
bool contains(const Comparable & x) const;
void insert(const Comparable & x);
void remove(const Comparable & x);
int treeSize() const;
int treeHeight() const;
void printInOrder() const;
void printLevels() const;
void printMaxPath() const;
private:
struct BinaryNode
{
Comparable element;
BinaryNode *left;
BinaryNode *right;
BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode
*rt): element(theElement), left(lt), right(rt) {}
BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt):
element(move(theElement)), left(lt), right(rt) {}
};
BinaryNode *root;
BinaryNode * findMin( BinaryNode * t ) const;
BinaryNode * findMax( BinaryNode * t ) const;
void makeEmpty( BinaryNode * & t );
};
/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */
// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(NULL) {}
// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
makeEmpty();
}
// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
makeEmpty(root);
}
// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
if ( t != NULL ) {
makeEmpty(t->left);
makeEmpty(t->right);
delete t;
t = NULL;
}
}
// // public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
if (root == NULL) {
throw underflow_error("Tree is empty");
}
return findMin(root)->element;
}
// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t)
const {
if ( t == NULL ) {
return NULL;
} else if (t->left == NULL) {
return t;
} else {
return findMin(t->left);
}
}
// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
if (root == NULL) {
throw underflow_error("Tree is empty");
}
return findMax(root)->element;
}
// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t)
const {
if ( t == NULL ) {
return NULL;
} else if (t->right == NULL) {
return t;
} else {
return findMin(t->right);
}
}
// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains(Node*root, int v ) const {
if(root==nullptr){
return false;
}
if(root->data==v){
return true;
}
if(v < root->data){
return contains(root->left, v);
}
  if(v > root->data){
    return contains(root->right, v);
  }
}

// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
Node* BST<Comparable>::insert(Node*root, int v) {
if(root==nullptr){
return new Node(v);
}
if(v< root->data){
root->left=insert(root->left,v);
}else if(v > root->data){
root->right=insert(root->right,v);
}
return root;
}
// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
Node* BST<Comparable>::remove(Node* root, int v) {
if(root== nullptr){
return root;
}
if(v < root->data){
root->left=remove(root->left,v);
}else if(v > root->data) {
root->right= remove(root->right, v);
} else{
if(root->left == nullptr){
Node* temp= root->right;
delete root;
return temp;
}else if(root->right == nullptr){
Node* temp= root->left;
delete root;
return temp;
}
}
return root;
}

// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize(Node*root) const {
if(root==nullptr){
return 0;
}
return 1+ treeSize(root->left)+ treeSize(root->right);
}
// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight(Node* root) const {
if(root==nullptr){
return -1;
}
return 1+ max(treeHeight(root->left), treeHeight(root->right));
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const {
if(root==nullptr){
return;
}
printInOrder(root->left);
cout<<root->data<<" ";
printInOrder(root->right);
}

// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
if(root == nullptr){
return;
}
queue<Node*> r;
r.push(root);
while(!r.empty()){
Node* node= r.front();
r.pop();
cout<<node->data<<"";
if(node->left !=nullptr){
r.push(node->left);
}
if(node->right !=nullptr){
r.push(node->right);
}
}
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath(Node* root) const {
if(root==nullptr){
return;
}
cout<<root->data<<endl;
if(treeHeight(root->left)>treeHeight(root->right)){
printMaxPath(root->left);
}else{
printMaxPath(root->right);
}
}
#endif
