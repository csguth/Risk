#include "continent.h"

namespace risk {
namespace map {

continent::continent(std::string name, int bonus) :
	name_(name),
	bonus_(bonus)
{

}

continent::~continent(){

}

std::shared_ptr<territory> continent::find_territory(const std::string name) const
{
	return territories_.at(name);
}

void continent::set_map(std::shared_ptr<map> m)
{
	map_ = m;
}

void continent::add_territory(std::shared_ptr<territory> territory)
{
	territories_.insert(std::make_pair(territory->name(), territory));
	territory->set_continent(shared_from_this());
}

continent_has_name::continent_has_name(const std::string name):
	name_(name)
{
}

bool continent_has_name::operator()(const continent & c) const
{
	return c.name() == name_;
}

}
}