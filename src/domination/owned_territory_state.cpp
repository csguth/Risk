/*
 * owned_territory_state.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "owned_territory_state.h"

namespace risk {
namespace domination {

owned_territory_state::~owned_territory_state() {
}

player::player::id owned_territory_state::owner() const {
    return m_player_id;
}

std::size_t owned_territory_state::army_size() const {
    return m_army_size;
}

owned_territory_state::owned_territory_state(player::player::id player_id, std::size_t army_size) :
        m_player_id(player_id), m_army_size(army_size) {

}

territory_state* owned_territory_state::assign_to_player(risk::player::player::id id, std::size_t army_size) {
    m_player_id = id;
    m_army_size = army_size;
    return this;
}

territory_state* owned_territory_state::add_army() {
    ++m_army_size;
    return this;
}

territory_state* owned_territory_state::remove_army() {
    if (--m_army_size == 0) {
        delete this;
        return new empty_territory_state;
    }
    return this;
}

} /* namespace domination */
} /* namespace risk */

