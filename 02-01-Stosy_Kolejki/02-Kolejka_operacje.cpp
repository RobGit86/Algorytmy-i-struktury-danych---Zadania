#include<iostream>

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
        return 1;
    else {
        ele* tmp = poczkol->nast;
        int result = poczkol->dana;
        delete poczkol;
        poczkol = tmp;
        return result;
    }
}
