
#include "graph.h"
#include <iostream>
#include <iomanip>
#include <algorithm> // transform
#include <cctype>    // tolower

void KampusGraph::tambahEdge(const std::string &dari, const std::string &ke, int jarak)
{
    adj[dari].push_back({ke, jarak});
    adj[ke].push_back({dari, jarak});
}
static std::string toLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return s;
}

void KampusGraph::tampilkanRute(const std::string &dari) const
{
    // cari key secara case‑insensitive
    std::string dariL = toLower(dari);
    const std::vector<std::pair<std::string, int>> *rute = nullptr;

    for (const auto &[k, v] : adj)
    {
        if (toLower(k) == dariL)
        {
            rute = &v;
            break;
        }
    }

    if (!rute)
    {
        std::cout << "Lokasi tidak ditemukan.\n";
        return;
    }

    std::cout << "\n\033[1;33mRute dari " << dari << ":\033[0m\n";
    for (const auto &tu : *rute)
    {
        std::cout << "  - "
                  << std::setw(12) << std::left << tu.first
                  << " (" << tu.second << " m)\n";
    }
}