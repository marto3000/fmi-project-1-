#ifndef HEADER
#define HEADER
class User
{
	char* username;
	char* password;
	char* email;
	//Destination* destinations;
	int destCount;
public:
	User();
	~User();
	void registration();
	void writeUser();
	void login();
	bool giveUser(char* name, char* pass);
};
class Destination
{

};
#endif // !HEADER