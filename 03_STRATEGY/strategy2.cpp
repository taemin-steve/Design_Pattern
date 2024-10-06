#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:

	std::string get_text()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter 키

			if (isdigit(c)) // 이런 validation, 제한 정책은 기존의 코드 수정없이 가능해야한다.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};











int main()
{
	Edit edit;
	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}