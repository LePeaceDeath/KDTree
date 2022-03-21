#ifndef KDTREE_HPP_
#define KDTREE_HPP_

#include <iostream>
#include <cmath>

using namespace std;

const int DIMENSION = 3;

struct Node{
    int arr[DIMENSION];
    Node *left = nullptr;
    Node *right = nullptr;
    Node(){};
    Node(const int *arr){
        for(int i = 0; i < DIMENSION; i++){
            this->arr[i] = arr[i];
        }
    }
    double length(const int *arr){
        double sum = 0;
        for(int i = 0;i < DIMENSION;i++)
            sum+=(this->arr[i]-arr[i])*(this->arr[i]-arr[i]);
        return sqrt(sum);
    }
    bool isLeaf(){
        if(this->left == nullptr && this->right == nullptr)
            return true;
        return false;
    }
    void print(){
        for(int i = 0; i < DIMENSION; i++)
            cout<<"x"<<i<<" = "<<arr[i]<<" ";
        cout<<endl;
    }
};


class KDTree{
    int treeSize = 0;
    int depth = 0;
    public:
    ~KDTree();
    Node *root = nullptr;
    void insert(const int *arr);
    void clearTree(Node *&node);
    void preorder(Node *node);
    int getTreeSize();
    int getTreeDepth();
    void getClosestPoint(Node *node,int *arr, int depth, Node **closestP, double &minDist);
};



void KDTree::clearTree(Node *&node){
    if (node != nullptr)
	{
	   clearTree(node->left);
	   clearTree(node->right);
	   delete node;
	   node = nullptr;
       treeSize--;
	}
}

KDTree::~KDTree(){
    clearTree(root);
}

void KDTree::insert(const int *arr){
    treeSize++;
    Node *nn = new Node(arr);
    if(root==nullptr)
        root = nn;
    else{
        Node *temp = root;
        int it = 0;
        int depth = 0;
        while(temp!=nullptr){
            depth++;
            if(arr[it] < temp->arr[it]){
                if(temp->left != nullptr)
                    temp = temp->left;
                else{
                    temp->left = nn;
                    break;
                }
            }
            else{
                if(temp->right!=nullptr)
                    temp = temp->right;
                else{
                    temp->right = nn;
                    break;
                }
            }
            it = (it+1)%DIMENSION;
        }
        if(depth > this->depth)
            this->depth = depth;
    }
}

void KDTree::getClosestPoint(Node *node,int *arr, int depth, Node **closestP, double &minDist)
{
    if(node->isLeaf()){
        const double dist = node->length(arr);
        if(dist < minDist){
            minDist = dist;
            *closestP = node;
        }
    }
    else{
        int i = depth % DIMENSION;
        if(arr[i] < node->arr[i]){
            getClosestPoint(node->left, arr, depth + 1, closestP, minDist);
            if (arr[i] + minDist >= node->arr[i] && node->right!=nullptr){
                getClosestPoint(node->right, arr, depth + 1, closestP, minDist);
            }
        }
        else{
            getClosestPoint(node->right, arr,  depth + 1, closestP, minDist);
            if (arr[i] - minDist <= node->arr[i] && node->left != nullptr){
                getClosestPoint(node->left, arr, depth + 1, closestP, minDist);
            }
        }
        const double dist = node->length(arr);
        if (dist < minDist){
            minDist = dist;
            *closestP = node;
        }
    }
}

void KDTree::preorder(Node *node){
    if(node != nullptr){
	    node->print();
        preorder(node->left);
        preorder(node->right);
    }
}

int KDTree::getTreeSize(){return treeSize;}
int KDTree::getTreeDepth(){return depth;}
#endif
