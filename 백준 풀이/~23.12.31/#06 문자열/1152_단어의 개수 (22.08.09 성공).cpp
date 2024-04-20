#include <iostream>
#include <string>

int solution(std::string text) {
    int res = 1;
    
	for (int i = 0; i < text.length(); ++i) {
		if (text[i] == ' ')
			res++;
	}

	if (text[0] == ' ') 
		res--;
	if (text[text.length() - 1] == ' ') 
		res--;

    return res;
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

	std::string text;
	getline(std::cin, text);
	
	std::cout << solution(text);

    return 0;
}