/* File        : linked.h */
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef linked_H
#define linked_H
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  char nama[50];
  int nilai;
} infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
  infotype info;
  address next;
} ElmtList;
typedef struct {
  address First;
} List;

bool isEmpty(address p);
void Create_Node(address *p);
void Isi_Node(address *p, char *nama, int nilai);
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
address Search(address p, infotype nilai);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void Del_After(address *pBef, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address p);
infotype Min(address p);
infotype Rerata(address p);
address BalikList(address p);

#endif
