// (C) J St Studio 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Aura/Aura.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectPropertiesData
{
	GENERATED_BODY()
	FEffectPropertiesData () {}

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<AActor> AvatarActor = nullptr;

	UPROPERTY()
	TObjectPtr<AController> Controller = nullptr;

	UPROPERTY()
	TObjectPtr<ACharacter> Character = nullptr;
};

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
	FEffectProperties () {}
	FEffectPropertiesData Source;
	FEffectPropertiesData Target;
	FGameplayEffectContextHandle EffectContextHandle;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TFunctionPointer<FGameplayAttribute>> TagsToAttributes;

	/**
	 * Vital Attributes
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana)

	/**
	 * Primary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Strength, Category="Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Intelligence, Category="Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Resilience, Category="Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Vigor, Category="Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor)

	/**
	 * Secondary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category=SecondaryAttributes)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category=SecondaryAttributes)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Armor, Category=SecondaryAttributes)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ArmorPenetration, Category=SecondaryAttributes)
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BlockChance, Category=SecondaryAttributes)
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitChance, Category=SecondaryAttributes)
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitDamage, Category=SecondaryAttributes)
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitResistance, Category=SecondaryAttributes)
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HealthRegeneration, Category=SecondaryAttributes)
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ManaRegeneration, Category=SecondaryAttributes)
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration)


	/**
	 * Vital Attributes Rep Notifies
	 */
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	/**
	 * Primary Attributes Rep Notifies
	 */
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	/**
	 * Secondary Attributes Rep Notifies
	 */
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
	void ClampAttributeValuesPostGameplayEffect(const FGameplayEffectModCallbackData& Data);
};


