#include "Header.h"

//struct Ships // Вроде класс, но все открыто//{
// bool horizontal = true;
// int x, y;
//};

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Q = 113 }; //клавиши
// Enum - перечисление констант

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    char** Playerfield1 = creatingField();
    /*char** PlayerfieldStep2 = creatingField();
    char** Playerfield2 = creatingField();*/

    char mas1[10] = { 'А','Б','В','Г','Д','Е','Ж','З','И','К' };
    char mas2[10] = { '1','2','3','4','5','6','7','8','9','0' };

    int keyboard = 0;
    keyboard = _getch(); // Дальше через switch можно будет проверять, какая клавиша была нажата

    //Корабли 

    char** arrayShip4 = new char* [1];
    for (int i = 0; i < 1; i++) {
        arrayShip4[i] = new char[4] { '#', '#', '#', '#' };
    }

    char** arrayShip3 = new char* [2]; 
    for (int i = 0; i < 2; i++) {
        arrayShip3[i] = new char[3] { '#', '#', '#' };
    }

    char** arrayShip2 = new char* [3];
    for (int i = 0; i < 3; i++) {
        arrayShip2[i] = new char[2] { '#', '#' };
    }

    char** arrayShip1 = new char* [4]; 
    for (int i = 0; i < 1; i++) {
        arrayShip1[i] = new char[1] { '#' };
    }

    //игра 
    initField(Playerfield1, mas1, mas2);
    //initField(Playerfield2, mas1, mas2);
    //copyfield(Playerfield2, PlayerfieldStep2);
    ShowField(Playerfield1); cout << "\n\n";

    string w;
    cout << "Хотите авто расстановку кораблей? (писать с большой буквы): "; cin >> w;
    if (w == "Да") {
        for (int i = 0; i < 10; i++) {
            createShipsAuto(arrayShip4, arrayShip3, arrayShip2, arrayShip1, Playerfield1, i);
        }
    }
    else if (w == "Нет") {
        char** PlayerfieldStep1 = creatingField();  copyfield(Playerfield1, PlayerfieldStep1);
        for (int i = 0; i < 10; i++) {
            createShips(arrayShip4, arrayShip3, arrayShip2, arrayShip1, Playerfield1, PlayerfieldStep1, i);
        }
    }
    else {
        cout << "Ошибка\n";
        while (true) {
            string w;
            cout << "Хотите авто расстановку кораблей? (писать с большой буквы): ";   cin >> w;
            if (w == "Да") {
                for (int i = 0; i < 10; i++) {
                    createShipsAuto(arrayShip4, arrayShip3, arrayShip2, arrayShip1, Playerfield1, i);
                }
                break;
            }
            else if (w == "Нет") {
                char** PlayerfieldStep1 = creatingField();
                copyfield(Playerfield1, PlayerfieldStep1);    
                for (int i = 0; i < 10; i++) {
                    createShips(arrayShip4, arrayShip3, arrayShip2, arrayShip1, Playerfield1, PlayerfieldStep1, i);
                }
                break;
            }
            else {
                cout << "Ошибка\n";
            }
        }
    } cout << "\n\n";

    ShowField(Playerfield1); cout << "\n\n";
    //ShowField(Playerfield2);

    while (true) {
        //UpdateField2(Playerfield2, PlayerfieldStep2, scope);
        //UpdateScope(scope);
    }
}