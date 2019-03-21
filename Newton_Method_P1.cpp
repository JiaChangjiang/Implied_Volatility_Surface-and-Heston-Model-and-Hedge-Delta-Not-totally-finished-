
#include"NewtonMethod_P1.h"
#include"European_Call_P1.h"
#include <functional>  

Newton::Newton(std::function<double(double)> fp0_y0, std::function<double(double)> fp1_y10, double error_check0, int iter0)
		:fp0_y(fp0_y0), fp1_y1(fp1_y10), error_check(error_check0), iter(iter0) {}


double Newton::newton() {
	double x = 0.5;
	for (int i = 0;i<iter;i++) {
		double error = fp0_y(x) / fp1_y1(x);
		if (abs(fp0_y(x) / fp1_y1(x)) < error_check) {
			return x;
			break;
		}
		x = x - (fp0_y(x) / fp1_y1(x));
	
	}
	return x;
}
