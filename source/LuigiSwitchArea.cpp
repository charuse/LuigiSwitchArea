#include "LuigiSwitchArea.h"

LuigiSwitchArea::LuigiSwitchArea(const char *pName) : AreaObj(pName) {
    mCheckLuigi = false;
    mLuigi = false;
}

void LuigiSwitchArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    MR::connectToSceneAreaObj(this);
    MR::getJMapInfoArg0NoInit(rIter, &mCheckLuigi);
    this->mLuigi = MR::isPlayerLuigi();
}

void LuigiSwitchArea::movement() {
    if (!isValidSwitchA) return;
    if (isOnSwitchA) return;

    if (isInVolume(*MR::getPlayerPos())) {
        bool isLuigi = this->mLuigi;
        bool check = this->mCheckLuigi;
        //Enabled + Player is Luigi
        if (check && isLuigi) {
            onSwitchA();
        }
        //Disabled + Player is Mario
        else if ((!check) && (!isLuigi)) {
            onSwitchA();
        }
    }
}

const char* LuigiSwitchArea::getManagerName() const {
    return "LuigiSwitchArea";
}

/*
    SW_A
    Activated on Player Enter Area
    
    Obj_arg0
    Disable to Check for Mario
    Enable to Check for Luigi
*/