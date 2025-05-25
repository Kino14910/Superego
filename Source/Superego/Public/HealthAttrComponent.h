// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LivingEntityAttributeSet.h"
#include "HealthAttrComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnValueChange, float, Health, float, Old);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class SUPEREGO_API UHealthAttrComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthAttrComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULivingEntityAttributeSet* AttrSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	void OnHealthChangedNative(const FOnAttributeChangeData& Data) const;
	void OnMaxHealthChangedNative(const FOnAttributeChangeData& Data) const;

	UPROPERTY(BlueprintAssignable)
	FOnValueChange OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnValueChange OnDeath;

	UPROPERTY(BlueprintAssignable)
	FOnValueChange OnMaxHealthChanged;
};
