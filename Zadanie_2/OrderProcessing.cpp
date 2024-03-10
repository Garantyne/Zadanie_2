#include "OrderProcessing.h"
#include<iostream>
#include <algorithm>

void OrderProcessing::fulfillmentOrderVerification(std::vector<DocumentEntity> order)
{
	std::vector<DocumentEntity> completedOrder;
	for (int i = 0; i < vde.size(); i++) {
		
		for (int j = 0; j < order.size(); j++ ) {
			bool isCalcCkeck = orderCalculator(vde[i].getQuantity(),
				order[j].getQuantity(),
				vde[i].getMarks(),
				order[j].getMarks()
			);
			if (isCalcCkeck) {
				vde[i].getQuantity() -= order[j].getQuantity();
				
				DocumentEntity de;
				de.getId() = vde[i].getId();
				de.getQuantity() = order[j].getQuantity();
				de.getMarks().push_back(order[j].getMarks()[0]);
				completedOrder.push_back(de);
				order.erase(order.begin() + j);
				j = -1;
			}			
		}
	}
	if (completedOrder.size() < order.size()) {
		std::cout << "Ќе удалось собрать заказ, не все позици на складе присутствуют в необходимом колиестве" << std::endl;
	}

	/*for (auto a : completedOrder) {
		std::cout << a.ToString() << std::endl;
	}*/

}

bool OrderProcessing::checkMarksInVde(std::vector<DocumentEntity> order)
{
	for (int i = 0; i < vde.size(); i++) {
		for (int j = 0; j < order.size(); j++) {
			if (vde[i].getMarks()[i] == order[j].getMarks()[j]) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void OrderProcessing::sortVde()
{
	for (int i = 0; i < vde.size(); i++) {
		std::vector<char> tmp = vde[i].getMarks();
		int idTmp = vde[i].getId();
		int quantTmp = vde[i].getQuantity();
		for (int j = 0; j < vde.size(); j++) {
			if (vde[j].getMarks().size() > tmp.size()) {
				int idTmp2 = vde[j].getId();
				int quantTmp2 = vde[j].getQuantity();
				std::vector<char> tmp2 = vde[j].getMarks();
				vde[j].getMarks() = tmp;
				vde[i].getMarks() = tmp2;
				vde[j].getId() = idTmp;
				vde[j].getQuantity() = quantTmp;
				vde[i].getId() = idTmp2;
				vde[i].getQuantity() = quantTmp2;
				break;
			}
		}
	}
	

	for (auto d : vde) {
		std::cout << d.ToString() << std::endl;
	}
}

bool OrderProcessing::orderCalculator(int docQuant, int orderQuant,std::vector<char> docMarks, 
									std::vector<char> orderMarks)
{
	for (int i = 0; i < docMarks.size(); i++) {

		for (int j = 0; j < orderMarks.size(); j++) {
			if (docMarks[i] == orderMarks[j] && docQuant >= orderQuant) {
				return true;
			}
		}
	}
	return  false;
}


