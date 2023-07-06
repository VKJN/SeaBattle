#pragma once 
#include <iostream> 
#include <ctime> 
#include <Windows.h> 
#include <conio.h> 
#include <string> 
#include <fstream> 
#define random(a,b) (a + rand()% (b + 1 - a)) 
using namespace std;
const int SIZE_FIELD = 10;
const int FPS = 100;

void copyfield(char**& field, char**& field1);

char** creatingField();

void initField(char** field, char* mas1, char* mas2);

void ShowField(char** field);

void UpdateField1();

void createShips(char**& arrayShip4, char**& arrayShip3, char**& arrayShip2, char**& arrayShip1,
	char**& Playerfield1, char**& PlayerfieldStep1, int i);

void createShipsAuto(char**& arrayShip4, char**& arrayShip3, char**& arrayShip2, char**& arrayShip1, char**& Playerfield1, int i);
