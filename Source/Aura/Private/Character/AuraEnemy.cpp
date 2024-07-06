// (C) J St Studio 2024


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

// @todo Finish highlight actor code


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(RED_HIGHLIGHT);
	if (Weapon)
	{
		Weapon->SetCustomDepthStencilValue(RED_HIGHLIGHT);
	}
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
