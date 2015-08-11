/*
 * full_continent_bonus_factory.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef BONUS_FULL_CONTINENT_BONUS_FACTORY_H_
#define BONUS_FULL_CONTINENT_BONUS_FACTORY_H_

#include "continent_bonus.h"
#include "single_appliance_bonus.h"

namespace risk {
namespace bonus {

class full_continent_bonus_factory {
	bonus* m_bonus;
	int m_size;
public:
	full_continent_bonus_factory(risk::map::map& m, risk::map::continent::id continent, int size);
	virtual ~full_continent_bonus_factory();

	std::vector<bonus*> create();
};

} /* namespace bonus */
} /* namespace risk */

#endif /* BONUS_FULL_CONTINENT_BONUS_FACTORY_H_ */
