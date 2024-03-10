#pragma once
#include <vector>
#include "DocumentEntity.h"
class OrderProcessing
{
public:
	std::vector<DocumentEntity> vde;
public:
	OrderProcessing() {}

	void fulfillmentOrderVerification(std::vector<DocumentEntity> order);

	bool checkMarksInVde(std::vector<DocumentEntity> order);

	void sortVde();

	bool orderCalculator(int docQuant, int orderQuant, std::vector<char> docMarks,
		std::vector<char> orderMarks);

	

	std::vector<DocumentEntity> getVde() { return vde; }

};

