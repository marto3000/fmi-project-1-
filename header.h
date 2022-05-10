#ifndef HEADER
#define HEADER
class User
{
	char* username;
	char* password;
	char* email;
	Destination* destinations;
	Destination* tempDestinations;
	int destCount;
public:
	User();
	~User();
	void registration();
	void writeUser();//parth of registration
	void login();
	bool giveUser(char* name, char* pass);//parth of login
	void mainMenue();
	void loggedMenue(char* name);
};
class Destination
{
	char* destination;
	char* time;
	char* comment;
	char* photos;
	int grade;
public:
	Destination();
	~Destination();
	void rateDest();
};
#endif // !HEADER