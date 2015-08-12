/*
 * single_appliance_bonus.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "single_appliance_bonus.h"

namespace risk {
namespace bonus {

single_appliance_bonus::single_appliance_bonus(bonus * the_bonus) :
        m_bonus(the_bonus), m_applied(false) {

}
single_appliance_bonus::~single_appliance_bonus() {
    delete m_bonus;
}
bool single_appliance_bonus::apply(risk::map::map& m,
        risk::map::continent_territory_id territory) {
    if (m_applied || !m_bonus->apply(m, territory))
        return false;
    m_applied = true;
    return true;
}

} /* namespace bonus */
} /* namespace risk */
