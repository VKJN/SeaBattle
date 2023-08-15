#include "Header.h"

struct Ships { // Вроде класс, но все открытo
    int sda = { 0 }; // кол-во палуб
    bool horizontal = true; // положение кораблика
    bool alive = true;
    int x, y; // позиции первой палубы кораблика 
};

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Q = 113}; //клавиши
// Enum - перечисление констант

void Alive(Ships* characteristicShips) {
    for (int i = 0; i < 20; i++) {
        characteristicShips[i].alive = true;
        characteristicShips[i].horizontal = true;
        characteristicShips[i].x = 0;
        characteristicShips[i].y = 0;
    }
}

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

void Auto(Ships* characteristicShips, int myShips[12][12], int plus) {
    int y, x, ship = plus; //переменная для координат и номера кораблика 
    while (ship < plus + 10) {
        characteristicShips[ship].horizontal = random(0, 1);
        y = random(2, 11), x = (random(1, 10)) * 2;
        if (characteristicShips[ship].horizontal == false && y + characteristicShips[ship].sda >= 13) {
            y -= y + characteristicShips[ship].sda - 12;
        }
        else if (characteristicShips[ship].horizontal == true && x + characteristicShips[ship].sda * 2 >= 24) {
            x -= (x + characteristicShips[ship].sda * 2) - 22;
        }

        int x1 = 0; // Переменная, для правильной отрисовки кораблей на поле
        switch (x) { //Для отрисовки кораблей 
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
            characteristicShips[ship].x = x1, characteristicShips[ship].y = y;
            for (int i = 0; i < 3; i++) {
                for (int j = 0, c = characteristicShips[ship].sda; j < characteristicShips[ship].sda + 2; j++, c--) {
                    if ((i == 0 || i == 2) || (i == 1 && j == 0 || j == characteristicShips[ship].sda + 1)) {
                        myShips[y - 2 + i][x1 - 2 + j] = 1; //меняем значение окупируемых позиций в двумерном массиве
                    }
                    else { //меняем значение позиций, где находится корабль в двумерном массиве
                        myShips[y - 1][x1 - 1 + c] = 13 - ship + plus;
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
            characteristicShips[ship].x = x1, characteristicShips[ship].y = y;
            for (int i = 0, c = characteristicShips[ship].sda; i < characteristicShips[ship].sda + 2; i++, c--) {
                for (int j = 0; j < 3; j++) {
                    if ((j == 0 || j == 2) || (j == 1 && i == 0 || i == characteristicShips[ship].sda + 1)) {
                        myShips[y - 2 + i][x1 - 2 + j] = 1;
                    }
                    else {
                        myShips[y - 1 + c][x1 - 1] = 13 - ship + plus;
                    }
                }
            }
            ship++;
        }
    }
}

void check_for_destruction(Ships* characteristicShips, int mas[12][12], int plus, int& end) {
    int B = 13; //переменная, которая будет помогать указывать на нужный кораблик
    int C = 0;
    bool alive = false;
    for (int n = 13; n > 3; n--) {
        for (int i = 1; i < 11; i++) {
            for (int j = 1; j < 11; j++) {
                if (mas[i][j] == n) {
                    alive = true;
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

    for (int i = plus; i < 10 + plus; i++) {
        if (characteristicShips[i].alive == false) {
            if (characteristicShips[i].horizontal == true) {
                for (int j = 0; j < 3; j++) {
                    for (int w = 0, c = characteristicShips[i].sda; w < characteristicShips[i].sda + 2; w++, c--) {
                        if ((j == 0 || j == 2) || (j == 1 && w == 0 || w == characteristicShips[i].sda + 1)) {
                            mas[characteristicShips[i].y - 2 + j][characteristicShips[i].x - 2 + w] = 2;
                        }
                        else {
                            mas[characteristicShips[i].y - 1][characteristicShips[i].x - 1 + c] = 3;
                        }
                    }
                } 
            }
            else if (characteristicShips[i].horizontal == false) {
                for (int j = 0, c = characteristicShips[i].sda; j < characteristicShips[i].sda + 2; j++, c--) {
                    for (int w = 0; w < 3; w++) {
                        if ((w == 0 || w == 2) || (w == 1 && j == 0 || j == characteristicShips[i].sda + 1)) {
                            mas[characteristicShips[i].y - 2 + j][characteristicShips[i].x - 2 + w] = 2;
                        }
                        else {
                            mas[characteristicShips[i].y - 1 + c][characteristicShips[i].x - 1] = 3;
                        }
                    }
                }
            }
            C++;
        }
    }

    if (C == 10 && plus == 0) { //если все наши кораблики уничтожены
        end = 1; //завершаем игру (поражение)
    }
    else if (C == 10 && plus == 10) { //если все кораблики врага уничтожены
        end = 2; //завершаем игру (победа)
    }
    else {
        C = 0;
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    char var[2][30] = { "Автоматическая расстановка ","Ручная расстановка " };
    char menu[5][15] = { "МОРСКОЙ БОЙ","Играть ","Управление ","История ","Выход " };
    char var2[2][20] = { "Главное меню ", "Сыграть еще раз " };
    int myShips[12][12] = { 0 };
    int enemyShips[12][12] = { 0 };
    /*
    0 - свободныем места
	1 - позиции возле корабликов
	2 - место куда попал снаряд, но где ничего не было
	3 - место где был снаряд и находился кораблик
	4 - 1-о палубный кораблик (1-ый)
	5 - 1-о палубный кораблик (2-ой)
	6 - 1-о палубный кораблик (3-ий)
	7 - 1-о палубный кораблик (4-ый)
	8 - 2-х палубный кораблик (1-ый)
	9 - 2-х палубный кораблик (2-ой)
	10 - 2-х палубный кораблик (3-ий)
	11 - 3-х палубный кораблик (1-ый)
	12 - 3-х палубный кораблик (2-ой)
	13 - 4-х палубный кораблик 
    */

    Ships* characteristicShips = new Ships[20]; // Создание 10 корабликов (Всего палуб 20)
    LoadShips(characteristicShips);

    int win = 0, all_plays = 0, defeat = 0; // Подсчет игр и их результата

    int key = 1, y = 2, x = 2, num = 0, change = 1, b = 0, xx = 37, yy = 2, over = 0, end = 0;
    bool arrangement = true, round = false, your_turn = false;
    /*
    key - для записи нажатой клавиши
    round - для проверки на начало боя
    b - дополнительная переменная для меню
    xx - дополнительная перемнная для записи положения курсора на вражеском поле
    yy - дополнительная перемнная для записи положения курсора на вражеском поле
    y - позиция по Y
    x - позиция по X
    change - номер расстановки который будет использован
    num - номер кораблкиа
    arrangement - тип расстановки который будет использован
    */
    
    // Доп текстовый файл
    string path_control = "C:\\Users\\PC\\Desktop\\SeaBattle\\Control.txt";

    // Игра
    cout << "Нажмите на любую клавишу для продолжения: ";
    int a = _getch();
    if (a != 0) {
        system("cls");
        Start(menu);
    }

    while (true) {
        // Меню
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
                        cout << "Игры сыграно: " << all_plays << endl << endl << 
                            "Побед - " << win << endl << "Поражений - " << defeat;
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

        b = 0, s = 0, change = 0;

        do {
            end = 0;
            system("cls");

            // Выбор расстановки
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

            b = 0, s = 0, change = 0;

            system("cls");
            Createfield(0);

            // Расстановка
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
                        switch (x) { //Для отрисовки кораблей
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
                            characteristicShips[num].x = x1, characteristicShips[num].y = y;
                            for (int i = 0; i < 3; i++) {
                                for (int j = 0, c = characteristicShips[num].sda; j < characteristicShips[num].sda + 2; j++, c--) {
                                    if ((i == 0 || i == 2) || (i == 1 && j == 0 || j == characteristicShips[num].sda + 1)) {
                                        myShips[y - 2 + i][x1 - 2 + j] = 1; //меняем значение окупируемых позиций в двумерном массиве
                                    }
                                    else { //меняем значение позиций, где находится корабль в двумерном массиве
                                        myShips[y - 1][x1 - 1 + c] = 13 - num;
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
                            characteristicShips[num].x = x1, characteristicShips[num].y = y;
                            for (int i = 0, c = characteristicShips[num].sda; i < characteristicShips[num].sda + 2; i++, c--) {
                                for (int j = 0; j < 3; j++) {
                                    if ((j == 0 || j == 2) || (j == 1 && i == 0 || i == characteristicShips[num].sda + 1)) {
                                        myShips[y - 2 + i][x1 - 2 + j] = 1;
                                    }
                                    else {
                                        myShips[y - 1 + c][x1 - 1] = 13 - num;
                                    }
                                }
                            }
                            num++;
                        }
                    }
                } while (num <= 9);
                round = true;
            }
            else if (arrangement == false) { // автоматическая расстановка
                Auto(characteristicShips, myShips, 0);
                Pos(myShips, 2);
                round = true;
            }

            Sleep(20);
            Createfield(35);

            // Игра
            Auto(characteristicShips, enemyShips, 10);
            Pos_enemy(myShips, 37);
            do {
                if (your_turn == true) {
                    do {
                        Meny(3);
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
                            switch (xx) { //Для отрисовки кораблей
                            case 37:
                                x1 = 37;
                                break;
                            case 39:
                                x1 = 38;
                                break;
                            case 41:
                                x1 = 39;
                                break;
                            case 43:
                                x1 = 40;
                                break;
                            case 45:
                                x1 = 41;
                                break;
                            case 47:
                                x1 = 42;
                                break;
                            case 49:
                                x1 = 43;
                                break;
                            case 51:
                                x1 = 44;
                                break;
                            case 53:
                                x1 = 45;
                                break;
                            case 55:
                                x1 = 46;
                                break;
                            }
                            if (enemyShips[y - 1][x1 - 36] >= 4) {
                                enemyShips[y - 1][x1 - 36] = 3;
                                check_for_destruction(characteristicShips, enemyShips, 10, over); //проверяем на уничтожение
                                Meny(5); //вывод реплики
                                Sleep(700);
                            }
                            else if (enemyShips[y - 1][x1 - 36] < 2) {
                                enemyShips[y - 1][x1 - 36] = 2;
                                Meny(4); //вывод реплики
                                Sleep(700);
                                your_turn = false;
                            }
                            break;
                        }
                    } while (key != Enter);
                }
                if (your_turn == false) {
                    Sleep(0 + rand() % 400);
                    Meny(0);
                    Sleep(random(400, 700));
                    y = random(2, 11), x = (random(1, 10)) * 2;
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
                        myShips[y - 1][x1 - 1] = 3;
                        check_for_destruction(characteristicShips, myShips, 0, over); //проверяем на уничтожение
                        Meny(2);
                        Sleep(700);
                    }
                    else if (myShips[y - 1][x1 - 1] < 2) {
                        myShips[y - 1][x1 - 1] = 2;
                        Pos(myShips, 2);
                        Meny(1);
                        Sleep(700);
                        your_turn = true;
                    }
                }
            } while (over == 0);

            Pos(myShips, 2);
            Pos_enemy(enemyShips, 37);

            // Результат игры
            if (over == 2) {
                win++;
                all_plays++;
                Meny(6);
                Choice_3(var2, change);
                do {
                    key = _getch();
                    switch (key) {
                    case Left:
                        if (s > 0) {
                            s--;
                            change = s;
                            Choice_3(var2, change);
                        }
                        break;
                    case Right:
                        if (s < 1) {
                            s++;
                            change = s;
                            Choice_3(var2, change);
                        }
                        break;
                    case Enter:
                        do {
                            switch (change) {
                            case 0:
                                b++;
                                end++;
                                break;
                            case 1:
                                b++;
                                break;
                            }
                        } while (key != Enter);
                    }
                } while (b < 1);
                b = 0, s = 0, change = 1;
                All_clear(myShips, enemyShips, key, y, x, num, xx, yy, over, 
                    arrangement, round, your_turn);
                Alive(characteristicShips);
            }
            else {
                defeat++;
                all_plays++;
                Meny(7);
                Choice_3(var2, change);
                do {
                    key = _getch();
                    switch (key) {
                    case Left:
                        if (s > 1) {
                            s--;
                            change = s;
                            Choice_3(var2, change);
                        }
                        break;
                    case Right:
                        if (s < 1) {
                            s++;
                            change = s;
                            Choice_3(var2, change);
                        }
                        break;
                    case Enter:
                        do {
                            switch (change) {
                            case 0:
                                b++;
                                end++;
                                break;
                            case 1:
                                b++;
                                break;
                            }
                        } while (key != Enter);
                    }
                } while (b < 1);
                b = 0, s = 0, change = 1;
                All_clear(myShips, enemyShips, key, y, x, num, xx, yy, over,
                    arrangement, round, your_turn);
                Alive(characteristicShips);
            }
        } while (end == 0);
    }
}