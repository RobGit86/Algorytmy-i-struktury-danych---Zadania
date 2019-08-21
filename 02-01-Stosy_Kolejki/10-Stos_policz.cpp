#include<iostream>
#include<climits>

using namespace std;

struct ele {
    int dana;
    ele* nast;
};

int countStack(ele* &stos);

void push(ele* &stos, int x);
int pop(ele* &stos);
int topEl(ele* stos);
bool isEmpty(ele* stos);

void initMenu(ele* stos);
void showStack(ele* stos);

int main() {

    ele* stos = NULL;

    initMenu(stos);

    return 0;
}

int countStack(ele* &stos) {

    int result = 0;
    ele* tmpStack = NULL;

    while(!isEmpty(stos)) {
        push(tmpStack, pop(stos));
        result++;
    }

    while(!isEmpty(tmpStack))
        push(stos, pop(tmpStack));

    return result;
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

bool isEmpty(ele* stos) {

    if(stos == NULL)
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
        cout << "6. LICZBA ELEMENTÓW NA STOSIE\n";
        cout << "7. Wyjdź\n\n";
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
            case '4': if(isEmpty(stos))
                        cout << "STOS JEST PUSTY" << endl << endl;
                      else
                        cout << "STOS NIE JEST PUSTY" << endl << endl;
                      break;
            case '5': showStack(stos);
                      break;
            case '6': cout << "LICZBA ELEMENTÓW NA STOSIE: ";
                      cout << countStack(stos) << endl << endl;
                      break;
            case '7': cout << "DO WIDZENIA!";
                      break;

            default: cout << "ZŁA OPCJA";
                     break;
        }
    } while(choice !='7');
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
