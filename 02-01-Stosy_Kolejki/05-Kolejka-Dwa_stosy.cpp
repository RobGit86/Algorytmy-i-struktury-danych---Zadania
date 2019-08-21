#include<iostream>
#include<climits>

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

void add(ele* &stos1, ele* &stos2, int x);
int next(ele* &stos1, ele* &stos2);
int firstEl(ele* stos1, ele* stos2);
bool isEmpty(ele* stos1);

void initMenu(ele* stos1, ele* stos2);
void showQueue(ele* stos1, ele* stos2);

void push(ele* &stos, int x);
int pop(ele* &stos);
int topEl(ele* stos);
bool isEmptyStack(ele* stos);

int main() {

    ele* stos1 = NULL;
    ele* stos2 = NULL;

    initMenu(stos1, stos2);

    return 0;
}

void add(ele* &stos1, ele* &stos2, int x) {

    push(stos1, x);
}

int next(ele* &stos1, ele* &stos2) {

    if(isEmptyStack(stos1)) {
        cout << "KOLEJKA PUSTA - OPERACJA NIEDOZWOLONA ";
        return INT_MIN;
    } else {
        int result;

        while(!isEmptyStack(stos1))
            push(stos2, pop(stos1));

        result = pop(stos2);

        while(!isEmptyStack(stos2))
            push(stos1, pop(stos2));

        return result;
    }
}

int firstEl(ele* stos1, ele* stos2) {

    if(isEmptyStack(stos1)) {
        cout << "KOLEJKA PUSTA - OPERACJA NIEDOZWOLONA ";
        return INT_MIN;
    } else {
        int result;

        while(!isEmptyStack(stos1))
            push(stos2, pop(stos1));
        result = topEl(stos2);

        while(!isEmptyStack(stos2))
            push(stos1, pop(stos2));

        return result;
    }
}

bool isEmpty(ele* stos1) {

    if(isEmptyStack(stos1))
        return true;
    else
        return false;
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

void initMenu(ele* stos1, ele* stos2) {

    char choice;

    do {
        cout << "Wybierz operację na stosie\n";
        cout << "1. Dodaj element do kolejki\n";
        cout << "2. Pobierz pierwszy element i zwróć\n";
        cout << "3. Zwróć element z początku kolejki bez jego usuwania\n";
        cout << "4. Sprawdź czy kolejka jest pusta\n";
        cout << "5. Wyświetl kolejkę\n";
        cout << "6. Wyjdź\n\n";
        cout << "OPCJA: ";

        cin >> choice;
        cout << endl;

        switch(choice) {
            case '1': cout << "Podaj daną do wprowadzenia: ";
                      int tmp;
                      cin >> tmp;
                      add(stos1, stos2, tmp);
                      cout << "Dodano " << tmp << endl << endl;
                      break;
            case '2': cout << "Zdjęto: " << next(stos1, stos2) << endl << endl;
                      break;
            case '3': cout << "Element na wierzchu: " << firstEl(stos1, stos2) << endl << endl;
                      break;
            case '4': if(isEmpty(stos1))
                        cout << "KOLEJKA JEST PUSTA" << endl << endl;
                      else
                        cout << "KOLEJKA NIE JEST PUSTA" << endl << endl;
                      break;
            case '5': showQueue(stos1, stos2);
                      break;
            case '6': cout << "DO WIDZENIA!";
                      break;

            default: cout << "ZŁA OPCJA";
                     break;
        }
    } while(choice !='6');
}

void showQueue(ele* stos1, ele* stos2) {

    if(isEmptyStack(stos1))
        cout << "KOLEJKA JEST PUSTA!\n\n";
    else {
        cout << "KOLEJKA: \n";
        while(!isEmptyStack(stos1))
            push(stos2, pop(stos1));
        while(!isEmptyStack(stos2)) {
            int tmp = pop(stos2);
            cout << tmp << endl;
            push(stos1, tmp);
        }
        cout << endl << endl;
    }
}
