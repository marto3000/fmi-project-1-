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
	void giveUser(char* name);
};
class Destination
{

};
#endif // !HEADER