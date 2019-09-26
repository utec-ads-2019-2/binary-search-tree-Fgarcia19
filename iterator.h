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

        Node<T>* buscar_padre(Node<T>* buscar){
            auto aux=raiz;
            while (true){
                if(aux->right==buscar | aux->left==buscar)
                    break;
                if(aux->data>buscar->data ){
                    aux=aux->left;
                }
                else if(aux->data<buscar->data )
                {
                    aux=aux->right;

                }

            }
            return aux;

        }

        Iterator<T>& operator++() {
//            auto cola=raiz;
//            while(cola->right!= nullptr){
//                cola=cola->right;
//            }
//            if(this->current==cola)
//                return * new Iterator<T>(nullptr,raiz);
//                return  &Iterator<T>(nullptr,raiz);

            if(this->current->right== nullptr){
                auto padre=buscar_padre(current);
                while(current->data>padre->data){
                    padre=buscar_padre(padre);
                }
                this->current=padre;
                return  *this;

            }
            else if(this->current->right!= nullptr){
                this->current=this->current->right;
                while(this->current->left!= nullptr) {
                    this->current = this->current->left;
                }
                return *this;
            }
        }

        Iterator<T>& operator--() {
            if(this->current->left== nullptr){
                auto padre=buscar_padre(current);
                while(current->data<padre->data){
                    padre=buscar_padre(padre);
                }
                this->current=padre;
                return  *this;

            }
            else if(this->current->left!= nullptr){
                this->current=this->current->left;
                while(this->current->right!= nullptr) {
                    this->current = this->current->right;
                }
                return *this;
            }
        }

        T operator*() {
            return current->data;
        }
};

#endif
