    #include "FamilyTrees.c"


    int currentYear;
    Tree familyTree;
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
                    // menu_tampilkan_silsilah();
                    Display("MonarchHierarchy.txt");
                    getch();
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
            // InsertDescendantInfo(familyTree.root, currentYear);
        char parentName[50];
        printf("\n\tMasukkan nama orang tua dari keturunan yang ingin ditambahkan: ");
        scanf(" %[^\n]", parentName);
        
        pointerN parentNode = FindNodeByName(familyTree.root, parentName);
        if (parentNode != NULL) {
            InsertDescendantInfo(familyTree.root, currentYear);
        } else {
            printf("\n\tOrang tua tidak ditemukan.\n");
            getch();
        }

    }

    void menu_tampilkan_silsilah() {
        if (familyTree.root == NULL) {
            printf("\n\tTitit Badag (File gagal dibuka)\n");
            getch();
            return;
        } else {
            printf("\n\tSilsilah Kerajaan:\n");
            Display("MonarchHierarchy.txt");
        }

        getch();
    }

    void menu_ubah_tahun() {
        printf("\n\tMasukkan tahun sekarang: ");
        scanf("%d", &currentYear);
        UpdateAges(familyTree.root, 0);
        printf("\n\tTahun sekarang telah diubah.\n");
        getch();
    }
