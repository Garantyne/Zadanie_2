#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>

#include "DocumentEntity.h"
#include "OrderProcessing.h"

std::vector<DocumentEntity> readFile(std::string filePath) {
	std::vector<DocumentEntity> vectorDe;
	
	std::fstream file(filePath, std::ios::in);
	if(!file.is_open()){
		std::cout << "Файл уже открыт" << std::endl;
		return vectorDe;
	}

	bool skipFirstLine = true;
	std::string line;

	while (std::getline(file, line)) {
		if (skipFirstLine) {
			skipFirstLine = false;
			continue; // Пропускаем первую строку 
		}
		std::stringstream ss(line);
		int firstColumn, secondColumn;
		char letter;
		DocumentEntity de;
		ss >> firstColumn >> secondColumn;
		de.getId() = firstColumn;
		de.getQuantity() = secondColumn;
		std::string temp;
		while (ss >> temp) { // Считываем оставшиеся значения во временную строку
			if (temp.size() > 2) {
				// Если значение содержит больше чем один символ, считаем его как последовательность букв
				for (char c : temp) {
					if (std::isalpha(c)) {
						de.setMarks(c); // Добавляем каждую букву в вектор
					}
				}
			}	
		}
		vectorDe.push_back(de);
		std::cout << line << std::endl;
	}
	file.close();
	return vectorDe;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using std::cout;
	using std::endl;
	std::vector<DocumentEntity> vde = readFile("D:\\dev\\projects_c#\\Zadanie_2\\file_1.txt");
	for (auto de : vde) {
		cout << de.ToString() << endl;
	}
	cout << endl;
	cout << endl;
	OrderProcessing op;
	op.vde = vde;
	op.sortVde();


	std::vector<DocumentEntity> completedOrder;
	DocumentEntity de;
	de.getId() = 1;
	de.getQuantity() = 2;
	de.getMarks().push_back('A');
	completedOrder.push_back(de);

	DocumentEntity deb;
	deb.getId() = 2;
	deb.getQuantity() = 2;
	deb.getMarks().push_back('B');
	completedOrder.push_back(deb);

	DocumentEntity dec;
	dec.getId() = 3;
	dec.getQuantity() = 1;
	dec.getMarks().push_back('C');
	completedOrder.push_back(dec);

	cout << endl;
	cout << endl;
	op.fulfillmentOrderVerification(completedOrder);

}
