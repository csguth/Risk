#include "full_continent_bonus.h"

namespace risk {
namespace bonus {


full_continent_bonus::full_continent_bonus(std::shared_ptr<risk::map::continent> continent, std::shared_ptr<risk::domination::conqueror_player> player):
	continent_(continent),
	player_(player),
	size_(0)
{
	int count = 0;
	for(auto territory : continent_->territories())
	{
		try {
			player->territory(territory.first);
			count++;
		} catch(std::out_of_range&e)
		{

		}
	}
	if(count == continent_->num_territories())
		size_ = continent->bonus();
}

full_continent_bonus::~full_continent_bonus()
{

}

bool full_continent_bonus::apply(std::shared_ptr<risk::domination::conquerable_territory> territory)
{
	continent_->territories().at(territory->name());
	if(size_ == 0)
		return false;
	territory->add_army(1);
	size_--;
	return true;

}


}
}