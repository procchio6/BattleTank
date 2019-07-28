// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ATank* ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possessing tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing: %s"), *ControlledTank->GetName());
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }

    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    return false;
}
