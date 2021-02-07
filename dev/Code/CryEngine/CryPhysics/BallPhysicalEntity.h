#pragma once

#include "rigidentity.h"

class CBallPhysicalEntity : public CRigidEntity {
public:
    explicit CBallPhysicalEntity(CPhysicalWorld* pworld, IGeneralMemoryHeap* pHeap = NULL);
    virtual ~CBallPhysicalEntity();
    virtual pe_type GetType() const { return PE_BALL; }


};