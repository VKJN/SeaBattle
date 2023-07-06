#include "Header.h"

void copyfield(char**& field, char**& field1) {
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        for (int j = 0; j < SIZE_FIELD + 1; j++) {
            field1[i][j] = field[i][j];
        }
    }
}

char** creatingField() {
    char** field = new char* [SIZE_FIELD + 1];
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        field[i] = new char[SIZE_FIELD + 1] {};
    } return field;
}

void initField(char** field, char* mas1, char* mas2) {
    int a = 0, b = 0; // переменные для прохода по массивам букв и цмфр
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        for (int j = 0; j < SIZE_FIELD + 1; j++) {
            if (i > 0 && j > 0) {
                field[i][j] = '~';
            }
            if (i == 0 && j > 0) {
                field[i][j] = mas1[a++]; //ряд из букв   }
            }
            else if (j == 0 && i > 0) {
                field[i][j] = mas2[b++]; // столбец из цифр
            }
        }
    }
}

void ShowField(char** field) {
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        for (int j = 0; j < SIZE_FIELD + 1; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void UpdateField1() {

}

void createShips(char**& arrayShip4, char**& arrayShip3, char**& arrayShip2, char**& arrayShip1,
    char**& Playerfield1, char**& PlayerfieldStep1, int i) {
    if (i == 0) {
        
    }
    else if (i > 0 && i < 4) {

    }
    else if (i > 4 && i < 7) {

    }
    else {

    }
}

void createShipsAuto(char**& arrayShip4, char**& arrayShip3, char**& arrayShip2, char**& arrayShip1, char**& Playerfield1, int i) {
    if (i == 0) {
        int x1 = random(1, SIZE_FIELD);
        int y1 = random(1, SIZE_FIELD);  for (int i = 0; i < 4; i++) {
        }
    }
    else if (i > 0 && i < 4) {
        int x2 = random(1, SIZE_FIELD);
        int y2 = random(1, SIZE_FIELD);  for (int j = 0; j < 2; j++) {
        }
    }
    else if (i > 4 && i < 7) {
        int x3 = random(1, SIZE_FIELD);
        int y3 = random(1, SIZE_FIELD);
        for (int j = 0; j < 3; j++) {
        }
    }
    else {
        for (int j = 0; j < 4; j++) {
            int x4 = random(1, SIZE_FIELD);
            int y4 = random(1, SIZE_FIELD);
        }
    }
}