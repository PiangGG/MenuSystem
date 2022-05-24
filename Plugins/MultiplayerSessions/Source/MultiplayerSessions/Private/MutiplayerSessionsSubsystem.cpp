// Fill out your copyright notice in the Description page of Project Settings.


#include "MutiplayerSessionsSubsystem.h"
#include "OnlineSubsystem.h"

UMutiplayerSessionsSubsystem::UMutiplayerSessionsSubsystem()
:
CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnCreateSessionComplete)),
FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this,&ThisClass::OnFindSessionComplete)),
JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnJoinSessionComplete)),
OnDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this,&ThisClass::OnDestroySessionComplete)),
StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnStartSessionComplete))
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		SessionInterface = Subsystem->GetSessionInterface();
	}
}

void UMutiplayerSessionsSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
}

void UMutiplayerSessionsSubsystem::FindSessions(int32 MaxSearchResults)
{
}

void UMutiplayerSessionsSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
}

void UMutiplayerSessionsSubsystem::DestroySession()
{
}

void UMutiplayerSessionsSubsystem::StartSession()
{
}

void UMutiplayerSessionsSubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMutiplayerSessionsSubsystem::OnFindSessionComplete(bool bWasSuccessful)
{
}

void UMutiplayerSessionsSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UMutiplayerSessionsSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMutiplayerSessionsSubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
