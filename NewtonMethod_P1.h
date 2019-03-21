#pragma once
#include<cmath>
#include<functional>
using namespace std;
class Newton {
public:
	Newton(function<double(double)> fp0_y0, function<double(double)> fp1_y10, double error_check0, int iter0);
	double newton();
	//friend double NumericalDifferentiation(double x);
private:
	function<double(double)> fp0_y ;
	function<double(double)> fp1_y1 ;
	//double(*fp0_y)(double) = nullptr;
	//double(*fp1_y1)(double) = nullptr;
	double error_check;
	int iter;
};
