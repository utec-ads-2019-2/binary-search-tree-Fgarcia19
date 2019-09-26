#include <iostream>
#include "tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    BSTree<int> arbol;

    arbol.insert(15);
    arbol.insert(20);
    arbol.insert(10);
    arbol.insert(21);
    arbol.insert(10);
    arbol.insert(8);
    arbol.insert(14);
    arbol.insert(13);
    arbol.insert(40);
    arbol.insert(30);
    arbol.insert(25);
    arbol.insert(25);
    arbol.insert(33);
    arbol.insert(50);
    arbol.insert(100);
auto aux=arbol.begin();
++aux;
cout<<*aux<<endl;
++aux;
cout<<*aux<<endl;
    ++aux;
    cout<<*aux<<endl;
    ++aux;
    cout<<*aux<<endl;
    ++aux;
    cout<<*aux<<endl;++aux;
    cout<<*aux<<endl;++aux;
    cout<<*aux<<endl;


    cout<<"De reversa"<<endl;
    --aux;
    cout<<*aux<<endl;
    --aux;
    cout<<*aux<<endl;
    --aux;
    cout<<*aux<<endl;
    --aux;
    cout<<*aux<<endl;
    --aux;
    cout<<*aux<<endl;
    --aux;
    cout<<*aux<<endl;
//    Tester::execute();
//    return EXIT_SUCCESS;

}
