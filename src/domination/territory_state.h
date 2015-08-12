/*
 * territory_state.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef DOMINATION_TERRITORY_STATE_H_
#define DOMINATION_TERRITORY_STATE_H_

#include "../player/player.h"

namespace risk {
namespace domination {

class territory_state {
public:
    territory_state() {
    }
    virtual ~territory_state() {
    }

    virtual player::player::id owner() const = 0;
    virtual std::size_t army_size() const = 0;

    virtual territory_state* add_army() = 0;
    virtual territory_state* remove_army() = 0;
    virtual territory_state* assign_to_player(risk::player::player::id id, std::size_t army_size) = 0;
};

} /* namespace domination */
} /* namespace risk */

#endif /* DOMINATION_TERRITORY_STATE_H_ */
