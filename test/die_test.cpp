#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>
#include "../src/die/die_face.h"
#include "../src/die/land_defense_die_face.h"
#include "../src/die/land_attack_die_face.h"
#include "../src/die/simple_die.h"
#include "../src/die/land_attack_die_fight.h"
#include "../src/die/land_attack_attack_die.h"
#include "../src/die/land_attack_defense_die.h"
#include "../src/die/land_attack_dice_fight.h"

TEST_CASE( "face 1" )
{
	const risk::die::die_face FACE1{1};
	risk::die::die_face face{1};
	REQUIRE( face == FACE1 );
	REQUIRE( !(face != FACE1) );
}

TEST_CASE( "face 1 different than face 2" )
{
	const risk::die::die_face FACE2{2};
	risk::die::die_face face{1};
	REQUIRE( face != FACE2 );
	REQUIRE( !(face == FACE2) );
}

TEST_CASE( "face 2 greater than face 1" )
{
	risk::die::die_face face1{1};
	risk::die::die_face face2{2};
	REQUIRE( face2 > face1 );
}

TEST_CASE( "face 1 less than face 2" )
{
	risk::die::die_face face1{1};
	risk::die::die_face face2{2};
	REQUIRE( face1 < face2 );
}

TEST_CASE( "face 3  equals face 3" )
{
	risk::die::die_face face3{3};
	risk::die::die_face faceOutro3{3};
	REQUIRE( face3 == faceOutro3 );
}

TEST_CASE( "sorting dice 1, 2 e 3" )
{
	const std::vector<risk::die::die_face> initial{3,2,1};
	const std::vector<risk::die::die_face> sorted{1,2,3};
	std::vector<risk::die::die_face> faces{initial};
	std::sort(faces.begin(), faces.end(), std::less<risk::die::die_face>());
	REQUIRE( faces == sorted );
}

TEST_CASE( "defense die wins if draw" )
{
	const risk::die::land_defense_die_face defense{3};
	const risk::die::land_attack_die_face attack{3};

	REQUIRE( defense.wins(attack) );
}

TEST_CASE( "defense die wins if the value is greater than attack" )
{
	const risk::die::land_defense_die_face defense{4};
	const risk::die::land_attack_die_face attack{3};

	REQUIRE( defense.wins(attack) );
}

TEST_CASE( "defense die loses if the value is lower than attack" )
{
	const risk::die::land_defense_die_face defense{2};
	const risk::die::land_attack_die_face attack{3};

	REQUIRE( !defense.wins(attack) );
}


TEST_CASE( "attack die wins if the value is greater than defense" )
{
	const risk::die::land_defense_die_face defense{3};
	const risk::die::land_attack_die_face attack{4};

	REQUIRE( attack.wins(defense) );
}

TEST_CASE( "attack die loses if the value is lower than defense" )
{
	const risk::die::land_defense_die_face defense{3};
	const risk::die::land_attack_die_face attack{2};

	REQUIRE( !attack.wins(defense) );
}

TEST_CASE( "atack loses wins if draw" )
{
	const risk::die::land_defense_die_face defense{3};
	const risk::die::land_attack_die_face attack{3};

	REQUIRE( !attack.wins(defense) );
}

TEST_CASE( "roll d6" )
{

	const std::vector<risk::die::die_face> faces{1, 2, 3, 4, 5, 6};
	risk::die::simple_die<risk::die::die_face> d6{faces};
	const risk::die::die_face face = d6.roll();
	REQUIRE( face >=  faces.front() );
	REQUIRE( !(face < faces.front()) );
	REQUIRE( face <=  faces.back() );
	REQUIRE( !(face > faces.back()) );
}

TEST_CASE( "die land fight attack wins" )
{

	risk::die::land_defense_die_face defense{2};
	risk::die::land_attack_die_face attack{3};
	risk::die::land_attack_die_fight fight{attack, defense};
	REQUIRE( fight.result() == risk::die::land_attack_die_fight_result::ATTACK );

}

TEST_CASE( "die land fight defense wins" )
{

	risk::die::land_defense_die_face defense{3};
	risk::die::land_attack_die_face attack{3};
	risk::die::land_attack_die_fight fight{attack, defense};
	REQUIRE( fight.result() == risk::die::land_attack_die_fight_result::DEFENSE );

}

TEST_CASE( "dice fight 3x2" )
{
	risk::die::land_attack_attack_die attack;
	risk::die::land_attack_defense_die defense;
	risk::die::land_attack_dice_fight fight{attack, 3, defense, 2};
	int count = fight.attacks() + fight.defenses();
	REQUIRE( count == 2 );
}

TEST_CASE( "dice fight 1x1" )
{
	risk::die::land_attack_attack_die attack;
	risk::die::land_attack_defense_die defense;
	risk::die::land_attack_dice_fight fight{attack, 1, defense, 1};
	int count = fight.attacks() + fight.defenses();
	REQUIRE( count == 1 );
}

TEST_CASE( "dice fight 1x2" )
{
	risk::die::land_attack_attack_die attack;
	risk::die::land_attack_defense_die defense;
	risk::die::land_attack_dice_fight fight{attack, 1, defense, 2};
	int count = fight.attacks() + fight.defenses();
	REQUIRE( count == 1 );
}

TEST_CASE( "dice fight 3x3" )
{
	risk::die::land_attack_attack_die attack;
	risk::die::land_attack_defense_die defense;
	risk::die::land_attack_dice_fight fight{attack, 3, defense, 3};
	int count = fight.attacks() + fight.defenses();
	REQUIRE( count == 3 );
}

