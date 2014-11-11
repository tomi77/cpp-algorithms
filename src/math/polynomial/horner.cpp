#include <vector>

using namespace std;

namespace math {
	namespace polynomial {
		double eval(const unsigned int n, const vector<double> &polynomial, const double x0)
		{
			return n == polynomial.size() - 1 ? polynomial[n] : polynomial[n] + eval(n + 1, polynomial, x0) * x0;
		}

		double eval(const vector<double> &polynomial, const double x0)
		{
			return eval(0, polynomial, x0);
		}
	}
}