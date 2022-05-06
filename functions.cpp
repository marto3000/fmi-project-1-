#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//files locations: "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginPosition.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt"				!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLocationsData.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
				   
User::User()//not logged default user
{
	email = new char[14];//email length;
	strcpy_s(email, 14, "default emai4");

	password = new char[17];//password length
	strcpy_s(password, 17, "default passwor4");
	
	username = new char[13];//name length
	strcpy_s(username, 13, "default nam4");

	destCount = 4;

	//cout << email << "\n";
	//cout << password << "\n";
	//cout << username << "\n";
	//cout << destCount << "\n";
}
void User::writeUser()//for saving new users in the end of the file (after the last user)
{
	//writing the maxLeng
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::app);
	int maxLeng = strlen(username) + 1 + strlen(password) + 1 + strlen(email) + 1 + sizeof(destCount) + (3 * 4) + (4 * 2);//each char array + "\0" from each array + the destination count + every number telling the array size + every "\n"
	writeNewUser.write((char*)&maxLeng, sizeof(maxLeng));
	//writing email
	int leng = strlen(email) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(email, leng).write("\n", 1);
	//writing password
	leng = strlen(password) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(password, leng).write("\n", 1);
	//writing username
	leng = strlen(username) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(username, leng).write("\n", 1);
	//writing destCount
	writeNewUser.write((char*)&destCount, sizeof(destCount)).write("\n", 1);
	writeNewUser.close();
}
void User::giveUser(char* name)//from the file
{
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::in);
	//searching for user
	int leng;
	int skip;
	for (bool i = false; i == false; i = i)
	{
		giveUser.read((char*)&skip, sizeof(skip));
		if (giveUser.tellg() < 0)
		{
			i = true;
			cout << "no";//comment or delete later
		}
		else
		{
			int skipFrom = giveUser.tellg();
			giveUser.read((char*)&leng, sizeof(leng));
			if (leng == strlen(name) + 1)
			{
				char* give1 = new char[leng];
				giveUser.read(give1, leng);
				for (int pos = 0; pos < leng; pos++)
				{
					if (give1[pos] != name[pos])
					{
						giveUser.seekg(skipFrom + skip);
						pos = leng;
					}
					if (pos == leng - 1)
					{
						i = true;
						//giving email
						cout << give1 << "\n";//comment or delete later
						//giving password
						int pos = giveUser.tellg();
						pos += 2;
						giveUser.seekg(pos);
						giveUser.read((char*)&leng, sizeof(leng));
						char* give2 = new char[leng];
						giveUser.read(give2, leng);
						cout << give2 << "\n";//comment or delete later
						//giving username
						pos = giveUser.tellg();
						pos += 2;
						giveUser.seekg(pos);
						giveUser.read((char*)&leng, sizeof(leng));
						char* give3 = new char[leng];
						giveUser.read(give3, leng);
						cout << give3 << "\n";//comment or delete later
						//giving destCount
						pos = giveUser.tellg();
						pos += 2;
						giveUser.seekg(pos);
						int give4 = 0;
						giveUser.read((char*)&give4, sizeof(give4));
						cout << give4 << "\n";//comment or delete later

						delete[] give1;
						delete[] give2;
						delete[] give3;
					}
				}
			}
			else
			{
				giveUser.seekg(skipFrom + skip);
			}
		}
	}
}
User::~User()
{
	delete[] username;
}