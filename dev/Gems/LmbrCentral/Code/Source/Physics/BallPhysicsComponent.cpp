

#include "LmbrCentral_precompiled.h"


#if ENABLE_CRY_PHYSICS

#include "BallPhysicsComponent.h"
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace LmbrCentral
{
	void BallPhysicsComponent::Reflect(AZ::ReflectContext* context)
	{
		//PhysicsComponent::Reflect(context);

		//AzFramework::RigidPhysicsConfig::Reflect(context);

		if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
		{
			serializeContext->Class<BallPhysicsComponent, RigidPhysicsComponent, PhysicsComponent>()
				->Version(1)
				->Field("Configuration", &BallPhysicsComponent::m_configuration)
				;
		}

		if (auto behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
		{
			behaviorContext->Constant("BallPhysicsComponentTypeId", BehaviorConstant(AzFramework::BallPhysicsComponentTypeId));
		}
	}




	void BallPhysicsComponent::Activate()
	{
#ifdef AZ_ENABLE_TRACING
		bool isStaticTransform = false;
		AZ::TransformBus::EventResult(isStaticTransform, GetEntityId(), &AZ::TransformBus::Events::IsStaticTransform);
		AZ_Warning("Ball Physics Component", !isStaticTransform,
			"Ball Physics needs to move, but entity '%s' %s has a static transform.", GetEntity()->GetName().c_str(), GetEntityId().ToString().c_str());
#endif

		PhysicsComponent::Activate();
	}

} // namespace LmbrCentral


#endif // ENABLE_CRY_PHYSICS