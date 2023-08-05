#include "Header.h"

struct Ships { // Вроде класс, но все открытo
    int sda = { 0 }; // кол-во палуб
    bool horizontal = true; // положение кораблика
    bool alive = true;
    int x, y; // позиции первой палубы кораблика 
};

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Q = 113}; //клавиши
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

// Эта функция работает по какой-то причине через раз, не знаю почему
void Auto(Ships* characteristicShips, int myShips[12][12], int plus) {
    int y, x, ship = plus; //переменная для координат и номера кораблика 
    while (ship < plus + 10) {
        characteristicShips[ship].horizontal = random(0, 2);
        y = random(1, 10), x = (random(1, 10)) * 2;
        if (characteristicShips[ship].horizontal == false && y + characteristicShips[ship].sda >= 13) {
            y -= y + characteristicShips[ship].sda - 12;
        }
        else if (characteristicShips[ship].horizontal == true && x + characteristicShips[ship].sda * 2 >= 24) {
            x -= (x + characteristicShips[ship].sda * 2) - 22;
        }

        int x1 = 0; // Переменная, для правильной отрисовки кораблей на поле
        switch (x) { //Для отрисовки кораблей (я не знаю, почему у меня раньше не получалось)
        case 2:
            x1 = 2;
            break;
        case 4:
            x1 = 3;
            break;
        case 6:
            x1 = 4;
            break;
        case 8:
            x1 = 5;
            break;
        case 10:
            x1 = 6;
            break;
        case 12:
            x1 = 7;
            break;
        case 14:
            x1 = 8;
            break;
        case 16:
            x1 = 9;
            break;
        case 18:
            x1 = 10;
            break;
        case 20:
            x1 = 11;
            break;
        }
        int counter1 = 0, counter2 = 0;
        if (characteristicShips[ship].horizontal == true) {
            for (int j = 0; j < characteristicShips[ship].sda; j++) {
                if (myShips[y - 1][x1 - 1 + j] == 0) {
                    counter1++;
                }
            }
        }
        if (characteristicShips[ship].horizontal == true && counter1 == characteristicShips[ship].sda) {
            characteristicShips[ship].x = x, characteristicShips[ship].y = y;
            for (int i = 0; i < 3; i++) {
                for (int j = 0, c = characteristicShips[ship].sda; j < characteristicShips[ship].sda + 2; j++, c--) {
                    if ((i == 0 || i == 2) || (i == 1 && j == 0 || j == characteristicShips[ship].sda + 1)) {
                        myShips[y - 2 + i][x1 - 2 + j] = 1; //меняем значение окупируемых позиций в двумерном массиве
                    }
                    else { //меняем значение позиций, где находится корабль в двумерном массиве
                        switch (characteristicShips[ship].sda) {
                        case 4:
                            myShips[y - 1][x1 - 1 + c] = 7;
                            break;
                        case 3:
                            myShips[y - 1][x1 - 1 + c] = 6;
                            break;
                        case 2:
                            myShips[y - 1][x1 - 1 + c] = 5;
                            break;
                        case 1:
                            myShips[y - 1][x1 - 1 + c] = 4;
                            break;
                        }
                    }
                }
            }
            ship++;
        }

        if (characteristicShips[ship].horizontal == false) {
            for (int j = 0; j < characteristicShips[ship].sda; j++) {
                if (myShips[y - 1 + j][x1 - 1] == 0) {
                    counter2++;
                }
            }
        }
        if (characteristicShips[ship].horizontal == false && counter2 == characteristicShips[ship].sda) {
            characteristicShips[ship].x = x, characteristicShips[ship].y = y;
            for (int i = 0, c = characteristicShips[ship].sda; i < characteristicShips[ship].sda + 2; i++, c--) {
                for (int j = 0; j < 3; j++) {
                    if ((j == 0 || j == 2) || (j == 1 && i == 0 || i == characteristicShips[ship].sda + 1)) {
                        myShips[y - 2 + i][x1 - 2 + j] = 1;
                    }
                    else {
                        switch (characteristicShips[ship].sda) {
                        case 4:
                            myShips[y - 1 + c][x1 - 1] = 7;
                            break;
                        case 3:
                            myShips[y - 1 + c][x1 - 1] = 6;
                            break;
                        case 2:
                            myShips[y - 1 + c][x1 - 1] = 5;
                            break;
                        case 1:
                            myShips[y - 1 + c][x1 - 1] = 4;
                            break;
                        }
                    }
                }
            }
            ship++;
        }
    }
}

void check_for_destruction(Ships* characteristicShips, int mas[12][12], int plus, int& end) {
    int A = 0; //для правильной зарисовки границы вокруг взоравнного кораблика
    int B = 13; //переменная, которая будет помогать указывать на нужный кораблик
    int C = 0; //хранение количества уничтоженных корабликов
    bool alive = false;
    for (int n = 13; n > 3; n--) //проверяем все номерки корабликов на наличие их в массиве
    {
        for (int i = 1; i < 11; i++) {
            for (int r = 1; r < 11; r++) {
                if (mas[i][r] == n) //проверяем, есть ли в массиве хоть один номерок с корабликом
                {
                    alive = true; //в случае успеха - кораблик жив/ранен
                    i = 11;
                    break;
                }
            }
        }
        if (alive == false) {
            characteristicShips[B - n + plus].alive = false;
        }
        else {
            alive = false;
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    char var[2][30] = { "Автоматическая расстановка ","Ручная расстановка " };
    char menu[5][15] = { "МОРСКОЙ БОЙ","Играть ","Управление ","История ","Выход " };
    int myShips[12][12] = { 0 };
    int enemyShips[12][12] = { 0 };
    /*
    0 - то, куда можно ставить кораблики
    1 - место около кораблика, куда нельзя ставить
    2 - место, где был выстрел, но не было кораблика
    3 - место, где был выстрел и находился кораблик
    4 - кораблики с 1 палубой
    5 - кораблики с 2 палубой
    6 - кораблики с 3 палубой
    7 - кораблики с 4 палубой
    */

    Ships* characteristicShips = new Ships[20]; // Создание 10 корабликов (Всего палуб 20)
    LoadShips(characteristicShips);

    int key = 1, y = 2, x = 2, num = 0, change = 1, b = 0, xx = 37, yy = 2, up = 0, down = 0, over = 0;

    bool arrangement = true, round = false, your_turn = random(0, 2);
    /*
    key - для записи нажатой клавиши
    round - для проверки на начало боя
    b - дополнительная переменная для меню
    up - поможет правильно добивать наши кораблики
    down - поможет правильно добивать наши кораблики
    xx - дополнительная перемнная для записи положения курсора на вражеском поле
    yy - дополнительная перемнная для записи положения курсора на вражеском поле
    y - позиция по Y
    x - позиция по X
    change - номер расстановки который будет использован
    num - номер кораблкиа
    arrangement - тип расстановки который будет использован
    */

    string path_histopy = "C:\\Users\\PC\\Desktop\\SeaBattle\\History.txt"; // Доп текстовые файлы
    string path_control = "C:\\Users\\PC\\Desktop\\SeaBattle\\Control.txt";

    // Игра
    cout << "Нажмите на любую клавишу для продолжения: ";
    int a = _getch();
    if (a != 0) {
        system("cls");
        Start(menu);
    }

    Choice_1(menu, change);
    int s = 1; // переменная для правильного передвижения стрелочки
    do {
        key = _getch(); 
        switch (key) {
        case Up:
            if (s > 1) {
                s--;
                change = s;
                Choice_1(menu, change);
            }
            break;
        case Down:
            if (s < 4) {
                s++;
                change = s;
                Choice_1(menu, change);
            }
            break;
        case Enter:
            do {
                switch (change) {
                case 1:
                    b++;
                    break;

                case 2:
                {
                    system("cls");
                    ifstream file_in;
                    string str;
                    file_in.open(path_control);
                    if (file_in.is_open()) {
                        while (getline(file_in, str)) {
                            cout << str << endl;
                        }
                    }
                    else {
                        cout << "Ошибка файла";
                        exit(0);
                    }
                    file_in.close();
                    cout << endl << "Нажмите любую клавишу, чтобы вернуться: ";
                    int a = _getch();
                    if (a != 0) {
                        Choice_1(menu, change);
                    }
                }
                    break;

                case 3:
                {
                    system("cls");
                    ifstream file_in;
                    string str;
                    file_in.open(path_histopy);
                    if (file_in.is_open()) {
                        while (getline(file_in, str)) {
                            cout << str << endl;
                        }
                    }
                    else {
                        cout << "Ошибка файла";
                        exit(0);
                    }
                    file_in.close();
                    cout << endl << "Нажмите любую клавишу, чтобы вернуться: ";
                    int a = _getch();
                    if (a != 0) {
                        Choice_1(menu, change);
                    }
                }
                    break;

                case 4:
                    exit(0);
                }
            } while (key != Enter);
        }
    } while (b < 1);

    b = 0, s = 1, change = 1; // На всякий верну на прежние значения

    system("cls");

    Choice_2(var, change);
    do {
        key = _getch();
        switch (key) {
        case Up:
            if (s > 0) {
                s--; 
                change = s; 
                Choice_2(var, change); 
            }
            break;
        case Down:
            if (s < 1) {
                s++; 
                change = s; 
                Choice_2(var, change);
            }
            break;
        case Enter:
            do {
                switch (change) {
                case 0:
                    arrangement = false; //автоматическая расстанвкоа
                    b++; 
                    break;
                case 1:
                    arrangement = true; //ручная расстановка
                    b++; 
                    s++;
                    break;
                }
            } while (key != Enter);
        }
    } while (b < 1);

    system("cls");
    Createfield(0);
    
    if (arrangement == true) { // ручная расстановка
        do {
            Pos(myShips, 2);
            SetCursor(x, y);
            if (characteristicShips[num].horizontal == true) {
                for (int i = 0; i < characteristicShips[num].sda; i++) {
                    cout << "# ";
                }
            }
            else if (characteristicShips[num].horizontal == false) {
                y += characteristicShips[num].sda; //изменяем позицию по "y" на то сколько палуб у кораблика
                for (int i = 0; i < characteristicShips[num].sda; i++) { //запускаем цикл который будет отрисовыввать кораблик с нужным колличеством палуб
                    cout << "# ";
                    y--; 
                    SetCursor(x, y);
                }
            }
            key = _getch();
            switch (key) {
            case Left:
                if (x > 2) {
                    x -= 2;
                }
                break;

            case Right:
                if (characteristicShips[num].horizontal == true) {
                    if (num < 3) {
                        if (x < 18 - characteristicShips[num].sda) {
                            x += 2;
                        }
                    }
                    else if (num > 2 && num < 6) {
                        if (x < 20 - characteristicShips[num].sda) {
                            x += 2;
                        }
                    }
                    else {
                        if (x < 21 - characteristicShips[num].sda) {
                            x += 2;
                        }
                    }
                }
                else {
                    if (x < 20) {
                        x += 2;
                    }
                }
                break;

            case Up:
                if (y > 2) {
                    y--;
                }
                break;

            case Down:
                if (characteristicShips[num].horizontal == false) {
                    if (y < 12 - characteristicShips[num].sda) {
                        y++;
                    }
                }
                else {
                    if (y < 11) {
                        y++;
                    }
                }
                break;

            case Q:
                characteristicShips[num].horizontal = !characteristicShips[num].horizontal; //изменяем ориентацию кораблика на противоположную
                if (characteristicShips[num].horizontal == false && y + characteristicShips[num].sda >= 13) {
                    y -= y + characteristicShips[num].sda - 12; 
                }
                else if (characteristicShips[num].horizontal == true && x + characteristicShips[num].sda * 2 >= 24) {
                    x -= (x + characteristicShips[num].sda * 2) - 22; 
                }
                for (int i = 0; i < 10 - num; i++) { //изменяем ориентацию так же и для последующих корабликов
                    characteristicShips[num + i].horizontal = characteristicShips[num].horizontal; 
                }
                break;

            case Enter:
                int x1 = 0; // Переменная, для правильной отрисовки кораблей на поле
                switch (x) { //Для отрисовки кораблей (я не знаю, почему у меня раньше не получалось)
                case 2:
                    x1 = 2;
                    break;
                case 4:
                    x1 = 3;
                    break;
                case 6:
                    x1 = 4;
                    break;
                case 8:
                    x1 = 5;
                    break;
                case 10:
                    x1 = 6;
                    break;
                case 12:
                    x1 = 7;
                    break;
                case 14:
                    x1 = 8;
                    break;
                case 16:
                    x1 = 9;
                    break;
                case 18:
                    x1 = 10;
                    break;
                case 20:
                    x1 = 11;
                    break;
                }
                int counter1 = 0, counter2 = 0;
                if (characteristicShips[num].horizontal == true) { 
                    for (int j = 0; j < characteristicShips[num].sda; j++) {
                        if (myShips[y - 1][x1 - 1 + j] == 0) {
                            counter1++;
                        }
                    }
                }
                if (characteristicShips[num].horizontal == true && counter1 == characteristicShips[num].sda) {
                    characteristicShips[num].x = x, characteristicShips[num].y = y;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0, c = characteristicShips[num].sda; j < characteristicShips[num].sda + 2; j++, c--) {
                            if ((i == 0 || i == 2) || (i == 1 && j == 0 || j == characteristicShips[num].sda + 1)) {
                                myShips[y - 2 + i][x1 - 2 + j] = 1; //меняем значение окупируемых позиций в двумерном массиве
                            }
                            else { //меняем значение позиций, где находится корабль в двумерном массиве
                                switch (characteristicShips[num].sda) {
                                case 4:
                                    myShips[y - 1][x1 - 1 + c] = 7;
                                    break;
                                case 3:
                                    myShips[y - 1][x1 - 1 + c] = 6;
                                    break;
                                case 2:
                                    myShips[y - 1][x1 - 1 + c] = 5;
                                    break;
                                case 1:
                                    myShips[y - 1][x1 - 1 + c] = 4;
                                    break;
                                }
                            }
                        }
                    }
                    num++;
                }

                if (characteristicShips[num].horizontal == false) {
                    for (int j = 0; j < characteristicShips[num].sda; j++) {
                        if (myShips[y - 1 + j][x1 - 1] == 0) {
                            counter2++;
                        }
                    }
                }
                if (characteristicShips[num].horizontal == false && counter2 == characteristicShips[num].sda) {
                    characteristicShips[num].x = x, characteristicShips[num].y = y;
                    for (int i = 0, c = characteristicShips[num].sda; i < characteristicShips[num].sda + 2; i++, c--) {
                        for (int j = 0; j < 3; j++) {
                            if ((j == 0 || j == 2) || (j == 1 && i == 0 || i == characteristicShips[num].sda + 1)) {
                                myShips[y - 2 + i][x1 - 2 + j] = 1;
                            }
                            else {
                                switch (characteristicShips[num].sda) {
                                case 4:
                                    myShips[y - 1 + c][x1 - 1] = 7;
                                    break;
                                case 3:
                                    myShips[y - 1 + c][x1 - 1] = 6;
                                    break;
                                case 2:
                                    myShips[y - 1 + c][x1 - 1] = 5;
                                    break;
                                case 1:
                                    myShips[y - 1 + c][x1 - 1] = 4;
                                    break;
                                }
                            }
                        }
                    }
                    num++; 
                }
            }
        } while (num <= 9);
        round = true;
    }
    else if (arrangement == false) {
        Auto(characteristicShips, myShips, 0);
        Pos(myShips, 2);
        round = true;
    }

    Sleep(20);
    Createfield(35);

    Auto(characteristicShips, enemyShips, 10);
    Pos_enemy(myShips, 37);
    do {
        if (your_turn == true) {
            do {
                x = xx, y = yy; //переменная которая будет запоминать где находился курсор 
                Pos_enemy(enemyShips, 37);
                SetCursor(x, y);
                cout << "@ ";
                key = _getch();
                switch (key) {
                case Left: 
                    if (x > 38) {
                        x -= 2; 
                        xx = x; 
                    }
                    break;
                case Right: 
                    if (x < 55) {
                        x += 2;
                        xx = x; 
                    }
                    break; 
                case Up:
                    if (y > 2) {
                        y--;  
                        yy = y;
                    }
                    break; 
                case Down:
                    if (y < 11) {
                        y++;
                        yy = y;
                    }
                    break;
                case Enter:
                    int x1 = 0; // Переменная, для правильной отрисовки кораблей на поле
                    switch (x) { //Для отрисовки кораблей (я не знаю, почему у меня раньше не получалось)
                    case 2:
                        x1 = 2;
                        break;
                    case 4:
                        x1 = 3;
                        break;
                    case 6:
                        x1 = 4;
                        break;
                    case 8:
                        x1 = 5;
                        break;
                    case 10:
                        x1 = 6;
                        break;
                    case 12:
                        x1 = 7;
                        break;
                    case 14:
                        x1 = 8;
                        break;
                    case 16:
                        x1 = 9;
                        break;
                    case 18:
                        x1 = 10;
                        break;
                    case 20:
                        x1 = 11;
                        break;
                    }
                    if (enemyShips[y - 1][x1 - 35] >= 4) {
                        for (int i = 0; i < 1; i++) //если это так то мызаменяем в клеточке номерок кораблика на "3"
                        {
                            enemyShips[y - 1][x1 - 35 + i] = 3; 
                            check_for_destruction(characteristicShips, enemyShips, 10, over); //проверяем на уничтожение
                        }
                        Meny(7); //вывод реплики
                        Sleep(500);
                    }
                    else if (enemyShips[y - 1][x1 - 35] < 2) {
                        for (int i = 0; i < 1; i++) {
                            enemyShips[y - 1][x1 - 35 + i] = 2; 
                        }
                        Sleep(500);
                        Meny(5); //вывод реплики
                        your_turn = false; 
                    }
                    break;
                }
            } while (key != Enter);
        }
        if (your_turn == false) {
            Sleep(0 + rand() % 400);
            Meny(0); 
            Pos(myShips, 2);
            Sleep(0 + rand() % 400);
            y = random(1, 10), x = (random(1, 10)) * 2;
            int x1 = 0; // Переменная, для правильной отрисовки кораблей на поле
            switch (x) { //Для отрисовки кораблей (я не знаю, почему у меня раньше не получалось)
            case 2:
                x1 = 2;
                break;
            case 4:
                x1 = 3;
                break;
            case 6:
                x1 = 4;
                break;
            case 8:
                x1 = 5;
                break;
            case 10:
                x1 = 6;
                break;
            case 12:
                x1 = 7;
                break;
            case 14:
                x1 = 8;
                break;
            case 16:
                x1 = 9;
                break;
            case 18:
                x1 = 10;
                break;
            case 20:
                x1 = 11;
                break;
            }
            if (myShips[y - 1][x1 - 1] >= 4) {
                for (int i = 0; i < 2; i++) //если это так то мызаменяем в клеточке номерок кораблика на "3"
                {
                    myShips[y - 1][x1 - 2 + i] = 3;
                    check_for_destruction(characteristicShips, myShips, 0, over); //проверяем на уничтожение
                }
                Meny(2); 
                Sleep(0 + rand() % 750);
            }
            else if (myShips[y - 1][x1 - 1] <= 2) {
                for (int i = 0; i < 2; i++) {
                    myShips[y - 1][x1 - 2 + i] = 2;
                }
                Meny(1); 
                Sleep(0 + rand() % 750); 
                your_turn = true;
            }
        }
    } while (over == 0);
}