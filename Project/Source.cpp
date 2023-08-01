#include "Header.h"

//char** creatingField() {
//    char** field = new char* [SIZE_FIELD + 1];
//    for (int i = 0; i < SIZE_FIELD + 1; i++) {
//        field[i] = new char[SIZE_FIELD + 1] {};
//    } return field;
//}
//
//void initField(char** field) {
//    char mas1[10] = { 'А','Б','В','Г','Д','Е','Ж','З','И','К' };
//    char mas2[10] = { '1','2','3','4','5','6','7','8','9','0' };
//
//    int a = 0, b = 0; // переменные для прохода по массивам букв и цмфр
//    for (int i = 0; i < SIZE_FIELD + 1; i++) {
//        for (int j = 0; j < SIZE_FIELD + 1; j++) {
//            if (i > 0 && j > 0) {
//                field[i][j] = '~';
//            }
//            if (i == 0 && j > 0) {
//                field[i][j] = mas1[a++]; //ряд из букв   }
//            }
//            else if (j == 0 && i > 0) {
//                field[i][j] = mas2[b++]; // столбец из цифр
//            }
//        }
//    }
//}
//
//void ShowField(char** field) {
//    for (int i = 0; i < SIZE_FIELD + 1; i++) {
//        for (int j = 0; j < SIZE_FIELD + 1; j++) {
//            cout << field[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Дескриптор активного окна

void SetCursor(int x, int y) { //функция для того чтобы устанавливать позицию курсора в консоли по оси Х и Y
    COORD Coords = { x,y }; 
    SetConsoleCursorPosition(hConsole, Coords); //Способ перемещения курсора
}

void Start(char menu[][15]) { //функция, самая первая
    
    for (int i = 0, y = 4; i < 4; i++, y += 2) {
        SetCursor(16, y); //Установка позиции курсора
        cout << menu[i];
    }
}

void Choice_1(char menu[][15], int a) { //меню
    system("cls");
    for (int i = 0, y = 4; i < 5; i++, y += 2) {
        SetCursor(16, y);
        for (int j = 0; j < 15; j++) {
            if (i == a) {
                menu[i][14] = '<';
            }
            else {
                menu[i][14] = ' ';
            }
            cout << menu[i][j];
        }
    }
}

void Choice_2(char var[][30], int a) { // Выбор расстановки 
    system("cls");
    for (int i = 0; i < 2; i++) {
        SetCursor(30, 6 + i);
        for (int j = 0; j < 30; j++) {
            if (i == a) {
                var[i][29] = '<';
            }
            else {
                var[i][29] = ' ';
            }
            cout << var[i][j];
        }
    }
    SetCursor(0, 0);
    Createfield(0);
}

void Createfield(int x) {
    SetCursor(x, 1);
    char mas[10] = { 'А','Б','В','Г','Д','Е','Ж','З','И','К' };
    
    int a = 0, b = 0;
    cout << "  " << mas[0];
    for (int i = 0; i < 11; i++) {
        if (b == 0) {
            SetCursor(x + 3, 1);
            b++;
        }
        else {
            SetCursor(x, 1 + i);
        }
        for (int j = 0; j < 11; j++) { 
            if (i == 0 && j > 0 && j < 10) {
                cout << ' ' << mas[j];
            }
            else if (i > 0 && i < 11 && j == 0) {
                cout << i - 1 << ' ';
            }
            else if (i > 0 && i < 11 && j > 0 && j < 11) {
                cout << "~ ";
            }
        }
    }
}

void Pos(int mas[12][12], int x) { //прорисовка игровой карты с положением поставленных корабликов
    for (int i = 1; i < 11; i++) {
        int y = 1 + i; 
        SetCursor(x, y); 
        for (int j = 1; j < 11; j++) {
            if (mas[i][j] == 1) {
                cout << "$ ";
            }
            else if (mas[i][j] == 2) {
                cout << "@ ";
            }
            else if (mas[i][j] == 3) {
                cout << "* ";
            }
            else if (mas[i][j] >= 4) {
                cout << "# ";
            }
            else {
                cout << "~ ";
            }  
        }
        cout << "\n";
    }
}