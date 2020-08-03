#include "Observer.h"
#include <iostream>

namespace Observer {

	void FacebookUser::attach(IFacebookObserver* observer)
	{
		observers.push_back(observer);
	}

	void FacebookUser::notifyAllObservers(UI& ui)
	{
		for (int i = 0; i < observers.size(); i++)
		{
			observers[i]->update(ui);
		}
	}

	void FacebookUser::setState(const EFacebookState& eNewFacebookState, UI& ui)
	{
		eFacebookState = eNewFacebookState;
		notifyAllObservers(ui);
	}

	IFacebookObserver::IFacebookObserver(shared_ptr<FacebookUser> _user)
		: user(move(_user)) 
	{
		user->attach(this);
	}

	void UI::render(string userInput)
	{
		cout << userInput << endl;
	}

	void MainAppObserver::update(UI& ui)
	{
		switch (user->getState())
		{
		case EFacebookState::ADD_FRIEND:
			ui.render("A New Friend has been Added!");
			break;
		case EFacebookState::BLOCK_FRIEND:
			ui.render("You can no longer search this friend up!");
			break;
		}
	}

	void MessengerObserver::update(UI& ui)
	{
		switch (user->getState())
		{
		case EFacebookState::ADD_FRIEND:
			ui.render("You may start chatting with your new friend!");
			break;
		case EFacebookState::BLOCK_FRIEND:
			ui.render("Your friend's chat is archived and you may not chat with him!");
			break;
		}
	}

}