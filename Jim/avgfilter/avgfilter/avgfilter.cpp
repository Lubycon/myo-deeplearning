#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <random>
#include <queue>
#define SIZE 10

double avgfilter(double newval, double prefilter, int valcnt)
{
	double newfilter;

	if (prefilter != 0.0)
		newfilter = prefilter * (valcnt - 1) / valcnt + newval / valcnt;
	else
		newfilter = newval;

	return newfilter;
}

double movingavgfilter(double newval, double prefilter, std::queue<double>* Q)
{
	double newfilter;
	double sumval = 0.0;
	std::queue<double> tmpQ;
	
	Q->push(newval);
	tmpQ = *Q;

	if (tmpQ.size() != SIZE)
		sumval = tmpQ.front() * (SIZE - tmpQ.size());

	while (!tmpQ.empty())
	{
		sumval += tmpQ.front();
		tmpQ.pop();
	}
	newfilter = sumval / SIZE;

	if (Q->size() == SIZE)
		Q->pop();

	return newfilter;
}

int main(int argc, char** argv)
{
	std::ofstream avgFilter;
	std::ofstream m_avgFilter;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<double> dist(0, 100);

	time_t timestamp = std::time(0);
	double avg = 0.0;
	double m_avg = 0.0;
	double value;
	int valcnt = 0;
	double avg_tick = 0.0;
	double m_avg_tick = 0.0;
	std::queue<double> Q;


	if (avgFilter.is_open()) {
		avgFilter.close();
	}
	if (m_avgFilter.is_open()) {
		m_avgFilter.close();
	}
	std::ostringstream avgFilterString;
	std::ostringstream m_avgFilterString;
	avgFilterString << "Volt_Data(average_filter)-" << timestamp << ".csv";
	m_avgFilterString << "SonarAlt_Data(moving_average_filter)-" << timestamp << ".csv";
	avgFilter.open(avgFilterString.str(), std::ios::out);
	m_avgFilter.open(m_avgFilterString.str(), std::ios::out);

	
	while(avg_tick < 10 || m_avg_tick < 10)
	{
		value = dist(eng);
		valcnt++;

		if (avg_tick < 10)
		{
			avg = avgfilter(value, avg, valcnt);
			avgFilter << avg_tick << ',' << avg << ',' << value << std::endl;
			avg_tick += 0.2;
		}

		if (m_avg_tick < 10)
		{
			m_avg = movingavgfilter(value, m_avg, &Q);
			m_avgFilter << m_avg_tick << ',' << m_avg << ',' << value << std::endl;
			m_avg_tick += 0.02;
		}
				
		
	}




	return 0;
}