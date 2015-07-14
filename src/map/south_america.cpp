#include "south_america.h"

namespace risk {
namespace map {


const std::unique_ptr<continent> south_america::instance_{new south_america};

south_america::south_america() :
	continent("South America")
{
	std::shared_ptr<territory> brazil{new territory{"Brazil"}};
	std::shared_ptr<territory> colombia{new territory{"Colombia/Venezuela"}};
	std::shared_ptr<territory> peru{new territory{"Peru/Bolívia/Chile"}};
	std::shared_ptr<territory> argentina{new territory{"Argentina/Uruguai"}};

	brazil->add_neighbor(colombia);
	brazil->add_neighbor(peru);
	brazil->add_neighbor(argentina);

	colombia->add_neighbor(brazil);
	colombia->add_neighbor(peru);

	peru->add_neighbor(colombia);
	peru->add_neighbor(brazil);
	peru->add_neighbor(argentina);

	argentina->add_neighbor(peru);
	argentina->add_neighbor(brazil);

	add_territory(brazil);
	add_territory(colombia);
	add_territory(peru);
	add_territory(argentina);
}

south_america::~south_america()
{
}

}
}