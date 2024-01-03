#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <time.h>
#include <map>
#include <fstream>
#define first(L) L.first
#define last(L) L.last
#define root(T) T.root
#define left(P) P->left
#define right(P) P->right
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define inventory(P) P->inventory
#define object(P) P->object
#define offensive(P) P->offensive
#define defensive(P) P->defensive
#define skill(P) P->skill
#define Class(P) P->Class
#define mc(P) P.last
#define allocate(p) p = new elmtList
#define head(Q) Q.head
#define tail(Q) Q.tail
#define top(S) S.top
#define peek(S) S.info[top(S)]
#define MC info(mc(PL))
#define ping printf("PING\n");
using namespace std;
#endif // DLL_H_INCLUDED
