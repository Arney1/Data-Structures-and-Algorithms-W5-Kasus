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
  char nama[100];
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
void Modify(address p, infotype mhs);
void createNode(address *p);
void createMhs(infotype *mhs, char* nama, int nilai);
void insertNode(address *p, infotype mhs);
void printList(address p);
void insertFirst(address *p, address PNew);
void printListDescendingByNilai(List l);
address insertSortedAscending(address p, address pNew);
void insertSortWrapper(List *l, address pNew);
void Ins_Akhir(address *p, address PNew);
void copyWhereNilaiAboveThreshold(List l1, List *l2, int nilaiMin);
void removeDuplicatedNama(List *l);
address Search(address p, infotype mhs);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void Del_After(address *pBef, infotype *X);
int compareDescending(infotype a, infotype b);
int compareAscending(infotype a, infotype b);
void printListSortedByNilai(List l, int (*cmp) (infotype, infotype));
void purgeList(List *l);
int NbElmt(address p);
int MinNilai(address p);
int RerataNilai(address p);
address BalikList(address p);

#endif
