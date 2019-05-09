#pragma once
#include  "ComponentsH.h"

namespace dae {

	class CommandComponent; 
	class HpComponent; 
	class DeathComponent : public  BaseComponent {
	public:
		DeathComponent(HpComponent & hpComponent, CommandComponent & eventGenComponent) : m_HpComponent(hpComponent), m_EventGenComponent(eventGenComponent) {};
		virtual ~DeathComponent() {}; 
		void Update(float ) override {};
		void NotifyOnDeath() ;
		bool HasDied() { return m_HasDied; }
		bool m_HasDied = false;
		CommandComponent & m_EventGenComponent; 
		HpComponent & m_HpComponent; 
	};

}