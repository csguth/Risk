/*
 * land_attack_attack_die.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_LAND_ATTACK_ATTACK_DIE_H_
#define DIE_LAND_ATTACK_ATTACK_DIE_H_

#include "six_faces_die.h"
#include "land_attack_die_face.h"

namespace risk {
namespace die {

class land_attack_attack_die: public six_faces_die<land_attack_die_face> {
public:
	land_attack_attack_die();
	virtual ~land_attack_attack_die();
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_LAND_ATTACK_ATTACK_DIE_H_ */
