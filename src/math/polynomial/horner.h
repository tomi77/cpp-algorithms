#ifndef MATH_POLYMONIAL_HORNER_H
#define MATH_POLYMONIAL_HORNER_H

#include <vector>

namespace math {
	namespace polynomial {
		double eval(const std::vector<double> &polynomial, const double x0);
	}
}

#endif // MATH_POLYMONIAL_HORNER_H