/*
 * land_attack_defense_die.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_LAND_ATTACK_DEFENSE_DIE_H_
#define DIE_LAND_ATTACK_DEFENSE_DIE_H_

#include "land_defense_die_face.h"
#include <vector>
#include "simple_die.h"

namespace risk {
namespace die {

class land_attack_defense_die: public simple_die<land_defense_die_face> {
public:
    land_attack_defense_die();
    virtual ~land_attack_defense_die();
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_LAND_ATTACK_DEFENSE_DIE_H_ */
