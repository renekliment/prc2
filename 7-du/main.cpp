#include <iostream>

std::string cpplize(std::string base)
{
	std::string s_find = "Pascal";
	std::string s_replace = "C++";
	
	std::size_t len = s_find.length();
	
	std::size_t found = base.find(s_find);
	while (found != std::string::npos) {
	
		base.replace(found, len, s_replace);
		found = base.find(s_find);
		
	}
	
	return base;
	
}

using namespace std;

int main (void)
{
	string str = "Pascal je nejlepsi jazyk na svete. Nebyl Pascalu, spousta aplikaci by ani nebyla, jelikoz by nikdo nepsal v tom osklivem assembleru, ci Jave. Pascal je tedy,aPascalA je tedy nase spasa.Pascal";

	cout << str << endl << endl;
	
	cout << cpplize(str) << endl;
	
	
	return 0;
}