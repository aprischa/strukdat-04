/*
Nama Program : Exercise
Nama         : Aprischa Nauva
NPM          : 140810180063
Tanggal Buat : 19 Maret 2019
Deskripsi    : Exercise
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct nama{
    char divisi[15] ;
    char pegawai[30];
    int gaji;
    nama* next;
};
typedef nama* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    List first;
    int pilih;

    createList(first);
    while(1){
        system("cls");
        cout << "[1] Insert First " << endl;
        cout << "[2] Insert Last" << endl;
        cout << "[3] Delete First" << endl;
        cout << "[4] Delete Last" << endl;
        cout << "[5] Tampilkan data" << endl;
        cout << "[6] Keluar Program" << endl;
        cout << " -> Masukan Pilihan : ";
        cin >> pilih;
        switch(pilih){
        case 1:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;

        case 5:
            traversal(first);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}

void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new nama;
    cin.ignore();
    cout << "Nama Panjang Pegawai : ";
    cin.getline(pBaru->pegawai, 40);
    cout << "Divisi : ";
    cin>>pBaru->divisi;
    cout << "Gaji     : ";
    cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}
void traversal (List First){
    pointer pBantu;
    pBantu=First;
    while(pBantu != NULL){
        cout << endl;
        cout << "Nama Panjang Pegawai : " << pBantu->pegawai << endl;
        cout << "Divisi : " << pBantu->divisi << endl;
        cout << "Gaji : " << pBantu->gaji << endl;
        pBantu=pBantu->next;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada  yang dihapus" << endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}
