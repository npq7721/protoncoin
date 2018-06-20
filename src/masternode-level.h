/*
 * Copyright (c) 2018 The Phase Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * masternode-level.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Tri Nguyen-Pham
 */

#ifndef SRC_MASTERNODE_LEVEL_H_
#define SRC_MASTERNODE_LEVEL_H_

#include "amount.h"
#include <vector>
using namespace std;
enum Level {
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	NULL_LEVEL
};

class MasternodeLevel {
public:
	MasternodeLevel(Level level, CAmount levelCollateral) {
		this->level = level;
		this->levelCollateral = levelCollateral;
	}
	Level getLevel(){
		return this->level;
	}
	CAmount getCollateral() {
		return this->levelCollateral;
	}
private:
	Level level;
	CAmount levelCollateral;
};
static const vector<MasternodeLevel> COLLATERALS = {
		MasternodeLevel(LEVEL1, 5000),
		MasternodeLevel(LEVEL2, 10000),
		MasternodeLevel(LEVEL3, 20000),
		MasternodeLevel(LEVEL4, 30000)
};
static const int LEVEL_COLLATERAL_START_HEIGHT = 3002;

extern bool isValidMasternode(CAmount value, int height);
extern Level getMasternodeLevel(CAmount value, int height);
extern CAmount getMinimumCollateral(int height);


#endif /* SRC_MASTERNODE_LEVEL_H_ */
