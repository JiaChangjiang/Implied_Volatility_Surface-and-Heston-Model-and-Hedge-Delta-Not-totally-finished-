#pragma once
#include<cmath>
const double interest = 0.004;

class europe_call {
public:
	europe_call(double share_price0, double current_time0, double expiry_time0, double strike_price0,double volatility0,double call_price0);
	double cdf(double x);
	double PriceCallAnalytic(double vol);
	double CallDeltaAnalytic(double vol);
	double CallVega(double vol);
private:
	double call_price;
	double share_price;
	double current_time;
	double expiry_time;
	double strike_price;
	double volatility;
	double  dividend=0;
	double T;
	double d1;
	double d2;
};
