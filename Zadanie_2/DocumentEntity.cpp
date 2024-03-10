#include "DocumentEntity.h"

std::string DocumentEntity::ToString()
{
	std::string str;
	for (int i = 0;i < marks.size(); i++) {		
		str.push_back(marks[i]);
		if (i < marks.size() - 1) {
			str.push_back(' ');
		}		
	}
	return std::to_string(id) + " - " + std::to_string(quantity) + " - " + str;
}
