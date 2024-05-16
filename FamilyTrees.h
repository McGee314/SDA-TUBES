#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "boolean.h"


// Dibuat oleh Muhammad Samudera Bagja
typedef char infoType[50];
typedef struct KingdomTree *pointerN;

// Sumber : Tugas Program Struktur Non Binary Tree SDA-P
// Modifikasi oleh : Samudera
// Struct Identitas Raja/Ratu dan Pasangannya
typedef struct {
    infoType name;
    int age;
    boolean gender;
    boolean liveStatus;
}identity;


// Struct Node Anggota Silsilah Kerajaan
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

typedef struct kingQueen{
    pointerN kingQueenP;
};

typedef struct princePrincess{
    pointerN princePrincessP;
};

// Modifikasi oleh : Rafli
// Struct Queue untuk Level-order Traversal
struct Queue {
    int front, rear, size;
    pointerN *arrQueue;
};



// Sumber : Tugas Program Struktur Non Binary Tree SDA-P
void Create_Tree(Tree *T);
// Membuat Tree Kosong

// Sumber : Tugas Program Struktur Non Binary Tree SDA-P
boolean isEmpty (struct Tree T);
// Mengirimkan true jika tree kosong

// Sumber GitHub
void gotoxy(int X, int y);
//untuk digunakan dalam loading Screen

// Sumber GitHub
void loading_screen();
// Menampilkan loading screen   

// Sumber : Tugas Program Struktur Non Binary Tree SDA-P
// Modifikasi oleh : Rafli
pointerN CreateNode (pointerN parent, infoType name, int age, boolean gender);
// Alokasi Node (Anggota Kerajaan)

