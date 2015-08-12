/*
 * conquerable_map.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef DOMINATION_CONQUERABLE_MAP_H_
#define DOMINATION_CONQUERABLE_MAP_H_

#include "../map/map.h"
#include "../player/lobby.h"
#include "territory_state.h"
#include "empty_territory_state.h"
#include "owned_territory_state.h"
#include <set>

namespace risk {
namespace domination {

using set_of_territories = std::set<risk::map::continent_territory_id>;
class conquerable_map {
    const risk::map::map & m_map;
    const risk::player::lobby & m_lobby;

    std::vector<set_of_territories> m_players_territories;
    std::map<risk::map::continent_territory_id, territory_state*> m_territories_states;
public:
    conquerable_map(const risk::map::map & map, const risk::player::lobby & l);
    virtual ~conquerable_map();

    const set_of_territories & territories(risk::player::player::id player_id) const {
        return m_players_territories[player_id];
    }
    std::size_t army_size(risk::map::continent_territory_id territory_id) const;

    risk::player::player::id owner(map::continent_territory_id territory_id) const;

    void assign_territory_to_player(risk::player::player::id player_id, risk::map::continent_territory_id territory_id, std::size_t army_size);
    bool add_army(risk::map::continent_territory_id territory_id);
    bool remove_army(risk::map::continent_territory_id territory_id);

};

} /* namespace domination */
} /* namespace risk */

#endif /* DOMINATION_CONQUERABLE_MAP_H_ */
