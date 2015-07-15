#ifndef DOMINATION_CONQUERABLE_TERRITORY_H
#define DOMINATION_CONQUERABLE_TERRITORY_H

#include "../map/territory.h"
#include "conqueror_player.h"

#include <memory>

namespace risk {
namespace domination {

class conqueror_player;
class conquerable_territory :
	public risk::map::territory
{
	friend class conqueror_player;
	std::shared_ptr<conqueror_player> player_;
	void player(std::shared_ptr<conqueror_player> player);
public:
	conquerable_territory(const std::string name);
	virtual ~conquerable_territory();
	std::shared_ptr<conqueror_player> player() { return player_; }

};

}
}

#endif /* DOMINATION_CONQUERABLE_TERRITORY_H */