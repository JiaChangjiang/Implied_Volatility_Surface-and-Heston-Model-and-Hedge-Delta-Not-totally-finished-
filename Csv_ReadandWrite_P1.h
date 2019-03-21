#pragma once
#include<iostream>
#include<vector>
#include <fstream>
#include<string>
using namespace std;

void ReadCsv(string Path, vector<vector<vector<double>>>& Data, vector<string> files);

void WriteCsv(const vector<vector<vector<double>>>& Data, vector<double> strike_price);

void WriteCsv_IV(const vector<vector<vector<double>>>& Data, const vector<double> strike_price);