/*
 * lobby.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef PLAYER_LOBBY_H_
#define PLAYER_LOBBY_H_

#include "player.h"
#include <vector>
#include <iterator>
#include <utility>
#include <set>

#include "../src/utils/storage.h"

namespace risk {
namespace player {

class lobby {
    utils::limited_storage<player> m_players;
public:
    lobby(std::size_t size = std::numeric_limits<std::size_t>::max());
    virtual ~lobby();

    player::id register_player(std::string name);
    bool remove_player(player::id id);

    std::size_t size() const {
        return m_players.size();
    }
    utils::limited_storage<player>::iterator begin() const {
        return m_players.begin();
    }
    utils::limited_storage<player>::iterator end() const {
        return m_players.end();
    }

};

} /* namespace player */
} /* namespace risk */

#endif /* PLAYER_LOBBY_H_ */
