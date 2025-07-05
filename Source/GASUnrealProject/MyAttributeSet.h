// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASUNREALPROJECT_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UMyAttributeSet();
	
	/** Returns properties that are replicated for the lifetime of the actor channel */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	// This uses the macro method defined earlier
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	// This uses the macro method defined earlier
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing=OnRep_Power)
	FGameplayAttributeData Power;
	// This uses the macro method defined earlier
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Power);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
protected:
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
	UFUNCTION()
	virtual void OnRep_Power(const FGameplayAttributeData& OldPower);
};
