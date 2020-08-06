// PatternExplorer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Observer.h"
#include "Builder.h"
#include "Adapter.h"

int main()
{
    UI ui;

    ui.render("1. Observer Pattern:");

    shared_ptr<Observer::FacebookUser> user = make_shared<Observer::FacebookUser>();
    auto pMainAppObserver = make_shared<Observer::MainAppObserver>(user);
    auto pMessengerObserver = make_shared<Observer::MessengerObserver>(user);

    user->setState(Observer::EFacebookState::ADD_FRIEND, ui);
    user->setState(Observer::EFacebookState::BLOCK_FRIEND, ui);

    ui.render("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    ui.render("2. Builder Pattern:");

    Builder::Manager director;
    shared_ptr<Builder::Client> client = make_shared<Builder::Client>();
    client->MakeMeABurger(director, ui);

	ui.render("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	ui.render("3. Adapter Pattern:");

    Adapter::Client adaptingClient;
    adaptingClient.Calculate();
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
