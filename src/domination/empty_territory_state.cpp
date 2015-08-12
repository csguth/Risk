/*
 * empty_territory_state.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "empty_territory_state.h"

#include <limits>

namespace risk {
namespace domination {

empty_territory_state::empty_territory_state() {

}

empty_territory_state::~empty_territory_state() {
}

std::size_t empty_territory_state::army_size() const {
    return static_cast<std::size_t>(0);
}

player::player::id empty_territory_state::owner() const {
    return std::numeric_limits<player::player::id>::max();
}

territory_state* empty_territory_state::assign_to_player(
        risk::player::player::id id, std::size_t army_size) {
    delete this;
    return new owned_territory_state(id, army_size);
}

territory_state* empty_territory_state::add_army() {
    return this;
}

territory_state* empty_territory_state::remove_army() {
    return this;
}

} /* namespace domination */
} /* namespace risk */

