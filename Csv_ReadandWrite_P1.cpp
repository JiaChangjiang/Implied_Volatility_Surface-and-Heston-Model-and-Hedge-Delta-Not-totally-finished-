
#include"Csv_ReadandWrite_P1.h"
using namespace std;
void ReadCsv(string Path, vector<vector<vector<double>>>& Data, vector<string> files) {
	for (int i = 0; i <int(files.size()); i++) {
		string str = "U:\\Visual Studio 2015\\Final_Project\\DAX_option_data\\";
		vector<vector<double>> OneData = {};
		str = str + files[i];
		FILE *fp;
		const char *loc = str.data();
		fopen_s(&fp, loc, "r");
		char s[300];
		fgets(s, 300, fp);
		std::cout << s << endl;
		while (fgets(s, 300, fp) != NULL) {
			float Date;
			float Opening;
			float High;
			float Low;
			float Close;
			char  volumn[20];
			sscanf_s(s, "%f,%f,%f,%f,%f,%s", &Date, &Opening, &High, &Low, &Close, volumn, 20);
			vector<double> temp = { Date, Opening, High, Low, Close };
			cout << Date << "  " << Opening << "  " << High << "   " << Low << "  " << Close << "   " << endl;
			OneData.push_back(temp);
		}
		Data.push_back(OneData);

		cout << endl;
		fclose(fp);

	}



}


void WriteCsv_IV(const vector<vector<vector<double>>>& Data, const vector<double> strike_price) {
	std::ofstream fileoutput("Data_IV.csv");
	fileoutput << " Date " << " , ";

	for (int k = 0;k < int(Data[0].size());k++) {
		fileoutput << Data[0][k][0] << " , ";
	}
	fileoutput << endl;
	for (int i = 0; i < int(Data.size() - 2);i++) {
		fileoutput << "Impiled Volatility  " << strike_price[i] << " , ";
		//fileoutput << strike_price[i] << " , ";
		for (int k = 0;k < int(Data[0].size());k++) {
			fileoutput << Data[i][k][5] << " , ";
		}
   fileoutput<< endl;
		
	}
	fileoutput.close();
}
void WriteCsv(const vector<vector<vector<double>>>& Data,const vector<double> strike_price) {
	std::ofstream fileoutput("Data.csv");
	fileoutput << " Date " << " , " << " Opening " << " , " << "High" << " , " << "Low" << " , " << "Close" << " , "
		<< "Impiled Volatility" << " , " << " Delta " << " , " << " Portfolio_Value" << " , " << " DAX " << endl;

	for (int i = 0;i < int(Data.size() - 2);i++) {
		fileoutput << strike_price[i] << endl;
		for (int j = 0;j < int(Data[i].size()); j++) {
			for (int k = 0;k < int(Data[i][j].size());k++) {
				fileoutput << Data[i][j][k] << " , ";
			}
			fileoutput << endl;
		}
	}
	fileoutput.close();




}