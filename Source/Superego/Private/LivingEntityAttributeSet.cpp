// Fill out your copyright notice in the Description page of Project Settings.


#include "LivingEntityAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

ULivingEntityAttributeSet::ULivingEntityAttributeSet()
{
}

void ULivingEntityAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), .0f, GetMaxHealth()));
	}
}
