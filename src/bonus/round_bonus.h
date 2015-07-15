#ifndef BONUS_ROUND_BONUS_H
#define BONUS_ROUND_BONUS_H

#include "../domination/conqueror_player.h"
#include "../domination/conquerable_territory.h"

namespace risk {
namespace bonus {

class round_bonus {
	std::shared_ptr<risk::domination::conqueror_player> player_;
	int size_;
public:
	round_bonus(std::shared_ptr<risk::domination::conqueror_player> player);
	virtual ~round_bonus();

	inline const int size() const { return size_; }

	bool apply(std::shared_ptr<risk::domination::conquerable_territory> territory);
};

}
}

#endif /* BONUS_ROUND_BONUS_H */