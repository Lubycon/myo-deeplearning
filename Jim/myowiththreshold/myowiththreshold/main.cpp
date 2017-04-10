#include "filter.h"
#include "multilayer.h"

int main(int argc, char** argv)
{
	std::ifstream fistFile;
	std::queue<int> msQ, labelQ;
	std::queue<int> emgQ[8];
	std::queue<double> RMSemgQ[8];
	Filter filter(10);

	int tmpms, tmplabel;
	int tmpemg[8];
	char delim;

	if (fistFile.is_open()) {
		fistFile.close();
	}
	fistFile.open("C:\\Users\\gjwla\\Documents\\GitHub\\study\\data\\myo\\sEMGsamples-3week(fist_weak).csv", std::ios::in);
	while (fistFile.get(delim))
		if (delim == '\n')
			break;
	while (!fistFile.eof())
	{
		fistFile >> tmpms >> delim;
		for (int i = 0;i < 8;i++)
		{
			fistFile >> tmpemg[i] >> delim;
			RMSemgQ[i].push(filter.movingavgfilter(tmpemg[i], &emgQ[i], i));
		}

		fistFile >> tmplabel;

		msQ.push(tmpms);
		labelQ.push(tmplabel);

	}
	fistFile.close();

	if (fistFile.is_open()) {
		fistFile.close();
	}
	fistFile.open("C:\\Users\\gjwla\\Documents\\GitHub\\study\\data\\myo\\sEMGsamples-3week(fist_normal).csv", std::ios::in);

	while (fistFile.get(delim))
		if (delim == '\n')
			break;
	while (!fistFile.eof())
	{
		fistFile >> tmpms >> delim;
		for (int i = 0;i < 8;i++)
		{
			fistFile >> tmpemg[i] >> delim;
			RMSemgQ[i].push(filter.movingavgfilter(tmpemg[i], &emgQ[i], i));
		}

		fistFile >> tmplabel;

		msQ.push(tmpms);
		labelQ.push(tmplabel);

	}
	fistFile.close();


	if (fistFile.is_open()) {	
		fistFile.close();
	}
	fistFile.open("C:\\Users\\gjwla\\Documents\\GitHub\\study\\data\\myo\\sEMGsamples-3week(fist_strong).csv", std::ios::in);

	while (fistFile.get(delim))
		if (delim == '\n')
			break;
	while (!fistFile.eof())
	{
		fistFile >> tmpms >> delim;
		for (int i = 0;i < 8;i++)
		{
			fistFile >> tmpemg[i] >> delim;
			RMSemgQ[i].push(filter.movingavgfilter(tmpemg[i], &emgQ[i], i));
		}

		fistFile >> tmplabel;

		msQ.push(tmpms);
		labelQ.push(tmplabel);

	}
	fistFile.close();

	return 0;
}