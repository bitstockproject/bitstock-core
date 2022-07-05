// Copyright (c) 2020 The Bitstock developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    if (nHeight >  900000) return   10000 * COIN;
    if (nHeight >  850000) return    9000 * COIN;
    if (nHeight >  800000) return    8000 * COIN;
    if (nHeight >  750000) return    7000 * COIN;
    if (nHeight >  700000) return    6000 * COIN;
    if (nHeight >  650000) return    5000 * COIN;
    if (nHeight >  600000) return    4500 * COIN;
    if (nHeight >  550000) return    4000 * COIN;
    if (nHeight >  500000) return    3500 * COIN;
    if (nHeight >  450000) return    3000 * COIN;
    if (nHeight >  400000) return    2500 * COIN;
    if (nHeight >  350000) return    2000 * COIN;
    if (nHeight >  300000) return    1500 * COIN;
    if (nHeight >  250000) return    1000 * COIN;
    if (nHeight >  200000) return     700 * COIN;
    if (nHeight >  150000) return     500 * COIN;
    if (nHeight >  100000) return     300 * COIN;
    if (nHeight >   60000) return     200 * COIN;
         
    return 100 * COIN;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
