#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//files locations: "C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt"		!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!
//				   "C:/Users/ACER/source/repos/fmi project (1)/UsersLocationsData.txt"	!!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!


User::User()//not logged default user
{
	username = new char[14];//name length
	strcpy_s(username, 14, "default name5");

	password = new char[18];//password length
	strcpy_s(password, 18, "default password5");

	email = new char[15];//email length;
	strcpy_s(email, 15, "default email5");

	destCount = 0;

	//cout << username << "\n";s
	//cout << password << "\n";
	//cout << email << "\n";
	//cout << destCount << "\n";
}
void User::registration()
{
	//clearing the user loaded data
	username = new char[1];
	username[0] = '\0';
	password = new char[1];
	password[0] = '\0';
	email = new char[1];
	email[0] = '\0';
	//getting information
	char* getData = new char[1024];
	//getting and validating username
	cout << "Enter your username (latin letters, numbers, spaces and NO special characters): ";
	bool good = false;
	bool ready = false;
	while (good == false)
	{
		cin.getline(getData, 1024, '\n');
		for (int i = 0; i < strlen(getData); i++)
		{
			//checking if there are unwanted characters
			if (!((int(getData[i]) >= 48 && int(getData[i]) <= 57) || (int(getData[i]) >= 65 && int(getData[i]) <= 90) || (int(getData[i]) >= 97 && int(getData[i]) <= 122) || int(getData[i]) == 32))
			{
				i = strlen(getData);
				cout << "The name contains forbidden character. Please enter again: ";
				cin.getline(getData, 1024, '\n');
			}
			//if the username is fine
			if (i == strlen(getData) - 1)
			{
				//checking if it already exist
				ifstream checkUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::in);
				int leng;
				int skip;
				for (bool i = false; i == false; i = i)
				{
					checkUser.read((char*)&skip, sizeof(skip));
					//when the end of the file is reached
					if (checkUser.tellg() < 0)
					{
						good = true;
						i = true;
					}
					else
					{
						int skipFrom = checkUser.tellg();
						checkUser.read((char*)&leng, sizeof(leng));
						//checking the username
						if (leng == strlen(getData) + 1)
						{
							char* check = new char[leng];
							checkUser.read(check, leng);
							for (int charPos = 0; charPos < leng; charPos++)
							{
								//on first wrong char
								if (check[charPos] != getData[charPos])
								{
									checkUser.seekg(skipFrom + skip);
									charPos = leng;
									delete[] check;
								}
								if (charPos == leng - 1)
								{
									cout << "This username already exist. Please choose a new one: ";
									i = true;//not actually done
									good = false;
								}
							}
						}
						else
						{
							checkUser.seekg(skipFrom + skip);
						}
					}
				}
				checkUser.close();
			}
		}
		if (good == true)
		{
			cout << "You entered (" << getData << ") for your username. Are you fine with that?\nYOU WON'T BE ABLE TO CHANGE THIS LATER!!!\n";
			cout << "1 - yes\n";
			cout << "2 - no\n";
			int tryAgain = 0;
			cin >> tryAgain;
			while (tryAgain > 2 || tryAgain < 1)
			{
				cout << "1 - yes\n";
				cout << "2 - no\n";
				cin >> tryAgain;
			}
			if (tryAgain == 2)
			{
				good = false;
				cout << "Reenter your username: ";
			}
			//the username is ready
			else
			{
				username = new char[strlen(getData) + 1];
				strcpy_s(username, strlen(getData) + 1, getData);
				username[strlen(getData)] = '\0';
			}
		}
	}
	//getting and validating password (validation from the code is not really needed)
	cout << "Enter your password (non latin letters might not be displayed correctly): ";
	good = false;
	while (good == false)
	{
		getData[0] = '\0';
		while (strlen(getData) == 0)
		{
			cin.getline(getData, 1024, '\n');
		}
		good = true;
		cout << "You entered (" << getData << ") for your password. Are you alright with that?\nYOU WON'T BE ABLE TO CHANGE THIS LATER!!!\n";
		cout << "1 - yes\n";
		cout << "2 - no\n";
		int tryAgain = 0;
		cin >> tryAgain;
		while (tryAgain > 2 || tryAgain < 1)
		{
			cout << "1 - yes\n";
			cout << "2 - no\n";
			cin >> tryAgain;
		}
		if (tryAgain == 2)
		{
			good = false;
			cout << "Reenter your password: ";
		}
		else
		{
			password = new char[strlen(getData) + 1];
			strcpy_s(password, strlen(getData) + 1, getData);
			password[strlen(getData)] = '\0';
		}
	}
	good = false;
	//getting and validating email
	cout << "Enter your email (non latin letters might not be displayed correctly): ";
	while (good == false)
	{
		getData[0] = '\0';
		while (strlen(getData) == 0)
		{
			cin.getline(getData, 1024, '\n');
		}
		//checking if it already exist
		ifstream checkEmail("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::in);
		int leng;
		int skip;
		for (bool i = false; i == false; i = i)
		{
			checkEmail.read((char*)&skip, sizeof(skip));
			//when the end of the file is reached
			if (checkEmail.tellg() < 0)
			{
				ready = true;
				good = true;
				i = true;
				cout << "Your email is ("<<getData<<"). Are you sure this is the right one?\nYOU WONT BE ABLE TO RETRIEVE YOUR ACCOUNT USING YOUR EMAIL IF THE WRITEN ONE IS WRONG!!!\n";
				cout << "1 - yes\n";
				cout << "2 - no\n";
				int tryAgain = 0;
				cin >> tryAgain;
				while (tryAgain > 2 || tryAgain < 1)
				{
					cout << "1 - yes\n";
					cout << "2 - no\n";
					cin >> tryAgain;
				}
				if (tryAgain == 2)
				{
					cout << "Reenter your email: ";
					ready = false;
					good = false;
				}
				else
				{
					email = new char[strlen(getData) + 1];
					strcpy_s(email, strlen(getData) + 1, getData);
					email[strlen(getData)] = '\0';
				}
			}
			else
			{
				int skipFrom = checkEmail.tellg();
				checkEmail.read((char*)&leng, sizeof(leng));
				for (int i = 0; i < 2; i++)//skipping the email and the password in the file
				{
					leng = leng + 2 + checkEmail.tellg();//adding the length of '\n' and the curent position so we can skip the text
					checkEmail.seekg(leng);
					checkEmail.read((char*)&leng, sizeof(leng));
				}
				//checking the email
				if (leng == strlen(getData) + 1)
				{
					char* check = new char[leng];
					checkEmail.read(check, leng);
					for (int charPos = 0; charPos < leng; charPos++)
					{
						//on first wrong char
						if (check[charPos] != getData[charPos])
						{
							checkEmail.seekg(skipFrom + skip);
							charPos = leng;
							delete[] check;
						}
						if (charPos == leng - 1)
						{
							cout << "This email is already registered. Do you want to cancel the registration?\n";
							i = true;//not actually done
							good = true;//not actually valid
							cout << "1 - yes\n";
							cout << "2 - no\n";
							int tryAgain = 0;
							cin >> tryAgain;
							while (tryAgain > 2 || tryAgain < 1)
							{
								cout << "1 - yes\n";
								cout << "2 - no\n";
								cin >> tryAgain;
							}
							if (tryAgain == 2)
							{
								cout << "Reenter your email: ";
								good = false;
							}
						}
					}
				}
				else
				{
					checkEmail.seekg(skipFrom + skip);
				}
			}
		}
		checkEmail.close();	
	}
	delete[] getData;
	destCount = 0;
	if (ready == true)
	{
		cout << "Are you sure you want to create your account?\nYOU WON'T BE ABLE TO DELETE IT LATER!!!\n";
		cout << "1 - yes\n";
		cout << "2 - no\n";
		int tryAgain = 0;
		cin >> tryAgain;
		while (tryAgain > 2 || tryAgain < 1)
		{
			cout << "1 - yes\n";
			cout << "2 - no\n";
			cin >> tryAgain;
		}
		if (tryAgain == 1)
		{
			writeUser();
		}
		else
		{
			username = new char[14];//name length
			strcpy_s(username, 14, "default name5");

			password = new char[18];//password length
			strcpy_s(password, 18, "default password5");

			email = new char[15];//email length;
			strcpy_s(email, 15, "default email5");

			destCount = 0;
		}
	}
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


void User::login()//gets the login information and passes it to giveUser(...) for the actual login validtion
{
	bool isLogged = false;
	while (isLogged == false)
	{
		char* getUser = new char[1024];
		getUser[0] = '\0';
		char* getPass = new char[1024];
		getPass[0] = '\0';
		cout << "Enter your username and password (separate with <-enter): ";
		cin.getline(getUser, 1024, '\n');
		while (getUser[0] == '\0')//the 1 from the retry if can be accepted as cin.getline for getUser (this while prevents this)
		{
			cin.getline(getUser, 1024, '\n');
		}
		cin.getline(getPass, 1024, '\n');
		getPass[strlen(getPass)] = '\0';
		char* user = new char[strlen(getUser) + 1];
		strcpy_s(user, strlen(getUser) + 1, getUser);
		user[strlen(getUser)] = '\0';
		char* pass = new char[strlen(getPass) + 1];
		strcpy_s(pass, strlen(getPass) + 1, getPass);
		pass[strlen(getPass)] = '\0';
		delete[] getUser;
		delete[] getPass;
		isLogged = giveUser(user, pass);
		delete[] user;
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


bool User::giveUser(char* name, char* pass)//actual login validation
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
			cout << "Wrong username or password.";
			i = true;
			return false;
		}
		else
		{
			int skipFrom = giveUser.tellg();
			giveUser.read((char*)&leng, sizeof(leng));
			//checking the username
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
					//checking the password if the username is correct (must be after the "on first wrong letter")
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
									cout << "Wrong username or password.";
									return false;
								}
								//if the password is correct
								if (charPos2 == leng2 - 1)
								{
									//giving username
									username = new char[strlen(give1) + 1];
									strcpy_s(username, strlen(give1) + 1, give1);
									username[strlen(give1)] = '\0';
									cout << username << "\n";//comment or delete later
									//giving password
									password = new char[strlen(give2) + 1];
									strcpy_s(password, strlen(give2) + 1, give2);
									password[strlen(give2)] = '\0';
									cout << password << "\n";//comment or delete later
									//giving email
									pos = giveUser.tellg();
									pos += 2;
									giveUser.seekg(pos);
									giveUser.read((char*)&leng2, sizeof(leng2));
									char* give3 = new char[leng2];
									giveUser.read(give3, leng2);
									email = new char[strlen(give3) + 1];
									strcpy_s(email, strlen(give3) + 1, give3);
									email[strlen(give3)] = '\0';
									cout << email << "\n";//comment or delete later
									//giving destCount
									pos = giveUser.tellg();
									pos += 2;
									giveUser.seekg(pos);
									int give4 = 0;
									giveUser.read((char*)&give4, sizeof(give4));
									destCount = give4;
									cout << destCount << "\n";//comment or delete later

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
							cout << "Wrong username or password.";
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