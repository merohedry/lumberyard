/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

// Description : CVars for the MaterialEffects subsystem


#include "CryLegacy_precompiled.h"
#include "MaterialEffectsCVars.h"
#include <CryAction.h>

#include "MaterialEffects.h"

CMaterialEffectsCVars* CMaterialEffectsCVars::s_pThis = 0;

namespace
{
    void MFXReload(IConsoleCmdArgs* pArgs)
    {
        CMaterialEffects* pMaterialEffects = static_cast<CMaterialEffects*>(CCryAction::GetCryAction()->GetIMaterialEffects());

        if (pMaterialEffects)
        {
            pMaterialEffects->FullReload();
        }
    }
};

CMaterialEffectsCVars::CMaterialEffectsCVars()
{
    assert (s_pThis == 0);
    s_pThis = this;

    REGISTER_CVAR(mfx_ParticleImpactThresh, 2.0f, VF_CHEAT, "Impact threshold for particle effects. Default: 2.0");
    REGISTER_CVAR(mfx_SoundImpactThresh, 1.5f, VF_CHEAT, "Impact threshold for sound effects. Default: 1.5");
    REGISTER_CVAR(mfx_RaisedSoundImpactThresh, 3.5f, VF_CHEAT, "Impact threshold for sound effects if we're rolling. Default: 3.5");
    REGISTER_CVAR(mfx_Debug, 0, 0, "Turns on MaterialEffects debug messages. 1=Collisions, 2=Breakage, 3=Both");
    REGISTER_CVAR(mfx_DebugVisual, 0, 0, "Turns on/off visual debugging for MFX system");
    mfx_DebugVisualFilter = REGISTER_STRING("mfx_DebugVisualFilter", "", VF_CHEAT, "");
    REGISTER_CVAR(mfx_Enable, 1, VF_CHEAT, "Enables MaterialEffects.");
    REGISTER_CVAR(mfx_pfx_minScale, .5f, 0, "Min scale (when particle is close)");
    REGISTER_CVAR(mfx_pfx_maxScale, 1.5f, 0, "Max scale (when particle is far)");
    REGISTER_CVAR(mfx_pfx_maxDist, 35.0f, 0, "Max dist (how far away before scale is clamped)");
    REGISTER_CVAR(mfx_Timeout, 0.01f, 0, "Timeout (in seconds) to avoid playing effects too often");
    REGISTER_CVAR(mfx_EnableAttachedEffects, 1, VF_CHEAT, "Enable attached effects (characters, entities...)");

    //Reload Excel Spreadsheet
    REGISTER_COMMAND("mfx_Reload", MFXReload, 0, "Reload MFX Spreadsheet");
}

CMaterialEffectsCVars::~CMaterialEffectsCVars()
{
    assert (s_pThis != 0);
    s_pThis = 0;

    IConsole* pConsole = gEnv->pConsole;

    pConsole->RemoveCommand("mfx_Reload");
    pConsole->RemoveCommand("mfx_ReloadHUDEffects");

    pConsole->UnregisterVariable("mfx_ParticleImpactThresh", true);
    pConsole->UnregisterVariable("mfx_SoundImpactThresh", true);
    pConsole->UnregisterVariable("mfx_RaisedSoundImpactThresh", true);
    pConsole->UnregisterVariable("mfx_Debug", true);
    pConsole->UnregisterVariable("mfx_DebugVisual", true);
    pConsole->UnregisterVariable("mfx_DebugVisualFilter", true);
    pConsole->UnregisterVariable("mfx_Enable", true);
    pConsole->UnregisterVariable("mfx_pfx_minScale", true);
    pConsole->UnregisterVariable("mfx_pfx_maxScale", true);
    pConsole->UnregisterVariable("mfx_pfx_maxDist", true);
    pConsole->UnregisterVariable("mfx_Timeout", true);
    pConsole->UnregisterVariable("mfx_EnableAttachedEffects", true);
}
