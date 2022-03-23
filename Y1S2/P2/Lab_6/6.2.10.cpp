
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#pragma warning(disable:4996)
#define MAX_SIZE 256

void modificareData(char * str) {
	char* day = new char[2];
	char* month = new char[2];
	char* year = new char[4];
	strncpy(day, str, strchr(str, '/') - str);
	day[strchr(str, '/') - str] = '\0';
	str = strchr(str, '/') + 1;

	strncpy(month, str, strchr(str, '/') - str);
	month[strchr(str, '/') - str] = '\0';
	str = strchr(str, '/') + 1;

	strncpy(year, str, strlen(str));
	year[strlen(str)] = '\0';

	std::stringstream geek(day);

	int dayInteger = 0;
	geek >> dayInteger;

	printf("%s-%d-%s", month, dayInteger  + 5, year);
}

//char* modificareData(char * str,int day, int year) {
//
//}
//
//char* modificareData(int month, int day ,int year) {
//
//}

int main()
{
	char data[12];
	std::cin.getline(data,256);
	modificareData(data);
}
