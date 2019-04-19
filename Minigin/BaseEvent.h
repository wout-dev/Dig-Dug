#pragma once
#include <functional>

namespace dae {
	class MoveComponent;
	class PositionComponent; 
	class AnimationComponent; 
	class EventArgs
	{
	public:
		//class EventArgs() {};
		class EventArgs(MoveComponent & mc) : MComp(mc) {}; 
		virtual ~EventArgs() = default;
		union {

			std::reference_wrapper<MoveComponent> MComp;
			std::reference_wrapper<PositionComponent> PComp;
		};
		bool isFlipped; 
		AnimationComponent * AComp; 
	};
	class EventArgKeyDown final : public EventArgs
	{
	public:
		~EventArgKeyDown() = default;
		EventArgKeyDown(MoveComponent & mc) : EventArgs(mc) {};
		
	};
	class Event
	{
	public: 
		virtual ~Event() = default;
		virtual void Execute(EventArgs & EvArg) = 0;
	};

	

}
