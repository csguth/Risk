/*
 * single_appliance_bonus.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef BONUS_SINGLE_APPLIANCE_BONUS_H_
#define BONUS_SINGLE_APPLIANCE_BONUS_H_

#include "bonus.h"

namespace risk {
namespace bonus {

class single_appliance_bonus: public bonus {
    bonus* m_bonus;
    bool m_applied;
public:
    single_appliance_bonus(bonus * the_bonus);
    virtual ~single_appliance_bonus();
    bool apply(risk::map::map& m, risk::map::continent_territory_id territory);
};

} /* namespace bonus */
} /* namespace risk */

#endif /* BONUS_SINGLE_APPLIANCE_BONUS_H_ */
