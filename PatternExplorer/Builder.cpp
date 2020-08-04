#include "Builder.h"
namespace Builder {
	void Chef::AddVeggies(UI& ui)
	{
		hamburger->SetLettuce("Fresh Green Lettuce", ui);
		hamburger->SetTomato("Red Juicy Tomato", ui);
		ui.render("Chef has added " + hamburger->GetLettuce() + " and " + hamburger->GetTomato() + ".");
	}
	void Chef::AddMeat(UI& ui)
	{
		hamburger->SetPatty("Beyond Meat Patty", ui);
		ui.render("Chef has added " + hamburger->GetPatty());
	}
	void Chef::AddBread(UI& ui)
	{
		hamburger->SetBun("Crispy Buttery Bun", ui);
		ui.render("Chef has added " + hamburger->GetBun());
	}
	shared_ptr<Hamburger> Chef::GetHamburger(UI& ui)
	{
		shared_ptr<Hamburger> newBurger = move(hamburger);
		ui.render("Burger is ready!");
		Reset();
		return newBurger;
	}

	void Manager::setBuilder(shared_ptr<IHamburgerBuilder> _builder, UI& ui)
	{
		builder = _builder; 
		string builderName = string(typeid(*_builder).name());
		string extractedName = builderName.substr(builderName.find(":") + 2);
		string finalizedName = extractedName != "" ? extractedName : builderName;
		ui.render("The " + finalizedName + " is ready");
	}

	void Manager::MakeBurger(UI& ui)
	{
		ui.render("The Restaurant Manager has taken in an order - Beyond Meat Burger");
		builder->AddMeat(ui);
		builder->AddVeggies(ui);
		builder->AddBread(ui);
	}

	void Client::MakeMeABurger(Manager& director, UI& ui)
	{
		ui.render("Please make me a beyond meat burger");
		ui.render("===================================");
		shared_ptr<Chef> chef = make_shared<Chef>();
		director.setBuilder(chef, ui);
		director.MakeBurger(ui);
		chef->GetHamburger(ui);
		ui.render("===================================");
		ui.render("Thanks!  I am hungry take my money.");
	}

}