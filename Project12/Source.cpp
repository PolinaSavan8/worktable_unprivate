#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <time.h>

using namespace std;



class Player 
{
private:
	string name;
	string nickname;
	int age;
	string team;

public:
	Player(string n, string s, int a, string t) 
	{
		name = n;
		nickname = s;
		age = a;
		team = t;
		cout << "Player has been created!\n";
	}

	void printInfo()
	{

		cout << name << " "
			<< nickname << " "
			<< age << " year, group"
			<< team << " " << endl;
	}

	Player()
	{

		name = "Noname ";
		nickname = "Noname";
		age = 0;
		team = "-";
	}

	void setName(const string &n, const string& s, const int& a, const string& t)
	{
		name = n;
	}

	void setNickname(const string& s) {
		nickname = s;
	}

	void setAge( const int& a)
	{
		age = a;
	}

	void setTeam(const string& t)
	{
		team = t;
	}
};

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Player p1;
	p1.printInfo();
	
	p1.setName("Polina");
	p1.setNickname("POLLYnax");
	p1.setAge(17);
	p1.setTeam("bloggers");

	p1.printInfo();

	string n_temp;
	string s_temp;
	int a_temp;
	string t_temp;

	Player player1("Polina", "POLLYnax", 17, "bloggers");
	player1.printInfo();
	

	Player player2;
	player2.printInfo();
	cout << "Enter the name of player: ";
	getline(cin, player2.name);

	cout << "Enter surname: ";
	getline(cin, player2.nickname);

	cout << "Enter age: ";
	cin >> player2.age;
	cin.ignore();


	Player player3;
	player3.printInfo();
	cout << "Enter the name of the player: ";
	getline(cin, n_temp);

	cout << "Enter surname: ";
	getline(cin, s_temp);

	cout << "Enter age: ";
	cin >> a_temp;


	return 0;
}