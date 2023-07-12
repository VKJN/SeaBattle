#include "Header.h"

char** creatingField() {
    char** field = new char* [SIZE_FIELD + 1];
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        field[i] = new char[SIZE_FIELD + 1] {};
    } return field;
}

void initField(char** field, char* mas1, char* mas2) {
    int a = 0, b = 0; // ���������� ��� ������� �� �������� ���� � ����
    for (int i = 0; i < SIZE_FIELD + 1; i++) {
        for (int j = 0; j < SIZE_FIELD + 1; j++) {
            if (i > 0 && j > 0) {
                field[i][j] = '~';
            }
            if (i == 0 && j > 0) {
                field[i][j] = mas1[a++]; //��� �� ����   }
            }
            else if (j == 0 && i > 0) {
                field[i][j] = mas2[b++]; // ������� �� ����
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

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //���������� ��������� ����

void SetCursor(int x, int y) { //������� ��� ���� ����� ������������� ������� ������� � ������� �� ��� � � Y
    COORD Coords = { x,y }; 
    SetConsoleCursorPosition(hConsole, Coords); //������ ����������� �������
}

void Start(char menu[][15]) { //�������, ����� ������
    
    for (int i = 0, y = 4; i < 4; i++, y += 2) {
        SetCursor(16, y); //��������� ������� �������
        cout << menu[i];
    }
}

void Choice_1(char menu[][15], int a) { //���� ������
    system("cls");
    for (int i = 0, y = 4; i < 4; i++, y += 2) {
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