#include "LmbrCentral_precompiled.h"

#if ENABLE_CRY_PHYSICS

#include "EditorBallPhysicsComponent.h"
#include <AzCore/Serialization/EditContext.h>

namespace LmbrCentral
{

	void EditorBallPhysicsConfig::Reflect(AZ::ReflectContext* context)
	{
		auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context);
		if (serializeContext)
		{
			serializeContext->Class<EditorBallPhysicsConfig, AzFramework::BallPhysicsConfig>()
				->Version(2)
				;

			AZ::EditContext* editContext = serializeContext->GetEditContext();
			if (editContext)
			{
				editContext->Class<AzFramework::BallPhysicsConfig>(
					"Ball Physics Configuration", "");
			}
		}
	}





	void EditorBallPhysicsComponent::Reflect(AZ::ReflectContext* context)
	{
		//EditorPhysicsComponent::Reflect(context);
		EditorBallPhysicsConfig::Reflect(context);

		auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context);
		if (serializeContext)
		{
			serializeContext->Class<EditorBallPhysicsComponent, EditorRigidPhysicsComponent, EditorPhysicsComponent>()
				->Field("Configuration", &EditorBallPhysicsComponent::m_configuration)
				->Version(1)
				;

			AZ::EditContext* editContext = serializeContext->GetEditContext();
			if (editContext)
			{
				editContext->Class<EditorBallPhysicsComponent>(
					"Ball Physics", "The Ball Physics component is used to represent balls that move realistically when touched")
					->ClassElement(AZ::Edit::ClassElements::EditorData, "")
					->Attribute(AZ::Edit::Attributes::Category, "Physics (Legacy)")
					->Attribute(AZ::Edit::Attributes::Icon, "Editor/Icons/Components/RigidPhysics.svg")
					->Attribute(AZ::Edit::Attributes::ViewportIcon, "Editor/Icons/Components/Viewport/RigidPhysics.png")
					->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game", 0x232b318c))
					->Attribute(AZ::Edit::Attributes::AutoExpand, true)
					->Attribute(AZ::Edit::Attributes::HelpPageURL, "https://docs.aws.amazon.com/lumberyard/latest/userguide/component-rigid-body.html")
					->DataElement(0, &EditorBallPhysicsComponent::m_configuration, "Configuration", "Configuration for ball physics.")
					->Attribute(AZ::Edit::Attributes::Visibility, AZ::Edit::PropertyVisibility::ShowChildrenOnly)
					;
			}
		}
	}



	//bool EditorBallPhysicsComponent::ReadInConfig(const AZ::ComponentConfig* baseConfig)
	//{
	//	if (auto config = azrtti_cast<const AzFramework::RigidPhysicsConfig*>(baseConfig))
	//	{
	//		static_cast<AzFramework::RigidPhysicsConfig&>(m_configuration) = *config;
	//		return true;
	//	}
	//	return false;
	//}

	//bool EditorBallPhysicsComponent::WriteOutConfig(AZ::ComponentConfig* outBaseConfig) const
	//{
	//	if (auto config = azrtti_cast<AzFramework::RigidPhysicsConfig*>(outBaseConfig))
	//	{
	//		*config = m_configuration;
	//		return true;
	//	}
	//	return false;
	//}


	void EditorBallPhysicsComponent::BuildGameEntity(AZ::Entity* gameEntity)
	{
		gameEntity->CreateComponent<BallPhysicsComponent>()->SetConfiguration(m_configuration);
	}

} // namespace LmbrCentral

#endif // ENABLE_CRY_PHYSICS