#include "FamilyTrees.cpp"

void menu(struct Tree *tree, int currentYear) {
    int choice;
    infoType parentName;
    pointerN parent;

    do {
        printf("\n\t======================================");
        printf("\n\t|    SISTEM INFORMASI KETURUNAN     |");
        printf("\n\t|        KERAJAAN TERPADU           |");
        printf("\n\t======================================");
        printf("\n\t| 1. Tambah Raja/Ratu               |");
        printf("\n\t| 2. Tambah Keturunan               |");
        printf("\n\t| 3. Lihat Silsilah                 |");
        printf("\n\t| 4. Keluar                         |");
        printf("\n\t======================================");
        printf("\n\tPilihan: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                InsertKing(tree, currentYear);
                break;
            case 2:
                printf("\n\tMasukkan nama orang tua: ");
                scanf(" %[^\n]", parentName);
                parent = FindNodeByName(tree->root, parentName);
                if (parent != NULL) {
                    InsertDescendantInfo(parent, currentYear);
                } else {
                    printf("\n\tOrang tua tidak ditemukan.");
                }
                break;
            case 3:
                printf("\n\tData Raja dan Ratu:\n");
                printf("\nParent\tNama\tUsia\tGender\tStatus\tTahun Lahir\t");
                printf("Nama Pasangan\tUsia\tGender\tStatus\tTahun Lahir\n");
                ReadFromFileAndDisplay("MonarchHierarchy.txt");

                printf("\n\tData Keturunan:\n");
                printf("\nParent\tNama\tUsia\tGender\tStatus\tTahun Lahir\n");
                ReadDescendantFromFileAndDisplay("MonarchDescendants.txt");
                getch();
                break;
            case 4:
                printf("\n\tKeluar dari program...");
                break;
            default:
                printf("\n\tPilihan tidak valid.");
                break;
        }
    } while (choice != 4);
}

int main() {
    Tree familyTree;
    int currentYear;

    Create_Tree(&familyTree);
    printf("Masukkan tahun saat ini: ");
    scanf("%d", &currentYear);

    loading_screen();

    menu(&familyTree, currentYear);

    return 0;
}
