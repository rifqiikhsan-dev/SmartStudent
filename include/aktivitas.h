
#ifndef AKTIVITAS_H
#define AKTIVITAS_H
#include <string>

struct AktivitasNode {
    std::string aktivitas;
    AktivitasNode* next;
    explicit AktivitasNode(const std::string& act): aktivitas(act), next(nullptr){}
};

class RiwayatAktivitas{
    AktivitasNode* head;
public:
    RiwayatAktivitas();
    ~RiwayatAktivitas();
    void tambahAktivitas(const std::string& act);
    void tampilkan() const;
};
#endif
