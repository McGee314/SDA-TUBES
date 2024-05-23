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

	read=fopen(location, "rt");
	while((c=fgetc(read))!=EOF){
		printf("%c", c);
	}

	fclose(read);
}

//Create non binary tree
void Create_Tree(Tree *T){
	T->root = NULL;
}

boolean IsEmpty(Tree T){
	return (T.root == NULL);
}

// Prosedur untuk menginisialisasi identitas kosong
// dibuat oleh Muhammad Samudera Bagja
pointerN CreateNode(pointerN pr, infoType name, int age, boolean gender, boolean liveStatus) {
	pointerN newNode;
	newNode = (pointerN)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->fs = NULL;
        newNode->nb = NULL;
        newNode->pr = pr;
        strcpy(newNode->infoKeturunan.name,name);
        newNode->infoKeturunan.age = age;
        newNode->infoKeturunan.gender = gender;
        newNode->infoKeturunan.liveStatus = liveStatus;
		
        // Inisialisasi pasangan sebagai NULL
        strcpy(newNode->infoPasangan.name,NULL);
        newNode->infoPasangan.age = 0;
        newNode->infoPasangan.gender = false;
        newNode->infoPasangan.liveStatus = false;
		
	}
return newNode;
}

// Prosedur untuk memasukkan infoKeturunan ke dalam tree
// void insertInfoKeturunan(pointerN* root, const char* name, int age, boolean gender) {
//     pointerN newNode = (pointerN)malloc(sizeof(TreeNode));
//     if (newNode != NULL) {
//         initIdentity(&(newNode->infoKeturunan), name, age, gender, true); // liveStatus true
//         newNode->infoPasangan.name = NULL;
//         newNode->infoPasangan.age = 0;
//         newNode->infoPasangan.gender = 0;
//         newNode->infoPasangan.liveStatus = false;
//         newNode->pr = NULL;
//         newNode->fs = NULL;
//         newNode->nb = NULL;

//         if (*root == NULL) {
//             *root = newNode;
//         } else {
//             // Bisa tambahkan logika untuk menambahkan node ke posisi yang sesuai di tree
//             // Misalnya, menambahkan sebagai first child atau sibling tergantung kebutuhan
//             // Contoh menambahkan sebagai sibling root
//             newNode->nb = (*root)->fs;
//             (*root)->fs = newNode;
//         }
//     } else {
//         printf("Gagal mengalokasikan memori untuk node baru.\n");
//     }
// }

// void printNodeInfo(TreeNode* node) {
//     if (node != NULL) {
//         printf("Nama: %s, Umur: %d, Gender: %s, LiveStatus: %s\n",
//             node->infoKeturunan.name,
//             node->infoKeturunan.age,
//             node->infoKeturunan.gender ? "Laki-laki" : "Perempuan",
//             node->infoKeturunan.liveStatus ? "Hidup" : "Meninggal");
//         if (node->infoPasangan.name != NULL) {
//             printf("Pasangan: %s\n", node->infoPasangan.name);
//         } else {
//             printf("Pasangan: NULL\n");
//         }
//     }
// }