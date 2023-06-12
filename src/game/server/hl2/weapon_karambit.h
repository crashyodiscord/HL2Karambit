//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#ifndef WEAPON_KARAMBIT_H
#define WEAPON_KARAMBIT_H

#include "basebludgeonweapon.h"

#if defined( _WIN32 )
#pragma once
#endif

#ifdef HL2MP
#error weapon_karambit.h must not be included in hl2mp. The windows compiler will use the wrong class elsewhere if it is.
#endif

#define	KARAMBIT_RANGE	75.0f
#define	KARAMBIT_REFIRE	0.4f

//-----------------------------------------------------------------------------
// CWeaponKarambit
//-----------------------------------------------------------------------------

class CWeaponKarambit : public CBaseHLBludgeonWeapon
{
public:
	DECLARE_CLASS(CWeaponKarambit, CBaseHLBludgeonWeapon);

	DECLARE_SERVERCLASS();
	DECLARE_ACTTABLE();

	CWeaponCrowbar();

	float		GetRange(void) { return	KARAMBIT_RANGE; }
	float		GetFireRate(void) { return	KARAMBIT_REFIRE; }

	void		AddViewKick(void);
	float		GetDamageForActivity(Activity hitActivity);

	virtual int WeaponMeleeAttack1Condition(float flDot, float flDist);
	void		SecondaryAttack(void) { return; }

	// Animation event
	virtual void Operator_HandleAnimEvent(animevent_t* pEvent, CBaseCombatCharacter* pOperator);

private:
	// Animation event handlers
	void HandleAnimEventMeleeHit(animevent_t* pEvent, CBaseCombatCharacter* pOperator);
};

#endif // WEAPON_KARAMBIT_H
