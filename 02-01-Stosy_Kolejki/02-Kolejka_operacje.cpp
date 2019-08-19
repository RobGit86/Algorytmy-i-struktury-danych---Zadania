#include<iostream>

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

void add(ele* &poczkol, ele* &konkol, int x);

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
