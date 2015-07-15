#include "conquerable_territory.h"

namespace risk {
namespace domination {

conquerable_territory::conquerable_territory(const std::string name):
	risk::map::territory(name)
{

}
conquerable_territory::~conquerable_territory()
{

}

void conquerable_territory::player(std::shared_ptr<conqueror_player> player)
{
	player_ = player;
}

}
}
