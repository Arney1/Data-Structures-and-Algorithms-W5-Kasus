#include "mahasiswa.c"
#include "mahasiswa.h"

int main() {
  List l1, l2;
  address newNode;
  infotype value, newMhs;

  initiateList(&l1);
  initiateList(&l2);

  createNode(&newNode);
  createMhs(&newMhs, "Arkan", 80);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Muhammad", 79);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Aril", 53);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Bambang", 10);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Busan", 100);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Lucy", 99);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Luna", 70);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Eren yeagah", 70);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Angry Bird", 1);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Python", 60);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Bernard Bear", 80);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  // printList(l1.First);

  createNode(&newNode);
  createMhs(&newMhs, "Violet", 80);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);

  createNode(&newNode);
  createMhs(&newMhs, "Arkan", 87);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  createNode(&newNode);
  createMhs(&newMhs, "Zaza", 87);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);
  createNode(&newNode);
  createMhs(&newMhs, "Zaza", 87);
  insertNode(&newNode, newMhs);
  insertSortWrapper(&l1, newNode);

  printList(l1.First);
  // printListDescendingByNilai(l1);
  printListSortedByNilai(l1, compareDescending);

  printf("%d\n", NbElmt(l1.First));

  copyWhereNilaiAboveThreshold(l1, &l2, 70);
  printList(l2.First);

  removeDuplicatedNama(&l2);
  printList(l2.First);

  purgeList(&l1);
  purgeList(&l2);

  return 0;
}
