
#include "aktivitas.h"
#include <iostream>

RiwayatAktivitas::RiwayatAktivitas() : head(nullptr) {}
RiwayatAktivitas::~RiwayatAktivitas()
{
    while (head)
    {
        auto *tmp = head;
        head = head->next;
        delete tmp;
    }
}
void RiwayatAktivitas::tambahAktivitas(const std::string &act)
{
    auto *node = new AktivitasNode(act);
    if (!head)
    {
        head = node;
        return;
    }
    auto *t = head;
    while (t->next)
        t = t->next;
    t->next = node;
}
void RiwayatAktivitas::tampilkan() const
{
    std::cout << "\n\033[1;34mRiwayat Aktivitas:\033[0m\n";
    auto *t = head;
    while (t)
    {
        std::cout << "- " << t->aktivitas << "\n";
        t = t->next;
    }
}
