#include "territory.h"

namespace risk {
namespace map {

territory::territory(const std::string name):
	name_(name)
{

}

territory::~territory()
{

}

void territory::set_continent(std::shared_ptr<continent> c)
{
	continent_ = c;
}

std::shared_ptr<territory> territory::find_neighbor(const std::string name) const
{
	return neighborhood_.at(name);
}

void territory::add_neighbor(std::shared_ptr<territory> neighbor)
{
	neighborhood_.insert(std::make_pair(neighbor->name(), neighbor));
	try{
		neighbor->find_neighbor(name_);
	}catch(std::out_of_range&e)
	{
		neighbor->add_neighbor(shared_from_this());	
	}
}

}
}