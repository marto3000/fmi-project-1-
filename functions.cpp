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
				cout << "Re enter your username: ";
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
			cout << "Re enter your password: ";
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
					cout << "Re enter your email: ";
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
			cout << "You successfully created your account. The program will be closed for security reasons.";
		}
		else
		{
			username = new char[14];//name length
			strcpy_s(username, 14, "default name5");

			password = new char[18];//password length
			strcpy_s(password, 18, "default password5");

			email = new char[15];//email length;
			strcpy_s(email, 15, "default email5");
		}
	}
}


void User::writeUser()//for saving new users in the end of the file (after the last user)
{
	//writing the maxLeng
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/UsersLoginData.txt", ios::app);
	int maxLeng = strlen(username) + 1 + strlen(password) + 1 + strlen(email) + 1 + (3 * 4) + (3 * 2);//each char array + "\0" from each array + the destination count + every number telling the array size + every "\n"
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
		else
		{
			loggedMenue(username);
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
									//cout << username << "\n";//comment or delete later
									//giving password
									password = new char[strlen(give2) + 1];
									strcpy_s(password, strlen(give2) + 1, give2);
									password[strlen(give2)] = '\0';
									//cout << password << "\n";//comment or delete later
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
									//cout << email << "\n";//comment or delete later

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


void User::mainMenue()
{
	cout << "Welcome to the Adventurer's Diary!\n";
	cout << "1 - register\n";
	cout << "2 - login\n";
	cout << "3 - exit\n";
	int option = 0;
	cin >> option;
	while (option < 1 || option>3)
	{
		cout << "1 - register\n";
		cout << "2 - login\n";
		cout << "3 - exit\n";
		cin >> option;
	}
	if (option == 1)
	{
		registration();
	}
	if (option == 2)
	{
		login();
	}
}


void User::loggedMenue(char* user)
{
	cout << "Welcome " << user << "! What do you want to do today?\n";
	int option = 0;
	while (option != 3)
	{
		cout << "1 - see my destinations ratings\n";
		cout << "2 - rate a destination\n";
		cout << "3 - exit account\n";
		cin >> option;
		if (option == 1)
		{

		}
		if (option == 2)
		{
			destination.rateDest(username);
		}
		if (option == 3)
		{
			mainMenue();
		}
	}
}


Destination::Destination()
{
	destination = new char[0];
	comment = new char[0];
	photos = new char[0];
	yearS = 0;
	monthS = 0;
	dayS = 0;
	yearE = 0;
	monthE = 0;
	dayE = 0;
	grade = 0;
}


void Destination::rateDest(char* username)
{
	char* getData = new char[1024];
	bool good = false;
	bool ready = false;
	//getting the destination
	if (good == false && ready == false)
	{
		cout << "Give the destination (place and country for example): ";
	}
	while (good == false && ready == false)
	{
		getData[0] = '\0';
		while (strlen(getData) == 0)
		{
			cin.getline(getData, 1024, '\n');
		}
		good = true;
		cout << "You entered: " << getData << "\nContinue?\n";
		cout << "1 - yes\n";
		cout << "2 - re enter\n";
		cout << "3 - quit\n";
		int option = 0;
		cin >> option;
		while (option < 1 || option>3)
		{
			cout << "1 - yes\n";
			cout << "2 - re enter\n";
			cout << "3 - quit\n";
			cin >> option;
		}
		if (option == 1)
		{
			destination = new char[strlen(getData) + 1];
			strcpy_s(destination, strlen(getData) + 1, getData);
			destination[strlen(getData)] = '\0';
		}
		if (option == 2)
		{
			good = false;
			cout << "Re enter the destination: ";
		}
		if (option == 3)
		{
			ready = true;
		}
	}
	good = false;
	//getting and validating the time period
	if (good == false && ready == false)
	{
		cout << "Give the starter date (yyyy mm dd)(separate with space ot <-enter): ";
	}
	validDate(yearS, monthS, dayS, good, ready);
	good = false;
	if (good == false && ready == false)
	{
		cout << "Give the end date (yyyy mm dd)(separate with space ot <-enter): ";
	}
	validDate(yearE, monthE, dayE, good, ready);
	good = false;
	if (good == false && ready == false)
	{
		while (!((yearS == yearE && monthS == monthE && dayS < dayE) || (yearS == yearE && monthS < monthE) || yearS < yearE))
		{
			cout << "The end date can't be before the starter date. Please enter again: ";
			validDate(yearE, monthE, dayE, good, ready);
		}
	}
	good = false;
	//getting the grade
	if (good == false && ready == false)
	{
		cout << "Rate the destination (1-5): ";
	}
	while (good == false && ready == false)
	{
		cin >> grade;
		while (grade < 1 || grade>5)
		{
			cout << "Invalid rating. Please enter again: ";
			cin >> grade;
		}
		good = true;
		cout << "You entered: " << grade << "\nContinue?\n";
		cout << "1 - yes\n";
		cout << "2 - re enter\n";
		cout << "3 - quit\n";
		int option = 0;
		cin >> option;
		while (option < 1 || option>3)
		{
			cout << "1 - yes\n";
			cout << "2 - re enter\n";
			cout << "3 - quit\n";
			cin >> option;
		}
		if (option == 2)
		{
			good = false;
			cout << "Re enter the rating: ";
		}
		if (option == 3)
		{
			ready = true;
		}
	}
	//getting comment
	good = false;
	if (good == false && ready == false)
	{
		cout << "Give your comment for the destination (up to 1023 characters)(non latin letters might not be displayed propperly):\n";
	}
	while (good == false && ready == false)
	{
		getData[0] = '\0';
		while (strlen(getData) == 0)
		{
			cin.getline(getData, 1024, '\n');
		}
		good = true;
		cout << "You entered:\n\n" << getData << "\n\nContinue?\n";
		cout << "1 - yes\n";
		cout << "2 - re enter\n";
		cout << "3 - quit\n";
		int option = 0;
		cin >> option;
		while (option < 1 || option>3)
		{
			cout << "1 - yes\n";
			cout << "2 - re enter\n";
			cout << "3 - quit\n";
			cin >> option;
		}
		if (option == 1)
		{
			comment = new char[strlen(getData) + 1];
			strcpy_s(comment, strlen(getData) + 1, getData);
			comment[strlen(getData)] = '\0';
		}
		if (option == 2)
		{
			good = false;
			cout << "Re enter your comment: ";
		}
		if (option == 3)
		{
			ready = true;
		}
	}
	//getting and validating images names
	good = false;
	if (good == false && ready == false)
	{
		cout << "Give the names of your images (might contain only letters and _ )(have to be separated with space and have to end with the name extention (only .jpeg and .png))(non latin letters might not be displayed propperly): ";
	}
	photos = new char[1024];
	photos[0] = '\0';
	while (good == false && ready == false)
	{
		getData[0] = '\0';
		while (strlen(getData) == 0)
		{
			cin.getline(getData, 1024, '\n');
		}
		//checking for correct name
		if (!(strlen(getData) < 5))//less than a.png for example
		{
			for (int i = 0; i < strlen(getData); i++)
			{
				//cout << getData[i];
				//on first invalid char
				if ((int(getData[i]) < 65 || (int(getData[i]) > 90 && int(getData[i]) < 97) || int(getData[i]) > 122) && int(getData[i]) != 95 && int(getData[i]) != 46)
				{
					//invalid name at all
					i = strlen(getData);
					cout << "The name you gave contains invalid character.\n";
				}
				if (i == strlen(getData) - 5 && int(getData[i]) == 46)//? .jpeg
				{
					i++;
					char* formatCheck = new char[5];
					strcpy_s(formatCheck, 5, "jpeg");
					for (int a = 0; a < 4; a++)
					{
						if (getData[i + a] != formatCheck[a])
						{
							//invalid name at all
							cout << "File format is not recognised.\n";
							a = 4;
						}
						if (a == 3)//it's .jpeg
						{
							if (strlen(photos) + strlen(getData) + 1 >= 1024)
							{
								cout << "You gave too many images or their names are just too long. You can't give more images.";
							}
							else
							{
								strcat_s(photos, 1024, getData);
								photos[strlen(photos)] = '\0';
								cout << " " << photos << "\n";
							}
						}
					}
					delete[] formatCheck;
				}
				if (i == strlen(getData) - 4 && int(getData[i]) == 46)//? .png
				{
					i++;
					char* formatCheck = new char[4];
					strcpy_s(formatCheck, 4, "png");
					for (int a = 0; a < 3; a++)
					{
						if (getData[i + a] != formatCheck[a])
						{
							//invalid name at all
							cout << "File format is not recognised.\n";
							a = 3;
						}
						if (a == 2)//it's .png
						{
							strcat_s(photos, 1024, getData);
							photos[strlen(photos)] = '\0';
							cout << " " << photos << "\n";
						}
					}
					delete[] formatCheck;
				}
			}
		}
		else
		{
			cout << "The name is too short to be valid\n";
		}
		good = true;
		cout << "1 - give more images\n";
		cout << "2 - stop giving images\n";
		cout << "3 - quit\n";
		int option = 0;
		cin >> option;
		while (option < 1 || option>3)
		{
			cout << "1 - give more images\n";
			cout << "2 - stop giving images\n";
			cout << "3 - quit\n";
			cin >> option;
		}
		if (option == 1)
		{
			good = false;
		}
		if (option == 3)
		{
			ready = true;
		}
	}
	if (good == true && ready == false)//adding in the file
	{
		writeDest(username);
		cout << "You successfully created a new rating.\n";
	}
	if (ready == true)
	{
		cout << "You canceled the destination rating.\n";
	}
	delete[] getData;
}


void Destination::writeDest(char* username)
{
	//writing the maxLeng
	ofstream writeNewDest("C:/Users/ACER/source/repos/fmi project (1)/UsersLocationsData.txt", ios::app);
	int maxLeng = strlen(username) + 1 + strlen(destination) + 1 + strlen(comment) + 1 + strlen(photos) + 1 + (3 * 7) + (4 * 4) + (5 * 2);//each char array + "\0" from each array + the leng of the 7 int values + every number telling the array size + every "\n"
	writeNewDest.write((char*)&maxLeng, sizeof(maxLeng));
	//write username (so the rating can be found)
	int leng = strlen(username) + 1;
	writeNewDest.write((char*)&leng, sizeof(leng));
	writeNewDest.write(username, leng).write("\n", 1);
	//write destination
	leng = strlen(destination) + 1;
	writeNewDest.write((char*)&leng, sizeof(leng));
	writeNewDest.write(destination, leng).write("\n", 1);
	//write comment
	leng = strlen(comment) + 1;
	writeNewDest.write((char*)&leng, sizeof(leng));
	writeNewDest.write(comment, leng).write("\n", 1);
	//write photos
	leng = strlen(photos) + 1;
	writeNewDest.write((char*)&leng, sizeof(leng));
	writeNewDest.write(photos, leng).write("\n", 1);
	//writing the ints
	writeNewDest.write((char*)&yearS, sizeof(yearS))
		.write((char*)&monthS, sizeof(monthS))
		.write((char*)&dayS, sizeof(dayS))
		.write((char*)&yearE, sizeof(yearE))
		.write((char*)&monthE, sizeof(monthE))
		.write((char*)&dayE, sizeof(dayE))
		.write((char*)&grade, sizeof(grade))
		.write("\n", 1);
	
	writeNewDest.close();
}


void Destination::validDate(int &y, int &m, int &d, bool &good, bool &ready)
{
	while (good == false && ready == false)
	{
		cin >> y;
		while (y < 0)
		{
			cout << "The year can't be negtive number. Enter again: ";
			cin >> y;
		}
		cin >> m;
		while (m < 1 || m > 12)
		{
			cout << "The month shall be between 1 and 12. Enter again: ";
			cin >> m;
		}
		cin >> d;
		while (d <= 0 || d > 31 || (m >= 8 && m % 2 == 1 && d > 30) || (m <= 7 && m % 2 == 0 && d > 30) || (m == 2 && y % 4 != 0 && d > 28) || (m == 2 && y % 4 == 0 && d > 29))
		{
			cout << "The day is invalid. Enter again: ";
			cin >> d;
		}
		good = true;
		cout << "You entered: " << y << "-" << m << "-" << d << "\nContinue?\n";
		cout << "1 - yes\n";
		cout << "2 - re enter\n";
		cout << "3 - quit\n";
		int option = 0;
		cin >> option;
		while (option < 1 || option>3)
		{
			cout << "1 - yes\n";
			cout << "2 - re enter\n";
			cout << "3 - quit\n";
			cin >> option;
		}
		if (option == 2)
		{
			good = false;
			cout << "Re enter the date: ";
		}
		if (option == 3)
		{
			ready = true;
		}
	}
}


Destination::~Destination()
{
	delete[] destination;
	delete[] comment;
	delete[] photos;
}


User::~User()
{
	delete[] username;
	delete[] password;
	delete[] email;
}