/*
 * territory_bonus.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef BONUS_TERRITORY_BONUS_H_
#define BONUS_TERRITORY_BONUS_H_

#include "bonus.h"

namespace risk {
namespace bonus {

class territory_bonus: public bonus {
    risk::map::map & m_map;
    risk::map::continent_territory_id m_territory;
public:
    territory_bonus(risk::map::map & map,
            risk::map::continent_territory_id territory);
    virtual ~territory_bonus();

    bool apply(risk::map::map& m, risk::map::continent_territory_id territory);
};

} /* namespace bonus */
} /* namespace risk */

#endif /* BONUS_TERRITORY_BONUS_H_ */
