// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthAttrComponent.h"

// Sets default values for this component's properties
UHealthAttrComponent::UHealthAttrComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHealthAttrComponent::BeginPlay()
{
	Super::BeginPlay();

	auto Owner = GetOwner();
	AttrSet = NewObject<ULivingEntityAttributeSet>(Owner);
	AbilitySystemComponent = Owner->FindComponentByClass<UAbilitySystemComponent>();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AddAttributeSetSubobject(AttrSet);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttrSet->GetHealthAttribute())
			.AddUObject(this, &UHealthAttrComponent::OnHealthChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttrSet->GetMaxHealthAttribute())
			.AddUObject(this, &UHealthAttrComponent::OnMaxHealthChangedNative);
	}
}


// Called every frame
void UHealthAttrComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthAttrComponent::OnHealthChangedNative(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue, Data.OldValue);

	if (Data.NewValue <= 0)
	{
		OnDeath.Broadcast(Data.NewValue, Data.OldValue);
	}
}

void UHealthAttrComponent::OnMaxHealthChangedNative(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue, Data.OldValue);
}
