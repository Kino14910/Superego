// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LivingEntityAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class SUPEREGO_API ULivingEntityAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	ULivingEntityAttributeSet();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Gas2DCharacter")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(ULivingEntityAttributeSet, Health)

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Gas2DCharacter")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(ULivingEntityAttributeSet, MaxHealth)

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
