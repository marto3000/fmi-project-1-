#ifndef HEADER
#define HEADER
class User
{
	char* username;
	char* password;
	char* email;
	//Destination* destinations;
	//int destCount;
public:
	User();
	~User();
	void writeUser();
	void giveUser(int position);
	void giveLoadedUser();
};
class Destination
{

};
#endif // !HEADER