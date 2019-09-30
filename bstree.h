#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <iostream>
#include <algorithm>
using namespace std;
template <typename T> 
class BSTree {

    int nodos;

    public:
    Node<T> *root;
        BSTree() : root(nullptr),nodos(0) {};

        bool find(T data) {
            if(size()==0){
                return false;
            }
            auto aux=root;
            while (true){
                if(aux->data>data ){
                    if(aux->left== nullptr){ return false;}

                    aux=aux->left;
                }
                else if(aux->data<data )
                {
                    if(aux->right== nullptr)
                        return false;
                    aux=aux->right;
                }
                else{
                    return true;
                }
            }
            // TODO
        } 

        void insert(T data) {
            auto nuevo= new Node<T>(data);
            if(size()==0){
                root=nuevo;
                nodos++;
            }
            else
                {
                    auto aux=root;
                    while (true){
                        if(nuevo->data<=aux->data){
                            if(aux->left== nullptr)
                            {
                                aux->left=nuevo;
                                nodos++;
                                break;
                            }
                            aux=aux->left;
                        }
                        else
                        {
                            if(aux->right== nullptr)
                            {
                                aux->right=nuevo;
                                nodos++;
                                break;
                            }
                            aux=aux->right;
                        }
                    }
                }
        }

        bool remove(T data) {
            // Mucho código repetido, podrías reducirlo bastante usando por ejemplo un doble puntero
            if(!root){
                return false;
            }
            auto aux=root;
            auto temp=root;
            while(temp->data!=data)
            {
                if(data>temp->data){
                    if(temp->right!=nullptr){
                        aux=temp;
                        temp=temp->right;
                    }
                    else
                        return false;
                }
                else if(data<temp->data){
                    if(temp->left!=nullptr){
                        aux=temp;
                        temp=temp->left;
                    }
                    else
                        return false;
                }
            }
            auto temp2=temp;
            if(temp==root){
                if(size()==1){
                    root=nullptr;
                }
                else if(temp->right!= nullptr){
                    if(temp->left== nullptr)
                        root=temp->right;
                    else
                    {
                        aux=temp;
                        temp=temp->left;
                        while(temp->right!= nullptr){
                            aux=temp;
                            temp=temp->right;
                        }
                        temp2->data=temp->data;
                        if(aux->right==temp)
                            aux->right=temp->left;
                        else
                            aux->left=temp->left;
                    }
                }
                else
                if (temp->left!= nullptr)
                    root=temp->left;
                delete temp;
                nodos--;
                return true;
            }
            if(temp->left== nullptr){
                if(temp->right== nullptr){
                    if(aux!= nullptr){
                        if (aux->right==temp)
                            aux->right=nullptr;
                        else
                            aux->left=nullptr;
                    }
                    delete temp;
                }
                else{
                    if(aux->right==temp)
                        aux->right=temp->right;
                    else
                        aux->left=temp->right;
                    delete temp;
                }
            }
            else{
                if(temp->right== nullptr){
                    if(aux->right==temp)
                        aux->right=temp->left;
                    else
                        aux->left=temp->left;
                    delete temp;
                }
                else{
                    aux=temp;
                    temp=temp->left;
                    while(temp->right!= nullptr){
                        aux=temp;
                        temp=temp->right;
                    }
                    temp2->data=temp->data;
                    if(aux->right==temp)
                        aux->right=temp->left;
                    else
                        aux->left=temp->left;
                    delete temp;
                }
            }
            nodos--;
            return true;

        }

        int size() {
            return nodos;
        }

    int height() {
        return hallar_altura(this->root);
    }

    // Debería ser privado
    int hallar_altura(Node<T>* temp)
    {
        if(temp == nullptr)
        {
            return -1;
        }
        return max(hallar_altura(temp->left),hallar_altura(temp->right))+1;
    }

        void traversePreOrder() {
            preorder(root);
        }

        // Debería ser privado
        void preorder(Node<T>* aux){
            if (aux== nullptr) return;
            cout << aux->data << " ";
            preorder(aux->left);
            preorder(aux->right);
        }

        void traverseInOrder() {
            inorder(root);
        }

        // Debería ser privado
        void inorder(Node<T>* aux){
            if (aux== nullptr) return;
            inorder(aux->left);
            cout << aux->data << " ";
            inorder(aux->right);

        }

        void traversePostOrder() {
            postorder(root);
        }

        // Debería ser privado
        void postorder(Node<T>* aux){
            if (aux== nullptr) return;
            traversepostOrder(aux->left);
            traversepostOrder(aux->right);
            cout << aux->data << " ";

        }

        Iterator<T> begin() {
            auto aux=root;
            if(aux!= nullptr) {
                while (aux->left != nullptr) {
                    aux = aux->left;
                }
                return Iterator<T>(aux, root);
            }
        }

        Iterator<T> end() {
            auto aux=root;
            while(aux->right!= nullptr){
                aux=aux->right;
            }
            return Iterator<T>(nullptr,root);
        }

        ~BSTree() {
            root->killself();
        }
};

#endif
