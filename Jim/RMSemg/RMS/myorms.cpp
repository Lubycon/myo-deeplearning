#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

class Filter{
private:
	int SIZE;
	double prefilter[8];
	double pre_front[8];
public:
	Filter(int size);
	double movingavgfilter(int newval, std::queue<int>* Q, int idx);
};

Filter::Filter(int size)
{
	memset(prefilter, 0, sizeof(prefilter));
	memset(pre_front, 0, sizeof(pre_front));
	SIZE = size;
}

double Filter::movingavgfilter(int newval, std::queue<int>* Q, int idx)
{
	double newfilter = 0.0;
	int sumval = 0;
	std::queue<int> tmpQ;

	if (newval < 0)
		newval *= -1;
	///*
	Q->push(newval);

	if (Q->size() != SIZE)
		while (Q->size() != SIZE)
			Q->push(newval);
	tmpQ = *Q;
	if (!prefilter[idx])
	{
		while (!tmpQ.empty())
		{
			sumval += tmpQ.front();
			tmpQ.pop();
		}
		newfilter = sumval / (double)SIZE;
	}
	else
		newfilter = prefilter[idx] + (newval - pre_front[idx]) / SIZE;


	
	pre_front[idx] = Q->front();
	Q->pop();


	prefilter[idx] = newfilter;
	//*/
	/*
	Q->push(newval);
	tmpQ = *Q;

	if (tmpQ.size() != SIZE)
		sumval = tmpQ.front() * (SIZE - tmpQ.size());

	while (!tmpQ.empty())
	{
		sumval += tmpQ.front();
		tmpQ.pop();
	}
	newfilter = sumval / (double)SIZE;

	if (Q->size() == SIZE)
		Q->pop();
	prefilter = newfilter;
	*/
	return newfilter;
}


int main(int argc, char** argv)
{
	std::ifstream inFile;
	std::ofstream outFile;
	std::queue<int> msQ, labelQ;
	std::queue<int> emgQ[8];
	std::queue<double> RMSemgQ[8];
	Filter filter(10);

	int tmpms, tmplabel;
	int tmpemg[8];
	char delim;

	if (inFile.is_open()) {
		inFile.close();
	}
	inFile.open("C:\\Users\\gjwla\\Documents\\GitHub\\study\\data\\myo\\sEMGsamples(waveout)-1490341675.csv", std::ios::in);
	while (inFile.get(delim))
		if (delim == '\n')
			break;
	while (!inFile.eof())
	{
		inFile >> tmpms >> delim;
		for (int i = 0;i < 8;i++)
		{
			inFile >> tmpemg[i] >> delim;
			RMSemgQ[i].push(filter.movingavgfilter(tmpemg[i], &emgQ[i], i));
		}
		inFile >> tmplabel;

		msQ.push(tmpms);
		labelQ.push(tmplabel);

	}
	inFile.close();

	if (outFile.is_open()) {
		outFile.close();
	}
	outFile.open("sEMGsamples(waveout)-1490341675RMS.csv", std::ios::out);
	
	while (!msQ.empty())
	{
		outFile << msQ.front() << ',';
		for (int i = 0;i < 8;i++)
		{
			outFile << RMSemgQ[i].front() << ',';
			RMSemgQ[i].pop();
		}
		outFile << labelQ.front() << std::endl;
		msQ.pop();
		labelQ.pop();
	}
	
	outFile.close();
	
	return 0;
}