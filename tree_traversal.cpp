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
};
class Tree{
public:
    void preorder(TreeNode *CurrentNode);
    void inorder(TreeNode *CurrentNode);
    void postorder(TreeNode *CurrentNode);
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

int main(){
    int n;
    cin>>n;
    
    
    
    return 0;
}
