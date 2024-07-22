// (C) J St Studio 2024


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent*, const FGameplayEffectSpec&,
                                                FActiveGameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Blue, FString("Effect Applied!"));
}
