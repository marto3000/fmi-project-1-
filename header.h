#ifndef HEADER
#define HEADER
class User
{
	char* username;
	char* password;
	char* email;
	//Destination* destinations;
public:
	User();
	~User();
	void writeUser();
	void giveUser();
	void giveLoadedUser();
};
class Destination
{

};
#endif // !HEADER