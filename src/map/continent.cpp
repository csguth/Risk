/*
 * continent.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "continent.h"
#include <limits>

namespace risk {
namespace map {

const continent continent::null("null continent");
continent::id continent::null_id() {
    return std::numeric_limits<continent::id>::max();
}

continent::continent(std::string name) :
                m_name(name) {

}

continent::~continent() {

}

const territory& continent::get_territory(territory::id id) const {
    if (id >= m_territories.size())
        return territory::null;
    return m_territories.at(id);
}

territory::id continent::add_territory(std::string name) {
    if (m_recycled.empty()) {
        m_territories.push_back(territory(name));
        return m_territories.size() - 1;
    }
    auto recycled_id_it = m_recycled.begin();
    territory::id recycled_id = *recycled_id_it;
    m_territories[recycled_id] = territory(name);
    m_recycled.erase(recycled_id_it);
    return recycled_id;
}
bool continent::remove_territory(territory::id territory) {
    if(m_recycled.insert(territory).second)
    {
        m_territories[territory] = territory::null;
        return true;
    }
    return false;
}

} /* namespace map */
} /* namespace risk */

