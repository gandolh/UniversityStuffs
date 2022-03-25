
#include <iostream>
#include <cmath>
#include <cstring>
#pragma warning(disable:4996)
#define MAX_SIZE 256

char* toLower(char* s) {
    for (char* p = s; *p; p++) *p = tolower(*p);
    return s;
}

int main()
{
    char mini_str[MAX_SIZE], long_str[MAX_SIZE];
    int num;
    std::cin >> mini_str >> num;
    std::cin.get();
    for (int i = 0; i < num; i++) {
        std::cin.getline(long_str, 256);
        int count = 0;
        char* p = (char*)malloc(sizeof(char) * MAX_SIZE);
        strcpy(p, long_str);
        for (; p; p = strstr(toLower(p) + strlen(mini_str), toLower(mini_str)))
            count++;
        if (count >= 2)std::cout << long_str << "\n";
    }
}
