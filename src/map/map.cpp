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
        return std::make_pair(continent::null_id(), territory::null_id());
    return std::make_pair(continent, m_continents.at(continent).add_territory(name));
}

const continent& map::get_continent(continent::id id) const {
    if (id >= m_continents.size())
        return continent::null;
    return m_continents.at(id);
}

std::pair<std::set<continent_territory_id>::const_iterator, std::set<continent_territory_id>::const_iterator> map::neighbors(std::pair<continent::id, territory::id> territory) const {
    return {m_connections.at(territory).cbegin(), m_connections.at(territory).cend()};
}

void map::connect_territories(continent_territory_id u, continent_territory_id v) {
        m_connections[u].insert(v);
        m_connections[v].insert(u);
}

std::size_t map::num_neighbors(std::pair<continent::id, territory::id> territory) const {
    if(m_connections.find(territory) == m_connections.end())
        return static_cast<std::size_t>(0);
    return m_connections.at(territory).size();
}

}

}
