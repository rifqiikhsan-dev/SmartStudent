
#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <map>
#include <vector>

class KampusGraph{
    std::map<std::string, std::vector<std::pair<std::string,int>>> adj;
public:
    void tambahEdge(const std::string& dari,const std::string& ke,int jarak);
    void tampilkanRute(const std::string& dari) const;
};
#endif
