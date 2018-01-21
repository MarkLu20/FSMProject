// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CreateObject.generated.h"

/**
 * 
 */
UCLASS()
class FSM_API UCreateObject : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CatreateObject")
		static UObject* CreaeObject(UObject* owner,UClass *uclass);
	
	
	
};
