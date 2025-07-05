// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GASUnrealProject.h"
#include "Abilities/GameplayAbility.h"
#include "MyGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASUNREALPROJECT_API UMyGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UMyGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gas")
	EGASAbilityInputID AbilityInputID = EGASAbilityInputID::None;
};
