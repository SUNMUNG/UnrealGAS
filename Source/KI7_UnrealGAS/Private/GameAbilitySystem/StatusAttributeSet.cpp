// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/StatusAttributeSet.h"

UStatusAttributeSet::UStatusAttributeSet()
{
}

void UStatusAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UStatusAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}
