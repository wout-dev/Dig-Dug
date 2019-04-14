#include "MiniginPCH.h"

#include "ServiceLocator.h"


std::unique_ptr < dae::Renderer> dae::ServiceLocator::m_Renderer = nullptr;
 std::unique_ptr < dae::SceneManager > dae::ServiceLocator::m_SceneManager = nullptr;
 std::unique_ptr < dae::PhysicsManager >  dae::ServiceLocator::m_PhysicsManager = nullptr;
 std::unique_ptr < dae::InputManager>  dae::ServiceLocator::m_InputManager = nullptr;