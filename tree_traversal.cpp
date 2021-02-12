//
//  tree_traversal.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/11.
//  acmicpc.net/problem/1991

#include <iostream>

using namespace std;

class Tree;
class TreeNode{
    friend class Tree;
private:
    TreeNode *LeftChild;
    char data;
    TreeNode *RightChild;
public:
    TreeNode(char data=0, TreeNode* left=0, TreeNode* right=0){
        this->data=data;
        this->LeftChild=left;
        this->RightChild=right;
    }
};
class Tree{
public:
    Tree(char data=0){
        root= new TreeNode(data);
    }
    void preorder(TreeNode *CurrentNode);
    void inorder(TreeNode *CurrentNode);
    void postorder(TreeNode *CurrentNode);
    void insert(TreeNode *CurrentNode, char parent, char left, char right);
    TreeNode* getRoot(){return root;}
private:
    TreeNode *root;
};

void Tree::inorder(TreeNode *CurrentNode){
    if(CurrentNode){
        inorder(CurrentNode->LeftChild);
        cout<<CurrentNode->data;
        inorder(CurrentNode->RightChild);
    }
}

void Tree::preorder(TreeNode *CurrentNode){
    if(CurrentNode){
        cout<<CurrentNode->data;
        preorder(CurrentNode->LeftChild);
        preorder(CurrentNode->RightChild);
    }
}

void Tree::postorder(TreeNode *CurrentNode){
    if(CurrentNode){
        postorder(CurrentNode->LeftChild);
        postorder(CurrentNode->RightChild);
        cout<<CurrentNode->data;
    }
}

void Tree::insert(TreeNode *CurrentNode, char parent, char left, char right){
    if(CurrentNode->data>parent) return;
    if(CurrentNode->data==parent){
        if(left!='.'){
            TreeNode* left_node=new TreeNode(left);
            CurrentNode->LeftChild=left_node;
        }
        if(right!='.'){
            TreeNode* right_node=new TreeNode(right);
            CurrentNode->RightChild=right_node;
        }
    }
    else{
        if(CurrentNode->LeftChild) insert(CurrentNode->LeftChild,parent,left,right);
        if(CurrentNode->RightChild) insert(CurrentNode->RightChild,parent,left,right);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    
    Tree tree('A');
    
    for(int i=0;i<n;i++){
        char root,left,right;
        cin>>root>>left>>right;
        tree.insert(tree.getRoot(), root, left, right);
    }
    tree.preorder(tree.getRoot());
    cout<<"\n";
    tree.inorder(tree.getRoot());
    cout<<"\n";
    tree.postorder(tree.getRoot());
    cout<<"\n";
    
    return 0;
}
