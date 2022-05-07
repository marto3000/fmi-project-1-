#ifndef HEADER
#define HEADER
class User
{
	char* email;
	char* password;
	char* username;
	//Destination* destinations;
	int destCount;
public:
	User();
	~User();
	void writeUser();
	void login();
	bool giveUser(char* name, char* pass);
};
class Destination
{

};
#endif // !HEADER