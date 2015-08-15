/*
 * lobby.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "lobby.h"

namespace risk {
namespace player {

lobby::lobby(std::size_t size) :
        m_players(size) {
}

lobby::~lobby() {
}

player::id lobby::register_player(std::string name) {
    return m_players.insert(player(name));
}

bool lobby::remove_player(player::id id) {
    return m_players.remove(id);
}

} /* namespace player */
} /* namespace risk */
