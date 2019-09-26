#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator;
    Node(T data):data(data),left(nullptr),right(nullptr){};

    void killself(){
        if(this->left!= nullptr)
            this->left->killself();
        if(this->right!= nullptr)
            this->right->killself();
        delete this;
    }
};

#endif