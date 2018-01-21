// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSMStateBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FSM_API UFSMStateBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "FSM")
		void Enter();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "FSM")
		void OnUpDate(float DeltaTime);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "FSM")
		void Exit();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "FSM")
		int GetIndex();

	
	
	
	
};
