/*
 * empty_territory_state.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef DOMINATION_EMPTY_TERRITORY_STATE_H_
#define DOMINATION_EMPTY_TERRITORY_STATE_H_

#include "territory_state.h"
#include "owned_territory_state.h"

namespace risk {
namespace domination {

class owned_territory_state;
class empty_territory_state: public territory_state {
public:
	empty_territory_state();
	virtual ~empty_territory_state();

	player::player::id owner() const;
	std::size_t army_size() const;
	territory_state* add_army();
	territory_state* remove_army();
	territory_state* assign_to_player(risk::player::player::id id, std::size_t army_size);
};

} /* namespace domination */
} /* namespace risk */

#endif /* DOMINATION_EMPTY_TERRITORY_STATE_H_ */
