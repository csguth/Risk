/*
 * owned_territory_state.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef DOMINATION_OWNED_TERRITORY_STATE_H_
#define DOMINATION_OWNED_TERRITORY_STATE_H_

#include "territory_state.h"
#include "empty_territory_state.h"

namespace risk {
namespace domination {

class empty_territory_state;
class owned_territory_state: public territory_state {
    player::player::id m_player_id;
    std::size_t m_army_size;
public:
    owned_territory_state(player::player::id player_id, std::size_t army_size);
    virtual ~owned_territory_state();
    player::player::id owner() const;
    std::size_t army_size() const;
    territory_state* add_army();
    territory_state* remove_army();
    territory_state* assign_to_player(risk::player::player::id id, std::size_t army_size);
};

} /* namespace domination */
} /* namespace risk */

#endif /* DOMINATION_OWNED_TERRITORY_STATE_H_ */
