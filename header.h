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
	void giveUser(int position);
	void giveLoadedUser();
};
class Destination
{

};
#endif // !HEADER