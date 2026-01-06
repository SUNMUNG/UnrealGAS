// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/StatusAttributeSet.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayEffectExtension.h"

UStatusAttributeSet::UStatusAttributeSet()
{
	InitMoveSpeed(1.0f);
	InitJumpPower(1.0f);

	
}

void UStatusAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMoveSpeedAttribute())
	{
		Cast<ACharacter>(GetOwningActor())->GetCharacterMovement()->MaxWalkSpeed =
			Cast<ACharacter>(GetOwningActor())->GetCharacterMovement()->GetMaxSpeed() * NewValue;
		UE_LOG(LogTemp, Log, TEXT("현재 이동속도 : %.1f"), GetMoveSpeed());
	}

	if (Attribute == GetJumpPowerAttribute())
	{

	}
}

void UStatusAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	UE_LOG(LogTemp, Log, TEXT("현재 이동속도 : %.1f"), GetMoveSpeed());
	if (Data.EvaluatedData.Attribute == GetMoveSpeedAttribute())	// Health를 변경시키는 이팩트가 실행된 후에 호출되었는지 확인
	{
	
		UE_LOG(LogTemp, Log, TEXT("현재 이동속도 : %.1f"), GetMoveSpeed());
		

	
	}

}
