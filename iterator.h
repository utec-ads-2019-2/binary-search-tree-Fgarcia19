#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include "algorithm"
template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        Node<T>* raiz;

    public:
        Iterator() {
            current= nullptr;
        }

        Iterator(Node<T> *node,Node<T>* raiz_) {
            current=node;
            raiz=raiz_;
        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            current=other.current;
        }

        bool operator!=(Iterator<T> other) {
            return current!=other.current;
        }
    Node<T>* buscar_padre(Node<T>* buscado)
    {
        auto padre = raiz;
        while(true)
        {
            if(padre->right == buscado |padre->left == buscado)
            {
                break;
            }
            if(buscado->data<=padre->data)
            {
                padre = padre->left;
            }
            else if(buscado->data>padre->data)
            {
                padre = padre->right;
            }
        }
        return padre;
    }

    Iterator<T>& operator++() {
        auto cola = raiz;
        while(cola->right!=nullptr)
        {
            cola = cola->right;
        }
        if(current != cola) {
            if (current->right == nullptr) {
                auto padre = buscar_padre(current);
                while (padre->data < current->data) {
                    padre = buscar_padre(padre);
                }
                current = padre;
            } else {
                auto aux = current->right;
                while (true) {
                    if (aux->left == nullptr) {
                        current = aux;
                        break;
                    }
                    aux = aux->left;
                }
            }
            return *this;
        }
        *this = Iterator<T>(nullptr,raiz);
        return  *this;
    }



    Iterator<T>& operator--() {
        if (current != nullptr) {
            if (current->left != nullptr) {
                auto aux = current->left;
                while (true) {
                    if (aux->right == nullptr) {
                        current = aux;
                        break;
                    }
                    aux = aux->right;
                }
            } else {
                auto padre = buscar_padre(current);
                while (padre->data >= current->data) {
                    padre = buscar_padre(padre);
                }
                current = padre;
            }
            return *this;
        }
        auto cola = raiz;
        while(cola->right!=nullptr)
        {
            cola = cola->right;
        }
        *this = Iterator<T>(cola,raiz);
        return *this;
    }

        T operator*() {
            return current->data;
        }
};

#endif
