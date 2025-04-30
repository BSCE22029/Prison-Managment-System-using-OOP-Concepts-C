#ifndef PROJECT_GROUP_HHH_CALLING_H
#define PROJECT_GROUP_HHH_CALLING_H
#pragma once
#include"standard_header.h"
#include"user_defined.h"
#include"Visitor.h"
void displayLoginManu();
char checkLogin(string password);
void displayPoliceManu(char rank);
void displayRecords(string filename);
//void calling(int op);
void judgemenu();
void usermenu();
void policeTask(int op,string id);
string incrementCode(const string& code);
void visitormenu();
void adminmenu();
extern json police_id;



#endif //PROJECT_GROUP_HHH_CALLING_H
