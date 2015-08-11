/*
 * continent_bonus.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef BONUS_CONTINENT_BONUS_H_
#define BONUS_CONTINENT_BONUS_H_

#include  "bonus.h"

namespace risk {
namespace bonus {

class continent_bonus : public bonus{
	risk::map::map& m_map;
	risk::map::continent::id m_continent;
public:
	continent_bonus(risk::map::map& m, risk::map::continent::id continent);
	virtual ~continent_bonus();
	bool apply(risk::map::map& m, risk::map::continent_territory_id territory);

};

} /* namespace bonus */
} /* namespace risk */

#endif /* BONUS_CONTINENT_BONUS_H_ */
