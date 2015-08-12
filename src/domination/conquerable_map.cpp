/*
 * conquerable_map.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "conquerable_map.h"

namespace risk {
namespace domination {

conquerable_map::conquerable_map(const risk::map::map& map, const risk::player::lobby & l) :
        m_map(map), m_lobby(l), m_players_territories(m_lobby.size()) {
    for (std::size_t i = 0; i < m_map.num_continents(); ++i) {
        for (std::size_t j = 0; j < m_map.get_continent(i).num_territories(); ++j)
            m_territories_states[std::make_pair(i, j)] = new empty_territory_state;
    }
}

conquerable_map::~conquerable_map() {
    for (auto & i : m_territories_states)
        delete i.second;
}

risk::player::player::id conquerable_map::owner(map::continent_territory_id territory_id) const {
    return m_territories_states.at(territory_id)->owner();
}

bool conquerable_map::assign_territory_to_player(risk::player::player::id player_id, risk::map::continent_territory_id territory_id, std::size_t army_size) {
    if(player_id == player::player::null_id())
        return false;
    risk::player::player::id owner_before = m_territories_states.at(territory_id)->owner();
    m_territories_states.at(territory_id) = m_territories_states.at(territory_id)->assign_to_player(player_id, army_size);
    m_players_territories.at(m_territories_states.at(territory_id)->owner()).insert(territory_id);
    if (m_territories_states.at(territory_id)->owner() != owner_before && owner_before != player::player::null_id())
        m_players_territories.at(owner_before).erase(territory_id);
    return m_territories_states.at(territory_id)->owner() != owner_before;
}

std::size_t conquerable_map::army_size(risk::map::continent_territory_id territory_id) const {
    return m_territories_states.at(territory_id)->army_size();
}

bool conquerable_map::add_army(risk::map::continent_territory_id territory_id) {
    std::size_t size_before = army_size(territory_id);
    m_territories_states.at(territory_id) = m_territories_states.at(territory_id)->add_army();
    std::size_t size_after = army_size(territory_id);
    return size_after != size_before;
}

bool conquerable_map::remove_army(risk::map::continent_territory_id territory_id) {
    std::size_t size_before = army_size(territory_id);
    player::player::id owner_before = m_territories_states.at(territory_id)->owner();
    m_territories_states.at(territory_id) = m_territories_states.at(territory_id)->remove_army();
    std::size_t size_after = army_size(territory_id);
    if (m_territories_states.at(territory_id)->owner() != owner_before)
        m_players_territories[owner_before].erase(territory_id);
    return size_after != size_before;
}

} /* namespace domination */
} /* namespace risk */
