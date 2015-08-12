/*
 * lobby.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "lobby.h"

namespace risk {
namespace player {

lobby::lobby() {
}

lobby::~lobby() {
}

player::id lobby::register_player(std::string name) {
	if(m_recycled.empty())
	{
		m_players.push_back(player(name));
		return m_players.size() - 1;
	}
	auto recycled_id_it = m_recycled.begin();
	player::id recycled_id = *recycled_id_it;
	m_players[recycled_id] = player(name);
	m_recycled.erase(recycled_id_it);
	return recycled_id;
}

bool lobby::remove_player(player::id id) {
	if(id >= m_players.size() || m_recycled.find(id) != m_recycled.end())
		return false;
	m_recycled.insert(id);
	m_players[id] = player::null;
	return true;
}

} /* namespace player */
} /* namespace risk */
