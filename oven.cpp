#include <iostream>
#include <string>


using namespace std;

class Oven
{

	int temperature;
	int time;
	string modeList[5] = { "termoobieg", "grill", "pieczenie obustronne", "rozmrazanie", "podgrzewanie" };
	string mode = "brak"; 




public:

	void setTemperature(int temperature)
	{
		this->temperature = temperature;
	}
	
	void setMode(string mode)
	{
		this->mode = mode;
	}

	void setTime(int time)
	{
		this->time = time;
	}

	//get
	int getTime();
	int getTemperature();
	string getMode();
	

	void getInfo();

	void printModes();
	

	

};



//MAIN	

int main()
{
	Oven oven1;
	oven1.setTemperature(200);
	oven1.setMode("rozmrazanie");
	oven1.setTime(30);
	oven1.getInfo();
	oven1.printModes();
	

	return 0;
}

//METODY

void  Oven::getInfo()
{
	cout << "Temperatura: " << temperature << " stopni" << endl;
	cout << "Tryb: " << mode << "." << endl;
	cout << "Czas trwania: " << time << " minut." << endl;
}

int Oven::getTime() 
{
	return time;
}

string Oven::getMode()
{
	return mode;
}

int Oven::getTemperature()
{
	return temperature;
}

void Oven::printModes()
{
	cout << "Dostepne tryby" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << modeList[i] << endl;
	}
}
