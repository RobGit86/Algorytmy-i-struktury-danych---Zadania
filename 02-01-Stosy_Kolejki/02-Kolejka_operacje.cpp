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

void initMenu(ele* poczkol, ele* konkol);
void showQueue(ele* poczkol, ele* konkol);

int main() {

    ele* head = NULL;
    ele* tail = NULL;

    initMenu(head, tail);

    return 0;
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

bool isEmpty(ele* poczkol) {

    if(poczkol == NULL)
        return true;
    else
        return false;
}

void initMenu(ele* poczkol, ele* konkol) {

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
                      add(poczkol, konkol, tmp);
                      cout << "Dodano " << tmp << endl << endl;
                      break;
            case '2': cout << "Zdjęto: " << next(poczkol, konkol) << endl << endl;
                      break;
            case '3': cout << "Element na wierzchu: " << firstEl(poczkol) << endl << endl;
                      break;
            case '4': if(isEmpty(poczkol))
                        cout << "KOLEJKA JEST PUSTA" << endl << endl;
                      else
                        cout << "KOLEJKA NIE JEST PUSTA" << endl << endl;
                      break;
            case '5': showQueue(poczkol, konkol);
                      break;
            case '6': cout << "DO WIDZENIA!";
                      break;

            default: cout << "ZŁA OPCJA";
                     break;
        }
    } while(choice !='6');
}

void showQueue(ele* poczkol, ele* konkol) {

    if(poczkol == NULL)
        cout << "KOLEJKA JEST PUSTA!\n\n";
    else {
        cout << "KOLEJKA: \n";
        while(poczkol != NULL) {
            cout << poczkol->dana << endl;
            poczkol = poczkol->nast;
        }
        cout << endl << endl;
    }
}
