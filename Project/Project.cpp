#include "Header.h"

struct Ships { // Вроде класс, но все открытo
    int sda = { 0 }; // кол-во палуб
    bool horizontal = true; // положение кораблика
    int x, y; // позиции первой палубы кораблика 
};

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Q = 113 }; //клавиши
// Enum - перечисление констант

void LoadShips(Ships* characteristicShips) {
    for (int i = 0; i < 20; i++) {
        if (i == 0 || i == 10) {
            characteristicShips[i].sda = 4; // 4-палубный кораблик
        }
        else if (i > 0 && i <= 2 || i > 10 && i <= 12) {
            characteristicShips[i].sda = 3; // 3-палубные кораблики
        }
        else if (i > 2 && i <= 5 || i > 12 && i <= 15) {
            characteristicShips[i].sda = 2; // 2-палубные кораблики
        }
        else if (i > 5 && i <= 9 || i > 15 && i <= 19) {
            characteristicShips[i].sda = 1; // 1-палубные кораблики
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    char var[2][30] = { "Автоматическая расстановка","Ручная расстановка" };
    char menu[4][15] = { "МОРСКОЙ БОЙ","Играть","История","Выход" };
    int myShips[12][12] = { 0 };
    int enemyShips[12][12] = { 0 };
    /*
    0 - то, куда можно ставить кораблики
    1 - место около кораблика, куда нельзя ставить
    2 - место, где был выстрел, но не было кораблика
    3 - место, где был выстрел и находился кораблик
    4 - 1 кораблик с 1 палубой
    5 - 2 кораблик с 1 палубой
    6 - 3 кораблик с 1 палубой
    7 - 4 кораблик с 1 палубой
    8 - 1 кораблик с 2 палубой
    9 - 2 кораблик с 2 палубой
    10 - 3 кораблик с 2 палубой
    11 - 1 кораблик с 3 палубой
    12 - 2 кораблик с 3 палубой
    13 - 1 кораблик с 4 палубой
    */

    Ships* characteristicShips = new Ships[20]; // Создание 10 корабликов (Всего палуб 20)
    LoadShips(characteristicShips);

   /* char mas1[10] = { 'А','Б','В','Г','Д','Е','Ж','З','И','К' };
    char mas2[10] = { '1','2','3','4','5','6','7','8','9','0' };*/


    int key = 1, y = 2, x = 2, num = 0, change = 1, b = 0, x2 = 37, y2 = 2, up = 0, down = 0, over = 0;

    bool arrangement = true, round = false;
    /*
    key - переменная для записи нажатой клавиши
    round - переменная для проверки на начало боя
    b - дополнительная переменная для меню
    up - переменная которая поможет правильно добивать наши кораблики
    down - переменная которая поможет правильно добивать наши кораблики
    x2 - дополнительная перемнная для записи положения курсора на вражеском поле
    y2 - дополнительная перемнная для записи положения курсора на вражеском поле
    y - позиция по Y
    x - позиция по X
    change - номер расстановки который будет использован
    num - номер кораблкиа
    arrangement - тип расстановки который будет использован
    */


    // Игра
    cout << "Нажмите на любую клавишу для продолжения: ";
    int a = _getch();
    if (a != 0) {
        system("cls");
        Start(menu);
        Sleep(100);
    }
    Choice_1(menu, change);
    do {
        key = _getch(); 
        switch (key) {
        case Up:
            if (y > 1) {
                y--;
                change = y;
                Choice_1(menu, change);
            }
            break;
        case Down:
            if (y < 3) {
                y++;
                change = y;
                Choice_1(menu, change);
            }
            break;
        case Enter:
            do {
                switch (change) {
                case 1:
                    cout << endl << "Игра";
                    b++;
                    break;
                case 2:
                    cout << endl << "Файл";
                    b++;
                    break;
                case 3:
                    exit(0);
                }
            } while (key != Enter);
        }
    } while (b < 1);
}