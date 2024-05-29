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
pointerN CreateNode(pointerN pr, infoType name, int age, int birthYear, boolean gender, boolean liveStatus) {
    pointerN newNode;
    newNode = (pointerN)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->fs = NULL;
        newNode->nb = NULL;
        newNode->pr = pr;
        strcpy(newNode->infoKeturunan.name, name);
        newNode->infoKeturunan.age = age;
        newNode->infoKeturunan.birthYear = birthYear;
        newNode->infoKeturunan.gender = gender;
        newNode->infoKeturunan.liveStatus = liveStatus;
        
        // Inisialisasi pasangan sebagai NULL
        strcpy(newNode->infoPasangan.name, "");
        newNode->infoPasangan.age = 0;
        newNode->infoPasangan.birthYear = 0;
        newNode->infoPasangan.gender = false;
        newNode->infoPasangan.liveStatus = false;
    }
    return newNode;
}

//dibuat oleh Muhammad Rafli Fadhilah
void InsertKing(struct Tree *pTree, int currentYear){
    pointerN king;
    infoType name;
    int birthYear, temp;
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

    /* Input Tahun Lahir Raja / Ratu */
    printf("\n\tTahun Lahir: ");
    scanf(" %d", &birthYear);

    int age = currentYear - birthYear;

    /* Alokasi node */
    king = CreateNode(NULL, name, age, birthYear, gender, liveStatus);

    /* Insert ke tree */
    pTree->root = king;
    printf("\n\tRaja/ratu berhasil ditambahkan");

    /* Menambahkan pasangan */
    InsertSpouse(king, currentYear);

    /* Print ke file */
    PrintKingAndSpouseToFile(king, "MonarchHierarchy.txt");
    
    getch();
}

//dibuat oleh Muhammad Rafli Fadhilah
void InsertSpouse(pointerN kingNode, int currentYear) {
    infoType name;
    int birthYear, temp;
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

    /* Input Tahun Lahir Pasangan */
    printf("\n\tTahun Lahir: ");
    scanf(" %d", &birthYear);

    int age = currentYear - birthYear;

    if (currentYear - kingNode->infoKeturunan.birthYear < 19) {
        printf("\n\tKeturunan belum mencapai usia 19 tahun. Silakan masukkan tahun saat ini yang akan menaikkan umur mereka.\n");
        printf("\tMasukkan tahun saat ini: ");
        scanf("%d", &currentYear);
        kingNode->infoKeturunan.age = currentYear - kingNode->infoKeturunan.birthYear;
    }

    /* Assign pasangan ke node raja/ratu */
    strcpy(kingNode->infoPasangan.name, name);
    kingNode->infoPasangan.age = age;
    kingNode->infoPasangan.birthYear = birthYear;
    kingNode->infoPasangan.gender = gender;
    kingNode->infoPasangan.liveStatus = liveStatus;

    printf("\n\tPasangan Raja/ratu berhasil ditambahkan\n");

    /* Print ke file */
    PrintKingAndSpouseToFile(kingNode, "MonarchHierarchy.txt");
}

//dibuat oleh Muhammad Samudera Bagja
pointerN FindNodeByName(pointerN root, const char* name) {
    if (root == NULL) return NULL;
    if (strcmp(root->infoKeturunan.name, name) == 0) return root;

    pointerN foundNode = FindNodeByName(root->fs, name);
    if (foundNode != NULL) return foundNode;

    return FindNodeByName(root->nb, name);
}

//dibuat oleh Muhammad Samudera Bagja
pointerN CreateDescendantNode(pointerN parent, infoType name, int age, int birthYear, boolean gender, boolean liveStatus) {
    return CreateNode(parent, name, age, birthYear, gender, liveStatus);
}

//dibuat oleh Muhammad Samudera Bagja
void InsertDescendantInfo(pointerN parent, int currentYear) {
    if (parent == NULL) {
        printf("\n\tNode parent tidak ditemukan.\n");
        return;
    }

    pointerN descendant;
    infoType name;
    int birthYear, temp;
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

    /* Input Tahun Lahir */
    printf("\n\tTahun Lahir: ");
    scanf(" %d", &birthYear);

    int age = currentYear - birthYear;

    /* Alokasi node */
    descendant = CreateDescendantNode(parent, name, age, birthYear, gender, liveStatus);

    /* Insert ke tree */
    if (parent->fs == NULL) {
        parent->fs = descendant;
    } else {
        pointerN temp = parent->fs;
        while (temp->nb != NULL) {
            temp = temp->nb;
        }
        temp->nb = descendant;
    }

    printf("\n\tKeturunan berhasil ditambahkan");

    /* Print ke file */
    PrintDescendantToFile(descendant, "MonarchHierarchy.txt", "a");

    /* Tambahkan pasangan untuk keturunan */
    InsertSpouseForDescendant(descendant, currentYear);

    getch();
}


//dibuat oleh Muhammad Rafli Fadhilah
void PrintKingAndSpouseToFile(pointerN kingNode, const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("\n\tError membuka file.\n");
        return;
    }

    fprintf(file, "%s,%s,%d,%d,%s,%s,%d,%d,%s\n",
            "Parent", kingNode->infoKeturunan.name, kingNode->infoKeturunan.age,
            kingNode->infoKeturunan.gender, kingNode->infoKeturunan.liveStatus ? "Hidup" : "Mati",
            kingNode->infoPasangan.name, kingNode->infoPasangan.age,
            kingNode->infoPasangan.gender, kingNode->infoPasangan.liveStatus ? "Hidup" : "Mati");

    fclose(file);
}

//dibuat oleh Muhammad Samudera Bagja
void ReadFromFileAndDisplay(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n\tError membuka file.\n");
        return;
    }

    char parent[50], name[50], spouseName[50];
    int age, spouseAge, gender, spouseGender;
    char liveStatus[10], spouseLiveStatus[10];
    while (fscanf(file, "%[^,],%[^,],%d,%d,%[^,],%[^,],%d,%d,%s\n",parent, name, &age, &gender, liveStatus, spouseName, &spouseAge, &spouseGender, spouseLiveStatus) != EOF) {
       
        // sscanf(line, "%[^,],%[^,],%d,%d,%[^,],%[^,],%d,%d,%s\n",
        //        parent, name, &age, &gender, liveStatus, spouseName, &spouseAge, &spouseGender, spouseLiveStatus);

        printf("\n\tNama: %s\n", name);
        printf("\tUmur: %d\n", age);
        printf("\tJenis Kelamin: %s\n", gender ? "Pria" : "Wanita");
        printf("\tStatus Hidup: %s\n", strcmp(liveStatus, "Hidup") == 0 ? "Hidup" : "Mati");

        if (strcmp(spouseName, "-") != 0) {
            printf("\tPasangan:\n");
            printf("\tNama: %s\n", spouseName);
            printf("\tUmur: %d\n", spouseAge);
            printf("\tJenis Kelamin: %s\n", spouseGender ? "Pria" : "Wanita");
            printf("\tStatus Hidup: %s\n", strcmp(spouseLiveStatus, "Hidup") == 0 ? "Hidup" : "Mati");
        }
    }

    fclose(file);
}

//dibuat oleh Muhammad Samudera Bagja
void PrintDescendantToFile(pointerN node, const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("\n\tError membuka file.\n");
        return;
    }

    fprintf(file, "%s,%s,%d,%d,%s\n",
            node->pr->infoKeturunan.name, node->infoKeturunan.name, node->infoKeturunan.age,
            node->infoKeturunan.gender, node->infoKeturunan.liveStatus ? "Hidup" : "Mati");

    fclose(file);
}

//dibuat oleh Muhammad Samudera Bagja
void ReadDescendantFromFileAndDisplay(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n\tError membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char parent[50], name[50];
        int age;
        char gender[10];
        char liveStatus[10];

        sscanf(line, "%[^,],%[^,],%d,%[^,],%[^,]\n",
               parent, name, &age, gender, liveStatus);

        printf("\n\tNama: %s\n", name);
        printf("\tUmur: %d\n", age);
        printf("\tJenis Kelamin: %s\n", gender);
        printf("\tStatus Hidup: %s\n", liveStatus);
    }

    fclose(file);
}

//dibuat oleh Muhammad Samudera Bagja
void UpdateAges(pointerN root, int currentYear) {
    if (root == NULL) return;

    root->infoKeturunan.age = currentYear - root->infoKeturunan.birthYear;
    if (root->infoPasangan.birthYear != 0) {
        root->infoPasangan.age = currentYear - root->infoPasangan.birthYear;
    }

    UpdateAges(root->fs, currentYear);
    UpdateAges(root->nb, currentYear);
}

//dibuat oleh Muhammad Samudera Bagja
void SetDeceasedStatus(pointerN root, const char* name) {
    pointerN node = FindNodeByName(root, name);
    if (node != NULL) {
        node->infoKeturunan.liveStatus = false;
    }
}

//dibuat oleh Muhammad Rafli Fadhilah
void UpdatePrincePrincess(Tree* tree) {
    if (tree->root == NULL) {
        printf("\n\tTidak ada raja/ratu dalam silsilah.\n");
        return;
    }

    if (tree->root->fs == NULL) {
        printf("\n\tRaja/ratu tidak memiliki keturunan.\n");
        return;
    }

    tree->princePrincess = tree->root->fs;
    printf("\n\tKeturunan pertama berhasil diatur sebagai pangeran/putri.\n");
}

void InsertSpouseForDescendant(pointerN descendantNode, int currentYear) {
    infoType name;
    int birthYear, temp;
    boolean gender;
    boolean liveStatus = true; // true = hidup, false = mati

    /* Input Nama */
    printf("\n\tMasukan Identitas Pasangan Keturunan:\n");
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

    /* Input Tahun Lahir Pasangan */
    printf("\n\tTahun Lahir: ");
    scanf(" %d", &birthYear);

    int age = currentYear - birthYear;

    /* Assign pasangan ke node keturunan */
    strcpy(descendantNode->infoPasangan.name, name);
    descendantNode->infoPasangan.age = age;
    descendantNode->infoPasangan.birthYear = birthYear;
    descendantNode->infoPasangan.gender = gender;
    descendantNode->infoPasangan.liveStatus = liveStatus;

    printf("\n\tPasangan Keturunan berhasil ditambahkan\n");

    /* Print ke file */
    PrintDescendantToFile(descendantNode, "MonarchHierarchy.txt", "a");
}
