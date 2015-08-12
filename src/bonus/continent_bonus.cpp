/*
 * continent_bonus.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "continent_bonus.h"

namespace risk {
namespace bonus {

continent_bonus::continent_bonus(risk::map::map& m, risk::map::continent::id continent) :
        m_map(m), m_continent(continent) {

}
continent_bonus::~continent_bonus() {

}
bool continent_bonus::apply(risk::map::map& m, risk::map::continent_territory_id territory) {
    if (&m_map != &m || m_continent != territory.first)
        return false;
    return true;
}

} /* namespace bonus */
} /* namespace risk */
