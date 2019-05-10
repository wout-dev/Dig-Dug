#include "MiniginPCH.h"
#include "ComponentsH.h"
#include "PumpComponent.h"

dae::PumpComponent::PumpComponent(HoseComponent & hose, OrientationComponent & orientationComp, PositionComponent & positionComp, CommandComponent & eventGenComponent)
	: m_Hose(hose), m_OrientationComp(orientationComp), m_PositionComp(positionComp), m_CommandComponent(eventGenComponent)

{
	m_Hose.m_PumpComp = this; 
}

void dae::PumpComponent::NotifyOnPumpLaunch()
{
	m_Hose.NotifyOnPumpLaunch(m_PositionComp, m_OrientationComp);
}

void dae::PumpComponent::NotifyOnPumpEnd()
{
	m_Hose.NotifyOnPumpEnd(); 
}

void dae::PumpComponent::NotifyOnPumpHit()
{
	m_CommandComponent.GenerateStartPumpingEnemyEvent();
}

void dae::PumpComponent::NotifyOnPumping()
{
	m_CommandComponent.GeneratePlayerPumpingEvent();
	m_Hose.NotifyOnPlayerPumping();
}
