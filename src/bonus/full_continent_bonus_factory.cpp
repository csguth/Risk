/*
 * full_continent_bonus_factory.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "full_continent_bonus_factory.h"

namespace risk {
namespace bonus {

full_continent_bonus_factory::full_continent_bonus_factory(risk::map::map& m, risk::map::continent::id continent, int size):
		m_bonus(new continent_bonus(m, continent)),
		m_size(size)
{

}
full_continent_bonus_factory::~full_continent_bonus_factory()
{
	delete m_bonus;
}
std::vector<bonus*> full_continent_bonus_factory::create()
{
	std::vector<bonus*> result(m_size);
	for(int i = 0; i < m_size; ++i)
		result[i] = new single_appliance_bonus(m_bonus);
	return result;
}

} /* namespace bonus */
} /* namespace risk */
