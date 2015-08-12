#include "map.h"

namespace risk {
namespace map {

map::map(std::string name) :
        m_name(name) {
}

map::~map() {
}

std::size_t map::num_continents() const {
    return m_continents.size();
}

std::string map::name() const {
    return m_name;
}

continent::id map::add_continent(std::string name) {
    m_continents.emplace_back(name);
    return m_continents.size() - 1;
}

std::pair<continent::id, territory::id> map::add_territory(continent::id continent, std::string name) {
    if (continent >= m_continents.size())
        return std::make_pair(std::numeric_limits<continent::id>::max(), std::numeric_limits<territory::id>::max());
    return std::make_pair(continent, m_continents.at(continent).add_territory(name));
}

const continent& map::get_continent(continent::id id) const {
    if (id >= m_continents.size())
        return continent::null;
    return m_continents.at(id);
}

void map::connect_territories(continent_territory_id u, continent_territory_id v) {
    m_connections[u].push_back(v);
    m_connections[v].push_back(u);
}

std::size_t map::num_neighbors(std::pair<continent::id, territory::id> territory) const {
    return m_connections.at(territory).size();
}

const territory& map::get_neighbor(std::pair<continent::id, territory::id> territory, territory::id id) const {
    auto neighbor_id = m_connections.at(territory);
    if (id >= neighbor_id.size())
        return territory::null;
    return m_continents[neighbor_id.at(id).first].get_territory(neighbor_id.at(id).second);
}

}

}
