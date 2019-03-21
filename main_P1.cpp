#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include"European_Call_P1.h"
#include"NewtonMethod_P1.h"
#include <functional>  
#include"Csv_ReadandWrite_P1.h"
using namespace std;

int main() {
	//const double interest = 0.004;
	const double Expiry = 44092;//18/9/2020
	vector<string> files = { "18092020_DAX_10700.csv","18092020_DAX_10750.csv","18092020_DAX_10800.csv","18092020_DAX_10850.csv",
"18092020_DAX_10900.csv","18092020_DAX_11100.csv","18092020_DAX_11400.csv","18092020_DAX_12200.csv","18092020_DAX_12550.csv",
"18092020_DAX_13750.csv","18092020_DAX_16000.csv","18092020_DAX_9100.csv","18092020_DAX_9500.csv","18092020_DAX_9800.csv","DAX - longer.csv","DAX.csv" };
	vector<vector<vector<double>>> Data = {};
	vector<double> strike_price = { 10700,10750,10800,10850,10900,11100,11400,12200,12550,13750,16000,9100,9500,9800 };
	string Path = "U:\\Visual Studio 2015\\Final_Project\\DAX_option_data\\";
	ReadCsv(Path, Data, files);
	for (int i = 0;i <int( files.size()-2);i++) {
		double strike_price0 = strike_price[i];
		for (int j = 0;j < 60;j++) {
			double Call_Price = Data[i][j][4];//call price
			double s0 = Data.back()[j][4];//share price
			double Date = Data.back()[j][0];
			double Date1 = Data[i][j][0];
			if (Date != Date1) { 
				cout << "the Date is wrong" << endl;
				return 0;
			}
			europe_call call1(s0, Date, Expiry, strike_price0, 0, Call_Price);
			function<double(double)> f = bind(&europe_call::PriceCallAnalytic, &call1, placeholders::_1);
			function<double(double)> f0 = bind(&europe_call::CallVega, &call1, placeholders::_1);
			Newton newton1(f, f0, 0.000001, 50);
			double result = newton1.newton();
			cout << result<<"   ";
			Data[i][j].push_back(result);
			Data[i][j].push_back(call1.CallDeltaAnalytic(result));
		}
	}

	WriteCsv(Data, strike_price);
	WriteCsv_IV(Data, strike_price);
	//calcualte portfolio
	vector<double> portfolio = {};
	for (int i = 0;i < int(Data.size() - 2);i++) {
		for (int j = 1;j < int(Data[i].size()); j++) {
			int size = int (Data[i].size());
			double Call_Previous_Price= Data[i][size - j][4];
			double Call_Price = Data[i][size-j-1][4];
			double Call_Previous_Delta = Data[i][size-j][6];
			double s0 = Data.back()[size-j][4];//share price
			double s1 = Data.back()[size - j - 1][4];
			double PortfolioValue = 100*(Call_Price - Call_Previous_Price)- Call_Previous_Delta*(s1-s0);
			Data[i][size - j - 1].push_back(PortfolioValue);
			Data[i][size - j - 1].push_back(s1);
		
		
		}
	}

	
	WriteCsv(Data, strike_price);


	return 0;
}
