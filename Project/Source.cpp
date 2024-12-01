#include "Header.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Äåñêðèïòîð àêòèâíîãî îêíà

void SetCursor(int x, int y) { //ôóíêöèÿ äëÿ òîãî ÷òîáû óñòàíàâëèâàòü ïîçèöèþ êóðñîðà â êîíñîëè ïî îñè Õ è Y
    COORD Coords = { x,y }; 
    SetConsoleCursorPosition(hConsole, Coords); //Ñïîñîá ïåðåìåùåíèÿ êóðñîðà
}

void Start(char menu[][15]) { //ôóíêöèÿ, ñàìàÿ ïåðâàÿ
    
    for (int i = 0, y = 4; i < 4; i++, y += 2) {
        SetCursor(16, y); //Óñòàíîâêà ïîçèöèè êóðñîðà
        cout << menu[i];
    }
}

void Choice_1(char menu[][15], int a) { //ìåíþ
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

void Choice_2(char var[][30], int a) { // Âûáîð ðàññòàíîâêè 
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

void Choice_3(char var1[][20], int a) {
    for (int i = 0; i < 2; i++) {
        SetCursor(0 + i * 20, 25);
        for (int j = 0; j < 20; j++) {
            if (i == a) {
                var1[i][18] = '<';
            }
            else {
                var1[i][18] = ' ';
            }
            cout << var1[i][j];
        }
    }
}

void Createfield(int x) {
    SetCursor(x, 1);
    char mas[10] = { 'À','Á','Â','Ã','Ä','Å','Æ','Ç','È','Ê' };
    
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

void Pos(int mas[12][12], int x) { //ïðîðèñîâêà èãðîâîé êàðòû ñ ïîëîæåíèåì ïîñòàâëåííûõ êîðàáëèêîâ
    for (int i = 1; i < 11; i++) {
        int y = 1 + i; 
        SetCursor(x, y); 
        for (int j = 1; j < 11; j++) {
            if (mas[i][j] == 2) {
                cout << "* ";
            }
            else if (mas[i][j] == 3) {
                cout << "X ";
            }
            /*(else if (mas[i][j] >= 4) {
                cout << "# ";
            }*/
            else {
                cout << "~ ";
            }  
        }
        cout << "\n";
    }
}

void Pos_enemy(int mas[12][12], int x) {
    for (int i = 1; i < 11; i++) {
        int y = 1 + i;
        SetCursor(x, y);
        for (int j = 1; j < 11; j++) {
            if (mas[i][j] == 2) {
                cout << "* ";
            }
            else if (mas[i][j] == 3) {
                cout << "X ";
            }
            /*else if (mas[i][j] >= 4) {
                cout << "# ";
            }*/
            else {
                cout << "~ ";
            }
        }
        cout << "\n";
    }
}

void Meny(int num) {
    char replicas[8][40] = { "Âðàã äóìàåò, êóäà óäàðèòü... ","Âðàã ïðîìàçàë ", "Âðàã ïîïàë ",
        "Òâîé õîä " , "Òû ïðîìàçàë...", "Òû ïîïàë!", "Ïîçäðàâëÿþ, òû ïîáåäèë!", "Ê ñîæàëåíèþ, òû ïðîèãðàë!" };

    SetCursor(22, 15); 
    for (int i = 0; i < 30; i++) {
        cout << " ";
    }
    SetCursor(22, 15);
    for (int i = 0; i < 30; i++) {
        cout << replicas[num][i];
    }
}

void All_clear(int myShips[12][12], int enemyShips[12][12], int& key, int& y, int& x, int& num,
    int& xx, int& yy, int& over, bool& arrangement, bool& round, bool& your_turn) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            myShips[i][j] = 0;
            enemyShips[i][j] = 0;
        }
    }
    key = 1, y = 2, x = 2, num = 0, xx = 37, yy = 2, over = 0;
    arrangement = true, round = false, your_turn = true;
}
