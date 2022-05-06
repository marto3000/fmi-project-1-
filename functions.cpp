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
void User::giveUser(char* name, char* pass)//from the file
{
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::in);
	//searching for user's email
	int leng;
	int skip;
	for (bool i = false; i == false; i = i)
	{
		giveUser.read((char*)&skip, sizeof(skip));
		//when the end of the file is reached
		if (giveUser.tellg() < 0)
		{
			cout << "Wrong email or password.ne";
			i = true;
		}
		else
		{
			int skipFrom = giveUser.tellg();
			giveUser.read((char*)&leng, sizeof(leng));
			//checking the email
			if (leng == strlen(name) + 1)
			{
				char* give1 = new char[leng];
				giveUser.read(give1, leng);
				for (int charPos = 0; charPos < leng; charPos++)
				{
					//on first wrong char
					if (give1[charPos] != name[charPos])
					{
						giveUser.seekg(skipFrom + skip);
						charPos = leng;
						delete[] give1;
					}
					//checking the password if the email is correct (must be after the "on first wrong letter")
					if (charPos == leng - 1)
					{
						i = true;
						int leng2;
						int pos = giveUser.tellg();
						pos += 2;
						giveUser.seekg(pos);//skipping "\n"
						giveUser.read((char*)&leng2, sizeof(leng2));
						if (leng2 == strlen(pass) + 1)
						{
							char* give2 = new char[leng2];
							giveUser.read(give2, leng2);
							for (int charPos2 = 0; charPos2 < leng2; charPos2++)
							{
								//on first wrong char
								if (give2[charPos2] != pass[charPos2])
								{
									charPos2 = leng2;
									delete[] give2;
									//wrong password
									cout << "Wrong email or password.";
								}
								//if the password is correct
								if (charPos2 == leng2 - 1)
								{
									//giving email
									cout << give1 << "\n";//comment or delete later
									//giving password
									cout << give2 << "\n";//comment or delete later
									//giving username
									pos = giveUser.tellg();
									pos += 2;
									giveUser.seekg(pos);
									giveUser.read((char*)&leng2, sizeof(leng2));
									char* give3 = new char[leng2];
									giveUser.read(give3, leng2);
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
						//shorter/longer password
						else
						{
							cout << "Wrong email or password.pl";
						}
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