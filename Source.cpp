

#include<iostream>
#include<queue>
#include <thread>
#include <chrono>

using namespace std;


class Engine {
	int engine_num;
	string company;
	float volume;
public:
	Engine() {
		engine_num = 0;
		company = "";
		volume = 0;
	}
	Engine(int engine_num, string company, float volume) :Engine() {
		Set_EngineNum(engine_num);
		Set_Company(company);
		Set_Volume(volume);
	}

	int Get_EngineNum() {
		return engine_num;
	}
	string Get_Company() {
		return company;
	}
	float Get_Volume() {
		return volume;
	}

	void Set_EngineNum(int engine_num) {
		if (engine_num<=0) {
			cout<<"Engine Number cannot be zero or negative"<<endl;
		}
		else {
			this->engine_num = engine_num;
		}
	}

	void Set_Company(string company) {
		this->company = company;
	}

	void Set_Volume(float volume) {
		if (volume <= 0) {
			cout << "Volume cannot be zero or negative";
		}
		else {
			this->volume = volume;
		}
	}

	

};

class Transportation: public Engine {
	static int next_ID;
	int ID;
	string model;
	string vendor;
	
public:
	Transportation():Engine() {
		ID = ++next_ID;
		model = "";
		vendor = "";
		
	}
	Transportation(string model, string vendor, int engine_num, string company, float volume) : Engine(engine_num,company,volume) {
		ID = ++next_ID;
		Set_Model(model);
		Set_Vendor(vendor);
	}


	int Get_ID() {
		return ID;
	}

	string Get_Model() {
		return model;
	}

	string Get_Vendor() {
		return vendor;
	}

    void Set_Model(string model) {
		this->model = model;
	}

	void Set_Vendor(string vendor) {
		this->vendor = vendor;
	}

	

	
};


class Car:public Transportation {
	bool has_spoiler;
public:
	Car():Transportation() {
		has_spoiler = false;
	}
	Car( string model, string vendor, int engine_num, string company, float volume, bool has_spoiler ):Transportation(model,vendor,engine_num,company,volume) {
		Set_Spoiler(has_spoiler);
	}

	bool Get_Spoiler() {
		return has_spoiler;
	}

	void Set_Spoiler(bool has_spoiler) {
		this->has_spoiler = has_spoiler;
	}
	void Show() {
		
		cout << endl;
		cout << "ID : " << Get_ID() << endl;
		cout << "Model : " << Get_Model() << endl;
		cout << "Vendor : " << Get_Vendor() << endl;
		cout << "Engine number : " << Get_EngineNum() << endl;
		cout << "Company : " << Get_Company() << endl;
		cout << "Volume : " << Get_Volume() << endl;
		cout << "Has Spoiler : " << (Get_Spoiler() ? "Yes" : "No") << endl;
		cout << endl;
		cout << endl;
	}

};



class Ship : public Transportation {
	bool has_sail;
public:
	Ship() :Transportation() {
		has_sail = false;
	}
	Ship(string model, string vendor, int engine_num, string company, float volume, bool has_sail) :Transportation(model, vendor, engine_num, company, volume) {
		Set_Sail(has_sail);
	}

	bool Get_Sail() {
		return has_sail;
	}


	void Set_Sail(bool has_sail) {
		this->has_sail = has_sail;
	}
	void Show() {

		cout << endl;
		cout << "ID : " << Get_ID() << endl;
		cout << "Model : " << Get_Model() << endl;
		cout << "Vendor : " << Get_Vendor() << endl;
		cout << "Engine number : " << Get_EngineNum() << endl;
		cout << "Company : " << Get_Company() << endl;
		cout << "Volume : " << Get_Volume() << endl;
		cout << "Has Sail : " << (Get_Sail() ? "Yes" : "No") << endl;
		cout << endl;
		cout << endl;
	}

};

class AirPlane: public  Transportation {
	int engine_count;
	int person_capacity;
public:
	AirPlane():Transportation() {
		engine_count = 0;
		person_capacity = 0;
	}
	AirPlane(string model, string vendor, int engine_num, string company, float volume, int engine_count, int person_capacity) :Transportation(model, vendor, engine_num, company, volume) {
		Set_EngineCount(engine_count);
		Set_PersonCapacity(person_capacity);
	}

	int Get_EngineCount() {
		return engine_count;
	}

	int Get_PersonCapacity() {
		return person_capacity;
	}

	void Set_EngineCount(int engine_count) {
		if (engine_count <= 0) {
			cout << "Engine Count cannot be zero or negative" << endl;
		}
		else {
			this->engine_count = engine_count;
		}
	}

	void Set_PersonCapacity(int person_capacity) {
		if (person_capacity <= 0) {
			cout << "Person Capacity cannot be zero or negative" << endl;
		}
		else {
			this->person_capacity = person_capacity;
		}
	}



	void Show() {

		cout << endl;
		cout << "ID : " << Get_ID() << endl;
		cout << "Model : " << Get_Model() << endl;
		cout << "Vendor : " << Get_Vendor() << endl;
		cout << "Engine number : " << Get_EngineNum() << endl;
		cout << "Company : " << Get_Company() << endl;
		cout << "Volume : " << Get_Volume() << endl;
		cout << "Engine Count : " << Get_EngineCount() << endl;
		cout << "Person Capacity : " << Get_PersonCapacity() << endl;
		cout << endl;
		cout << endl;
	}
};

class VehicleDepo {
	queue<Car>cars;
	queue<Ship>ships;
	queue<AirPlane>airplanes;
public:
	void Add_Car(const Car& car) {
		cars.push(car);
	}

	void Add_Ship(const Ship& ship) {
		ships.push(ship);
	}

	void Add_AirPlane(const AirPlane& plane) {
		airplanes.push(plane);
	}

	void Show_All() {

		cout << "---------------------------------------------------------CARS-----------------------------------------------------------" << endl;
		queue<Car> tempcars = cars;
		while (!tempcars.empty()) {
			tempcars.front().Show();
			tempcars.pop();
			this_thread::sleep_for(chrono::seconds(1));
		}
	   
		cout << "---------------------------------------------------------SHIPS----------------------------------------------------------" << endl;
		queue<Ship> tempships = ships;
		while (!tempships.empty()) {
			tempships.front().Show();
			tempships.pop();
			this_thread::sleep_for(chrono::seconds(1));
		}

		cout << "---------------------------------------------------------PLANE----------------------------------------------------------" << endl;
		queue<AirPlane> tempairplanes = airplanes;
		while (!tempairplanes.empty()) {
			tempairplanes.front().Show();
			tempairplanes.pop();
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
};

int Transportation::next_ID = 0;

int main() {
	VehicleDepo depo;

	Car* car1 = new Car("Ford", "Mustang", 55, "Ford Motors", 4.0, true);
	Car* car2 = new Car("Chevrolet", "Camaro", 67, "General Motors", 3.6, false);
	

	Ship* ship1 = new Ship("Titanic", "White Star Line", 1, "Harland and Wolff", 52.0, false);
	Ship* ship2 = new Ship("Queen Mary 2", "Cunard Line", 2, "Chantiers de Atlantique", 76.5, true);
	
	AirPlane* plane1=new AirPlane("Boeing 737", "Boeing", 2, "American Airlines", 200.5, 2, 200);
	AirPlane* plane2=new AirPlane("Airbus A320", "Airbus", 2, "Lufthansa", 210.0, 2, 180);
	
	depo.Add_Car(*car1);
	depo.Add_Car(*car2);
	depo.Add_Ship(*ship1);
	depo.Add_Ship(*ship2);
	depo.Add_AirPlane(*plane1);
	depo.Add_AirPlane(*plane2);

	depo.Show_All();

	 delete car1;
    delete car2;
    delete ship1;
    delete ship2;
    delete plane1;
    delete plane2;
	

}

	
