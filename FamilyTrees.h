#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include "boolean.h"

// Dibuat oleh Muhammad Samudera Bagja
typedef char infoType[50];
typedef struct KingdomTree *pointerN;

// Sumber : Tugas Program Struktur Non Binary Tree SDA-P
// Modifikasi oleh : Samudera
// Struct Identitas Raja/Ratu dan Pasangannya
typedef struct {
    int tahunLahir;
} year;

typedef struct {
    infoType name;
    int age;
    boolean gender;
    boolean liveStatus;
} identity;

// Struct Node Anggota Silsilah Kerajaan
typedef struct KingdomTree {
    pointerN pr;
    pointerN fs;
    pointerN nb;
    identity infoKeturunan;
    identity infoPasangan;
    year keturunan;
    year pasangan;
} TreeNode;

typedef struct Tree {
    pointerN root;
    pointerN kingQueen;
    pointerN princePrincess;
} Tree;

typedef struct kingQueen {
    pointerN kingQueenP;
} kingQueen;

typedef struct princePrincess {
    pointerN princePrincessP;
} princePrincess;

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
pointerN CreateNode (pointerN parent, infoType name, int age, boolean gender, boolean liveStatus, int tahunLahir);
// Alokasi Node (Anggota Kerajaan)

void printFromFile(const char* location);
/* Menampilkan teks pada file yang terdapat pada location*/

void InsertKing(struct Tree *pTree, int currentYear);
void InsertSpouse(pointerN kingNode);
void PrintKingAndSpouseToFile(pointerN kingNode, const char* filename);
void ReadFromFileAndDisplay(const char* filename);

// New functions
pointerN CreateDescendantNode(pointerN parent, infoType name, int age, boolean gender, boolean liveStatus, int tahunLahir);
void InsertDescendantInfo(pointerN parent, int currentYear);
void PrintDescendantToFile(pointerN node, const char* filename);
void ReadDescendantFromFileAndDisplay(const char* filename);

pointerN FindNodeByName(pointerN root, const char* name);

void UpdateAges(pointerN root, int currentYear);
void SetDeceasedStatus(pointerN root, const char* name);
void UpdatePrincePrincess(Tree* tree);
