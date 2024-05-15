#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "boolean.h"


// Dibuat oleh Muhammad Samudera Bagja
typedef char infoType[50];
typedef struct KingdomTree *pointerN;
typedef struct {
    infoType name;
    int age;
    boolean gender;
}identity;

typedef struct kingdomTree{
    pointerN pr;
    identity infoKeturunan;
    identity infoPasangan;
    pointerN fs;
    pointerN nb;
}TreeNode;

typedef struct Tree{
    pointerN root;
};

void Create_Tree(Tree *T);

//Sumber GitHub
void gotoxy(int X, int y);
//untuk digunakan dalam loading Screen

// Sumber GitHub
void loading_screen();
// Menampilkan loading screen