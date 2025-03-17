#include "mahasiswa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

bool isEmpty(address p) {
  // if (p == NULL) {
  //   return true;
  // }
  // return false;
  return (p == NULL);
}

void initiateList(List *l) {
    (*l).First = NULL;
}

void createNode(address *p) {
  *p = (address)malloc(sizeof(ElmtList));
  // if (*p == NULL) {
  //     *p = NULL;
  // }
}

void createMhs(infotype *mhs, char* nama, int nilai) {
    strcpy(mhs->nama, nama);
    mhs->nilai = nilai;
}

void insertNode(address *p, infotype mhs) {
  if (!isEmpty(*p)) {
    strcpy((**p).info.nama, mhs.nama);
    (**p).info.nilai = mhs.nilai;
    (**p).next = NULL;
  }
}

void printList(address p) {
  // while (!isEmpty(p)) {
  //   printf("%d -> ", p->info);
  //   p = p->next;
  // }
  // printf("NULL\n");
  if (isEmpty(p)) {
    printf("NULL\n");
  } else {
    printf("(%s, %d) -> ", (*p).info.nama, (*p).info.nilai);
    printList((*p).next);
  }
}

void insertFirst(address *p, address PNew) {
  (*PNew).next = *p;
  *p = PNew;
}

// typedef int (*CompareFunc)(infotype, infotype);

int compareDescending(infotype a, infotype b) {
    return b.nilai - a.nilai;
}

int compareAscending(infotype a, infotype b) {
    return a.nilai - b.nilai;
}

void printListSortedByNilai(List l, int (*cmp) (infotype, infotype)) {
    int count = NbElmt(l.First);
    if (count == 0)
        return;

    address nodes[count];
    address current = l.First;

    for (int i = 0; i < count; i++) {
        nodes[i] = current;
        current = current->next;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (cmp(nodes[i]->info, nodes[j]->info) > 0) {
                address temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("(%s, %d)\n", nodes[i]->info.nama, nodes[i]->info.nilai);
    }
}

address insertSortedAscending(address p, address pNew) {
  if (isEmpty(p) || strcasecmp((*pNew).info.nama, (*p).info.nama) < 0) {
    (*pNew).next = p;
    return pNew;
  }
  (*p).next = insertSortedAscending((*p).next, pNew);
  return p;
}

void insertSortWrapper(List *l, address pNew) {
  (*l).First = insertSortedAscending((*l).First, pNew);
}

void Ins_Akhir(address *p, address PNew) {
  if (isEmpty(*p)) {
    *p = PNew;
  } else {
    address temp = *p;
    while (!isEmpty((*temp).next)) {
      temp = (*temp).next;
    }
    (*temp).next = PNew;
  }
}
void copyWhereNilaiAboveThreshold(List l1, List *l2, int nilaiMin) {
  address current = l1.First;
  while (!isEmpty(current)) {
    if ((*current).info.nilai > nilaiMin) {
      address pNew;
      createNode(&pNew);
      infotype newMhs;
      createMhs(&newMhs, (*current).info.nama, (*current).info.nilai);
      insertNode(&pNew, newMhs);
      insertSortWrapper(l2, pNew);
    }
    current = current->next;
  }
}

void removeDuplicatedNama(List *l) {
  address current = (*l).First;
  while (!isEmpty(current) && !isEmpty(current->next)) {
    address temp = current;
    while (!isEmpty(temp->next)) {
      if (strcasecmp(current->info.nama, temp->next->info.nama) == 0) {
        address duplicate = temp->next;
        temp->next = temp->next->next;
        duplicate->next = NULL;
        free(duplicate);
      } else {
        temp = temp->next;
      }
    }
    current = current->next;
  }
}
address Search(address p, infotype mhs) {
  while (!isEmpty(p)) {
    if ((*p).info.nama == mhs.nama && (*p).info.nilai == mhs.nilai) {
      return p;
    }
    p = (*p).next;
  }
  return NULL;
}

void Modify(address p, infotype mhs) {
    p->info = mhs;
}

void InsertAfter(address *pBef, address PNew) {
  (*PNew).next = (**pBef).next;
  (**pBef).next = PNew;
}

void Del_Awal(address *p, infotype *X) {
  if (!isEmpty(*p)) {
    *X = (**p).info;
    address temp = *p;
    *p = (**p).next;
    (*temp).next = NULL;
    free(temp);
    // DeAlokasi(&temp);
  }
}

void Del_Akhir(address *p, infotype *X) {
  if (!isEmpty(*p)) {
    if (isEmpty((**p).next)) {
      printf("yellow!");
      *X = (**p).info;
      free(*p);
      *p = NULL;
    } else {
      address prev;
      address last = *p;
      while (!isEmpty((*last).next)) {
        prev = last;
        last = (*last).next;
      }
      *X = (*last).info;
      free(last);
      (*prev).next = NULL;
    }
  }
}

void Del_After(address *pBef, infotype *X) {
  address temp = (**pBef).next;
  // *X = (**pBef).info;
  (**pBef).next = (*temp).next;
  *X = (*temp).info;
  (*temp).next = NULL;
  free(temp);
}

void purgeList(List *l) {
  while (!isEmpty((*l).First)) {
    infotype i;
    Del_Awal(&(*l).First, &i);
  }
}

int NbElmt(address p) {
  // int sum = 0;
  // while (!isEmpty(p)) {
  //     sum += 1;
  //     p = (*p).next;
  // }
  // return sum;
  if (isEmpty(p)) {
    return 0;
  } else {
    return 1 + NbElmt((*p).next);
  }
}

int MinNilai(address p) {
  int Min = (*p).info.nilai;
  p = (*p).next;
  while (!isEmpty(p)) {
    if ((*p).info.nilai < Min) {
      Min = (*p).info.nilai;
    }
    p = (*p).next;
  }
  return Min;
}

int RerataNilai(address p) {
  int sum = 0, count = 0;
  while (!isEmpty(p)) {
    sum += (*p).info.nilai;
    count++;
    p = (*p).next;
  }
  return (count != 0) ? sum / count : 0;
}

address BalikList(address p) {
  if (!isEmpty(p)) {
    address prev = NULL;
    address this = p;
    address next = (*p).next;
    while (!isEmpty(next)) {
      (*this).next = prev;
      prev = this;
      this = next;
      next = (*this).next;
    }
    (*this).next = prev;
    p = this;
  }
  return p;
}
