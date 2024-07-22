// (C) J St Studio 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();
	
protected:
	// FOnGameplayEffectAppliedDelegate 
	void EffectApplied(UAbilitySystemComponent*, const FGameplayEffectSpec&, FActiveGameplayEffectHandle);
	
};
