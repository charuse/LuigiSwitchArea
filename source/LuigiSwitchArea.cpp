#include "LuigiSwitchArea.h"

LuigiSwitchArea::LuigiSwitchArea(const char *pName) : AreaObj(pName) {
    mLuigi = false;
}

void LuigiSwitchArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    MR::connectToSceneAreaObj(this);
    this->mLuigi = MR::isPlayerLuigi();
}

void LuigiSwitchArea::movement() {
    if (isInVolume(*MR::getPlayerPos())) {
        bool switchB = isOnSwitchB();
        bool isLuigi = this->mLuigi;
        //SW_B enabled + Luigi
        if (switchB && isLuigi) {
            onSwitchA();
        }
        //SW_B disabled + Mario
        else if ((!switchB) && (!isLuigi)) {
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
    
    SW_B
    Disable to check for Mario
    Enable to check for Luigi
*/