/*
 * dice_fight.cpp
 *
 *  Created on: 12 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_dice_fight.h"

namespace risk {
namespace die {

land_attack_dice_fight::land_attack_dice_fight(
        land_attack_attack_die & attack_die, int attack_size,
        land_attack_defense_die & defense_die, int defense_size) :
        attacks_(0), defenses_(0) {
    std::vector<land_attack_die_face> attacks;
    for (int i = 0; i < attack_size; i++)
        attacks.push_back(attack_die.roll());

    std::vector<land_defense_die_face> defenses;
    for (int i = 0; i < defense_size; i++)
        defenses.push_back(defense_die.roll());

    std::sort(attacks.begin(), attacks.end(),
            std::greater<land_attack_die_face>());
    std::sort(defenses.begin(), defenses.end(),
            std::greater<land_defense_die_face>());

    for (std::size_t i = 0; i < std::min(attacks.size(), defenses.size()); i++)
        fights_.push_back(land_attack_die_fight(attacks.at(i), defenses.at(i)));

    attacks_ = std::count_if(fights_.begin(), fights_.end(), attack_wins());
    defenses_ = std::count_if(fights_.begin(), fights_.end(), defense_wins());
}

land_attack_dice_fight::~land_attack_dice_fight() {
}

bool defense_wins::operator ()(const land_attack_die_fight& a) {
    return a.result() == land_attack_die_fight_result::DEFENSE;
}

bool attack_wins::operator ()(const land_attack_die_fight& a) {
    return a.result() == land_attack_die_fight_result::ATTACK;
}

} /* namespace die */
} /* namespace risk */

