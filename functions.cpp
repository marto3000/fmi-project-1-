#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//files locations: "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginPosition.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt"				!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLocationsData.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
				   
User::User()//not logged default user
{
	username = new char[13];//name length
	strcpy_s(username, 13, "default nam3");

	password = new char[17];//password length
	strcpy_s(password, 17, "default passwor1");
	
	email = new char[14];//email length;
	strcpy_s(email, 14, "default emai1");

	destCount = 1;
	//cout << username << "\n";
	//cout << password << "\n";
	//cout << email << "\n";
	//cout << destCount << "\n";
}
void User::writeUser()//for saving new users in the end of the file (after the last user)
{
	//writing the maxLeng
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::app);
	int maxLeng = strlen(username) + 1 + strlen(password) + 1 + strlen(email) + 1 + sizeof(destCount) + (3 * 4) + (4 * 2);//each char array + "\0" from each array + the destination count + every number telling the array size + every "\n"
	writeNewUser.write((char*)&maxLeng, sizeof(maxLeng));
	//writing username
	int leng = strlen(username) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(username, leng).write("\n", 1);
	//writing password
	leng = strlen(password) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(password, leng).write("\n", 1);
	//writing email
	leng = strlen(email) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(email, leng).write("\n", 1);
	//writing destCount
	writeNewUser.write((char*)&destCount, sizeof(destCount)).write("\n", 1);
	writeNewUser.close();
}
void User::giveUser(int position)//from the file
{
	while (position < 0)
	{
		//write validation later (more than -1 and less than all of the users)
	}
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::in);
	for (int i = 0; i < position; i++)//this starts to skip users from the first one
	{
		int tempLen = 0;
		giveUser.read((char*)&tempLen, sizeof(tempLen));
		int tempTellg = giveUser.tellg();
		giveUser.seekg(tempLen + tempTellg);
	}
	//skipping the maxLen variable
	int skipMaxLen = giveUser.tellg();
	skipMaxLen += 4;
	giveUser.seekg(skipMaxLen);
	//giving username
	int leng = 0;
	giveUser.read((char*)&leng, sizeof(leng));
	char* give1 = new char[leng];
	giveUser.read(give1, leng);
	cout << give1 << "\n";
	//giving password
	int pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	giveUser.read((char*)&leng, sizeof(leng));
	char* give2 = new char[leng];
	giveUser.read(give2, leng);
	cout << give2 << "\n";
	//giving email
	pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	giveUser.read((char*)&leng, sizeof(leng));
	char* give3 = new char[leng];
	giveUser.read(give3, leng);
	cout << give3 << "\n";
	//giving destCount
	pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	int give4 = 0;
	giveUser.read((char*)&give4, sizeof(give4));
	cout << give4 << "\n";

	giveUser.close();
	delete[] give1;
	delete[] give2;
	delete[] give3;
}
User::~User()
{
	delete[] username;
}