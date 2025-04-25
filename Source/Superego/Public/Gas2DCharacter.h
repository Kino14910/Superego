// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "Gas2DCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SUPEREGO_API AGas2DCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
    AGas2DCharacter();

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
};
