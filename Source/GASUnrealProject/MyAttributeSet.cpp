// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAttributeSet.h"

#include "Net/UnrealNetwork.h"

UMyAttributeSet::UMyAttributeSet()
{
}

void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Power, COND_None, REPNOTIFY_Always);
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetMaxHealthAttribute())
	{
		UAbilitySystemComponent* AbilityComponent = GetOwningAbilitySystemComponent();

		const float CurrentMaxHealth = MaxHealth.GetCurrentValue();

		if(!FMath::IsNearlyEqual(NewValue, CurrentMaxHealth) && AbilityComponent)
		{
			const float CerrentHealth = Health.GetCurrentValue();
			
			float NewHealth = NewValue / CurrentMaxHealth * CerrentHealth;

			AbilityComponent-> ApplyModToAttributeUnsafe(GetHealthAttribute(), EGameplayModOp::Override, NewHealth);
		}
	}
}

void UMyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
}

void UMyAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxHealth, OldMaxHealth);
}

void UMyAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Power, OldPower);
}