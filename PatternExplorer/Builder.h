#include <string>
#include <memory>
#include "UI.h"

using namespace std;

namespace Builder {
	class Hamburger {
	public:

		Hamburger(string _lettuce, string _patty, string _tomato, string _bun) 
			: lettuce(_lettuce), patty(_patty), tomato(_tomato), bun(_bun) {}

		inline string GetLettuce() const { return lettuce; }
		inline string GetPatty() const { return patty; }
		inline string GetTomato() const { return tomato; }
		inline string GetBun() const { return bun; }

		inline void SetLettuce(const string& _lettuce, UI& ui) { lettuce = _lettuce; ui.render("Got the " + _lettuce); }
		inline void SetPatty(const string& _patty, UI& ui) { patty = _patty; ui.render("Got the " + _patty); }
		inline void SetTomato(const string& _tomato, UI& ui) { tomato = _tomato; ui.render("Got the " + _tomato); }
		inline void SetBun(const string& _bun, UI& ui) { bun = _bun;  ui.render("Got the " + _bun);}

	private:
		string lettuce;
		string patty;
		string tomato;
		string bun;
	};

	class IHamburgerBuilder 
	{
	public:
		virtual void AddVeggies(UI& ui) = 0;
		virtual void AddMeat(UI& ui) = 0;
		virtual void AddBread(UI& ui) = 0;
	};

	class Chef : public IHamburgerBuilder {
	public:
		Chef() : IHamburgerBuilder() { Reset(); }

		virtual void AddVeggies(UI& ui);
		virtual void AddMeat(UI& ui);
		virtual void AddBread(UI& ui);

		shared_ptr<Hamburger> GetHamburger(UI& ui);

	private:
		shared_ptr<Hamburger> hamburger;
		inline void Reset() { hamburger = make_shared<Hamburger>(Hamburger("", "", "", "")); }
	};

	class Manager { //aka. Director
	private:
		shared_ptr<IHamburgerBuilder> builder;
	public:
		void setBuilder(shared_ptr<IHamburgerBuilder> _builder, UI& ui);

		void MakeBurger(UI& ui);

	};

	class Client {
	public:
		void MakeMeABurger(Manager& director, UI& ui);
	};

}