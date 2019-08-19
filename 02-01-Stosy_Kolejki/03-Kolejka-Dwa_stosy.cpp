#include<iostream>
#include<climits>

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

void add(ele* &poczkol, ele* &konkol, int x);
int next(ele* &poczkol, ele* &konkol);
int firstEl(ele* poczkol);
bool isEmpty(ele* poczkol);

void push(ele* &stos, int x);
int pop(ele* &stos);
int topEl(ele* stos);
bool isEmptyStack(ele* stos);

int main() {

}

void add(ele* &poczkol, ele* &konkol, int x) {

}

int next(ele* &poczkol, ele* &konkol) {


}

int firstEl(ele* poczkol) {

}

bool isEmpty(ele* poczkol) {

}

void push(ele* &stos, int x) {

    ele* nowy = new ele;
    nowy->dana = x;
    nowy->nast = stos;
    stos = nowy;
}

int pop(ele* &stos) {

    if(stos == NULL) {
        cout << "STOS JEST PUSTY - OPERACJA NIEDOZWOLONA";
        return INT_MIN;
    } else {
        ele* tmp = stos->nast;
        int tmp_dana = stos->dana;
        delete stos;
        stos = tmp;
        return tmp_dana;
    }
}

int topEl(ele* stos) {

    if(stos == NULL)
        cout << "STOS JEST PUSTY - OPERACJA NIEDOZWOLONA";
    else
        return stos->dana;
}

bool isEmptyStack(ele* stos) {

    if(stos == NULL)
        return true;
    else
        return false;
}
