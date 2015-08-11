#include <catch/catch.hpp>
#include "../src/bonus/territory_bonus.h"
#include "../src/bonus/continent_bonus.h"
#include "../src/bonus/single_appliance_bonus.h"
#include "../src/bonus/full_continent_bonus_factory.h"

using map = risk::map::map;
using bonus = risk::bonus::bonus;
using territory_bonus = risk::bonus::territory_bonus;
using continent_bonus = risk::bonus::continent_bonus;
using single_appliance_bonus = risk::bonus::single_appliance_bonus;
using fcb_factory = risk::bonus::full_continent_bonus_factory;

TEST_CASE( "territory bonus" )
{
	map earth("earth");
	auto america_id = earth.add_continent("america");
	auto brazil_id = earth.add_territory(america_id, "brazil");
	auto colombia_id = earth.add_territory(america_id, "colombia");
	bonus* brazil_bonus = new territory_bonus(earth, brazil_id);

	REQUIRE( !brazil_bonus->apply(earth, colombia_id) );
	REQUIRE( brazil_bonus->apply(earth, brazil_id) );

	delete brazil_bonus;

}

TEST_CASE( "continent bonus" )
{
	map earth("earth");
	auto america_id = earth.add_continent("america");
	auto africa_id = earth.add_continent("africa");
	auto brazil_id = earth.add_territory(america_id, "brazil");
	auto colombia_id = earth.add_territory(america_id, "colombia");
	auto argelia_id = earth.add_territory(africa_id, "argelia");
	bonus* america_bonus = new continent_bonus(earth, america_id);

	REQUIRE( !america_bonus->apply(earth, argelia_id) );
	REQUIRE( america_bonus->apply(earth, brazil_id) );
	REQUIRE( america_bonus->apply(earth, colombia_id) );

	delete america_bonus;

}

TEST_CASE( "single appliance bonus" )
{
	map earth("earth");
	auto america_id = earth.add_continent("america");
	auto brazil_id = earth.add_territory(america_id, "brazil");
	auto colombia_id = earth.add_territory(america_id, "colombia");

	bonus* america_bonus = new continent_bonus(earth, america_id);
	bonus* america1 = new single_appliance_bonus(america_bonus);

	REQUIRE( america1->apply(earth, brazil_id) );
	REQUIRE( !america1->apply(earth, brazil_id) );

	delete america_bonus;
	delete america1;
}

TEST_CASE( "full continent bonus" )
{
	map earth("earth");
	auto america_id = earth.add_continent("america");
	auto brazil_id = earth.add_territory(america_id, "brazil");
	auto colombia_id = earth.add_territory(america_id, "colombia");

	fcb_factory factory(earth, america_id, 3);
	std::vector<bonus*> fcbs = factory.create();

	REQUIRE( fcbs[0]->apply(earth, brazil_id) );
	REQUIRE( !fcbs[0]->apply(earth, brazil_id) );
	REQUIRE( fcbs[1]->apply(earth, brazil_id) );
	REQUIRE( !fcbs[1]->apply(earth, brazil_id) );
	REQUIRE( fcbs[2]->apply(earth, brazil_id) );
	REQUIRE( !fcbs[2]->apply(earth, brazil_id) );

	for(auto i : fcbs)
		delete i;
}
