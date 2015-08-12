#include <catch/catch.hpp>
#include "../src/map/map.h"
#include "../src/domination/conquerable_map.h"
#include "../src/player/player.h"

#include  <algorithm>

#include  <memory>

using map = risk::map::map;
using player = risk::player::player;
using lobby = risk::player::lobby;

// some helper functions
std::unique_ptr<map> create_earth() {
	risk::map::map earth("earth");
	auto america_id = earth.add_continent("america");
	auto africa_id = earth.add_continent("africa");
	auto asia_id = earth.add_continent("asia");

	auto brazil_id = earth.add_territory(america_id, "brazil");
	auto colombia_id = earth.add_territory(america_id, "colombia");
	auto nigeria_id = earth.add_territory(africa_id, "nigeria");
	auto egypt_id = earth.add_territory(africa_id, "egypt");
	auto middle_east_id = earth.add_territory(asia_id, "middle east");

	earth.connect_territories(brazil_id, colombia_id);
	earth.connect_territories(brazil_id, nigeria_id);
	earth.connect_territories(nigeria_id, egypt_id);
	earth.connect_territories(egypt_id, middle_east_id);
	return std::unique_ptr<map>(new risk::map::map(earth));
}

std::unique_ptr<lobby> create_lobby(player::id &csguth_id,
		player::id &other_id) {
	lobby my_lobby;
	csguth_id = my_lobby.register_player("csguth");
	other_id = my_lobby.register_player("other");
	return std::unique_ptr<lobby>(new lobby(my_lobby));
}

std::unique_ptr<lobby> create_lobby(player::id &csguth_id) {
	player::id other_id;
	return create_lobby(csguth_id, other_id);
}

std::unique_ptr<lobby> create_lobby(void) {
	player::id csguth_id;
	player::id other_id;
	return create_lobby(csguth_id, other_id);
}

TEST_CASE( "conquerable map construction" ) {
	auto earth = create_earth();
	auto lobby = create_lobby();
	risk::domination::conquerable_map map(*earth, *lobby);
}

TEST_CASE( "territory without player" ) {
	auto earth = create_earth();
	auto lobby = create_lobby();
	risk::domination::conquerable_map map(*earth, *lobby);

	risk::map::continent_territory_id territory_id(0, 0);
	REQUIRE(map.owner(territory_id) == std::numeric_limits<player::id>::max());
}

TEST_CASE( "conquest empty territory" ) {
	auto earth = create_earth();
	player::id csguth_id;
	auto lobby = create_lobby(csguth_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	REQUIRE_NOTHROW(map.assign_territory_to_player(csguth_id, territory_id, 5));
	REQUIRE(map.territories(csguth_id).size() == 1);
	auto the_territory = *map.territories(csguth_id).find(territory_id);
	REQUIRE(the_territory == territory_id);
	REQUIRE(map.owner(territory_id) == csguth_id);
}

TEST_CASE( "conquest territory from other player" ) {
	auto earth = create_earth();
	player::id csguth_id;
	player::id other_id;
	auto lobby = create_lobby(csguth_id, other_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	map.assign_territory_to_player(csguth_id, territory_id, 1);
	map.assign_territory_to_player(other_id, territory_id, 1);

	REQUIRE(map.owner(territory_id) == other_id);
	REQUIRE(map.territories(csguth_id).empty());
	REQUIRE(map.territories(other_id).size() == 1);
}

TEST_CASE( "empty territory army size" ) {
	auto earth = create_earth();
	auto lobby = create_lobby();
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);
	REQUIRE(map.army_size(territory_id) == 0);
}

TEST_CASE( "try to add army into an empty territory" ) {
	auto earth = create_earth();
	auto lobby = create_lobby();
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);
	REQUIRE(!map.add_army(territory_id));
}

TEST_CASE( "try to remove army of an empty territory" ) {
	auto earth = create_earth();
	auto lobby = create_lobby();
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);
	REQUIRE(!map.remove_army(territory_id));
}

TEST_CASE( "army size" ) {

	auto earth = create_earth();
	player::id csguth_id;
	auto lobby = create_lobby(csguth_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	const std::size_t ARMY_SIZE = 5;
	map.assign_territory_to_player(csguth_id, territory_id, ARMY_SIZE);

	REQUIRE( map.army_size(territory_id) == ARMY_SIZE );

}

TEST_CASE( "add army" ) {

	auto earth = create_earth();
	player::id csguth_id;
	auto lobby = create_lobby(csguth_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	const std::size_t ARMY_SIZE = 5;
	map.assign_territory_to_player(csguth_id, territory_id, ARMY_SIZE);

	REQUIRE( map.add_army(territory_id) );
	REQUIRE( map.army_size(territory_id) == ARMY_SIZE + 1 );

}

TEST_CASE( "remove army" ) {

	auto earth = create_earth();
	player::id csguth_id;
	auto lobby = create_lobby(csguth_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	const std::size_t ARMY_SIZE = 5;
	map.assign_territory_to_player(csguth_id, territory_id, ARMY_SIZE);

	REQUIRE( map.remove_army(territory_id) );
	REQUIRE( map.army_size(territory_id) == ARMY_SIZE - 1 );

}

TEST_CASE( "remove army from a territory with size = 1" ) {

	auto earth = create_earth();
	player::id csguth_id;
	auto lobby = create_lobby(csguth_id);
	risk::domination::conquerable_map map(*earth, *lobby);
	risk::map::continent_territory_id territory_id(0, 0);

	map.assign_territory_to_player(csguth_id, territory_id, 1);
	map.remove_army(territory_id);
	REQUIRE( map.army_size(territory_id) == 0 );
	REQUIRE( !map.remove_army(territory_id) );
	REQUIRE( map.army_size(territory_id) == 0 );

}


