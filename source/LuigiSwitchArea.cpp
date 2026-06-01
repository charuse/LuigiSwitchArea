#include "LuigiSwitchArea.h"
using namespace MR;

LuigiSwitchArea::LuigiSwitchArea(const char *pName) : AreaObj(pName) {
    mCtrl = NULL;
    mLuigi = false;
    mGo = true;
}

void LuigiSwitchArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    connectToSceneAreaObj(this);
    mCtrl = createStageSwitchCtrl(this, rIter);
    this->mLuigi = !isPlayerLuigi();
}

void LuigiSwitchArea::movement() {
    if (mGo && isInVolume(*getPlayerPos())) {
        mGo = false;
        if (mLuigi) mCtrl->onSwitchA(); // Mario
        else mCtrl->onSwitchB(); // Luigi
    }
}

const char* LuigiSwitchArea::getManagerName() const {
    return "LuigiSwitchArea";
}

/*      SW_A: Mario
        SW_B: Luigi     */