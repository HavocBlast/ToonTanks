// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find distance to the tank
	if(Tank)
	{
		float const Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		// See if tank is in range

		if(Distance <= FireRange)
		{
			// If in range then rotate turret to tank
			RotateTurret(Tank->GetActorLocation());
		}

		
	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

