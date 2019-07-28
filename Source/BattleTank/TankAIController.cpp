// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *PlayerTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();    
    return Cast<ATank>(PlayerPawn);
}
