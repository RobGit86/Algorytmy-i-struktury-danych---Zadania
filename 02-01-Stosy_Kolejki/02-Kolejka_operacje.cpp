#include<iostream>
<<<<<<< HEAD
=======
#include<climits>
>>>>>>> master

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

void add(ele* &poczkol, ele* &konkol, int x);
int next(ele* &poczkol, ele* &konkol);

int main() {


}

void add(ele* &poczkol, ele* &konkol, int x) {

    ele* node = new ele;
    node->dana = x;
    node->nast = NULL;

    if(poczkol == NULL && konkol == NULL)
        poczkol = konkol = node;
    else {
        konkol->nast = node;
        konkol = node;
    }
}

int next(ele* &poczkol, ele* &konkol) {

    if(poczkol == NULL && konkol == NULL)
<<<<<<< HEAD
        return 1;
=======
        return INT_MIN;
>>>>>>> master
    else {
        ele* tmp = poczkol->nast;
        int result = poczkol->dana;
        delete poczkol;
        poczkol = tmp;
        return result;
    }
}
<<<<<<< HEAD
=======

int firstEl(ele* poczkol) {

    if(poczkol == NULL && konkol == NULL)
        return INT_MIN;
    else
        return poczkol->dana;
}
>>>>>>> master
