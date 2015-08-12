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

namespace risk {
namespace player {

class lobby {
    const std::size_t c_MAX_SIZE;
    std::vector<player> m_players;
    std::set<player::id> m_recycled;
public:
    lobby(std::size_t size = std::numeric_limits<std::size_t>::max());
    virtual ~lobby();

    player::id register_player(std::string name);
    bool remove_player(player::id id);

    std::size_t size() const {
        return m_players.size() - m_recycled.size();
    }
    std::vector<player>::const_iterator begin() const {
        return m_players.cbegin();
    }
    std::vector<player>::const_iterator end() const {
        return m_players.end();
    }

};

} /* namespace player */
} /* namespace risk */

#endif /* PLAYER_LOBBY_H_ */
