
#include"European_Call_P1.h"

europe_call::europe_call(double share_price0, double current_time0, double expiry_time0, double strike_price0, double volatility0, double call_price0)
	:share_price(share_price0), current_time(current_time0), expiry_time(expiry_time0), strike_price(strike_price0),volatility(volatility0),call_price(call_price0){
	//initinal the call's data
	dividend = 0;
	T = (expiry_time - current_time)/365;//calculate the expiry_time 
}
double europe_call::PriceCallAnalytic(double vol) {
	volatility = vol;
	//using b-s model to calculate the option price
	d1 = (log(share_price / strike_price) + ((interest - dividend) + 0.5*volatility*volatility)*(T)) / (volatility*sqrt(T));//calculate the d1 for further calculating the greeks 
	d2 = d1 - volatility*sqrt(T);
	double result = (share_price*(cdf(d1)) - strike_price*exp(0 - (interest - dividend)*(T))*cdf(d2))*exp(-dividend*(T));
	return result-call_price*100;
}
double europe_call::cdf(double x) {

	// get the cdf of  normoal distribution  and return the probality of x
	return (0.5*erfc(-x / sqrt(double(2))));
}

double europe_call::CallDeltaAnalytic(double vol) {
	volatility = vol;
	d1 = (log(share_price / strike_price) + ((interest - dividend) + 0.5*volatility*volatility)*(T)) / (volatility*sqrt(T));//calculate the d1 for further calculating the greeks 
	//using formula to calculate delta
	return (cdf(d1)*exp(-dividend*(T)));

}

double europe_call::CallVega(double vol)
{
	volatility = vol;
	d1 = (log(share_price / strike_price) + ((interest - dividend) + 0.5*volatility*volatility)*(T)) / (volatility*sqrt(T));//calculate the d1 for further calculating the greeks 
	double pi = 3.141592653;
	double n_d1 = exp(-d1*d1 / 2) / (sqrt(2 * pi));
	return (share_price*sqrt(T)*n_d1);
}

