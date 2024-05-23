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

    printf("\n\nMenampilkan isi file MonarchHierarchy.txt:\n\n");
    ReadFromFileAndDisplay("MonarchHierarchy.txt");

    return 0;
}
