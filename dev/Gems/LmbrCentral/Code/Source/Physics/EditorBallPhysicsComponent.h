#if ENABLE_CRY_PHYSICS

#pragma once

#include "EditorRigidPhysicsComponent.h"
#include "BallPhysicsComponent.h"

namespace LmbrCentral
{
    ///**
    // * Configuration data for EditorRigidPhysicsComponent.
    // */
    struct EditorBallPhysicsConfig
        : public AzFramework::BallPhysicsConfig
    {
        AZ_CLASS_ALLOCATOR(EditorBallPhysicsConfig, AZ::SystemAllocator, 0);
        AZ_RTTI(EditorBallPhysicsConfig, "{DAED9BF0-A10F-4DC6-9A36-648D0158029F}", AzFramework::BallPhysicsConfig);
        static void Reflect(AZ::ReflectContext* context);

        // currently, there's no difference between EditorBallPhysicsConfig and its base class.
    };

    /**
     * In-editor physics component for a ball object.
     */
    class EditorBallPhysicsComponent
        : public EditorRigidPhysicsComponent
    {
    public:
        AZ_EDITOR_COMPONENT(EditorBallPhysicsComponent, "{474BB4F0-ABB6-4DDA-A345-88562176A95C}", EditorRigidPhysicsComponent);
        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
        {
            EditorRigidPhysicsComponent::GetProvidedServices(provided);
            //provided.push_back(AZ_CRC("RigidPhysicsService", 0xc03b426c));
            //provided.push_back(AZ_CRC("LegacyCryPhysicsService", 0xbb370351));
        }

        EditorBallPhysicsComponent() = default;
        ~EditorBallPhysicsComponent() override = default;

        ////////////////////////////////////////////////////////////////////////
        // EditorComponentBase
		void BuildGameEntity(AZ::Entity* gameEntity) override;
		//bool ReadInConfig(const AZ::ComponentConfig* baseConfig) override;
		//bool WriteOutConfig(AZ::ComponentConfig* outBaseConfig) const override;
        ////////////////////////////////////////////////////////////////////////

    private:

        EditorBallPhysicsConfig m_configuration;
    };
} // namespace LmbrCentral

#endif // ENABLE_CRY_PHYSICS

