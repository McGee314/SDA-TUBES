#include "FamilyTrees.cpp"
#define CREATOR "Dibuat oleh Muhammad Samudera Bagja, Muhammad Rafli Fadhilah, Devi Febrianti"

int main(){
    // loading_screen();
    printFromFile("ascii/kingdom.txt");
    printf("\n\n\t\t");
    printf(CREATOR);
    printf("\n\n");
    system("pause");

    Tree T;
    Create_Tree(&T);
    InsertKing(&T);

    // Insert Descendants
    char choice;
    do {
        printf("\nApakah Anda ingin menambahkan keturunan? (y/n): ");
        choice = getch();
        if (choice == 'y' || choice == 'Y') {
            InsertDescendantInfo(T.root);
        }
    } while (choice == 'y' || choice == 'Y');

    printf("\n\nMenampilkan isi file MonarchHierarchy.txt:\n\n");
    ReadDescendantFromFileAndDisplay("MonarchHierarchy.txt");

    return 0;
}
