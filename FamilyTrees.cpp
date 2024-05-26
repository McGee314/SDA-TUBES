#include "FamilyTrees.h"

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

void printFromFile(const char* location){
    FILE *read;
    char c;

    read = fopen(location, "rt");
    while ((c = fgetc(read)) != EOF) {
        printf("%c", c);
    }

    fclose(read);
}

// Create non binary tree
void Create_Tree(Tree *T){
    T->root = NULL;
}

boolean isEmpty(Tree T){
    return (T.root == NULL);
}

// Prosedur untuk menginisialisasi identitas kosong
pointerN CreateNode(pointerN pr, infoType name, int age, boolean gender, boolean liveStatus) {
    pointerN newNode;
    newNode = (pointerN)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->fs = NULL;
        newNode->nb = NULL;
        newNode->pr = pr;
        strcpy(newNode->infoKeturunan.name, name);
        newNode->infoKeturunan.age = age;
        newNode->infoKeturunan.gender = gender;
        newNode->infoKeturunan.liveStatus = liveStatus;
        
        // Inisialisasi pasangan sebagai NULL
        strcpy(newNode->infoPasangan.name, "");
        newNode->infoPasangan.age = 0;
        newNode->infoPasangan.gender = false;
        newNode->infoPasangan.liveStatus = false;
    }
    return newNode;
}

void InsertKing(struct Tree *pTree){
    pointerN king;
    infoType name;
    int age, temp;
    boolean gender;
    boolean liveStatus = true; // true = hidup, false = mati

    /* Input Nama */
    printf("\n\tMasukan Identitas Raja / Ratu:\n");
    printf("\n\tNama: ");
    scanf(" %[^\n]", name);

    /* Input Jenis Kelamin */
    do {
        printf("\n\t%c Pilih jenis kelamin\n", 175);
        printf("\t  0. Wanita\n");
        printf("\t  1. Pria\n");
        printf("\t  Pilihan: ");
        scanf(" %d", &temp);
        if (temp != 0 && temp != 1) {
            printf("\t Input tidak valid \n");
        } else {
            gender = (temp == 1);
            break;
        }
    } while (1);

    /* Input Umur Raja / Ratu */
    do {
        printf("\n\tUmur: ");
        scanf(" %d", &age);
    } while (age < 0 || age >= 100);

    /* Alokasi node */
    king = CreateNode(NULL, name, age, gender, liveStatus);

    /* Insert ke tree */
    pTree->root = king;
    printf("\n\tRaja/ratu berhasil ditambahkan");

    /* Menambahkan pasangan */
    InsertSpouse(king);

    /* Print ke file */
    PrintKingAndSpouseToFile(king, "MonarchHierarchy.txt");
    
    getch();
}

void InsertSpouse(pointerN kingNode){
    infoType name;
    int age, temp;
    boolean gender;
    boolean liveStatus = true; // true = hidup, false = mati

    /* Input Nama */
    printf("\n\tMasukan Identitas Pasangan Raja / Ratu:\n");
    printf("\n\tNama: ");
    scanf(" %[^\n]", name);

    /* Input Jenis Kelamin */
    do {
        printf("\n\t%c Pilih jenis kelamin\n", 175);
        printf("\t  0. Wanita\n");
        printf("\t  1. Pria\n");
        printf("\t  Pilihan: ");
        scanf(" %d", &temp);
        if (temp != 0 && temp != 1) {
            printf("\t Input tidak valid \n");
        } else {
            gender = (temp == 1);
            break;
        }
    } while (1);

    /* Input Umur Pasangan */
    do {
        printf("\n\tUmur: ");
        scanf(" %d", &age);
    } while (age < 0 || age >= 100);

    /* Assign pasangan ke node raja/ratu */
    strcpy(kingNode->infoPasangan.name, name);
    kingNode->infoPasangan.age = age;
    kingNode->infoPasangan.gender = gender;
    kingNode->infoPasangan.liveStatus = liveStatus;
}

void PrintKingAndSpouseToFile(pointerN kingNode, const char* filename){
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("File tidak ditemukan/file tidak dapat dibuka\n");
        return;
    }

    fprintf(file, "NULL, %s, %d, %d, %d, ", 
        kingNode->infoKeturunan.name, kingNode->infoKeturunan.age, kingNode->infoKeturunan.gender, kingNode->infoKeturunan.liveStatus);
    fprintf(file, "%s, %d, %d, %d\n", 
        kingNode->infoPasangan.name, kingNode->infoPasangan.age, kingNode->infoPasangan.gender, kingNode->infoPasangan.liveStatus);

    fclose(file);
}

void ReadFromFileAndDisplay(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File tidak ditemukan/file tidak dapat dibuka\n");
        return;
    }

    char parent[50], kingName[50], spouseName[50];
    int kingAge;
    int kingGender, kingLiveStatus;
    int spouseAge;
    int spouseGender, spouseLiveStatus;

    while (fscanf(file, "%[^,], %[^,], %d, %d, %d, %[^,], %d, %d, %d\n", 
                  parent, kingName, &kingAge, &kingGender, &kingLiveStatus, 
                  spouseName, &spouseAge, &spouseGender, &spouseLiveStatus) != EOF) {
        
        if (strcmp(parent, "NULL") != 0) {
            printf("Orang tua: %s\n", parent);
        }
        printf("Raja/Ratu: %s\n", kingName);
        printf("Umur Raja/Ratu: %d\n", kingAge);
        printf("Gender Raja/Ratu: %s\n", kingGender ? "Laki-laki" : "Perempuan");
        printf("Status Raja/Ratu: %s\n", kingLiveStatus ? "Hidup" : "Mati");

        printf("Pasangan: %s\n", spouseName);
        printf("Umur Pasangan: %d\n", spouseAge);
        printf("Gender Pasangan: %s\n", spouseGender ? "Laki-laki" : "Perempuan");
        printf("Status Pasangan: %s\n", spouseLiveStatus ? "Hidup" : "Mati");
        printf("\n");
    }

    fclose(file);
}

// New functions
pointerN CreateDescendantNode(pointerN parent, infoType name, int age, boolean gender, boolean liveStatus) {
    return CreateNode(parent, name, age, gender, liveStatus);
}

void InsertDescendantInfo(pointerN parent) {
    pointerN descendant;
    infoType name;
    int age, temp;
    boolean gender;
    boolean liveStatus = true; // true = hidup, false = mati

    /* Input Nama */
    printf("\n\tMasukan Identitas Keturunan:\n");
    printf("\n\tNama: ");
    scanf(" %[^\n]", name);

    /* Input Jenis Kelamin */
    do {
        printf("\n\t%c Pilih jenis kelamin\n", 175);
        printf("\t  0. Wanita\n");
        printf("\t  1. Pria\n");
        printf("\t  Pilihan: ");
        scanf(" %d", &temp);
        if (temp != 0 && temp != 1) {
            printf("\t Input tidak valid \n");
        } else {
            gender = (temp == 1);
            break;
        }
    } while (1);

    /* Input Umur Keturunan */
    do {
        printf("\n\tUmur: ");
        scanf(" %d", &age);
    } while (age < 0 || age >= 100);

    /* Alokasi node */
    descendant = CreateDescendantNode(parent, name, age, gender, liveStatus);

    /* Insert ke tree */
    if (parent->fs == NULL) {
        parent->fs = descendant;
    } else {
        pointerN sibling = parent->fs;
        while (sibling->nb != NULL) {
            sibling = sibling->nb;
        }
        sibling->nb = descendant;
    }
    printf("\n\tKeturunan berhasil ditambahkan");

    /* Print ke file */
    PrintDescendantToFile(descendant, "MonarchHierarchy.txt");
    
    getch();
}

void PrintDescendantToFile(pointerN node, const char* filename) {
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("File tidak ditemukan/file tidak dapat dibuka\n");
        return;
    }

    fprintf(file, "%s, %s, %d, %d, %d, %s, %d, %d, %d\n", 
        node->pr != NULL ? node->pr->infoKeturunan.name : "NULL",
        node->infoKeturunan.name, node->infoKeturunan.age, node->infoKeturunan.gender, node->infoKeturunan.liveStatus,
        node->infoPasangan.name, node->infoPasangan.age, node->infoPasangan.gender, node->infoPasangan.liveStatus);

    fclose(file);
}

void ReadDescendantFromFileAndDisplay(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File tidak ditemukan/file tidak dapat dibuka\n");
        return;
    }

    char parent[50], descendantName[50], spouseName[50];
    int descendantAge;
    int descendantGender, descendantLiveStatus;
    int spouseAge;
    int spouseGender, spouseLiveStatus;

    while (fscanf(file, "%[^,], %[^,], %d, %d, %d, %[^,], %d, %d, %d\n", 
                  parent, descendantName, &descendantAge, &descendantGender, &descendantLiveStatus, 
                  spouseName, &spouseAge, &spouseGender, &spouseLiveStatus) != EOF) {
        
        if (strcmp(parent, "NULL") != 0) {
            printf("Orang tua: %s\n", parent);
        }
        printf("Keturunan: %s\n", descendantName);
        printf("Umur Keturunan: %d\n", descendantAge);
        printf("Gender Keturunan: %s\n", descendantGender ? "Laki-laki" : "Perempuan");
        printf("Status Keturunan: %s\n", descendantLiveStatus ? "Hidup" : "Mati");

        printf("Pasangan: %s\n", spouseName);
        printf("Umur Pasangan: %d\n", spouseAge);
        printf("Gender Pasangan: %s\n", spouseGender ? "Laki-laki" : "Perempuan");
        printf("Status Pasangan: %s\n", spouseLiveStatus ? "Hidup" : "Mati");
        printf("\n");
    }

    fclose(file);
}
