// (C) J St Studio 2024


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

class AAuraPlayerState;

TTuple<AAuraHUD*, FWidgetControllerParams> UAuraAbilitySystemLibrary::GetWidgetControllerPackage(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
		
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return TTuple<AAuraHUD*, FWidgetControllerParams>(AuraHUD, WidgetControllerParams);
		}
	}
	
	return TTuple<AAuraHUD*, FWidgetControllerParams>(nullptr, FWidgetControllerParams());
}

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	TTuple<AAuraHUD*, FWidgetControllerParams> WidgetControllerPackage = GetWidgetControllerPackage(WorldContextObject);
	return WidgetControllerPackage.Key->GetOverlayWidgetController(WidgetControllerPackage.Value);
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	TTuple<AAuraHUD*, FWidgetControllerParams> WidgetControllerPackage = GetWidgetControllerPackage(WorldContextObject);
	return WidgetControllerPackage.Key->GetAttributeMenuWidgetController(WidgetControllerPackage.Value);
}


