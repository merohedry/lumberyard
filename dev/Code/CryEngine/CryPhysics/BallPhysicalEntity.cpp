#include "StdAfx.h"


#if ENABLE_CRY_PHYSICS

#include "bvtree.h"
#include "geometry.h"
#include "bvtree.h"
#include "singleboxtree.h"
#include "boxgeom.h"
#include "raybv.h"
#include "raygeom.h"
#include "rigidbody.h"
#include "physicalplaceholder.h"
#include "physicalentity.h"
#include "geoman.h"
#include "physicalworld.h"
#include "rigidentity.h"
#include "waterman.h"



#include "BallPhysicalEntity.h"


CBallPhysicalEntity::CBallPhysicalEntity(CPhysicalWorld* pworld, IGeneralMemoryHeap* pHeap /*= NULL*/) : CRigidEntity(pworld, pHeap)
{

}

CBallPhysicalEntity::~CBallPhysicalEntity()
{

}



#endif // ENABLE_CRY_PHYSICS