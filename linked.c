#include "linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isEmpty(address p) {
  // if (p == NULL) {
  //   return true;
  // }
  // return false;
  return (p == NULL);
}

void Create_Node(address *p) {
  *p = (address)malloc(sizeof(ElmtList));
  // if (*p == NULL) {
  //     *p = NULL;
  // }
}

void Isi_Node(address *p, char* nama, int nilai) {
  if (!isEmpty(*p)) {
    strcpy( (**p).info.nama, nama);
    (**p).info.nilai = nilai;
    (**p).next = NULL;
  }
}

void Tampil_List(address p) {
  // while (!isEmpty(p)) {
  //   printf("%d -> ", p->info);
  //   p = p->next;
  // }
  // printf("NULL\n");
  if (isEmpty(p)) {
    printf("NULL\n");
  } else {
    printf("[%s, %d] -> \n", (*p).info.nama, (*p).info.nilai);
    Tampil_List((*p).next);
  }
}

void Ins_Awal(address *p, address PNew) {
  (*PNew).next = *p;
  *p = PNew;
}

address insertSorted(address p, address pNew) {
  if (isEmpty(p) || strcmp((*pNew).info.nama, (*p).info.nama) < 0) {
    (*pNew).next = p;
    return pNew;
  }
  (*p).next = insertSorted((*p).next, pNew);
  return p;
}

void insertSortWrapper(List *l, address pNew) {
    (*l).First = insertSorted((*l).First, pNew);
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

address SearchNilai(address p, infotype nilai) {
  while (!isEmpty(p)) {
    if ((*p).info.nilai == nilai.nilai) {
      return p;
    }
    p = (*p).next;
  }
  return NULL;
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

void DeAlokasi(address *p) {
  while (!isEmpty(*p)) {
    int i;
    Del_Awal(p, &i);
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

// infotype Min(address p) {
//   int Min = (*p).info;
//   p = (*p).next;
//   while (!isEmpty(p)) {
//     if ((*p).info < Min) {
//       Min = (*p).info;
//     }
//     p = (*p).next;
//   }
//   return Min;
// }

// infotype Rerata(address p) {
//   int sum = 0, count = 0;
//   while (!isEmpty(p)) {
//     sum += (*p).info;
//     count++;
//     p = (*p).next;
//   }
//   return (count != 0) ? sum / count : 0;
// }

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

// int main() {
//   address head = NULL;
//   address newNode;
//   infotype value;

//   printf("=== TESTING LINKED LIST ===\n");

//   // Test Create Node & Insert at the Beginning
//   printf("Inserting 10, 20, 30, 40, 50, 60 at the beginning:\n");
//   for (int i = 10; i <= 60; i += 10) {
//     Create_Node(&newNode);
//     Isi_Node(&newNode, i);
//     Ins_Awal(&head, newNode);
//   }
//   Tampil_List(head);

//   // Test Insert at the End
//   printf("Inserting 40 at the end:\n");
//   Create_Node(&newNode);
//   Isi_Node(&newNode, 40);
//   Ins_Akhir(&head, newNode);
//   Tampil_List(head);

//   // Test Search
//   printf("Searching for value 20:\n");
//   address found = Search(head, 20);
//   if (found != NULL)
//     printf("Value 20 found!\n");
//   else
//     printf("Value 20 not found!\n");

//   printf("Inserting 67 after 20\n");
//   Create_Node(&newNode);
//   Isi_Node(&newNode, 67);
//   InsertAfter(&found, newNode);
//   Tampil_List(head);

//   // Test Delete First
//   printf("Deleting first element:\n");
//   Del_Awal(&head, &value);
//   printf("Deleted value: %d\n", value);
//   Tampil_List(head);

//   // Test Delete Last
//   printf("Deleting last element:\n");
//   Del_Akhir(&head, &value);
//   printf("Deleted value: %d\n", value);
//   Tampil_List(head);

//   printf("Deleting node after 20:\n");
//   found = Search(head, 20);
//   Del_After(&found, &value);
//   printf("Deleted value: %d\n", value);
//   Tampil_List(head);

//   // Test Reverse List
//   printf("Reversing the list:\n");
//   head = BalikList(head);
//   Tampil_List(head);

//   // Test Count Elements
//   printf("Number of elements: %d\n", NbElmt(head));

//   // Test Min & Average
//   if (!isEmpty(head)) {
//     printf("Minimum value: %d\n", Min(head));
//     printf("Average value: %d\n", Rerata(head));
//   }

//   // Cleanup
//   DeAlokasi(&head);
//   printf("List cleared.\n");

//   return 0;
// }
