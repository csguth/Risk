/*
 * bonus.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef BONUS_BONUS_H_
#define BONUS_BONUS_H_

#include "../map/map.h"

namespace risk {
namespace bonus {

class bonus {
public:
	virtual ~bonus(){}
	virtual bool apply(risk::map::map& m, risk::map::continent_territory_id territory) = 0;
};

} /* namespace bonus */
} /* namespace risk */

#endif /* BONUS_BONUS_H_ */
