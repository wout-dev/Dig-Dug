#pragma once
#include <functional>
#include "MiniginPCH.h"
namespace dae {
	class MoveComponent;
	class PositionComponent; 
	class AnimationComponent; 
	class DeathComponent; 
	class HoseComponent; 
	class PumpComponent; 
	class StateComponent; 
	class MenuComponent; 
	class cArgs
	{
	public:
		
		cArgs() = default;
		union {

			MoveComponent * MComp;
			PositionComponent * PComp;
		};
		union {
			HoseComponent * HoseComp;
			PumpComponent * PumpComp;
			StateComponent * StateComp; 
			MenuComponent * MenuComp;
		};
		DeathComponent * DComp; 
		AnimationComponent * AComp;
		CommandTypes commandType;
	};
	

}
