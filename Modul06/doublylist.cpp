#include "Doublylist.h"

void CreateList(List &L)
{
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = Nil;
}

void printInfo(List L)
{
    address P = L.First;
    while (P != Nil)
    {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

void insertFirst(List &L, address P)
{
    if (L.First == Nil)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P)
{
    if (L.First == Nil)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, string nopol)
{
    address P = L.First;
    while (P != Nil)
    {
        if (P->info.nopol == nopol)
        {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P)
{
    P = L.First;
    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P)
{
    P = L.Last;
    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil)
    {
        P->next->prev = Prec;
    }
    else
    {
        L.Last = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteNode(List &L, string nopol)
{
    address P = findElm(L, nopol);
    if (P != Nil)
    {
        if (P == L.First)
        {
            deleteFirst(L, P);
        }
        else if (P == L.Last)
        {
            deleteLast(L, P);
        }
        else
        {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
    }
}