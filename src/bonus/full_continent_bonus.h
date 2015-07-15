#ifndef BONUS_FULL_CONTINENT_BONUS_H
#define BONUS_FULL_CONTINENT_BONUS_H

#include "../domination/conqueror_player.h"
#include "../domination/conquerable_territory.h"
#include "../map/continent.h"

namespace risk {
namespace bonus {

class full_continent_bonus
{
	std::shared_ptr<risk::map::continent> continent_;
	std::shared_ptr<risk::domination::conqueror_player> player_;
	int size_;
public:
	full_continent_bonus(std::shared_ptr<risk::map::continent> continent, std::shared_ptr<risk::domination::conqueror_player> player);
	virtual ~full_continent_bonus();
	inline const int size() const { return size_; }

	bool apply(std::shared_ptr<risk::domination::conquerable_territory> territory);
};

}
}

#endif /* BONUS_FULL_CONTINENT_BONUS_H */