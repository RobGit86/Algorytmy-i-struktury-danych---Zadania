#include<iostream>
#include<climits>

#define N 3

using namespace std;

void add(int &poczkol, int &konkol, int x, int *que);
int next(int &poczkol, int &konkol, int *que);
int firstEl(int poczkol, int *que);
bool isEmpty(int poczkol);

void initMenu(int &poczkol, int &konkol, int *que);
void showQueue(int &poczkol, int &konkol, int *que);

int main() {

    int que[N];
    int head = -1;
    int tail = -1;

    initMenu(head, tail, que);

    return 0;
}

void add(int &poczkol, int &konkol, int x, int *que) {

    if(konkol == N-1)
        cout << "KOLEJKA PEŁNA - OPERACJA NIEMOŻLIWA\n\n";
    else {
        que[konkol+1] = x;
        konkol++;
        if(poczkol == -1)
            poczkol++;
    }
}

int next(int &poczkol, int &konkol, int *que) {

    if(poczkol == -1 && konkol == -1) {
        cout << "KOLEJKA PUSTA - OPERACJA NIEDOZWOLONA ";
        return INT_MIN;
    } else {
        int result = que[0];
        for(int i=0; i<N; i++)
            que[i] = que[i+1];
        konkol--;
        if(konkol == -1)
            poczkol--;
        return result;
    }
}

int firstEl(int poczkol, int *que) {

    if(poczkol == -1) {
        cout << "KOLEJKA PUSTA - OPERACJA NIEDOZWOLONA ";
        return INT_MIN;
    } else
        return que[0];
}

bool isEmpty(int poczkol) {

    if(poczkol == -1)
        return true;
    else
        return false;
}

void initMenu(int &poczkol, int &konkol, int *que) {

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
                      add(poczkol, konkol, tmp, que);
                      cout << "Dodano " << tmp << endl << endl;
                      break;
            case '2': cout << "Zdjęto: " << next(poczkol, konkol, que) << endl << endl;
                      break;
            case '3': cout << "Element na wierzchu: " << firstEl(poczkol, que) << endl << endl;
                      break;
            case '4': if(isEmpty(poczkol))
                        cout << "KOLEJKA JEST PUSTA" << endl << endl;
                      else
                        cout << "KOLEJKA NIE JEST PUSTA" << endl << endl;
                      break;
            case '5': showQueue(poczkol, konkol, que);
                      break;
            case '6': cout << "DO WIDZENIA!";
                      break;

            default: cout << "ZŁA OPCJA";
                     break;
        }
    } while(choice !='6');
}

void showQueue(int &poczkol, int &konkol, int *que) {

    if(poczkol == -1)
        cout << "KOLEJKA JEST PUSTA!\n\n";
    else {
        cout << "KOLEJKA: \n";
        for(int i=0; i <= konkol; i++)
            cout << que[i] << endl;
        cout << endl << endl;
    }
}
