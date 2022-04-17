#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

#pragma warning(disable:4996)
void list_univ(char path_universities[]);
void aplic(char path[], char path_univ[], char path_fac[], char path_spec[]);
void view_old(char path[]);
void statistics_menu(char* patj_univ, char* path_fac, char* path_spec, char* path_aplication);
void print_line();
void main_menu();
void arrow(int realPosition, int desiredPosition);
void universitati_side_menu(char*,char*,int,int);
void facultati_side_menu(char*,char*);
void specializari_side_menu(char*,char*);

