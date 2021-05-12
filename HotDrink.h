#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <functional>
using namespace std;

struct HotDrink
{
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
	{
	virtual void prepare(int volume) override {
		cout << "Tea " << endl;
	}
};


struct Coffee : HotDrink
{
	virtual void prepare(int volume) override {
		cout << "Coffee " << endl;
	}
};


//Abstract factory
struct HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const override
	{
		return make_unique<Tea>();
	}
};


struct CoffeeFactory : HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const override
	{
		return make_unique<Coffee>();
	}
};


//Create Concrete class from abstract factory  facilitator 
class DrinkFactory
{
	map<string, unique_ptr<HotDrinkFactory>> hotFactories;
public:
	DrinkFactory() {
		hotFactories["coffee"] = make_unique<CoffeeFactory>(); 
		hotFactories["tea"] = make_unique<TeaFactory>();

	}

	unique_ptr<HotDrink> make_drink(const string name)
	{
		auto drink = hotFactories[name]->make();
		drink->prepare(200);
		return drink;
	}
};

//Functional Factory , that elimnates the HotDrinkFactory classes
class DrinkWithVolumeFactory
{
	map<string, function<unique_ptr<HotDrink>()>> factories;
public:
	DrinkWithVolumeFactory()
	{
		factories["tea"] = [] {
			auto tea = make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};

		factories["coffee"] = [] {
			auto coffee = make_unique<Coffee>();
			coffee->prepare(200);
			return coffee;
		};
	}

	unique_ptr<HotDrink> make_drink(const string& name)
	{
		return factories[name]();
	}
};


struct Person
{
	int id;
	string name;
	
	friend ostream& operator<<(ostream& out, const Person &p)
	{
		cout << p.id << "->" << p.name << endl;
		return out;
	}
};

class PersonFactory
{
	static int gid;
public:
	Person create_person(const string& name) 
	{
		return Person{ gid++,name };
	}
};

int PersonFactory::gid = 0;