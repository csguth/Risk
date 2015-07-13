/*
 * six_faces_die.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_SIMPLE_DIE_H_
#define DIE_SIMPLE_DIE_H_

#include "die_random_engine.h"
#include "die.h"
#include <vector>

namespace risk {
namespace die {

template <typename T>
class simple_die: public die<T> {
protected:
	const std::vector<T> faces_;
public:
	simple_die(const std::vector<T> faces):
		faces_(faces)
	{}
	virtual ~simple_die(){}

	const T roll()
	{
		std::uniform_int_distribution<std::size_t> distribution(0, faces_.size()-1);
		std::size_t face_index{distribution(die_random_engine::RANDOM_ENGINE)};
		return faces_.at(face_index);
	}
};



} /* namespace die */
} /* namespace risk */

#endif /* DIE_SIMPLE_DIE_H_ */
