//
//  tree_traversal.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/13.
//  acmicpc.net/problem/1068

#include <iostream>

using namespace std;
int cnt=0;
class Tree;
class TreeNode{
    friend class Tree;
private:
    TreeNode *LeftChild;
    int data;
    TreeNode *RightChild;
public:
    TreeNode(int data=0, TreeNode* left=0, TreeNode* right=0){
        this->data=data;
        this->LeftChild=left;
        this->RightChild=right;
    }
};
class Tree{
public:
    Tree(int data=0){
        root= new TreeNode(data);
    }
    void preorder(TreeNode* CurrentNode);
    void insert(TreeNode *CurrentNode, int parentNode, int data);
    void delete_node(TreeNode *CurrentNode, int data);
    void count_leaf(TreeNode* CurrentNode);
    TreeNode* getRoot(){return root;}
private:
    TreeNode *root;
};

void Tree::preorder(TreeNode *CurrentNode){
    if(CurrentNode){
        cout<<CurrentNode->data;
        preorder(CurrentNode->LeftChild);
        preorder(CurrentNode->RightChild);
    }
}


void Tree::insert(TreeNode *CurrentNode, int parentNode, int data){
    if(CurrentNode->data>parentNode) return;
    
    if(CurrentNode->data==parentNode){
        if(CurrentNode->LeftChild==0){
            TreeNode* leftNode=new TreeNode(data);
            CurrentNode->LeftChild=leftNode;
        }
        else{
            TreeNode* rightNode=new TreeNode(data);
            CurrentNode->RightChild=rightNode;
        }
    }
    else{
        insert(CurrentNode->LeftChild, parentNode, data);
        insert(CurrentNode->RightChild, parentNode, data);
    }
    return;
}

void Tree::delete_node(TreeNode *CurrentNode, int data){
    if(CurrentNode->LeftChild->data==data){
        CurrentNode->LeftChild=0;
        delete CurrentNode->LeftChild;
    }
    else if(CurrentNode->RightChild->data==data){
        CurrentNode->RightChild=0;
        delete CurrentNode->RightChild;
    }
    else{
    delete_node(CurrentNode->LeftChild,data);
    delete_node(CurrentNode->RightChild, data);
    }
    return;
}

void Tree::count_leaf(TreeNode *CurrentNode){
    if(!CurrentNode->LeftChild && !CurrentNode->RightChild) cnt++;
    
    else{
        count_leaf(CurrentNode->LeftChild);
        count_leaf(CurrentNode->RightChild);
    }
    return;
}


int main(){
    int n, num;
    cin>>n;
    int arr[n];
    Tree tree(0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0){
            tree.insert(tree.getRoot(), arr[i],i);
        }
    }
    tree.preorder(tree.getRoot());
    cout<<"\n";
    cin>>num;
    
    tree.delete_node(tree.getRoot(), num);
    tree.preorder(tree.getRoot());
    cout<<"\n";
    tree.count_leaf(tree.getRoot());
    
    cout<<cnt<<"\n";
    
    return 0;
}
