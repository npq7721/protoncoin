/*
 * Copyright (c) 2018 The Phase Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * masternode-level.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Tri Nguyen-Pham
 */

#include "masternode-level.h"


bool isValidMasternode(CAmount value, int height) {
	if(height < LEVEL_COLLATERAL_START_HEIGHT) {
		MasternodeLevel level = COLLATERALS[0];
		CAmount collateral = level.getCollateral();
		return value == collateral;
	}
	int totalLevel = COLLATERALS.size();
	for(int i = 1; i < totalLevel; i++) {
		MasternodeLevel level = COLLATERALS[i];
		if(level.getCollateral() == value) {
			return true;
		}
	}
	return false;

}
Level getMasternodeLevel(CAmount value, int height) {
	if(height < LEVEL_COLLATERAL_START_HEIGHT) {
		MasternodeLevel level = COLLATERALS[0];
		CAmount collateral = level.getCollateral();
		return (value == collateral) ? level.getLevel() : NULL_LEVEL;
	}
	int totalLevel = COLLATERALS.size();
	for(int i = 1; i < totalLevel; i++) {
		MasternodeLevel level = COLLATERALS[i];
		if(level.getCollateral() == value) {
			return level.getLevel();
		}
	}
	return NULL_LEVEL;
}

CAmount getMinimumCollateral(int height){
	CAmount collateral;
	if(height < LEVEL_COLLATERAL_START_HEIGHT) {
		MasternodeLevel level = COLLATERALS[0];
		collateral = level.getCollateral();
	} else {
		MasternodeLevel level = COLLATERALS[1];
		collateral = level.getCollateral();
	}
	return collateral;

}
