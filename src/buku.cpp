
#include "buku.h"
#include <iostream>

BSTBuku::BSTBuku(): root(nullptr){}
BSTBuku::~BSTBuku(){}

void BSTBuku::insert(BukuNode*& node,const std::string& j){
    if(!node) node=new BukuNode(j);
    else if(j<node->judul) insert(node->kiri,j);
    else if(j>node->judul) insert(node->kanan,j);
}
void BSTBuku::tambahBuku(const std::string& j){ insert(root,j);}
void BSTBuku::inorder(BukuNode* node) const{
    if(!node) return;
    inorder(node->kiri);
    std::cout<<"  - "<<node->judul<<"\n";
    inorder(node->kanan);
}
void BSTBuku::tampilkanBuku() const{ inorder(root);}
bool BSTBuku::cari(BukuNode* node,const std::string& j) const{
    if(!node) return false;
    if(j==node->judul) return true;
    if(j<node->judul) return cari(node->kiri,j);
    return cari(node->kanan,j);
}
bool BSTBuku::cariBuku(const std::string& j) const{ return cari(root,j);}
