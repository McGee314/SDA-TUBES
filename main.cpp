
#include "FamilyTrees.cpp"

int currentYear = 2024; // Tahun sekarang
Tree familyTree;
int currentYear;
void menu_utama();
void menu_tampilkan_silsilah();
void menu_tambah_anggota();
void menu_ubah_tahun();
void tampilkan_semua_silsilah(pointerN node);

int main() {
    // Buat tree keluarga
    Create_Tree(&familyTree);
    
    // Tampilkan loading screen
    loading_screen();
    
    // Tampilkan menu utama
    menu_utama();
    
    return 0;
}

void menu_utama() {
    int choice;
    
    do {
        system("cls");
        printf("\n\tSistem Informasi Silsilah Kerajaan\n");
        printf("\t1. Tambah Raja/Ratu\n");
        printf("\t2. Tambah Keturunan\n");
        printf("\t3. Tampilkan Silsilah\n");
        printf("\t4. Ubah Tahun Sekarang\n");
        printf("\t5. Keluar\n");
        printf("\tPilihan: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                InsertKing(&familyTree, currentYear);
                break;
            case 2:
                menu_tambah_anggota();
                break;
            case 3:
                menu_tampilkan_silsilah();
                break;
            case 4:
                menu_ubah_tahun();
                break;
            case 5:
                printf("\n\tTerima kasih!\n");
                break;
            default:
                printf("\n\tPilihan tidak valid!\n");
                getch();
                break;
        }
    } while (choice != 5);
}

void menu_tambah_anggota() {
    char parentName[50];
    printf("\n\tMasukkan nama orang tua dari keturunan yang ingin ditambahkan: ");
    scanf(" %[^\n]", parentName);
    
    pointerN parentNode = FindNodeByName(familyTree.root, parentName);
    if (parentNode != NULL) {
        InsertDescendantInfo(parentNode, currentYear);
    } else {
        printf("\n\tOrang tua tidak ditemukan.\n");
        getch();
    }
}

void menu_tampilkan_silsilah() {
    if (familyTree.root == NULL) {
        printf("\n\tSilsilah kosong.\n");
        getch();
        return;
    }
    
    printf("\n\tSilsilah Kerajaan:\n");
    tampilkan_semua_silsilah(familyTree.root);
    getch();
}

void tampilkan_semua_silsilah(pointerN node) {
    if (node == NULL) return;
    
    printf("\n\tNama: %s\n", node->infoKeturunan.name);
    printf("\tUmur: %d\n", node->infoKeturunan.age);
    printf("\tTahun Lahir: %d\n", node->infoKeturunan.birthYear);
    printf("\tJenis Kelamin: %s\n", node->infoKeturunan.gender ? "Pria" : "Wanita");
    printf("\tStatus Hidup: %s\n", node->infoKeturunan.liveStatus ? "Hidup" : "Mati");
    
    if (node->infoPasangan.birthYear != 0) {
        printf("\tPasangan:\n");
        printf("\tNama: %s\n", node->infoPasangan.name);
        printf("\tUmur: %d\n", node->infoPasangan.age);
        printf("\tTahun Lahir: %d\n", node->infoPasangan.birthYear);
        printf("\tJenis Kelamin: %s\n", node->infoPasangan.gender ? "Pria" : "Wanita");
        printf("\tStatus Hidup: %s\n", node->infoPasangan.liveStatus ? "Hidup" : "Mati");
    }
    
    if (node->fs != NULL) {
        printf("\tKeturunan:\n");
        tampilkan_semua_silsilah(node->fs);
    }
    
    tampilkan_semua_silsilah(node->nb);
}

void menu_ubah_tahun() {
    printf("\n\tMasukkan tahun sekarang: ");
    scanf("%d", &currentYear);
    UpdateAges(familyTree.root, currentYear);
    printf("\n\tTahun sekarang telah diubah.\n");
    getch();
}
