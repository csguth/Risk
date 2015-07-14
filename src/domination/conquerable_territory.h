#ifndef DOMINATION_CONQUERABLE_TERRITORY_H
#define DOMINATION_CONQUERABLE_TERRITORY_H

#include "../map/territory.h"
#include "conqueror_player.h"

namespace risk {
namespace domination {

class conqueror_player;
class conquerable_territory : public risk::map::territory {
	std::shared_ptr<conqueror_player> player_;
public:
	conquerable_territory(const std::string name);
	virtual ~conquerable_territory();
	std::shared_ptr<conqueror_player> player() { return player_; }

	void player(std::shared_ptr<conqueror_player> player);
	void release();
};

}
}

#endif /* DOMINATION_CONQUERABLE_TERRITORY_H */