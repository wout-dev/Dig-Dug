#pragma once

#include <functional>
#include <string>
#include "DataStructs.h"
#include "ComponentsH.h"
namespace dae {
	enum SupportedAnimationLoadingTypes{
		PlayerAnim, 
		EnemyAnim, 
		PookaAnim, 
		FygarAnim
	};
	struct PlayerAnimationData{
		//Name, ClipId, Initial UvOffset, AmountOfFrames
		static const unsigned char AnimationClipCount = 15;
		std::tuple< dae::Vec2, unsigned int,std::string> AnimationClipData[AnimationClipCount] =
		{
			{Vec2(0,0), 1,"IdleRight" },				//0
			{Vec2(384+32,0), 1, "IdleLeft"},			//1
			{Vec2(0,32), 1, "IdleDown"},				//2
			{Vec2(0,64), 1, "IdleUp"},				    //3
			{Vec2(0,32), 1, "IdleDownFlipped"},			//4
			{Vec2(0,64), 1, "IdleUpFlipped"},		    //5
			{Vec2(0,0), 2, "WalkingRight"},				//6
			{Vec2(384,0), 2, "WalkingLeft"},			//7
			{Vec2(0,32), 2, "WalkingDown"},				//8
			{Vec2(0,64), 2, "WalkingUp"},				//9
			{Vec2(384,32), 2, "WalkingDownFlipped"},	//10
			{Vec2(384,64), 2, "WalkingUpFlipped"},		//11
			{Vec2(128,0), 2, "Pumping"},				//12
			{Vec2(0,96), 6, "Dying"},					//13
			{Vec2(192, 0), 1, "Winning" }				//14
		};

		
	};
	struct PookaAnimationData {
		//Name, ClipId, Initial UvOffset, AmountOfFrames
		static const unsigned char AnimationClipCount = 5;
		std::tuple< dae::Vec2, unsigned int, std::string> AnimationClipData[AnimationClipCount] =
		{
			{Vec2(32,160), 1,"IdleRight" },				//0
			{Vec2(64,160), 1, "IdleLeft"},			//1
			{Vec2(0,160), 2, "WalkingRight"},				//2
			{Vec2(64,160), 2, "WalkingLeft"},			//3
			{Vec2(128,0), 2, "Pumping"},				//4
		};

	};
	class AnimationLoader
	{
	public: 
		void LoadAnimation(AnimationComponent * animComp, SupportedAnimationLoadingTypes t)
		{
			PlayerAnimationData Player; 
			PookaAnimationData Pooka; 
			switch (t)
			{
			case PlayerAnim: 
				
				for (int i = 0; i < Player.AnimationClipCount; i++)
				{
					animComp->CreateAnimation(std::get<0>(Player.AnimationClipData[i]), std::get<1>(Player.AnimationClipData[i]));
				}
			case EnemyAnim:
				for (int i = 0; i < Pooka.AnimationClipCount; i++)
				{
					animComp->CreateAnimation(std::get<0>(Pooka.AnimationClipData[i]), std::get<1>(Pooka.AnimationClipData[i]));
				}

			}
		}
	};
}