#if ENABLE_CRY_PHYSICS

#pragma once

#include "RigidPhysicsComponent.h"
#include <AzFramework/Physics/PhysicsComponentBus.h>

namespace LmbrCentral
{
    /*!
     * Physics component for a ball object.
     */
    class BallPhysicsComponent : public RigidPhysicsComponent
    {
	public:
		AZ_COMPONENT(BallPhysicsComponent, AzFramework::BallPhysicsComponentTypeId, RigidPhysicsComponent);
		static void Reflect(AZ::ReflectContext* context);

		static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
		{
			RigidPhysicsComponent::GetProvidedServices(provided);
			//provided.push_back(AZ_CRC("BallPhysicsService", 0xc03b426c));
		}

		BallPhysicsComponent() = default;
		~BallPhysicsComponent() override = default;

	protected:
		////////////////////////////////////////////////////////////////////////
		// PhysicsComponent
		//void ConfigurePhysicalEntity() override;
		//void ConfigureCollisionGeometry() override;
		pe_type GetPhysicsType() const override { return PE_RIGID; }
		//bool CanInteractWithProximityTriggers() const override { return m_configuration.m_interactsWithTriggers; }
		//bool IsEnabledInitially() const override { return m_configuration.m_enabledInitially; }
		////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////
		// Component
		void Activate() override;
		//bool ReadInConfig(const AZ::ComponentConfig * baseConfig) override;
		//bool WriteOutConfig(AZ::ComponentConfig * outBaseConfig) const override;
		////////////////////////////////////////////////////////////////////////

		AzFramework::RigidPhysicsConfig m_configuration;




    };




} // namespace LmbrCentral

#endif // ENABLE_CRY_PHYSICS