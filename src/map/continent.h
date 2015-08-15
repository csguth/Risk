/*
 * continent.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef MAP_CONTINENT_H_
#define MAP_CONTINENT_H_

#include "territory.h"

#include <vector>
#include <set>

namespace risk {
namespace map {

class continent {
public:
    using id = std::size_t;
private:
    std::string m_name;
    std::vector<territory> m_territories;
    std::set<continent::id> m_recycled;

public:
    static const continent null;
    static id null_id();
    continent(std::string name);
    virtual ~continent();

    inline const std::string& name() const {
        return m_name;
    }
    inline std::size_t num_territories() const {
        return m_territories.size();
    }



    const territory& get_territory(territory::id id) const;
    territory::id add_territory(std::string name);
    bool remove_territory(territory::id territory);

};

} /* namespace map */
} /* namespace risk */

#endif /* MAP_CONTINENT_H_ */
