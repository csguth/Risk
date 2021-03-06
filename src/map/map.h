#ifndef RISK_MAP_MAP_H
#define RISK_MAP_MAP_H

#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include "continent.h"

namespace risk {
namespace map {

using continent_territory_id = std::pair<continent::id, territory::id>;

class map {
    std::string m_name;
    std::vector<continent> m_continents;
    std::map<continent_territory_id, std::set<continent_territory_id> > m_connections;
public:
    map(std::string name);
    virtual ~map();

    std::string name() const;
    std::size_t num_continents() const;
    const continent& get_continent(continent::id id) const;
    std::size_t num_neighbors(std::pair<continent::id, territory::id> territory) const;
    std::pair<std::set<continent_territory_id>::const_iterator, std::set<continent_territory_id>::const_iterator > neighbors(std::pair<continent::id, territory::id> territory) const;

    continent::id add_continent(std::string name);
    std::pair<continent::id, territory::id> add_territory(continent::id continent, std::string name);
    void connect_territories(continent_territory_id u, continent_territory_id v);

};

}

}

#endif /*  RISK_MAP_MAP_H */
