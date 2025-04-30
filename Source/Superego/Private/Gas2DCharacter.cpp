// Fill out your copyright notice in the Description page of Project Settings.


#include "Gas2DCharacter.h"

AGas2DCharacter::AGas2DCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AGas2DCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}