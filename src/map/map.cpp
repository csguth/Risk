#include "map.h"

namespace risk {
namespace map {

map::map(std::string name) :
	name_(name)
{

}

map::~map(){

}

void map::add_continent(std::shared_ptr<continent> c){
	continents_.insert(std::make_pair(c->name(), c));
	c->set_map(shared_from_this());
}

std::shared_ptr<continent> map::find_continent(const std::string name) const {
	return continents_.at(name);
}

}
}