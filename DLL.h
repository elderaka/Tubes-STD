#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define inventory(P) P->inventory
#define object(P) P->object
#define skill(P) P->skill
#define allocate(p) p = new elmtList
using namespace std;
#endif // DLL_H_INCLUDED
