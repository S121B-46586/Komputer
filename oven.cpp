#include <iostream>
#include <string>


using namespace std;

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

class Oven
{

	int temperature;
	int time;
	int wentylacja; // wlaczona = 1, wylaczona = 0
	string modeList[5] = { "termoobieg", "grill", "obustronnie", "rozmrazanie", "podgrzewanie" };
	string mode = "brak";

	Clock* clock;


public:
	
	Oven() : Oven(0, 0, "Brak"){} 

	Oven(int temperature, int time, string mode, Clock * clock = new Clock(00, 12)) : 
		temperature{(temperature > 200)? temperature = 200 : temperature}
		//sprawdza, czy temperatura jest wyzsza niz 200 stopni, jak to to zmiena na 200
	{
		this->time = time;
		this->mode = mode;
		this->clock = clock;	
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


};



//MAIN	

int main()
{ 
	Oven* c1 = new Oven(300, 40, "Termoobieg"); 
	Oven* c2 = new Oven; 
	Oven* c3 = new Oven(300, 300);
	c2->getInfo();
	c2->setTemperature(90);
	c2->setMode("rozmrazanie");
	c2->setTime(30);
	c2->getInfo();
	c1->printModes();
	cout << endl;
	c2->getInfo();
	cout << endl;
	c2->getInfo();
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
