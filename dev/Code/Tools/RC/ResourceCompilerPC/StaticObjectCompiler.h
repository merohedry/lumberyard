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

#ifndef CRYINCLUDE_TOOLS_RC_RESOURCECOMPILERPC_STATICOBJECTCOMPILER_H
#define CRYINCLUDE_TOOLS_RC_RESOURCECOMPILERPC_STATICOBJECTCOMPILER_H
#pragma once


#include "ConvertContext.h"

class CContentCGF;
struct CMaterialCGF;
class CMesh;
class CPhysicsInterface;
//START: Add Skinned Geometry (.CGF) export type (for touch bending vegetation)
struct CSkinningInfo;
struct SFoliageInfoCGF;
struct SSpineRC;
//END: Add Skinned Geometry (.CGF) export type (for touch bending vegetation)

class CStaticObjectCompiler
{
public:
#if ENABLE_CRY_PHYSICS
    CStaticObjectCompiler(CPhysicsInterface* pPhysicsInterface, bool bConsole, int logVerbosityLevel = 0);
#else
    CStaticObjectCompiler(bool bConsole, int logVerbosityLevel = 0);
#endif
    ~CStaticObjectCompiler();

    void SetSplitLods(bool bSplit);
    // Confetti: Nicholas Baldwin
    void SetOptimizeStripify(bool bStripify);
    void SetUseMikkTB(bool bUseMikkTB);

    CContentCGF* MakeCompiledCGF(CContentCGF* pCGF, bool const forceRecompile = false);

    static int GetSubMeshCount(const CContentCGF* pCGFLod0);
    static int GetJointCount(const CContentCGF* pCGF);

private:
    bool ProcessCompiledCGF(CContentCGF* pCGF);

    void AnalyzeSharedMeshes(CContentCGF* pCGF);
    bool CompileMeshes(CContentCGF* pCGF);

    bool SplitLODs(CContentCGF* pCGF);
    CContentCGF* MakeLOD(int nLodNum, const CContentCGF* pCGF);

    bool Physicalize(CContentCGF* pCompiledCGF, CContentCGF* pSrcCGF);
    void CompileDeformablePhysData(CContentCGF* pCGF);
    void AnalyzeFoliage(CContentCGF* pCGF, struct CNodeCGF* pNodeCGF);
    void PrepareSkinData(CNodeCGF* pNode, const Matrix34& mtxSkelToMesh, CNodeCGF* pNodeSkel, float r, bool bSwapEndian);

    bool ValidateBoundingBoxes(CContentCGF* pCGF);
    void ValidateBreakableJoints(const CContentCGF* pCGF);

    bool MakeMergedCGF(CContentCGF* pCompiledCGF, CContentCGF* pCGF);

    //START: Add Skinned Geometry (.CGF) export type (for touch bending vegetation)
    void BuildFoliageInfoFromSkinningInfo(SFoliageInfoCGF& foliageInfo, const CSkinningInfo* pSkinningInfo, CContentCGF* pCGF);
    void CreateSpinesFromSkinningData(SSpineRC** pSpines, int& spineCount, const CSkinningInfo* pSkinningInfo, const CMesh& mesh, CContentCGF* pCGF);
    void ConnectSpines(SSpineRC* pSpines, const CSkinningInfo* pSkinningInfo, int spineCount);
    void SetupPhysData(SSpineRC* pSpines, int spineCount, const CSkinningInfo* pSkinningInfo, const CMesh& mesh);
    //END: Add Skinned Geometry (.CGF) export type (for touch bending vegetation)

private:
#if ENABLE_CRY_PHYSICS
    CPhysicsInterface* m_pPhysicsInterface;
#endif
    bool m_bSplitLODs;
    bool m_bOwnLod0;
    bool m_bConsole;
    int m_logVerbosityLevel;
    bool m_bUseMikkTB;
    // Confetti: Nicholas Baldwin
    bool m_bOptimizePVRStripify;

public:
    enum
    {
        MAX_LOD_COUNT = 6
    };
    CContentCGF* m_pLODs[MAX_LOD_COUNT];
};

#endif // CRYINCLUDE_TOOLS_RC_RESOURCECOMPILERPC_STATICOBJECTCOMPILER_H
