// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SUPEREGO_API AttackData
{

public:
	AttackData();
	~AttackData();

	// Melee weapon like sword, axe...
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Damage;

	// Projectile like arrow...
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float ArmorDamage;

};
