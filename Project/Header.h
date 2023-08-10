#pragma once 
#include <iostream> 
#include <ctime> 
#include <Windows.h> 
#include <conio.h> 
#include <string> 
#include <fstream> 
#include <cstdlib>

#define random(a,b) (a + rand()% (b + 1 - a)) 
using namespace std;

void SetCursor(int x, int y);

void Start(char menu[][15]);

void Choice_1(char menu[][15], int a);

void Choice_2(char var[][30], int a);

void Choice_3(char var[][20], int a);

void Createfield(int x);

void Pos(int mas[12][12], int x);

void Pos_enemy(int mas[12][12], int x);

void Meny(int num);

void Clear(int myShips[12][12], int enemyShips[12][12]);