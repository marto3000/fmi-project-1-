#ifndef HEADER
#define HEADER

class Destination
{
	char* destination;
	char* comment;
	char* photos;
	int yearS;
	int monthS;
	int dayS;
	int yearE;
	int monthE;
	int dayE;
	int grade;
public:
	Destination();
	//coppy constructor
	//= operator
	~Destination();
	void rateDest(char* username);
	void writeDest(char* username);
	void validDate(int& y, int& m, int& d, bool& good, bool& ready);
	void giveDest(char* username);
};
class User
{
	char* username;
	char* password;
	char* email;
	Destination destination;
public:
	User();
	//coppy constructor
	//= operator
	~User();
	void registration();
	void writeUser();//parth of registration
	void login();
	bool giveUser(char* name, char* pass);//parth of login	
	void mainMenue();
	void loggedMenue(char* name);
};

#endif // !HEADER