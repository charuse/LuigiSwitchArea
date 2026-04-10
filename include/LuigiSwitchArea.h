#pragma once
#include "syati.h"

class LuigiSwitchArea : public AreaObj {
public:
    LuigiSwitchArea(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual const char* getManagerName() const;

    bool mCheckLuigi;
    bool mLuigi;
};