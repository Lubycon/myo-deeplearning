#include "filter.h"

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

double Filter::movingavgfilter(double newval, std::queue<double>* Q, int idx)
{
	double newfilter = 0.0;
	int sumval = 0;
	std::queue<double> tmpQ;

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