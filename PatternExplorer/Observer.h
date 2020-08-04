#pragma once
#include <string>
#include <memory>
#include <vector>
#include "UI.h"

using namespace std;

namespace Observer {

	enum class EFacebookState {
		NONE = 0,
		ADD_FRIEND,
		BLOCK_FRIEND
	};

	class FacebookUser;

	class IFacebookObserver {
	public:
		IFacebookObserver(shared_ptr<FacebookUser> _user);
		virtual void update(UI& ui) {};
	protected:
		shared_ptr<FacebookUser> user;
	};

	class MainAppObserver : public IFacebookObserver
	{
	public:
		MainAppObserver(shared_ptr<FacebookUser> _user) : IFacebookObserver(move(_user)) {};
		virtual void update(UI& ui);
	};

	class MessengerObserver : public IFacebookObserver {
	public:
		MessengerObserver(shared_ptr<FacebookUser> _user) : IFacebookObserver(move(_user)) {};
		virtual void update(UI& ui);
	};

	class FacebookUser { //is the Subject
	public:
		void attach(shared_ptr<IFacebookObserver> observer);
		void notifyAllObservers(UI& ui);
		void setState(const EFacebookState& eNewFacebookState, UI& ui);
		inline EFacebookState getState() { return eFacebookState; }

	private:
		EFacebookState eFacebookState = EFacebookState::ADD_FRIEND;
		vector<weak_ptr<IFacebookObserver>> observers;
	};
}