// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MutiplayerSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMutiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMutiplayerSessionsSubsystem();
	
	/*
	 * 处理会话，Menu将调用这些函数
	 */
	void CreateSession(int32 NumPublicConnections,FString MatchType);
	void FindSessions(int32 MaxSearchResults);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	void DestroySession();
	void StartSession();
 protected:
	/*
	 *我们将添加到联机会话界面委托列表中的委托的内部回调。
	 * 这个不需要在这个类之外调用。
	 */
	void OnCreateSessionComplete(FName SessionName,bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName,EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName,bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName,bool bWasSuccessful);
private:
	IOnlineSessionPtr SessionInterface;

	/*
	 *添加到联机会话界面委派列表。
	 * 我们将把我们的Mult-iplayerSess-ionsubsystem内部回调绑定到这些。
	 */
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;
	
};
