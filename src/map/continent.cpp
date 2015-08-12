/*
 * continent.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "continent.h"

namespace risk {
namespace map {

const continent continent::null("null continent");

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
    m_territories.push_back(territory(name));
    return m_territories.size() - 1;
}

} /* namespace map */
} /* namespace risk */
