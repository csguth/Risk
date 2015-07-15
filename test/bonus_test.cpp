#include <catch/catch.hpp>
#include "../src/domination/conqueror_player.h"
#include "../src/bonus/round_bonus.h"
#include "../src/bonus/full_continent_bonus.h"
#include "../src/map/continent.h"

typedef risk::domination::conqueror_player conqueror_player;
typedef risk::domination::conquerable_territory conquerable_territory;
typedef risk::map::continent continent;

TEST_CASE( "round bonus has size at least = 3", "[bonus][round_bonus]")
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};
	risk::bonus::round_bonus bonus(john);
	REQUIRE( bonus.size() == 3 );
}

TEST_CASE( "round bonus: player gets half of conquested territories", "[bonus][round_bonus]" )
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};
	std::shared_ptr<conqueror_player> alice{new conqueror_player{"alice"}};

	std::shared_ptr<conquerable_territory> brasil{new conquerable_territory{"Brasil"}};
	std::shared_ptr<conquerable_territory> argelia{new conquerable_territory{"Argélia/Nigéria"}};
	std::shared_ptr<conquerable_territory> egito{new conquerable_territory{"Egito"}};
	std::shared_ptr<conquerable_territory> oriente_medio{new conquerable_territory{"Oriente Médio"}};
	std::shared_ptr<conquerable_territory> japao{new conquerable_territory{"Japão"}};
	std::shared_ptr<conquerable_territory> china{new conquerable_territory{"China"}};
	std::shared_ptr<conquerable_territory> vladivostok{new conquerable_territory{"Vladivostok"}};
	std::shared_ptr<conquerable_territory> alaska{new conquerable_territory{"Alaska"}};

	john->conquest(brasil);
	john->conquest(argelia);
	john->conquest(egito);
	john->conquest(oriente_medio);
	john->conquest(japao);
	john->conquest(china);
	john->conquest(vladivostok);
	john->conquest(alaska);

	risk::bonus::round_bonus bonus(john);
	REQUIRE( bonus.size() == 4 );

	alice->conquest(alaska);

	risk::bonus::round_bonus bonus2(john);
	REQUIRE( bonus2.size() == 3 );
}

TEST_CASE( "apply round bonus", "[bonus][round_bonus]" )
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};

	std::shared_ptr<conquerable_territory> brasil{new conquerable_territory{"Brasil"}};
	std::shared_ptr<conquerable_territory> argelia{new conquerable_territory{"Argélia/Nigéria"}};
	std::shared_ptr<conquerable_territory> egito{new conquerable_territory{"Egito"}};
	std::shared_ptr<conquerable_territory> oriente_medio{new conquerable_territory{"Oriente Médio"}};
	std::shared_ptr<conquerable_territory> japao{new conquerable_territory{"Japão"}};
	std::shared_ptr<conquerable_territory> china{new conquerable_territory{"China"}};
	std::shared_ptr<conquerable_territory> vladivostok{new conquerable_territory{"Vladivostok"}};
	std::shared_ptr<conquerable_territory> alaska{new conquerable_territory{"Alaska"}};
	std::shared_ptr<conquerable_territory> ottawa{new conquerable_territory{"Ottawa"}};

	john->conquest(brasil);
	john->conquest(argelia);
	john->conquest(egito);
	john->conquest(oriente_medio);
	john->conquest(japao);
	john->conquest(china);
	john->conquest(vladivostok);
	john->conquest(alaska);

	risk::bonus::round_bonus bonus(john);
	REQUIRE_THROWS_AS( bonus.apply(ottawa), std::out_of_range );
	REQUIRE( bonus.size() == 4 );

	REQUIRE( bonus.apply(brasil) );
	REQUIRE( bonus.size() == 3);

	REQUIRE( brasil->army_size() == 2 );

}

TEST_CASE( "can't apply round bonus with size = 0", "[bonus][round_bonus]" )
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};
	std::shared_ptr<conquerable_territory> brasil{new conquerable_territory{"Brasil"}};
	john->conquest(brasil);
	
	risk::bonus::round_bonus bonus(john);
	REQUIRE( bonus.size() == 3 );
	REQUIRE( bonus.apply(brasil) ); // = 3
	REQUIRE( bonus.apply(brasil) ); // = 2
	REQUIRE( bonus.apply(brasil) ); // = 1
	REQUIRE( bonus.size() == 0 );
	REQUIRE( brasil->army_size() == 4 );
	REQUIRE( !bonus.apply(brasil) );
	REQUIRE( brasil->army_size() == 4 );
}

TEST_CASE( "full continent bonus if player doesn't have the full continent", "[bonus][round_bonus]" )
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};
	std::shared_ptr<conquerable_territory> brasil{new conquerable_territory{"Brasil"}};
	std::shared_ptr<conquerable_territory> argentina{new conquerable_territory{"Argentina"}};
	std::shared_ptr<conquerable_territory> colombia{new conquerable_territory{"Colômbia"}};

	std::shared_ptr<continent> america_do_sul{new continent{"América do Sul"}};

	america_do_sul->add_territory(brasil);
	america_do_sul->add_territory(argentina);
	america_do_sul->add_territory(colombia);

	john->conquest(brasil);
	john->conquest(argentina);
	// john->conquest(colombia);

	risk::bonus::full_continent_bonus bonus(america_do_sul, john);
	REQUIRE( bonus.size() == 0 );

}

TEST_CASE( "full continent bonus if player HAS the full continent", "[bonus][round_bonus]" )
{
	std::shared_ptr<conqueror_player> john{new conqueror_player{"john"}};
	std::shared_ptr<conquerable_territory> brasil{new conquerable_territory{"Brasil"}};
	std::shared_ptr<conquerable_territory> argentina{new conquerable_territory{"Argentina"}};
	std::shared_ptr<conquerable_territory> colombia{new conquerable_territory{"Colômbia"}};

	std::shared_ptr<conquerable_territory> argelia{new conquerable_territory{"Argélia/Nigéria"}};

	std::shared_ptr<continent> america_do_sul{new continent{"América do Sul"}};
	std::shared_ptr<continent> africa{new continent{"África"}};

	africa->add_territory(argelia);

	america_do_sul->add_territory(brasil);
	america_do_sul->add_territory(argentina);
	america_do_sul->add_territory(colombia);

	john->conquest(brasil);
	john->conquest(argentina);
	john->conquest(colombia);

	john->conquest(argelia);

	risk::bonus::full_continent_bonus bonus(america_do_sul, john);
	REQUIRE( bonus.size() == 2 );

	REQUIRE_NOTHROW( bonus.apply(brasil) );
	REQUIRE( bonus.size() == 1 );
	REQUIRE_NOTHROW( bonus.apply( argentina ) );
	REQUIRE_THROWS_AS (bonus.apply( argelia ), std::out_of_range );

	REQUIRE( brasil->army_size() == 2 );
	REQUIRE( argentina->army_size() == 2 );
	REQUIRE( colombia->army_size() == 1 );
	REQUIRE( argelia->army_size() == 1 );

	REQUIRE( bonus.size() == 0 );



}
