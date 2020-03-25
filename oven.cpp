#include <iostream>
#include <string>


using namespace std;

class Oven
{

	int temperature;
	int time;
	int wentylacja; // wlaczona = 1, wylaczona = 0
	string modeList[5] = { "termoobieg", "grill", "obustronnie", "rozmrazanie", "podgrzewanie" };
	string mode = "brak";

	



public:
	
	Oven() : Oven(0, 0, "Brak"){} 

	Oven(int temperature, int time, string mode) : 
		temperature{(temperature > 200)? temperature = 200 : temperature}
		//sprawdza, czy temperatura jest wyzsza niz 200 stopni, jak to to zmiena na 200
	{
		this->temperature = temperature;
		this->time = time;
		this->mode = mode;
		
		
	}

	Oven(int temperature, int time) : Oven(temperature, time, "Brak") //odsyla do konstruktora 2
	{
		wentylacja = 0;
	}

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

	//Klasa Clock, zegarek w piekarniku

	class Clock
	{
		int minute = 00, hour = 12;
		int day = 13, month = 01, year = 2020;

	public:
		Clock(int minute, int hour)
		{
			this->minute = minute;
			this->hour = hour;
		}
		
	};
};



//MAIN	

int main()
{ 
	Oven* c1 = new Oven(300, 40, "Termoobieg"); Oven k1 = *c1;
	Oven* c2 = new Oven; Oven k2 = *c2;
	Oven* c3 = new Oven(300, 300); Oven k3 = *c3;
	k2.getInfo();
	k2.setTemperature(90);
	k2.setMode("rozmrazanie");
	k2.setTime(30);
	k2.getInfo();
	k1.printModes();
	cout << endl;
	k2.getInfo();
	cout << endl;
	k3.getInfo();
	delete c1; c1 = nullptr;
	delete c2; c2 = nullptr;
	delete c3; c3 = nullptr;


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
