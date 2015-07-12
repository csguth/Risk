/*
 * land_defense_die_face.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_LAND_DEFENSE_DIE_FACE_H_
#define DIE_LAND_DEFENSE_DIE_FACE_H_

#include "die_face.h"
#include "land_attack_die_face.h"

namespace risk {
namespace die {

class land_attack_die_face;
class land_defense_die_face: public die_face {
public:
	land_defense_die_face(die_face_value value);
	virtual ~land_defense_die_face();
	bool wins(const land_attack_die_face & o) const;
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_LAND_DEFENSE_DIE_FACE_H_ */
