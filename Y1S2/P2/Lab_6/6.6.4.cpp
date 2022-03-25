
#include <iostream>
#include <cmath>
#include <cstring>
#pragma warning(disable:4996)
#define MAX_SIZE 256

char* strrstr(const char* str, const char* strSearch)
{
    char* ptr, * last = NULL;
    ptr = (char*)str;
    while ((ptr = strstr(ptr, strSearch))) last = ptr++;
    return last;
}

char* deleteGroup(char arr[], char group[]) {
    char arr_copy[MAX_SIZE];
    strcpy(arr_copy, arr);
    int index = strrstr(arr_copy, group) - arr_copy;
    strcpy(arr_copy + index, arr_copy + index + strlen(group));
    std::cout << arr_copy << '\n';
    return arr_copy;
}

char* deleteGroup(char arr[], char group[], int n) {
    char arr_copy[MAX_SIZE];
    strcpy(arr_copy, arr);

    for (int i = 1; i <= n; i++) {
        int index = strrstr(arr_copy, group) - arr_copy;
        strcpy(arr_copy + index, arr_copy + index + strlen(group));
    }
    std::cout << arr_copy;
    return arr_copy;
}

int main()
{
    char mini_str[MAX_SIZE], long_str[MAX_SIZE];
    int num;
    std::cin >> mini_str >> num >> long_str;
    deleteGroup(long_str, mini_str);
    deleteGroup(long_str, mini_str, num);
}





