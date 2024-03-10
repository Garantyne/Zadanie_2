#pragma once
#include <vector>
#include <string>
class DocumentEntity
{
private:
	int id;
	int quantity;
	std::vector<char> marks;

public:
	DocumentEntity() {}

	int& getId() { return id; }
	int& getQuantity() { return quantity; }

	std::vector<char>& getMarks() { return marks; }
	void setMarks(char c) { marks.push_back(c); }
	
	std::string ToString();
};

