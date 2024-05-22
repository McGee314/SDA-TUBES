#include "FamilyTrees.h"
#include <iostream>
#include <windows.h>

//sumber github
void gotoxy(int X, int y) {
	COORD coord;
	coord.X = X;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//sumber github
void loading_screen() {
	int i;
	gotoxy(50, 10); printf("Loading...");
	gotoxy(50, 12);
	for (i = 0; i <= 17; i++) {
		Sleep(90);
		printf("%c", 177);
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

//Create non binary tree
void Create_Tree(Tree *T){
	T->root = NULL;
}

boolean IsEmpty(Tree T){
	return (T.root == NULL);
}

void printFromFile(const char* location){
	FILE *read;
	char c;

	read=fopen(location, "rt");
	while((c=fgetc(read))!=EOF){
		printf("%c", c);
	}

	fclose(read);
}