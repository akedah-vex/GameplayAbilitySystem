// (C) J St Studio 2024


#include "Character/AuraEnemy.h"

// @todo Finish highlight actor code


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	highlighted = true;
}

void AAuraEnemy::UnHighlightActor()
{
	highlighted = false;
}
