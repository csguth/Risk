/*
 * territory_bonus.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "territory_bonus.h"

namespace risk {
namespace bonus {

territory_bonus::territory_bonus(risk::map::map & map, risk::map::continent_territory_id territory) :
		m_map(map),
		m_territory(territory)
{

}

territory_bonus::~territory_bonus() {
}

bool territory_bonus::apply(risk::map::map& m,
		risk::map::continent_territory_id territory) {
	if(&m_map != &m || m_territory != territory)
		return false;
	m.add_army(territory);
	return true;

}

} /* namespace bonus */
} /* namespace risk */
