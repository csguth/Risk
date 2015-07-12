/*
 * six_faces_die.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_SIX_FACES_DIE_H_
#define DIE_SIX_FACES_DIE_H_

#include "die.h"
#include <vector>
#include <random>

namespace risk {
namespace die {

template <typename T>
class six_faces_die: public die<T> {
	std::default_random_engine random_engine_;
protected:
	const std::vector<T> faces_;
public:
	six_faces_die(const std::vector<T> faces):
		random_engine_(time(NULL)),
		faces_(faces)
	{}
	virtual ~six_faces_die(){}

	const T roll()
	{
		std::uniform_int_distribution<std::size_t> distribution(0, faces_.size()-1);
		std::size_t face_index{distribution(random_engine_)};
		return faces_.at(face_index);
	}

};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_SIX_FACES_DIE_H_ */
