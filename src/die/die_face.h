/*
 * die_face.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_DIE_FACE_H_
#define DIE_DIE_FACE_H_

namespace risk {
namespace die {

typedef int die_face_value;

class die_face {
protected:
	die_face_value value_;
public:
	die_face(die_face_value value);
	virtual ~die_face();

	bool operator>(const die_face & o) const;
	bool operator<(const die_face & o) const;
	bool operator==(const die_face & o) const;
	bool operator!=(const die_face & o) const;
	bool operator>=(const die_face & o) const;
	bool operator<=(const die_face & o) const;

	virtual bool wins(const die_face & o) const;
	inline die_face_value value() const { return value_; }
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_DIE_FACE_H_ */
