
#ifndef BUKU_H
#define BUKU_H
#include <string>

struct BukuNode{
    std::string judul;
    BukuNode* kiri;
    BukuNode* kanan;
    explicit BukuNode(const std::string& j): judul(j), kiri(nullptr), kanan(nullptr){}
};

class BSTBuku{
    BukuNode* root;
    void insert(BukuNode*& node,const std::string& j);
    void inorder(BukuNode* node) const;
    bool cari(BukuNode* node,const std::string& j) const;
public:
    BSTBuku();
    ~BSTBuku();
    void tambahBuku(const std::string& j);
    void tampilkanBuku() const;
    bool cariBuku(const std::string& j) const;
};
#endif
