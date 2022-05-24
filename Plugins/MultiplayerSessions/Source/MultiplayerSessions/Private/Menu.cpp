// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

#include "MutiplayerSessionsSubsystem.h"
#include "Components/Button.h"

void UMenu::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController * PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
	
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		MutiplayerSessionsSubsystem = GameInstance->GetSubsystem<UMutiplayerSessionsSubsystem>();
	}
}

bool UMenu::Initialize()
{
	if (! Super::Initialize())
	{
		return false;
	}
	if (HostButton)
	{
		HostButton->OnClicked.AddDynamic(this,&ThisClass::HostButtonClicked);
	}
	if (JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this,&ThisClass::JoinButtonClicked);
		
	}
	return true;
}

void UMenu::HostButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow,FString("Host Button Clicked"));
	}
	if (MutiplayerSessionsSubsystem)
	{
		MutiplayerSessionsSubsystem->CreateSession(4,FString("FreeForAll")); 
	}
}

void UMenu::JoinButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow,FString("Join Button Clicked"));
	}
}
