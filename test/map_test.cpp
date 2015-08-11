#include <catch/catch.hpp>
#include "../src/map/map.h"

using continent = risk::map::continent;
using map = risk::map::map;
using territory = risk::map::territory;

TEST_CASE( "map name" ) {
	map earth("earth");
	REQUIRE(earth.name() == "earth");
}

TEST_CASE( "empty map" ) {
	map themap("a");
	REQUIRE(themap.num_continents() == 0);
}

TEST_CASE( "add continent" ) {
	map themap("a");
	auto continent_id = themap.add_continent("america");
	REQUIRE(themap.num_continents() == 1);
	REQUIRE(continent_id == 0);
	REQUIRE(themap.add_continent("africa") == 1);
	REQUIRE(themap.num_continents() == 2);
}

TEST_CASE( "continent name" ) {
	map themap("a");
	auto continent_id = themap.add_continent("america");
	REQUIRE(themap.get_continent(continent_id).name() == "america");
}

TEST_CASE( "null continent object" ) {
	map themap("a");
	auto continent_id = themap.add_continent("america");
	REQUIRE(themap.get_continent(2).name() == continent::null.name());
}

TEST_CASE( "null territory object" ) {
	map themap("a");
	auto continent_id = themap.add_continent("america");
	REQUIRE(
			&themap.get_continent(continent_id).get_territory(1)
					== &territory::null);
}

TEST_CASE( "continent territories" ) {
	map themap("a");
	auto continent_id = themap.add_continent("america");
	REQUIRE(themap.get_continent(continent_id).num_territories() == 0);
}

TEST_CASE( "add territory" ) {
	map themap("a");
	auto america_id = themap.add_continent("america");
	auto brazil_id = themap.add_territory(america_id, "brazil");
	REQUIRE(
			themap.get_continent(brazil_id.first).get_territory(
					brazil_id.second).name() == "brazil");
	REQUIRE(themap.get_continent(america_id).num_territories() == 1);
}

TEST_CASE( "connect territories" ) {
	map themap("a");
	auto america_id = themap.add_continent("america");
	auto brazil_id = themap.add_territory(america_id, "brazil");
	auto colombia_id = themap.add_territory(america_id, "colombia");
	themap.connect_territories(brazil_id, colombia_id);

	REQUIRE(themap.num_neighbors(brazil_id) == 1);
	REQUIRE(themap.num_neighbors(colombia_id) == 1);

	REQUIRE(
			&themap.get_neighbor(brazil_id, 0)
					== &themap.get_continent(colombia_id.first).get_territory(
							colombia_id.second));
	REQUIRE(&themap.get_neighbor(brazil_id, 1) == &territory::null);

	REQUIRE(
			&themap.get_neighbor(colombia_id, 0)
					== &themap.get_continent(brazil_id.first).get_territory(
							brazil_id.second));
	REQUIRE(&themap.get_neighbor(colombia_id, 1) == &territory::null);
}
