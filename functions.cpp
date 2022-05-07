#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//files locations: "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginPosition.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt"				!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLocationsData.txt"			!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
				   
User::User()//not logged default user
{
	email = new char[15];//email length;
	strcpy_s(email, 15, "default_email5");

	password = new char[18];//password length
	strcpy_s(password, 18, "default_password5");
	
	username = new char[14];//name length
	strcpy_s(username, 14, "default_name5");

	destCount = 5;

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
void User::login()
{
	bool isLogged = false;//default_email1 default_password1
	while (isLogged == false)
	{
		char* getEmail = new char[1024];
		char* getPass = new char[1024];
		cout << "Enter your email and password: ";
		cin >> getEmail;
		cin >> getPass;
		getPass[strlen(getPass)] = '\0';
		char* email = new char[strlen(getEmail) + 1];
		strcpy_s(email, strlen(getEmail) + 1, getEmail);
		email[strlen(getEmail)] = '\0';
		char* pass = new char[strlen(getPass) + 1];
		strcpy_s(pass, strlen(getPass) + 1, getPass);
		pass[strlen(getPass)] = '\0';
		delete[] getEmail;
		delete[] getPass;
		isLogged = giveUser(email, pass);
		delete[] email;
		delete[] pass;
		if (isLogged == false)
		{
			int tryAgain = 0;
			while (tryAgain > 2 || tryAgain < 1)
			{
				cout << "\nTry again?\n";
				cout << "1 - yes\n";
				cout << "2 - no\n";
				cin >> tryAgain;
			}
			if (tryAgain == 2)
			{
				isLogged = true;//not actually logged
			}
		}
	}
}
bool User::giveUser(char* name, char* pass)//from the file
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
			cout << "Wrong email or password.";
			i = true;
			return false;
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
									return false;
								}
								//if the password is correct
								if (charPos2 == leng2 - 1)
								{
									//giving email
									email = new char[strlen(give1) + 1];
									strcpy_s(email, strlen(give1) + 1, give1);
									email[strlen(give1)] = '\0';
									//cout << email << "\n";//comment or delete later
									//giving password
									password = new char[strlen(give2) + 1];
									strcpy_s(password, strlen(give2) + 1, give2);
									password[strlen(give2)] = '\0';
									//cout << password << "\n";//comment or delete later
									//giving username
									pos = giveUser.tellg();
									pos += 2;
									giveUser.seekg(pos);
									giveUser.read((char*)&leng2, sizeof(leng2));
									char* give3 = new char[leng2];
									giveUser.read(give3, leng2);
									username = new char[strlen(give3) + 1];
									strcpy_s(username, strlen(give3) + 1, give3);
									username[strlen(give3)] = '\0';
									//cout << username << "\n";//comment or delete later
									//giving destCount
									pos = giveUser.tellg();
									pos += 2;
									giveUser.seekg(pos);
									int give4 = 0;
									giveUser.read((char*)&give4, sizeof(give4));
									destCount = give4;
									//cout << destCount << "\n";//comment or delete later

									delete[] give1;
									delete[] give2;
									delete[] give3;

									return true;
								}
							}
						}
						//shorter/longer password
						else
						{
							cout << "Wrong email or password.";
							return false;
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