/*
 * continent.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef MAP_CONTINENT_H_
#define MAP_CONTINENT_H_

#include <vector>
#include <limits>
#include "territory.h"

namespace risk {
namespace map {


class continent {
	std::string m_name;
	std::vector<territory> m_territories;

public:
	using id = std::size_t;
	static const continent null;
	continent(std::string name);
	virtual ~continent();

	const std::string& name() const { return m_name; }
	std::size_t num_territories() const { return m_territories.size(); }
	const territory& get_territory(territory::id id) const;
	territory::id add_territory(std::string name);


};

} /* namespace map */
} /* namespace risk */

#endif /* MAP_CONTINENT_H_ */
