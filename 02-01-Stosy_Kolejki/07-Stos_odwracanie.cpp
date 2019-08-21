#include<iostream>
#include<climits>

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

void stackReverseStack(ele* &stos);
void stackReverseQueue(ele* &stos);

void push(ele* &stos, int x);
int pop(ele* &stos);
int topEl(ele* stos);
bool isEmptyStack(ele* stos);

void add(ele* &poczkol, ele* &konkol, int x);
int next(ele* &poczkol, ele* &konkol);
int firstEl(ele* poczkol);
bool isEmptyQueue(ele* poczkol);

void initMenu(ele* stos);
void showStack(ele* stos);



int main() {

    ele* stos = NULL;

    initMenu(stos);

    return 0;
}

void stackReverseStack(ele* &stos) {

    ele* stos2 = NULL;

    while(!isEmptyStack(stos))
        push(stos2, pop(stos));

    stos = stos2;
}

void stackReverseQueue(ele* &stos) {

    ele* poczkol = NULL;
    ele* konkol = NULL;

    while(!isEmptyStack(stos))
        add(poczkol, konkol, pop(stos));

    while(!isEmptyQueue(poczkol))
        push(stos, next(poczkol, konkol));
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
        return INT_MIN;
    else {
        ele* tmp = poczkol->nast;
        int result = poczkol->dana;
        delete poczkol;
        poczkol = tmp;
        return result;
    }
}

int firstEl(ele* poczkol) {

    if(poczkol == NULL) {
        cout << "KOLEJKA JEST PUSTA - NIEDOZWOLONA OPERACJA ";
        return INT_MIN;
    } else
        return poczkol->dana;
}

bool isEmptyQueue(ele* poczkol) {

    if(poczkol == NULL)
        return true;
    else
        return false;
}

void initMenu(ele* stos) {

    char choice;

    do {
        cout << "Wybierz operację na stosie\n";
        cout << "1. Dodaj do stosu\n";
        cout << "2. Pobierz ze stosu i zwróć jako wartość funkcji\n";
        cout << "3. Zwróć element bez jego usuwania\n";
        cout << "4. Sprawdź czy stos jest pusty\n";
        cout << "5. Wyświetl stos\n";
        cout << "6. ODWRÓĆ STOSEM\n";
        cout << "7. ODWRÓĆ KOLEJKĄ\n";
        cout << "8. Wyjdź\n\n";
        cout << "OPCJA: ";

        cin >> choice;
        cout << endl;

        switch(choice) {
            case '1': cout << "Podaj daną do wprowadzenia: ";
                      int tmp;
                      cin >> tmp;
                      push(stos, tmp);
                      cout << "Dodano " << tmp << endl << endl;
                      break;
            case '2': cout << "Zdjęto: " << pop(stos) << endl << endl;
                      break;
            case '3': cout << "Element na wierzchu: " << topEl(stos) << endl << endl;
                      break;
            case '4': if(isEmptyStack(stos))
                        cout << "STOS JEST PUSTY" << endl << endl;
                      else
                        cout << "STOS NIE JEST PUSTY" << endl << endl;
                      break;
            case '5': showStack(stos);
                      break;
            case '6': stackReverseStack(stos);
                      cout << "ODWRÓCONO\n\n";
                      break;
            case '7': stackReverseQueue(stos);
                      cout << "ODWRÓCONO\n\n";
                      break;
            case '8': cout << "DO WIDZENIA!";
                      break;

            default: cout << "ZŁA OPCJA";
                     break;
        }
    } while(choice !='8');
}

void showStack(ele* stos) {

    if(stos == NULL)
        cout << "STOS JEST PUSTY!\n\n";
    else {
        cout << "STOS: \n";
        while(stos != NULL) {
            cout << stos->dana << endl;
            stos = stos->nast;
        }
        cout << endl << endl;
    }
}

